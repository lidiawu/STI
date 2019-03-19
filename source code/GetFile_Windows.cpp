#include "windows.h"
#include <assert.h>

void GetFile(char* buffer, size_t bufferlen)
{
    assert(buffer != NULL);

    // Copied from https://msdn.microsoft.com/en-us/library/windows/desktop/ms646829(v=vs.85).aspx#open_file

    OPENFILENAME ofn;       // common dialog box structure
    CHAR szFile[260];      // buffer for file name
    HWND hwnd = NULL;       // owner window
    HANDLE hf = NULL;       // file handle

    // Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
    // Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
    // use the contents of szFile to initialize itself.
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn)) strcpy_s(buffer, bufferlen, ofn.lpstrFile);
    else buffer[0] = '\0';
}