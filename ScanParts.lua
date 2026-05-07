-- Script quét tất cả AREA / ZONE trong game
-- Execute trong game, mở Developer Console (F9) để xem kết quả

print("========================================")
print("  QUÉT TẤT CẢ AREAS TRONG GAME")
print("========================================")

-- Tìm theo tên chứa "area", "zone", "region", "world", "island"
local area_keywords = {"area", "zone", "region", "world", "island", "biome", "land"}
local found = {}

for _, obj in ipairs(workspace:GetDescendants()) do
    local name = obj.Name
    local lower = string.lower(name)
    
    for _, kw in ipairs(area_keywords) do
        if string.find(lower, kw) and not found[name] then
            found[name] = true
            local pos = "N/A"
            if obj:IsA("BasePart") then
                pos = string.format("X=%.0f, Y=%.0f, Z=%.0f", obj.Position.X, obj.Position.Y, obj.Position.Z)
            elseif obj:IsA("Model") and obj.PrimaryPart then
                local p = obj.PrimaryPart.Position
                pos = string.format("X=%.0f, Y=%.0f, Z=%.0f", p.X, p.Y, p.Z)
            end
            
            print(string.format(
                "📍 %-35s | Loại: %-10s | Vị trí: %s | Parent: %s",
                name,
                obj.ClassName,
                pos,
                tostring(obj.Parent and obj.Parent.Name or "?")
            ))
            break
        end
    end
end

-- Tìm thêm theo Folder/Model cấp cao (thường Area nằm ở đây)
print("")
print("========================================")
print("  CÁC FOLDER/MODEL CẤP CAO (WORKSPACE)")
print("========================================")
for _, child in ipairs(workspace:GetChildren()) do
    local class = child.ClassName
    local count = 0
    if child:IsA("Folder") or child:IsA("Model") then
        count = #child:GetChildren()
    end
    print(string.format("📁 %-35s | Loại: %-10s | Số con: %d", child.Name, class, count))
end

-- Tìm cả TextLabel/BillboardGui có chữ "Area"
print("")
print("========================================")
print("  TEXT/GUI HIỂN THỊ TRÊN MÀN HÌNH")
print("========================================")
local gui_found = {}
for _, obj in ipairs(game:GetService("Players").LocalPlayer.PlayerGui:GetDescendants()) do
    if (obj:IsA("TextLabel") or obj:IsA("TextButton")) and obj.Text and obj.Text ~= "" then
        local txt = obj.Text
        if not gui_found[txt] and (string.find(string.lower(txt), "area") or string.find(string.lower(txt), "zone")) then
            gui_found[txt] = true
            print("🏷️  GUI Text: " .. txt .. " | Name: " .. obj.Name .. " | Parent: " .. tostring(obj.Parent.Name))
        end
    end
end

print("")
print(">> Copy tên Area bạn muốn bay đến rồi báo lại cho mình!")
