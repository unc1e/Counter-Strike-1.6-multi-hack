#pragma once

#define M_PI         3.141592653f
#define MAX_PLAYERS  32
#define ASPECT_RATIO 0.5f

#define SOUNDOBJ_OFFSET 4
#define SOUNDOBJ_RED    0
#define SOUNDOBJ_GREEN  255
#define SOUNDOBJ_BLUE   255
#define SOUNDOBJ_ALPHA  255
#define SOUNDOBJ_WEIGHT 2.f

#define HEAD_OFFSET 25

#define BONE_OFFSET 5

#define MENU_WIDTH         100
#define MENU_LINE_HEIGHT   25
#define MENU_FONT_HEIGHT   15
#define MENU_MARGIN_TOP    10
#define MENU_MARGIN_LEFT   10
#define MENU_PADDING_LEFT  10
#define MENU_TOTAL         4
#define MENU_NAME_ESP      "ESP"
#define MENU_NAME_AIMBOT   "Aimbot"
#define MENU_NAME_REMOVALS "Removals"	
#define MENU_NAME_OTHER    "Other"

#define SUBMENU_WIDTH               150
#define SUBMENU_VALUES_MARGIN_LEFT  100

#define SUBMENU_TOTAL_ESP           14
#define SUBMENU_NAME_ESP_ESP        "esp"
#define SUBMENU_NAME_ESP_T_RED      "t red"
#define SUBMENU_NAME_ESP_T_GREEN    "t green"	
#define SUBMENU_NAME_ESP_T_BLUE     "t blue"	
#define SUBMENU_NAME_ESP_T_ALPHA    "t alpha"
#define SUBMENU_NAME_ESP_T_WEIGHT   "t weight"	
#define SUBMENU_NAME_ESP_CT_RED     "ct red"
#define SUBMENU_NAME_ESP_CT_GREEN   "ct green"	
#define SUBMENU_NAME_ESP_CT_BLUE    "ct blue"	
#define SUBMENU_NAME_ESP_CT_ALPHA   "ct alpha"
#define SUBMENU_NAME_ESP_CT_WEIGHT  "ct weight"	
#define SUBMENU_NAME_ESP_BARREL     "barrel"	
#define SUBMENU_NAME_ESP_GLOW       "glow"
#define SUBMENU_NAME_ESP_SOUND      "sound"
#define SUBMENU_VALUE_ESP_ESP       1
#define SUBMENU_VALUE_ESP_T_RED     255
#define SUBMENU_VALUE_ESP_T_GREEN   0
#define SUBMENU_VALUE_ESP_T_BLUE    0
#define SUBMENU_VALUE_ESP_T_ALPHA   255
#define SUBMENU_VALUE_ESP_T_WEIGHT  100
#define SUBMENU_VALUE_ESP_CT_RED    0
#define SUBMENU_VALUE_ESP_CT_GREEN  0
#define SUBMENU_VALUE_ESP_CT_BLUE   255
#define SUBMENU_VALUE_ESP_CT_ALPHA  255
#define SUBMENU_VALUE_ESP_CT_WEIGHT 100
#define SUBMENU_VALUE_ESP_BARREL    255
#define SUBMENU_VALUE_ESP_GLOW      0
#define SUBMENU_VALUE_ESP_SOUND     1

#define SUBMENU_TOTAL_AIMBOT            3
#define SUBMENU_NAME_AIMBOT_AIMBOT      "aimbot"  
#define SUBMENU_NAME_AIMBOT_BONE        "bone"
#define SUBMENU_NAME_AIMBOT_DEATHMATCH  "deathmatch"
#define SUBMENU_VALUE_AIMBOT_AIMBOT     1  
#define SUBMENU_VALUE_AIMBOT_BONE       8
#define SUBMENU_VALUE_AIMBOT_DEATHMATCH 0

#define SUBMENU_TOTAL_REMOVALS        3
#define SUBMENU_NAME_REMOVALS_FLASH   "flash"  
#define SUBMENU_NAME_REMOVALS_SMOKE   "smoke" 
#define SUBMENU_NAME_REMOVALS_SPREAD  "spread"  
#define SUBMENU_VALUE_REMOVALS_FLASH  1
#define SUBMENU_VALUE_REMOVALS_SMOKE  1
#define SUBMENU_VALUE_REMOVALS_SPREAD 60

#define SUBMENU_TOTAL_OTHER           2
#define SUBMENU_NAME_OTHER_BUNNYHOP   "bunny hop"  
#define SUBMENU_NAME_OTHER_SPEEDHACK  "speed hack"  
#define SUBMENU_VALUE_OTHER_BUNNYHOP  1
#define SUBMENU_VALUE_OTHER_SPEEDHACK 0  
