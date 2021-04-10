#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

LRESULT CALLBACK Windowsproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//The enrtry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    //the hindle of the window, filled by a function
    HWND hWnd;
    //this struct holds information for the window class
    WNDCLASSEX wc;
    //clear out the window for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    //fill in the window with needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = Windowsproc;
    wc.hInstance = hInstance;
}