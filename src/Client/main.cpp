#include <string.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	HANDLE hPipe;
	char szBuff[32];
	DWORD dwNumberOfBytesRead;
	DWORD dwNumberofBytesWritten;

	hPipe = CreateFile(L"\\\\.\\pipe\\mypipe",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hPipe == INVALID_HANDLE_VALUE) {
		return 1;
	}

	while (1) {
		fgets(szBuff, sizeof(szBuff) / sizeof(szBuff[0]), stdin);
		if (!WriteFile(hPipe, szBuff, strlen(szBuff), &dwNumberofBytesWritten, NULL)) {
			break;
		}
	}

	CloseHandle(hPipe);

	return 0;
}