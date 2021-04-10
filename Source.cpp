#include<stdio.h>
#include<Windows.h>
#include<string>
int main(int argc, char* argv[])
{

	char szExecFile[MAX_PATH] = "C:\\Windows\\System32\\cmd.exe";
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFOA si = { 0 };
	si.cb = sizeof(STARTUPINFOA);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	LPCSTR URL_String = "http://www.google.com.tw";
	ShellExecuteA(NULL, "open", URL_String,NULL,NULL ,SW_SHOWNORMAL);
	BOOL bRet = CreateProcessA(szExecFile, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);
	if (bRet == FALSE)
	{
		printf("CreateProcessA Error. (%d)\n", GetLastError());
		return EXIT_FAILURE;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	return 0;





}