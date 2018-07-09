#include "wx/wx.h"
//#include "wx/spinctrl.h"
//#include "wx/stattext.h"
//#include "wx/textctrl.h"
#include "wx/datetime.h"
//#include "thread.h"

#include "MainFrame.h"
#include "hdr/ThreadUpdateInfo.h"
 
 
class MyApp: public wxApp
{
    wxFrame* m_mainFrame;
    ThreadUpdateInfo* m_updateInfoThread;
public:
 
    bool OnInit()
    {
        m_mainFrame = new MyFrame();
        m_mainFrame->SetIcon(wxICON(aaaa));
        m_mainFrame->Show();
 
        // create the thread
        m_updateInfoThread = new ThreadUpdateInfo(m_mainFrame);
        wxThreadError err = m_updateInfoThread->Create();
 
        if (err != wxTHREAD_NO_ERROR)
        {
            wxMessageBox( _("Couldn't create thread!") );
            return false;
        }
 
        err = m_updateInfoThread->Run();
 
        if (err != wxTHREAD_NO_ERROR)
        {
            wxMessageBox( _("Couldn't run thread!") );
            return false;
        }
 
        return true;
    } 
 
};
 
IMPLEMENT_APP(MyApp)