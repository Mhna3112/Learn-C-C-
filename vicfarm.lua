_G.hook = "" -- discord webhook url (optional)
_G.uid = "" -- discord user id for ping (optional)
_G.delay = "0" -- delay before server hop in seconds
_G.minlvl = "1" -- minimum vic level to attack (1-12)
_G.maxlvl = "12" -- maximum vic level to attack (1-12)
_G.onlygifted = false -- true = only attack/find gifted vics, false = any
_G.room = "" -- sync room name for searcher system (optional, any name)
_G.mainuser = "" -- main user for auto searcher system (optional)
_G.mainwait = true -- true = main waits for searchers, false = main hops if no vics in list

loadstring(game:HttpGet("https://raw.githubusercontent.com/1toop/vichop/main/hop.lua"))()