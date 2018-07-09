#ifndef __GAME__HANDLE__H__
#define __GAME__HANDLE__H__

#define _CRT_SECURE_NO_WARNINGS //let's us use "unsafe" functions in the crt

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#include "AppDefine.h"

//class getProcessID;
typedef int(__stdcall *__MessageBoxA)(HWND, LPCSTR, LPCSTR, UINT);
typedef int(__stdcall *__SendMessageA)(HWND, UINT, WPARAM, LPARAM);

class DataInjection // store all of our remote data to one object
{
public:
    char chMessage[256]; //here we store it's message!
    char chTitle[256]; //here we will store our messagebox's title
    HWND m_currentHWND;
    DWORD paMessageBoxA; //pa = Procedure address : MessageBoxA in memory
    DWORD paSendMessageBoxA; // store address of SendMessageFunction in memory

};

class GameHandle
{
public:
    GameHandle();
    ~GameHandle();
    DWORD getProcessID(char* procname);
    bool injectCodeToProcess();
    HWND getWindowHandle();
    void mouseClickLeft(HWND mHWND, POINT btn);
    void mouseMove(HWND mHWND, POINT btn);

};

#endif // __GAME__HANDLE__H__
