#ifndef __THREAD__H__
#define __THREAD__H__

#include "wx/wx.h"
#include "wx/datetime.h"

#include "AppDefine.h"
#include "GameHandle.h"
 
// the ID we'll use to identify our event
 
// a thread class that will periodically send events to the GUI thread
class MyThread : public wxThread
{
private:
    int n;
    wxDateTime m_currentDT;
    wxFrame* m_parent;
    GameHandle* m_gameHandle;    

public:
    MyThread(wxFrame* parent);
    virtual ExitCode Entry();    
};

#endif // __THREAD__H__
