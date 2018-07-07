#ifndef __APP__DEFINE__H__
#define __APP__DEFINE__H__

// Define App Constant String
#define     STR_APP_TITLE               "Fo4A v1.0 build 0x01"
#define     STR_APP_CURRENT_TIME        "Thời gian hiện tại : "
#define     STR_APP_TIME_AUTO_RUN       "Thời gian Auto đã chạy : "
#define     STR_APP_COULD_NOT_START     "Auto không thể bắt đầu ! Vui lòng kiểm tra lại ."


// Defina App Constant Size - INT
#define     SIZE_APP_WINDOW_WIDTH       640
#define     SIZE_APP_WINDOW_HEIGHT      510

//  Define Process name
#define     STR_GARENA_PROCESS_NAME         "Garena.exe"
#define     STR_GAME_PROCESS_NAME           "fifa4zf.exe"
#define     STR_GAME_LAUNCHER_PROCESS_NAME  "fifa4launcher.exe"

//  Define Window name
#define     STR_GARENA_LOGOUT_WINDOW_NAME          "Garena - Your Ultimate Game Platform"
#define     STR_GARENA_LOGIN_WINDOW_NAME           "Garena - Game Center"
#define     STR_GAME_WINDOW_NAME                   "FIFA Online4 - Developed by SPEARHEAD"

//  Define ID EVENTS
enum class EVT_FO4A {
    EVT_CURRENT_TIME_UPDATE = 10000,
    EVT_TIME_AUTO_RUN_UPDATE
};

#endif // __APP__DEFINE__H__