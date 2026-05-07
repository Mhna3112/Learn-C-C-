local Players = game:GetService("Players")
local RunService = game:GetService("RunService")
local CoreGui = game:GetService("CoreGui")

local Player = Players.LocalPlayer

-- ==========================================
-- ANTI-CHEAT BYPASS
-- ==========================================
-- [1] Hook __namecall: Chặn Remote gửi lên Server khi đang bay
-- Các game Tsunami/Obby thường gửi RemoteEvent kiểm tra vị trí/tốc độ
local _bypassing = false -- cờ bật khi đang fly

local old_namecall
old_namecall = hookmetamethod(game, "__namecall", newcclosure(function(self, ...)
    local method = getnamecallmethod()

    -- Chặn các lệnh anti-cheat phổ biến khi đang bay
    if _bypassing and not checkcaller() then
        -- Chặn FireServer / InvokeServer nếu tên Remote nghi ngờ là anti-cheat
        if method == "FireServer" or method == "InvokeServer" then
            local remote_name = string.lower(tostring(self.Name or ""))
            -- Danh sách tên Remote anti-cheat phổ biến
            local blocked = {
                "check", "anticheat", "anti", "detect", "kick",
                "ban", "speed", "teleport", "exploit", "verify",
                "validation", "movement", "position", "velocity",
                "fly", "noclip", "cheat"
            }
            for _, kw in ipairs(blocked) do
                if string.find(remote_name, kw) then
                    -- Nuốt lệnh, không gửi lên server
                    if method == "InvokeServer" then
                        return nil
                    end
                    return
                end
            end
        end
    end

    return old_namecall(self, ...)
end))

-- [2] Disable Fall Damage: Khi nhân vật rơi xuống sau khi tắt fly
Player.CharacterAdded:Connect(function(char)
    local hum = char:WaitForChild("Humanoid")
    -- Bắt sự kiện FreeFalling và ngăn fall damage
    hum.FreeFalling:Connect(function(active)
        if active then
            -- Set state liên tục để không bị tính fall damage
            task.spawn(function()
                while hum and hum.Health > 0 and hum:GetState() == Enum.HumanoidStateType.Freefall do
                    hum:ChangeState(Enum.HumanoidStateType.Landed)
                    task.wait(0.1)
                end
            end)
        end
    end)
    -- Tắt các state gây chết
    hum:SetStateEnabled(Enum.HumanoidStateType.Dead, false)
    hum:SetStateEnabled(Enum.HumanoidStateType.FallingDown, false)
    hum:SetStateEnabled(Enum.HumanoidStateType.Ragdoll, false)
end)

print("[Bypass] Anti-cheat hooks loaded!")

-- ==========================================
-- CONFIG
-- ==========================================
getgenv().Config = getgenv().Config or {
    AutoFarm = false,
    FlySpeed = 500,  -- Studs/giây
    FlyHeight = 100, -- Độ cao Y khi bay
}

-- ==========================================
-- NOCLIP liên tục (tránh bị tường cản)
-- ==========================================
local _noclip_conn = nil
local function set_noclip(on)
    if on then
        if _noclip_conn then return end
        _noclip_conn = RunService.Stepped:Connect(function()
            local char = Player.Character
            if not char then return end
            for _, p in ipairs(char:GetDescendants()) do
                if p:IsA("BasePart") then p.CanCollide = false end
            end
        end)
    else
        if _noclip_conn then
            _noclip_conn:Disconnect()
            _noclip_conn = nil
        end
    end
end

-- ==========================================
-- XÓA KILL BRICKS (TouchTransmitter nguy hiểm)
-- ==========================================
local function remove_kill_bricks()
    for _, obj in ipairs(workspace:GetDescendants()) do
        if obj:IsA("TouchTransmitter") and obj.Parent then
            local n = string.lower(obj.Parent.Name)
            if not string.find(n, "win") and not string.find(n, "safe") and not string.find(n, "goal") then
                pcall(function() obj:Destroy() end)
            end
        end
    end
end

-- ==========================================
-- TÌM WIN PART
-- ==========================================
local function find_win_part()
    local keywords = { "win", "safe", "goal", "finish", "end", "reward" }
    for _, obj in ipairs(workspace:GetDescendants()) do
        if obj:IsA("BasePart") then
            local n = string.lower(obj.Name)
            for _, kw in ipairs(keywords) do
                if string.find(n, kw) then
                    return obj
                end
            end
        end
    end
    return nil
end

-- ==========================================
-- FLY ENGINE (BodyVelocity - smooth, no jitter)
-- Tự dọn dẹp khi character đổi
-- ==========================================
local _flying = false
local _fly_token = 0 -- Token tăng mỗi lần gọi fly_to mới, ngăn task cũ ghi đè kết quả
local _going_to_dest = true -- true = bay tới Celestial, false = bay về BrainrotFloor

local function stop_fly()
    _flying = false
    _bypassing = false -- Ngưng chặn anti-cheat remote
    set_noclip(false)
    local char = Player.Character
    if not char then return end
    local root = char:FindFirstChild("HumanoidRootPart")
    if root then
        local bv = root:FindFirstChild("_AFV")
        if bv then bv:Destroy() end
        local bg = root:FindFirstChild("_AFG")
        if bg then bg:Destroy() end
        pcall(function()
            root.AssemblyLinearVelocity = Vector3.new(0, 0, 0)
        end)
    end
    local hum = char:FindFirstChildOfClass("Humanoid")
    if hum then
        hum:ChangeState(Enum.HumanoidStateType.Freefall)
    end
end

-- Fly tới target_pos (Vector3), tự tắt khi tới nơi
-- Callback on_done() khi đến nơi hoặc bị hủy
local function fly_to(target_pos)
    stop_fly()
    task.wait(0.05)

    local char = Player.Character
    if not char then return end
    local root = char:FindFirstChild("HumanoidRootPart")
    local hum = char:FindFirstChildOfClass("Humanoid")
    if not root or not hum then return end

    _flying = true
    _fly_token = _fly_token + 1
    local my_token = _fly_token -- Chụp snapshot token

    _bypassing = true           -- Bật bypass anti-cheat khi bay
    set_noclip(true)
    remove_kill_bricks()

    -- TELEPORT LÊN ĐỘ CAO NGAY LẬP TỨC
    root.CFrame = CFrame.new(root.Position.X, target_pos.Y, root.Position.Z)

    local bv = Instance.new("BodyVelocity")
    bv.Name = "_AFV"
    bv.MaxForce = Vector3.new(9e9, 9e9, 9e9)
    bv.P = 9e4
    bv.Velocity = Vector3.new(0, 0, 0)
    bv.Parent = root

    local bg = Instance.new("BodyGyro")
    bg.Name = "_AFG"
    bg.MaxTorque = Vector3.new(9e9, 9e9, 9e9)
    bg.P = 9e4
    bg.D = 100
    bg.CFrame = root.CFrame
    bg.Parent = root

    hum:ChangeState(Enum.HumanoidStateType.Physics)

    task.spawn(function()
        while _flying and _fly_token == my_token do
            if not root or not root.Parent then break end

            if hum:GetState() ~= Enum.HumanoidStateType.Physics then
                hum:ChangeState(Enum.HumanoidStateType.Physics)
            end

            -- Giữ độ cao FlyHeight, bay thẳng về phía trước
            local cur = root.Position
            local dy = target_pos.Y - cur.Y
            local to = target_pos - cur

            local dir = Vector3.new(to.X, dy, to.Z)
            if dir.Magnitude > 0 then dir = dir.Unit end
            bv.Velocity = dir * getgenv().Config.FlySpeed
            bg.CFrame = CFrame.new(cur, cur + Vector3.new(to.X, 0, to.Z))


            RunService.Heartbeat:Wait()
        end

        -- CHỈ dọn dẹp nếu đây vẫn là phiên bay mới nhất (không bị supersede)
        if _fly_token == my_token then
            stop_fly()
        end
    end)
end

-- ==========================================
-- AUTO FARM MAIN LOOP
-- ==========================================
local function start_autofarm()
    -- Reset khi nhân vật đổi (die hoặc teleport respawn)
    Player.CharacterAdded:Connect(function(new_char)
        _flying = false
        -- Đợi character load xong hoàn toàn rồi mới cho bay lại
        new_char:WaitForChild("HumanoidRootPart")
        new_char:WaitForChild("Humanoid")
        task.wait(1) -- Đợi thêm 1 giây cho game ổn định
    end)

    task.spawn(function()
        while true do
            task.wait(0.5)

            if not getgenv().Config.AutoFarm then
                if _flying then stop_fly() end
                continue
            end

            -- Đang bay thì không làm phiền
            if _flying then continue end

            local char = Player.Character
            if not char then continue end

            local root = char:FindFirstChild("HumanoidRootPart")
            local hum = char:FindFirstChildOfClass("Humanoid")
            if not root or not hum or hum.Health <= 0 then continue end

            -- Tìm điểm đích: Celestial
            local destination = nil
            -- Cách 1: Path trực tiếp
            pcall(function()
                local c = workspace.DefaultMap_SharedInstances.Floors.Celestial
                destination = c:IsA("BasePart") and c or c:FindFirstChildWhichIsA("BasePart")
            end)
            -- Cách 2: Fallback quét workspace tìm part tên "Celestial"
            if not destination then
                for _, obj in ipairs(workspace:GetDescendants()) do
                    if obj:IsA("BasePart") and string.lower(obj.Name) == "celestial" then
                        destination = obj
                        break
                    end
                end
            end
            -- Debug: in lỗi nếu không tìm thấy
            if not destination then
                warn("[AutoFarm] Không tìm thấy Celestial! Kiểm tra lại path.")
                task.wait(5)
                continue
            end
            print("[AutoFarm] Bay tới:", destination:GetFullName(), destination.Position)

            local target = Vector3.new(
                destination.Position.X,
                getgenv().Config.FlyHeight,
                destination.Position.Z
            )

            fly_to(target)
        end
    end)
end

-- ==========================================
-- UI TOGGLE
-- ==========================================
local function create_ui()
    local old = CoreGui:FindFirstChild("TsunamiAutoFarmUI")
    if old then old:Destroy() end

    local gui = Instance.new("ScreenGui")
    gui.Name = "TsunamiAutoFarmUI"
    gui.ResetOnSpawn = false
    gui.Parent = CoreGui

    local frame = Instance.new("Frame")
    frame.Size = UDim2.new(0, 200, 0, 80)
    frame.Position = UDim2.new(0.5, -100, 0, 20)
    frame.BackgroundColor3 = Color3.fromRGB(25, 25, 25)
    frame.BorderSizePixel = 0
    frame.Parent = gui
    Instance.new("UICorner", frame).CornerRadius = UDim.new(0, 8)

    local title = Instance.new("TextLabel")
    title.Text = "Tsunami Brainrot Auto"
    title.Size = UDim2.new(1, 0, 0, 30)
    title.BackgroundTransparency = 1
    title.TextColor3 = Color3.fromRGB(255, 255, 255)
    title.Font = Enum.Font.GothamBold
    title.TextSize = 13
    title.Parent = frame

    local btn = Instance.new("TextButton")
    btn.Size = UDim2.new(0, 160, 0, 35)
    btn.Position = UDim2.new(0.5, -80, 0, 35)
    btn.BackgroundColor3 = Color3.fromRGB(220, 50, 50)
    btn.Text = "AUTO FARM: OFF"
    btn.TextColor3 = Color3.fromRGB(255, 255, 255)
    btn.Font = Enum.Font.GothamBold
    btn.TextSize = 13
    btn.Parent = frame
    Instance.new("UICorner", btn).CornerRadius = UDim.new(0, 6)

    btn.MouseButton1Click:Connect(function()
        getgenv().Config.AutoFarm = not getgenv().Config.AutoFarm
        if getgenv().Config.AutoFarm then
            btn.Text = "AUTO FARM: ON"
            btn.BackgroundColor3 = Color3.fromRGB(50, 200, 50)
        else
            btn.Text = "AUTO FARM: OFF"
            btn.BackgroundColor3 = Color3.fromRGB(220, 50, 50)
            stop_fly()
        end
    end)

    -- Drag
    local dragging, dstart, fstart
    frame.InputBegan:Connect(function(i)
        if i.UserInputType == Enum.UserInputType.MouseButton1 then
            dragging = true
            dstart = i.Position
            fstart = frame.Position
            i.Changed:Connect(function()
                if i.UserInputState == Enum.UserInputState.End then dragging = false end
            end)
        end
    end)
    frame.InputChanged:Connect(function(i)
        if dragging and (i.UserInputType == Enum.UserInputType.MouseMovement) then
            local d = i.Position - dstart
            frame.Position = UDim2.new(fstart.X.Scale, fstart.X.Offset + d.X, fstart.Y.Scale, fstart.Y.Offset + d.Y)
        end
    end)
end

-- ==========================================
-- AUTO COLLECT PHANTOM ITEMS
-- ==========================================
local function collect_phantoms()
    task.spawn(function()
        while true do
            task.wait(0.5)
            if not getgenv().Config.AutoFarm then continue end

            local char = Player.Character
            if not char then continue end
            local root = char:FindFirstChild("HumanoidRootPart")
            if not root then continue end

            for _, obj in ipairs(workspace:GetDescendants()) do
                if not getgenv().Config.AutoFarm then break end
                if obj:IsA("BasePart") and obj.Parent then
                    local n = string.lower(obj.Name)
                    -- Mở rộng keyword: phantom, coin, orb, bomb, pickup
                    if string.find(n, "phantom") or string.find(n, "coin") or string.find(n, "orb") 
                       or string.find(n, "bomb") or string.find(n, "pickup") then
                        local saved = root.CFrame
                        root.CFrame = obj.CFrame
                        task.wait(0.1)
                        -- Luôn fire touch (không cần check TouchTransmitter)
                        pcall(function()
                            firetouchinterest(root, obj, 0)
                            task.wait(0.05)
                            firetouchinterest(root, obj, 1)
                        end)
                        root.CFrame = saved
                        task.wait(0.1)
                    end
                end
            end
        end
    end)
end

-- Hook OnClientEvent để collect ngay khi phantom spawn
pcall(function()
    local Networking = game:GetService("ReplicatedStorage"):FindFirstChild("Shared")
    if Networking then
        Networking = Networking:FindFirstChild("Remotes")
        if Networking then
            Networking = Networking:FindFirstChild("Networking")
        end
    end
    if Networking then
        -- PhantomCoinBomb
        local coinEvent = Networking:FindFirstChild("RE/Events/PhantomCoinBombEvent")
        if coinEvent then
            coinEvent.OnClientEvent:Connect(function(cf)
                task.wait(0.2)
                local char = Player.Character
                if char and char:FindFirstChild("HumanoidRootPart") and getgenv().Config.AutoFarm then
                    local root = char.HumanoidRootPart
                    local saved = root.CFrame
                    root.CFrame = cf
                    task.wait(0.1)
                    root.CFrame = saved
                end
            end)
            print("[AutoFarm] Hooked PhantomCoinBombEvent!")
        end
        -- PhantomOrbBomb
        local orbEvent = Networking:FindFirstChild("RE/Events/PhantomOrbBomb")
        if orbEvent then
            orbEvent.OnClientEvent:Connect(function(cf, orbName)
                task.wait(0.2)
                local char = Player.Character
                if char and char:FindFirstChild("HumanoidRootPart") and getgenv().Config.AutoFarm then
                    local root = char.HumanoidRootPart
                    local saved = root.CFrame
                    root.CFrame = cf
                    task.wait(0.1)
                    root.CFrame = saved
                end
            end)
            print("[AutoFarm] Hooked PhantomOrbBomb!")
        end
    end
end)

-- ==========================================
-- KHỞI ĐỘNG
-- ==========================================
create_ui()
start_autofarm()
collect_phantoms()
print("[AutoFarm] Loaded! FlySpeed=" .. getgenv().Config.FlySpeed)
