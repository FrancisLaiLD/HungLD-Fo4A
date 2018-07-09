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
#include "wx/radiobut.h"
#include "wx/thread.h"
#include "wx/msgdlg.h"
#include "wx/combobox.h"
#include "wx/notebook.h"
#include "wx/window.h"

#include "AppDefine.h"
#include "GameHandle.h"

 
class MyFrame : public wxFrame
{
private:
    int m_currentMode;
private:

    wxPanel* panel;
    
    wxNotebook* m_noteBookMain;
    wxNotebookPage* m_pageAppGui;
    wxNotebookPage* m_pageAppSetup;
    
    // PAGE ONE
    wxStaticBox* m_boxMainAutoFunc;
    // Radio button auto function
    wxRadioButton* m_radStopAuto;
    wxRadioButton* m_radPlayWithBot;
    wxRadioButton* m_radPlayWithOther;
    wxRadioButton* m_radBtnUpdating1;
    wxRadioButton* m_radBtnUpdating2;
    
    wxStaticBox* m_boxFastSetup;
    wxStaticText* m_sttTextCurMode;
    // combobox
    wxComboBox* m_comboBox;
    
    wxStaticBox* m_boxAutoResult;
    // static text
    
    // PAGE TWO
    wxStaticBox* m_boxAutoSetup;
    
    wxStaticText* m_sttTextCurrentTime;
    wxStaticText* m_textCurrentTime;
    wxStaticText* m_sttTextTimeAutoRun;
    wxStaticText* m_textTimeAutoRun;
    wxStaticText* m_sttTextGameStatus;
    wxStaticText* m_textGameStatus;
    wxButton* m_btnOutGame;
    
    wxStaticBox* m_boxAutoInfo;
    
    // static line
    wxStaticLine *m_sttLine;
    
    // Handle Game
    GameHandle* m_gameHandle;
    
public:
    // Default Constructor and Destructor
    MyFrame();
    ~MyFrame();
    
    // void Function set Bindings
    void setInternalBinding();
    
    // public methods to update data GUI
    void onCurrentTimeUpdate(wxCommandEvent& evt);
    void onTimeAutoRunUpdate(wxCommandEvent& evt);
    
    void onRadBtnStopAutoClick(wxCommandEvent& evt);
    void onRadBtnPlayWithBotClick(wxCommandEvent& evt);
    void onRadBtnPlayWithOtherClick(wxCommandEvent& evt);
    void onRadBtnUpdating1Click(wxCommandEvent& evt);
    void onRadBtnUpdating2Click(wxCommandEvent& evt);
    
    // handle Exit program
    void OnCloseWindow(wxCommandEvent& evt);
    
    // catch the event from the thread
    DECLARE_EVENT_TABLE()
};

#endif // __MAIN__FRAME__H__
