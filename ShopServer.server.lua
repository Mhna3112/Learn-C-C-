local Players = game:GetService("Players")
local ReplicatedStorage = game:GetService("ReplicatedStorage")
local ServerStorage = game:GetService("ServerStorage")

local ShopConfig = require(script.Parent:WaitForChild("ShopConfig.module"))

local REMOTE_FOLDER_NAME = "ShopRemotes"
local ITEMS_FOLDER_NAME = "ShopItems"

local remotesFolder = ReplicatedStorage:FindFirstChild(REMOTE_FOLDER_NAME)
if not remotesFolder then
    remotesFolder = Instance.new("Folder")
    remotesFolder.Name = REMOTE_FOLDER_NAME
    remotesFolder.Parent = ReplicatedStorage
end

local getCatalogRemote = remotesFolder:FindFirstChild("GetCatalog")
if not getCatalogRemote then
    getCatalogRemote = Instance.new("RemoteFunction")
    getCatalogRemote.Name = "GetCatalog"
    getCatalogRemote.Parent = remotesFolder
end

local getBalanceRemote = remotesFolder:FindFirstChild("GetBalance")
if not getBalanceRemote then
    getBalanceRemote = Instance.new("RemoteFunction")
    getBalanceRemote.Name = "GetBalance"
    getBalanceRemote.Parent = remotesFolder
end

local buyItemRemote = remotesFolder:FindFirstChild("BuyItem")
if not buyItemRemote then
    buyItemRemote = Instance.new("RemoteFunction")
    buyItemRemote.Name = "BuyItem"
    buyItemRemote.Parent = remotesFolder
end

local purchaseEvent = remotesFolder:FindFirstChild("PurchaseResult")
if not purchaseEvent then
    purchaseEvent = Instance.new("RemoteEvent")
    purchaseEvent.Name = "PurchaseResult"
    purchaseEvent.Parent = remotesFolder
end

local itemsFolder = ServerStorage:WaitForChild(ITEMS_FOLDER_NAME)

local function ensureLeaderstats(player)
    local leaderstats = player:FindFirstChild("leaderstats")
    if not leaderstats then
        leaderstats = Instance.new("Folder")
        leaderstats.Name = "leaderstats"
        leaderstats.Parent = player
    end

    local coins = leaderstats:FindFirstChild("Coins")
    if not coins then
        coins = Instance.new("IntValue")
        coins.Name = "Coins"
        coins.Value = 500
        coins.Parent = leaderstats
    end

    return coins
end

local function getCoins(player)
    local leaderstats = player:FindFirstChild("leaderstats")
    if not leaderstats then
        return nil
    end

    local coins = leaderstats:FindFirstChild("Coins")
    if coins and coins:IsA("IntValue") then
        return coins
    end

    return nil
end

local function hasTool(player, toolName)
    local backpack = player:FindFirstChild("Backpack")
    if backpack and backpack:FindFirstChild(toolName) then
        return true
    end

    local character = player.Character
    if character and character:FindFirstChild(toolName) then
        return true
    end

    return false
end

Players.PlayerAdded:Connect(function(player)
    ensureLeaderstats(player)
end)

getCatalogRemote.OnServerInvoke = function(_player)
    local catalog = {}
    for id, item in pairs(ShopConfig.Items) do
        catalog[id] = {
            id = item.id,
            displayName = item.displayName,
            price = item.price,
        }
    end
    return catalog
end

getBalanceRemote.OnServerInvoke = function(player)
    local coins = ensureLeaderstats(player)
    return coins.Value
end

buyItemRemote.OnServerInvoke = function(player, itemId)
    if type(itemId) ~= "string" then
        return false, "Invalid item id"
    end

    local item = ShopConfig.Items[itemId]
    if not item then
        return false, "Item does not exist"
    end

    local coins = getCoins(player)
    if not coins then
        return false, "Coins data not found"
    end

    if hasTool(player, item.toolName) then
        return false, "You already own this item"
    end

    if coins.Value < item.price then
        return false, "Not enough coins"
    end

    local template = itemsFolder:FindFirstChild(item.toolName)
    if not template or not template:IsA("Tool") then
        return false, "Item template missing in ServerStorage/ShopItems"
    end

    coins.Value = coins.Value - item.price

    local clonedTool = template:Clone()
    clonedTool.Parent = player:WaitForChild("Backpack")

    purchaseEvent:FireClient(player, true, string.format("Bought %s for %d coins", item.displayName, item.price), coins.Value)
    return true, "Purchase successful", coins.Value
end
