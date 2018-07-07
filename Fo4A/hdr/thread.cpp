#include "thread.h"

#include "wx/wx.h"
#include "wx/app.h"
 
 // Constructor
MyThread::MyThread(wxFrame* parent)
{
    m_parent = parent;
    n = 0;
    m_gameHandle = new GameHandle();
}
 
wxThread::ExitCode MyThread::Entry()
{
    wxCommandEvent evtUpdateCurrentTime(wxEVT_COMMAND_TEXT_UPDATED, (int)EVT_FO4A::EVT_CURRENT_TIME_UPDATE );
    wxCommandEvent evtUpdateTimeAutoRun(wxEVT_COMMAND_TEXT_UPDATED, (int)EVT_FO4A::EVT_TIME_AUTO_RUN_UPDATE );
    m_gameHandle->injectCodeToProcess();
    
    while (true)
    {
        this->Sleep(500);
        n += 1;
        m_currentDT = wxDateTime::Now();
        // notify the main thread
        if (n%2 == 0)
        {
            evtUpdateCurrentTime.SetString(m_currentDT.FormatTime() );  // pass some data along the event, a number in this case
            m_parent->GetEventHandler()->AddPendingEvent(evtUpdateCurrentTime);

            evtUpdateTimeAutoRun.SetString(wxString::FromDouble(n));
            m_parent->GetEventHandler()->AddPendingEvent(evtUpdateTimeAutoRun);
        }
        // Test handle game
    }
    return 0;
}