#include "GameHandle.h"

DWORD __stdcall RemoteThread(DataInjection *cData) //thread that will be spawned in our target process
{
    __MessageBoxA MsgBox = (__MessageBoxA)cData->paMessageBoxA; //initialize our function
    __SendMessageA funcSendMessage = (__SendMessageA)cData->paSendMessageBoxA;
    if (MsgBox != NULL)
    {
        MsgBox(NULL, cData->chMessage, cData->chTitle, MB_ICONINFORMATION); //call it
    }
    if (funcSendMessage != NULL)
    {
        funcSendMessage(NULL, WM_LBUTTONDOWN, MK_LBUTTON , MAKELPARAM(575, 475));
        Sleep(50);
        funcSendMessage(NULL, WM_LBUTTONUP, 0, MAKELPARAM(575, 475) );
    }
    
    return EXIT_SUCCESS;
}

GameHandle::GameHandle()
{
    
}

GameHandle::~GameHandle()
{
    
}

DWORD GameHandle::getProcessID(char* procname)
{
    PROCESSENTRY32 pe;
    HANDLE hSnap;
    
    pe.dwSize = sizeof(PROCESSENTRY32);
    hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (Process32First(hSnap, &pe)) {
        do {
            if (strcmp(pe.szExeFile, procname) == 0)
                break;
        } while (Process32Next(hSnap, &pe));
    }
    return pe.th32ProcessID;
}

HWND GameHandle::getWindowHandle()
{
    return FindWindow(NULL, STR_GAME_WINDOW_NAME);
}

void GameHandle::mouseClickLeft(HWND mHWND, POINT btn) 
{
    PostMessage( mHWND, WM_LBUTTONDOWN, MK_LBUTTON , MAKELPARAM( btn.x, btn.y ) );
    Sleep(50);
    PostMessage( mHWND, WM_LBUTTONUP, 0, MAKELPARAM( btn.x, btn.y ) );
}

void GameHandle::mouseMove(HWND mHWND, POINT btn)
{
    PostMessage(mHWND, WM_MOUSEMOVE, 0, MAKELPARAM(btn.x,btn.y));
}

bool GameHandle::injectCodeToProcess()
{
    DataInjection m_DataInjection; //declare cave data object
    ZeroMemory(&m_DataInjection, sizeof(DataInjection)); // fill it with zeros
    strcpy(m_DataInjection.chMessage, "Hi, I was called from remote process!"); //set the variables inside it
    strcpy(m_DataInjection.chTitle, "Hello from code cave!");

    HINSTANCE hUserModule = LoadLibrary("user32.dll"); //load the user32.dll
    m_DataInjection.paMessageBoxA = (DWORD)GetProcAddress(hUserModule, "MessageBoxA"); //find MessageBox procedure from it
    m_DataInjection.paSendMessageBoxA = (DWORD)GetProcAddress(hUserModule, "PosMessageA"); // find SendMessage procedure
    // and pass it to paMessageBox.
    
    FreeLibrary(hUserModule);
    
    DWORD c_ProcessID = getProcessID(STR_GARENA_PROCESS_NAME);
    if (c_ProcessID == 0)
    {
        return false;
    }
    //open our target process for writing
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE,  c_ProcessID);
    // check Process running
    if (hProcess == NULL)
    {
        return false;
    }
    else
    {
        //allocate memory for our procedure in the remote process' address space
        LPVOID pRemoteThread = VirtualAllocEx(hProcess, NULL, sizeof(DataInjection), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        //write our thread to the target process
        WriteProcessMemory(hProcess, pRemoteThread, (LPVOID)RemoteThread, sizeof(DataInjection), 0);
        //allocate memory for our DataInjection object in the remote process
        DataInjection *pData = (DataInjection*)VirtualAllocEx(hProcess, NULL, sizeof(DataInjection), MEM_COMMIT, PAGE_READWRITE);
        //Write it to the target process
        WriteProcessMemory(hProcess, pData, &m_DataInjection, sizeof(DataInjection), NULL);
        //spawn/create our procedure/thread in the remote process
        HANDLE hThread = CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)pRemoteThread, pData, 0, 0);
        //close thread handle
        CloseHandle(hThread);
        //free the now un-used memory from the remote process' heap
        VirtualFreeEx(hProcess, pRemoteThread, sizeof(DataInjection), MEM_RELEASE);
        //close process' handle
        CloseHandle(hProcess);
    }
    return true;
}