#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include "loader.h"
#include "xorstr.h"
//#include "../CommonFiles/ioctls.h"

char Direccion[MAX_PATH];
char bufferrespuesta[512];
HWND dialog=NULL;
HANDLE hInyeccion=NULL;

BOOL FileExist(LPCSTR filename)
{
     WIN32_FIND_DATAA finddata;
     return (FindFirstFileA(filename,&finddata)!=INVALID_HANDLE_VALUE);
}

bool WINAPI InyectarDLL()
{
     DWORD pid;
     HANDLE proc,hToken=NULL;;
     LPVOID RemoteString,nLoadLibrary;
     HWND VentanaHL;
     TOKEN_PRIVILEGES tkp;

     if(OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&hToken))
     {
          LookupPrivilegeValue(NULL,SE_DEBUG_NAME,&tkp.Privileges[0].Luid);
          tkp.PrivilegeCount=1;tkp.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;
          AdjustTokenPrivileges(hToken,0, &tkp,sizeof(tkp),NULL,NULL);
     }

     while((VentanaHL=FindWindowA("Grand theft auto San Andreas",0))==NULL)
          Sleep(100);

     GetWindowThreadProcessId(VentanaHL,&pid);

     if((proc=OpenProcess(0xF0000|0x100000L|0xFFF,0,pid))==NULL)
		  return false;

     if((nLoadLibrary=(LPVOID)GetProcAddress(GetModuleHandle(/*Kernel32.dll*/XorStr<0xD2,13,0x47902CEA>("\x99\xB6\xA6\xBB\xB3\xBB\xEB\xEB\xF4\xBF\xB0\xB1"+0x47902CEA).s),/*LoadLibraryA*/XorStr<0x88,13,0xFA9E3BD2>("\xC4\xE6\xEB\xEF\xC0\xE4\xEC\xFD\xF1\xE3\xEB\xD2"+0xFA9E3BD2).s))==NULL)
		  return false;
	 if((RemoteString=(LPVOID)VirtualAllocEx(proc,NULL,strlen(Direccion),MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE))==NULL)
		  return false;
	 if(!WriteProcessMemory(proc,(LPVOID)RemoteString,Direccion,strlen(Direccion),NULL))
		  return false;
	 if(!CreateRemoteThread(proc,NULL,0,(LPTHREAD_START_ROUTINE)nLoadLibrary,(LPVOID)RemoteString,0,NULL))
		  return false;
	 CloseHandle(proc);
	 return true;
}

void PrepararInyeccionNormal()
{
	if(!InyectarDLL())
		MessageBox(dialog,/*Error injection!*/XorStr<0x71,17,0x7ADC702B>("\x34\x00\x01\x1B\x07\x56\x1E\x16\x13\x1F\x18\x08\x14\x11\x11\xA1"+0x7ADC702B).s,/*Crianosfera Hack - BloodSharp*/XorStr<0x03,30,0x312E9A14>("\x40\x76\x6C\x67\x69\x67\x7A\x6C\x6E\x7E\x6C\x2E\x47\x71\x72\x79\x33\x39\x35\x54\x7B\x77\x76\x7E\x48\x74\x7C\x6C\x6F"+0x312E9A14).s,MB_ICONERROR);
	hInyeccion=0;
	ExitThread(0);
}

LRESULT CALLBACK VentanaProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
			dialog=hwnd;
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDM_LOAD:
				{
					if(!hInyeccion)
						hInyeccion=CreateThread(NULL,(DWORD)NULL,(LPTHREAD_START_ROUTINE)PrepararInyeccionNormal,NULL,(DWORD)NULL,NULL);
					else if(hInyeccion)
						MessageBox(hwnd,/*The cheat is waiting the game. Please launch the game now!*/XorStr<0x72,59,0x84CC5A3D>("\x26\x1B\x11\x55\x15\x1F\x1D\x18\x0E\x5B\x15\x0E\x5E\x08\xE1\xE8\xF6\xEA\xEA\xE2\xA6\xF3\xE0\xEC\xAA\xEC\xED\xE0\xEB\xA1\xB0\xC1\xFE\xF6\xF5\xE6\xF3\xB7\xF4\xF8\xEF\xF5\xFF\xF5\xBE\xEB\xC8\xC4\x82\xC4\xC5\xC8\xC3\x87\xC6\xC6\xDD\x8A"+0x84CC5A3D).s,/*Crianosfera Hack - BloodSharp*/XorStr<0x0C,30,0x5E169F5F>("\x4F\x7F\x67\x6E\x7E\x7E\x61\x75\x71\x67\x77\x37\x50\x78\x79\x70\x3C\x30\x3E\x5D\x4C\x4E\x4D\x47\x77\x4D\x47\x55\x58"+0x5E169F5F).s,MB_ICONINFORMATION|MB_TOPMOST);
				}
				break;
			}
			return TRUE;
		case WM_CLOSE:
			EndDialog(hwnd,-1);
			return TRUE;
	}
	return FALSE;
}

int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nFunsterStil)
{
	GetCurrentDirectoryA(sizeof(Direccion),Direccion);
	strcat(Direccion,/*\\libCrianosfera.dll*/XorStr<0xD0,20,0x50A1F343>("\x8C\xBD\xBB\xB1\x97\xA7\xBF\xB6\xB6\xB6\xA9\xBD\xB9\xAF\xBF\xF1\x84\x8D\x8E"+0x50A1F343).s);
	if(!FileExist(Direccion))
	{
		MessageBoxA(0,/*Crianosfera.dll not found. The Loader will not run!*/XorStr<0xC6,52,0xC08A6124>("\x85\xB5\xA1\xA8\xA4\xA4\xBF\xAB\xAB\xBD\xB1\xFF\xB6\xBF\xB8\xF5\xB8\xB8\xAC\xF9\xBC\xB4\xA9\xB3\xBA\xF1\xC0\xB5\x8A\x86\xC4\xA9\x89\x86\x8C\x8C\x98\xCB\x9B\x84\x82\x83\xD0\x9F\x9D\x87\xD4\x87\x83\x99\xD9"+0xC08A6124).s,/*Crianosfera Hack - BloodSharp*/XorStr<0xB7,30,0x2F48D29B>("\xF4\xCA\xD0\xDB\xD5\xD3\xCE\xD8\xDA\xB2\xA0\xE2\x8B\xA5\xA6\xAD\xE7\xE5\xE9\x88\xA7\xA3\xA2\xAA\x9C\xB8\xB0\xA0\xA3"+0x2F48D29B).s,MB_ICONERROR|MB_TOPMOST);
		ExitProcess(0);
	}
	DialogBox(hInstance,MAKEINTRESOURCE(IDM_LOADER),NULL,(DLGPROC)VentanaProc);
	return 0;
}
