# 🗡️ Sailor Piece — Premium Boss Auto-Farm (UI/UX Version)

> **File:** `salior.lua`  
> **UI Library:** [Orion Library](https://github.com/shlexware/Orion)  
> **Executor:** Synapse X / KRNL / Fluxus (Any that support `readfile`/`writefile`)

---

## 🎨 New UI/UX Interface

The script now features a sleek dashboard for real-time control:

| Tab | Feature | Description |
|---|---|---|
| **Main** | `Auto-Farm Boss` | Toggle the entire farming loop on/off |
| **Main** | `Status Label` | Real-time feedback (e.g., "Farming: Kraken", "Waiting for Spawn") |
| **Main** | `Force Server Hop` | Manually trigger a hop using the advanced hopper |
| **Settings** | `Attack Range` | Slider to adjust how close you stand to the boss |
| **Settings** | `Hop Threshold`| Slider to set when to hop vs. wait (in seconds) |
| **Settings** | `Debug Mode` | Toggle verbose console printing |

---

## 🚀 Advanced Hopper

The integrated hopper is based on proven community logic:
- **Persistence:** Keeps track of visited servers in `NotSameServers.json`.
- **Session-Aware:** Automatically clears visited history every UTC hour.
- **Deep Search:** Uses `nextPageCursor` to search through hundreds of servers for a free slot.

---

## 🛠️ Configuration

While most settings are in the UI, you should update the initial `BossNames` list in the script code:

```lua
getgenv().Config = {
    BossNames = {"Boss", "SeaBoss", "OceanKing", "Kraken", "Leviathan", "NavyAdmiral"},
    -- other defaults...
}
```

---

## 📖 Quick Start

1. Copy the code from `salior.lua`.
2. Paste it into your Roblox executor.
3. Click **Execute**.
4. The window will appear. Toggle **Auto-Farm Boss** to begin.

> [!TIP]
> Use the **Destroy UI** button in the Main tab to safely close the script and clean up memory if you want to stop completely.

> [!NOTE]
> VS Code may show warnings for `game`, `workspace`, `task`, `readfile`, etc. These are **Roblox-specific globals** and are fully functional in your executor environment.