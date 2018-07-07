#ifndef __MAIN__FRAME__H__
#define __MAIN__FRAME__H__

//#include "wx/wx.h"

#include "wx/spinctrl.h"
#include "wx/stattext.h"
#include "wx/textctrl.h"
#include "wx/button.h"
#include "wx/datetime.h"
#include "wx/frame.h"
#include "wx/panel.h"
#include "wx/sizer.h"
#include "wx/statbox.h"
#include "wx/statline.h"

#include "AppDefine.h"
 
class MyFrame : public wxFrame
{
private:
    wxPanel* panel;
    wxStaticBoxSizer* sizer;
    wxStaticBox* m_stbFuncAuto;
    // static text
    wxStaticText* m_sttCurrentTime;
    wxStaticText* m_currentTime;
    wxStaticText* m_sttTimeAutoRun;
    wxStaticText* m_timeAutoRun;
    wxButton* m_btnTest;
    
    // static line
    wxStaticLine *m_sttLine;
    
public:
    // Default Constructor and Destructor
    MyFrame();
    ~MyFrame();
    
    // public methods to update data GUI
    void onCurrentTimeUpdate(wxCommandEvent& evt);
    void onTimeAutoRunUpdate(wxCommandEvent& evt);
    
    // catch the event from the thread
    DECLARE_EVENT_TABLE()
};

#endif // __MAIN__FRAME__H__
