#include "MultithreadDlg.h"
#include <string>
#include <iostream>
#include <chrono>
#include <fstream> 

CMultithreadDlg* CMultithreadDlg::ptr = NULL;
CMultithreadDlg::CMultithreadDlg(void)
{
	ptr = this;
}

CMultithreadDlg::~CMultithreadDlg(void)
{

}

void CMultithreadDlg::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}
HWND hList;
int cnt = 0;
std::chrono::milliseconds times;
CRITICAL_SECTION CriticalSelection;
std::ofstream ofs0("1.csv", std::ofstream::out);
std::ofstream ofs1("2.csv", std::ofstream::out);
std::ofstream ofs("result.csv", std::ofstream::out);
int i0, i1,check1,check2;
int numm0[50000];
int numm1[50000];
std::chrono::milliseconds FindTime()
{
	using namespace std::chrono;
	system_clock::time_point before = system_clock::now();

	for (int c = 3; c < 1000000; c += 2)
	{
		bool f = true;
		for (int d = 3; d * d <= c; d += 2)
		{
			if (c % d == 0)
			{
				f = false;
				break;
			}
		}
		if (f)
			f = true;
	}

	system_clock::time_point after = system_clock::now();

	return(duration_cast<milliseconds> (after - before));
}



DWORD WINAPI Thread1(LPVOID lp)
{
	////TCHAR *messages[3] = { TEXT("1"), TEXT("2"), TEXT("3") };
	//TCHAR *descriment[2] = { TEXT("завершил ++"), TEXT("завершил --") };

	int num = (int)lp;
	//for(int i = 0; i < 10; i++)
	//{
	//	if (num == 0)
	//	{
	//		EnterCriticalSection(&CriticalSelection);
	//		cnt++;
	//		//LeaveCriticalSection(&CriticalSelection);
	//	}
	//	else if (num == 1)
	//	{
	//		EnterCriticalSection(&CriticalSelection);
	//		cnt--;
	//		LeaveCriticalSection(&CriticalSelection);
	//	}
	//}
	////SendMessage(hList, LB_ADDSTRING, 0, LPARAM(descriment[num]));
	////SendMessage(hList, LB_ADDSTRING, 0, LPARAM(std::to_wstring(cnt).c_str()));

	using namespace std::chrono;
	system_clock::time_point before = system_clock::now();
	
	if (num == 0)
	{
		for (int c = 3; c < 1000000; c += 4)
		{
			bool f = true;
			for (int d = 3; d * d <= c; d += 2)
			{
				if (c % d == 0)
				{
					f = false;
					break;
				}
			}
			if (f)
			++i0;
			numm0[i0] = c;

		}
	}
	else if (num == 1)
	{
		for (int c = 5; c < 1000000; c += 4)
		{
			bool f = true;
			for (int d = 3; d * d <= c; d += 2)
			{
				if (c % d == 0)
				{
					f = false;
					break;
				}
			}
			if (f)
				++i1;
			numm1[i1] = c;
		}
	}
	else if (num == 2)
	{
		if (i1 > 5 || i0 > 5)
		{
			for (int i = 1; i1 > i; ++i)
			{
				if (numm0[i] < numm1[i])
				{
					ofs << numm0[i] << "\n";
					if (numm0[i] < numm1[i-1])
					{
						ofs << numm1[i-1] << "\n";
					}
				}
				if (numm0[i] > numm1[i])
				{
					ofs << numm1[i-1] << "\n";
					if (numm0[i] > numm1[i-1])
					{
						ofs << numm0[i] << "\n";
					}
				}
			}
			
		}
	}
	

	system_clock::time_point after = system_clock::now();

	times = duration_cast<milliseconds> (after - before);

	return 0;
}

BOOL CMultithreadDlg::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) 
{
	hList = GetDlgItem(hwnd, IDC_LIST1);
	SendMessage(hList, LB_ADDSTRING, 0, LPARAM(std::to_wstring(FindTime().count() * 1.0 / 1000).c_str()));
	//InitializeCriticalSection(&CriticalSelection);
	HANDLE handle1 = CreateThread(NULL, 0, Thread1, (LPVOID)0, 0, NULL);
	HANDLE handle2 =  CreateThread(NULL, 0, Thread1, (LPVOID)1, 0, NULL);	
	HANDLE handle3 = CreateThread(NULL, 0, Thread1, (LPVOID)2, 0, NULL);
	WaitForSingleObject(handle1, INFINITE);
	WaitForSingleObject(handle2, INFINITE);
	WaitForSingleObject(handle3, INFINITE);
	//DeleteCriticalSection(&CriticalSelection);
	SendMessage(hList, LB_ADDSTRING, 0, LPARAM(std::to_wstring(times.count() * 1.0 / 1000).c_str()));
	ofs0.close();
	ofs1.close();
	ofs.close();
	return TRUE;
}

BOOL CALLBACK CMultithreadDlg::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
	}
	return FALSE;
}