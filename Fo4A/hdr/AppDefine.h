#ifndef __APP__DEFINE__H__
#define __APP__DEFINE__H__

// Define App Constant String
#define     STR_APP_TITLE                   "Fo4A v1.0 build 0x01"
#define     STR_APP_COULD_NOT_START         "Auto không thể bắt đầu ! Vui lòng kiểm tra lại ."
#define     STR_APP_START_GAME_FIRST        "Vui lòng khởi động game trước . Arboting..."
#define     STR_APP_DLG_WARNING             "Warning"

#define     STR_APP_PAGE_APP_GUI            "Giao diện chương trình"

#define     STR_APP_STT_BOX_MAIN_AUTO       "Chức năng Auto" // 
#define     STR_APP_RAD_BTN_STOP_AUTO       "Tạm dừng Auto"
#define     STR_APP_RAD_BTN_PLAY_BOT        "Đá giả lập với máy"
#define     STR_APP_RAD_BTN_PLAY_OTHER      "Đá giả lập ngẫu nhiên"
#define     STR_APP_RAD_BTN_UPDATING        "Updating..."

#define     STR_APP_STT_BOX_FAST_SETUP      "Cài đặt nhanh" //

#define     STR_APP_STT_BOX_AUTO_RESULT     "Kết quả Auto" //

#define     STR_APP_PAGE_APP_SETUP          "Cài đặt Auto" //

#define     STR_APP_STT_BOX_AUTO_SETUP      "Auto Game setup" //
#define     STR_GAME_STATUS                 "Trạng thái đăng nhập :"
#define     STR_GAME_FAST_OUT_GAME          "Thoát game nhanh"

#define     STR_APP_STT_BOX_AUTO_INFO       "Thông tin Auto"

#define     STR_APP_CURRENT_TIME            "Thời gian hiện tại :"
#define     STR_APP_TIME_AUTO_RUN           "Thời gian Auto đã chạy :"
















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

// Define ID Windows
enum class WINID_FO4A {
    WINID_RAD_BTN_STOP_AUTO = 101,
    WINID_RAD_BTN_PLAY_BOT,
    WINID_RAD_BTN_PLAY_OTHER,
    WINID_RAD_BTN_UPDATING_1,
    WINID_RAD_BTN_UPDATING_2
};

#endif // __APP__DEFINE__H__
