#include <wx/wx.h>

// application class

#include "CustomDiaglog.h"


class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};
bool MyApp::OnInit()
{

    CustomDialog *custom = new CustomDialog(wxT("CustomDialog"));
    custom->Show(true);

    return true;
}

IMPLEMENT_APP(MyApp)