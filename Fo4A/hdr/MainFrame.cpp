
#include "MainFrame.h"



MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY,  wxT(STR_APP_TITLE), wxPoint(400, 300), wxSize(SIZE_APP_WINDOW_WIDTH, SIZE_APP_WINDOW_HEIGHT), wxMINIMIZE_BOX|wxCLOSE_BOX|wxSYSTEM_MENU|wxCAPTION),
                            m_currentMode(0)
{
//    panel = new wxPanel(this);
    panel = new wxPanel(this, wxID_ANY, wxPoint(50, 100), wxSize(620, 300));
    
    m_boxMainAutoFunc = new wxStaticBox(panel, wxID_ANY, wxT(STR_APP_STT_BOX_MAIN_AUTO), wxPoint(10, 30), wxSize(300, 250));
    
    // Radio button for choose Mode Auto 
    m_radStopAuto                  = new wxRadioButton(m_boxMainAutoFunc, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_STOP_AUTO), wxT(STR_APP_RAD_BTN_STOP_AUTO), wxPoint(15, 30));
    m_radPlayWithBot              = new wxRadioButton(m_boxMainAutoFunc, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_PLAY_BOT), wxT(STR_APP_RAD_BTN_PLAY_BOT), wxPoint(15, 60));
    m_radPlayWithOther          = new wxRadioButton(m_boxMainAutoFunc, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_PLAY_OTHER), wxT(STR_APP_RAD_BTN_PLAY_OTHER), wxPoint(15, 90));
    m_radPlayWithOther          = new wxRadioButton(m_boxMainAutoFunc, wxID_ANY, wxT(STR_APP_RAD_BTN_UPDATING), wxPoint(15, 120));
    m_radPlayWithOther          = new wxRadioButton(m_boxMainAutoFunc, wxID_ANY, wxT(STR_APP_RAD_BTN_UPDATING), wxPoint(15, 150));
    
    // Box Fast Auto Setup
    m_boxFastSetup = new wxStaticBox(panel, wxID_ANY, wxT(STR_APP_STT_BOX_FAST_SETUP), wxPoint(320, 30), wxSize(300, 250));
    
    m_sttTextCurMode = new wxStaticText(m_boxFastSetup, wxID_ANY, (wxString::FromDouble(m_currentMode)), wxPoint(15, 30));
    
    // Static box Auto result
    m_boxAutoResult = new wxStaticBox(panel, wxID_ANY, wxT(STR_APP_STT_BOX_AUTO_RESULT), wxPoint(10, 280), wxSize(610, 190));
    
    m_sttCurrentTime           = new wxStaticText(m_boxAutoResult, wxID_ANY, wxT(STR_APP_CURRENT_TIME), wxPoint(15,30 ));
    m_currentTime               = new wxStaticText(m_boxAutoResult, wxID_ANY, wxT("---"), wxPoint(200, 30));
    m_sttTimeAutoRun         = new wxStaticText(m_boxAutoResult, wxID_ANY, wxT(STR_APP_TIME_AUTO_RUN), wxPoint(15, 60));
    m_timeAutoRun             = new wxStaticText(m_boxAutoResult, wxID_ANY, wxT("---"), wxPoint(200, 60));
    
    // Set color of Panal
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
    m_currentTime->SetLabel(evt.GetString() );
}

void MyFrame::onTimeAutoRunUpdate(wxCommandEvent& evt)
{
    // set the value of text
    m_timeAutoRun->SetLabel(evt.GetString() );
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
}

void MyFrame::onRadBtnPlayWithOtherClick(wxCommandEvent& evt)
{
    //
    this->m_sttTextCurMode->SetLabel(wxT("Mode 3 Play with Other"));
}

void MyFrame::setInternalBinding()
{
    Bind(wxEVT_COMMAND_RADIOBUTTON_SELECTED, &MyFrame::onRadBtnStopAutoClick, this, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_STOP_AUTO));
    Bind(wxEVT_COMMAND_RADIOBUTTON_SELECTED, &MyFrame::onRadBtnPlayWithBotClick, this, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_PLAY_BOT));
    Bind(wxEVT_COMMAND_RADIOBUTTON_SELECTED, &MyFrame::onRadBtnPlayWithOtherClick, this, static_cast<int>(WINID_FO4A::WINID_RAD_BTN_PLAY_OTHER));
}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_COMMAND     ((int)EVT_FO4A::EVT_CURRENT_TIME_UPDATE,        wxEVT_COMMAND_TEXT_UPDATED,     MyFrame::onCurrentTimeUpdate)
EVT_COMMAND     ((int)EVT_FO4A::EVT_TIME_AUTO_RUN_UPDATE,       wxEVT_COMMAND_TEXT_UPDATED,     MyFrame::onTimeAutoRunUpdate)

END_EVENT_TABLE()

