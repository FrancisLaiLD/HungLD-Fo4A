#include <wx/wx.h>

// application class

#include "MainFrame.h"


class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};
bool MyApp::OnInit()
{

    MainFrameBase *custom = new MainFrameBase(wxT("CustomDialog"));
    custom->Show(true);

    return true;
}

IMPLEMENT_APP(MyApp)