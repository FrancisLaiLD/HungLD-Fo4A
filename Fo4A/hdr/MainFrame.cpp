
#include "MainFrame.h"


MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY,  wxT(STR_APP_TITLE), wxPoint(400, 300), wxSize(SIZE_APP_WINDOW_WIDTH, SIZE_APP_WINDOW_HEIGHT), wxMINIMIZE_BOX|wxCLOSE_BOX|wxSYSTEM_MENU|wxCAPTION)
{
//    panel = new wxPanel(this);
    panel = new wxPanel(this, wxID_ANY, wxPoint(50, 100), wxSize(620, 300));
    // static box Auto functions
//    sizer = new wxStaticBoxSizer(wxVERTICAL, panel, "hello");
//    m_stbFuncAuto = new wxStaticBox(panel, wxID_ANY, "StaticBox", wxPoint(20, 20), wxSize(400, 250));
    
    m_sttCurrentTime = new wxStaticText(m_stbFuncAuto, wxID_ANY,  wxT(STR_APP_CURRENT_TIME), wxPoint(40, 80));
    m_currentTime = new wxStaticText(m_stbFuncAuto, wxID_ANY,  "---", wxPoint(260, 80));
    m_sttTimeAutoRun = new wxStaticText(m_stbFuncAuto, wxID_ANY, wxT(STR_APP_TIME_AUTO_RUN), wxPoint(40, 60));
    m_timeAutoRun = new wxStaticText(m_stbFuncAuto, wxID_ANY, wxT("---"), wxPoint(200, 60));
    
    // static line
    m_sttLine = new wxStaticLine(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL, "staticLine");
    
//    sizer->Add(m_stbFuncAuto);
//    sizer->Add(m_sttLine);
    //
//    panel->SetSizer(sizer);
    
    Center();
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

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_COMMAND     ((int)EVT_FO4A::EVT_CURRENT_TIME_UPDATE,        wxEVT_COMMAND_TEXT_UPDATED,     MyFrame::onCurrentTimeUpdate)
EVT_COMMAND     ((int)EVT_FO4A::EVT_TIME_AUTO_RUN_UPDATE,       wxEVT_COMMAND_TEXT_UPDATED,     MyFrame::onTimeAutoRunUpdate)
END_EVENT_TABLE()

