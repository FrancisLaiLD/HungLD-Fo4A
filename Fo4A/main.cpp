#include "wx/wx.h"
//#include "wx/spinctrl.h"
//#include "wx/stattext.h"
//#include "wx/textctrl.h"
#include "wx/datetime.h"
#include "thread.h"

#include "MainFrame.h"
 
 
class MyApp: public wxApp
{
    wxFrame* m_frame;
public:
 
    bool OnInit()
    {
        m_frame = new MyFrame();
        m_frame->Show();
 
        // create the thread
        MyThread* t = new MyThread(m_frame);
        wxThreadError err = t->Create();
 
        if (err != wxTHREAD_NO_ERROR)
        {
            wxMessageBox( _("Couldn't create thread!") );
            return false;
        }
 
        err = t->Run();
 
        if (err != wxTHREAD_NO_ERROR)
        {
            wxMessageBox( _("Couldn't run thread!") );
            return false;
        }
 
        return true;
    } 
 
};
 
IMPLEMENT_APP(MyApp)