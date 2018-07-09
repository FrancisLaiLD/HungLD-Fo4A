
#include "MainFrame.h"



MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY,  wxT(STR_APP_TITLE), wxPoint(400, 300), wxSize(SIZE_APP_WINDOW_WIDTH, SIZE_APP_WINDOW_HEIGHT), wxMINIMIZE_BOX|wxCLOSE_BOX|wxSYSTEM_MENU|wxCAPTION),
                                     m_currentMode(0),
                                     m_gameHandle(new GameHandle())
{
//    panel = new wxPanel(this);
    panel = new wxPanel(this, wxID_ANY, wxPoint(5, 5), wxSize(620, 500));
    
    m_noteBookMain = new wxNotebook(panel, wxID_ANY, wxPoint(0, 0), wxSize(630, 490) );
    m_noteBookMain->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    m_noteBookMain->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));

    m_pageAppGui = new wxPanel(m_noteBookMain, wxID_ANY, wxPoint(0, 0), wxSize(620, 500));
    m_pageAppSetup = new wxPanel(m_noteBookMain, wxID_ANY, wxPoint(0, 0), wxSize(620, 500));
    
    m_noteBookMain->AddPage(m_pageAppGui, wxT(STR_APP_PAGE_APP_GUI));
    m_noteBookMain->AddPage(m_pageAppSetup, wxT(STR_APP_PAGE_APP_SETUP));
    
    /*=====================================================================================*/
    /* ---------------------BOX MAIN AUTO FUNCTION---------------------------------*/
    /*=====================================================================================*/
    m_boxMainAutoFunc = new wxStaticBox(m_pageAppGui, wxID_ANY, wxT(STR_APP_STT_BOX_MAIN_AUTO), wxPoint(10, 10), wxSize(300, 250));
    // Radio button for choose Mode Auto 
    m_radStopAuto               = new wxRadioButton(m_boxMainAutoFunc, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_STOP_AUTO),       wxT(STR_APP_RAD_BTN_STOP_AUTO), wxPoint(15, 30));
    m_radPlayWithBot            = new wxRadioButton(m_boxMainAutoFunc, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_PLAY_BOT),        wxT(STR_APP_RAD_BTN_PLAY_BOT), wxPoint(15, 60));
    m_radPlayWithOther          = new wxRadioButton(m_boxMainAutoFunc, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_PLAY_OTHER),      wxT(STR_APP_RAD_BTN_PLAY_OTHER), wxPoint(15, 90));
    m_radPlayWithOther          = new wxRadioButton(m_boxMainAutoFunc, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_UPDATING_1),      wxT(STR_APP_RAD_BTN_UPDATING), wxPoint(15, 120));
    m_radPlayWithOther          = new wxRadioButton(m_boxMainAutoFunc, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_UPDATING_2),      wxT(STR_APP_RAD_BTN_UPDATING), wxPoint(15, 150));
    m_radStopAuto->SetValue(true);
    
    /*=====================================================================================*/
    /* ---------------------BOX FAST SETUP-----------------------------------------*/
    /*=====================================================================================*/
    m_boxFastSetup = new wxStaticBox(m_pageAppGui, wxID_ANY, wxT(STR_APP_STT_BOX_FAST_SETUP), wxPoint(320, 10), wxSize(300, 250));
    //
    m_sttTextCurMode = new wxStaticText(m_boxFastSetup, wxID_ANY, (wxString::FromDouble(m_currentMode)), wxPoint(15, 30));
//    m_comboBox       = new wxComboBox(m_boxFastSetup, wxID_ANY, wxT(""), wxPoint(60, 60)); 
//    m_comboBox->SetString(0, wxT("1920x1080"));

    /*=====================================================================================*/
    /* -----------------------BOX AUTO RESULT--------------------------------------*/
    /*=====================================================================================*/
    m_boxAutoResult = new wxStaticBox(m_pageAppGui, wxID_ANY, wxT(STR_APP_STT_BOX_AUTO_RESULT), wxPoint(10, 260), wxSize(610, 190));
    
    /*=====================================================================================*/
    /* -----------------------BOX AUTO SETUP--------------------------------------*/
    /*=====================================================================================*/
    m_boxAutoSetup = new wxStaticBox(m_pageAppSetup, wxID_ANY, wxT(STR_APP_STT_BOX_AUTO_SETUP), wxPoint(10, 10), wxSize(610, 250));
    
    m_sttTextGameStatus             = new wxStaticText(m_boxAutoSetup, wxID_ANY, wxT(STR_GAME_STATUS), wxPoint(200, 220));
    m_sttTextGameStatus             = new wxStaticText(m_boxAutoSetup, wxID_ANY, wxT("---"), wxPoint(330, 220));
    m_btnOutGame                    = new wxButton(m_boxAutoSetup, wxID_ANY, wxT(STR_GAME_FAST_OUT_GAME), wxPoint(420, 215));
    
    /*=====================================================================================*/
    /* -----------------------BOX AUTO SETUP--------------------------------------*/
    /*=====================================================================================*/
    m_boxAutoInfo = new wxStaticBox(m_pageAppSetup, wxID_ANY, wxT(STR_APP_STT_BOX_AUTO_INFO), wxPoint(10, 260), wxSize(610, 190));
    m_sttTextCurrentTime            = new wxStaticText(m_boxAutoInfo, wxID_ANY, wxT(STR_APP_CURRENT_TIME), wxPoint(15,60 ));
    m_textCurrentTime               = new wxStaticText(m_boxAutoInfo, wxID_ANY, wxT("---"), wxPoint(130, 60));
    m_sttTextTimeAutoRun            = new wxStaticText(m_boxAutoInfo, wxID_ANY, wxT(STR_APP_TIME_AUTO_RUN), wxPoint(200, 60));
    m_textTimeAutoRun               = new wxStaticText(m_boxAutoInfo, wxID_ANY, wxT("---"), wxPoint(340, 60));
    // Set color of Panel
    panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    panel->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    Center();
    
    // Bindding EVENTS and HANDLES
    setInternalBinding();
}

MyFrame::~MyFrame()
{
    
}

// this is called when the event from the thread is received
void MyFrame::onCurrentTimeUpdate(wxCommandEvent& evt)
{
    // set the value of text
    m_textCurrentTime->SetLabel(evt.GetString() );
}

void MyFrame::onTimeAutoRunUpdate(wxCommandEvent& evt)
{
    // set the value of text
    m_textTimeAutoRun->SetLabel(evt.GetString() );
}

void MyFrame::onRadBtnStopAutoClick(wxCommandEvent& evt)
{
    // 
    this->m_sttTextCurMode->SetLabel(wxT("Mode 1 Stop auto"));
}

void MyFrame::onRadBtnPlayWithBotClick(wxCommandEvent& evt)
{
    //
    this->m_sttTextCurMode->SetLabel(wxT("Mode 2 Play with Bot"));
    /*if ( (m_gameHandle->getWindowHandle() == NULL))
    {
          wxMessageBox(wxT(STR_APP_START_GAME_FIRST), wxT(STR_APP_DLG_WARNING), wxOK, this);
        this->m_radStopAuto->SetValue(true);
        this->m_sttTextCurMode->SetLabelText(wxT("Mode 1 Stop auto"));
    }
    else*/
    {
        bool result = m_gameHandle->injectCodeToProcess();
    }
}void MyFrame::onRadBtnPlayWithOtherClick(wxCommandEvent& evt)
{
    //
    this->m_sttTextCurMode->SetLabel(wxT("Mode 3 Play with Other"));
    if ( (m_gameHandle->getWindowHandle() == NULL))
    {
        wxMessageBox(wxT(STR_APP_START_GAME_FIRST), wxT(STR_APP_DLG_WARNING), wxOK, this);
        this->m_radStopAuto->SetValue(true);
        this->m_sttTextCurMode->SetLabelText(wxT("Mode 1 Stop auto"));
    }
}

void MyFrame::onRadBtnUpdating1Click(wxCommandEvent& evt)
{
    //
    this->m_sttTextCurMode->SetLabel(wxT("Mode 4 Updating 1 ...."));
    if ( (m_gameHandle->getWindowHandle() == NULL))
    {
        wxMessageBox(wxT(STR_APP_START_GAME_FIRST), wxT(STR_APP_DLG_WARNING), wxOK, this);
        Centre();
        this->m_radStopAuto->SetValue(true);
        this->m_sttTextCurMode->SetLabelText(wxT("Mode 1 Stop auto"));
    }
}

void MyFrame::onRadBtnUpdating2Click(wxCommandEvent& evt)
{
    //
    this->m_sttTextCurMode->SetLabel(wxT("Mode 5 Updating 2 ..."));
    if ( (m_gameHandle->getWindowHandle() == NULL))
    {
        wxMessageBox(wxT(STR_APP_START_GAME_FIRST), wxT(STR_APP_DLG_WARNING), wxOK, this);
        this->m_radStopAuto->SetValue(true);
        this->m_sttTextCurMode->SetLabelText(wxT("Mode 1 Stop auto"));
    }
}

void MyFrame::OnCloseWindow(wxCommandEvent& evt)
{
    wxMessageBox(wxT("Bạn có chắc chắn muốn thoát Auto ?"), wxT("Confirmation"), 0, this, 100, 200);
}

void MyFrame::setInternalBinding()
{
    Bind(wxEVT_COMMAND_RADIOBUTTON_SELECTED, &MyFrame::onRadBtnStopAutoClick,               this, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_STOP_AUTO));
    Bind(wxEVT_COMMAND_RADIOBUTTON_SELECTED, &MyFrame::onRadBtnPlayWithBotClick,            this, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_PLAY_BOT));
    Bind(wxEVT_COMMAND_RADIOBUTTON_SELECTED, &MyFrame::onRadBtnPlayWithOtherClick,          this, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_PLAY_OTHER));
    Bind(wxEVT_COMMAND_RADIOBUTTON_SELECTED, &MyFrame::onRadBtnUpdating1Click,              this, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_UPDATING_1));
    Bind(wxEVT_COMMAND_RADIOBUTTON_SELECTED, &MyFrame::onRadBtnUpdating2Click,              this, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_UPDATING_2));
}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_COMMAND     ((int)EVT_FO4A::EVT_CURRENT_TIME_UPDATE,        wxEVT_COMMAND_TEXT_UPDATED,     MyFrame::onCurrentTimeUpdate)
EVT_COMMAND     ((int)EVT_FO4A::EVT_TIME_AUTO_RUN_UPDATE,       wxEVT_COMMAND_TEXT_UPDATED,     MyFrame::onTimeAutoRunUpdate)

END_EVENT_TABLE()

