local ShopConfig = {}

-- Key is the item id sent by client/server.
ShopConfig.Items = {
    wooden_sword = {
        id = "wooden_sword",
        displayName = "Wooden Sword",
        price = 100,
        toolName = "Wooden Sword",
    },
    iron_sword = {
        id = "iron_sword",
        displayName = "Iron Sword",
        price = 300,
        toolName = "Iron Sword",
    },
    gryphon = {
        id = "gryphon",
        displayName = "Gryphon",
        price = 750,
        toolName = "Gryphon",
    },
}

return ShopConfig
