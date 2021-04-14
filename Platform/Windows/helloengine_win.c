#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

LRESULT CALLBACK Windowproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//The enrtry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    //the hindle of the window, filled by a function
    HWND hWnd;
    //this struct holds information for the window class
    WNDCLASSEX wc;
    //clear out the window for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    //fill in the struct with needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = Windowproc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = _T("WindowsClass1");

    //Register the window class
    RegisterClassEx(&wc);

    //Create the window and use the result as the handle
    hWnd = CreateWindowEx(0, _T("WindowClass1"), _T("Hello, Engine!"),
                        WS_OVERLAPPEDWINDOW,300,300,500,400,NULL,NULL,hInstance,NULL);
    //Display the window on the screen
    ShowWindow(hWnd, nCmdShow);

    //Enter the main loop
    //This struct holds Windows event messages
    MSG msg;
    
    //Wait for the next message in the queue, store the result in 'msg'
    while(GetMessage(&msg, NULL, 0, 0))
    {
        //Translate keystroke messages into the right format
        TranslateMessage(&msg);
        //Send the message to the WindowProc function
        DispatchMessage(&msg);
    }
    //Return this part of the WM_QUIT message to Windows
    return msg.wParam;
}

//This is the main message handler for the program
LRESULT CALLBACK Windowproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //Sort through and find what code to run for the message given
    switch(message)
    {
        case WM_DESTROY:
        {
            //Close the application entirely
            PostQuitMessage(0);
            return 0;
        }break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}