#include "stdafx.h"
#include "App.h"

bool App::Init(int width, int height, bool windowMode)
{
    m_Width = width;
    m_Height = height;
    m_WindowMode = windowMode;

    if (!_CreateWindow())
        return false;
    if (!_CreateRenderer())
        return false;

    Time = 0;
    return true;

}

void App::Run()
{
    MSG msg;
    srand(time(NULL));
    ZeroMemory(&msg, sizeof(MSG));

    while (msg.message != WM_QUIT)
    {
        static DWORD lastTime = timeGetTime();
        DWORD curTime = timeGetTime();
        float timeDelta = (float)(curTime - lastTime) * 0.001;

        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Renderer::GetInst()->Begin();

            if (m_Stop == false)
            {
                SceneDirector::GetInst()->Update(timeDelta, Time);
            }

            DeltaTime = timeDelta;
            Time += timeDelta;
            SceneDirector::GetInst()->Render();
            Renderer::GetInst()->End();

            lastTime = curTime;


            if (GetAsyncKeyState(VK_ESCAPE))
            {
                App::GetInst()->Release();
                exit(0);
            }
        }


    }
}

void App::Release()
{
    FreeConsole();
    ObjMgr->Release();
    Renderer::GetInst()->Release();
}

LRESULT App::WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_LBUTTONDOWN:
        INPUT->ButtonDown(true);
        break;
    case WM_LBUTTONUP:
        INPUT->ButtonDown(false);
        break;
    }
    return DefWindowProc(hwnd, msg, wparam, lparam);
}
bool App::_CreateWindow()
{
    WNDCLASS wc = {};
    wc.lpszClassName = L"�ѽ�ȣ ������";
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.lpfnWndProc = WndProc;

    RegisterClass(&wc);

    DWORD Style = 0;
    if (m_WindowMode)
        Style = WS_OVERLAPPEDWINDOW;
    else
        Style = WS_POPUP | WS_EX_TOPMOST;

    HWND hWnd = CreateWindow(wc.lpszClassName, wc.lpszClassName, Style, 0, 0, m_Width, m_Height, 0, 0, 0, 0);

    if (hWnd)
        m_Hwnd = hWnd;
    else
        return false;

    ShowWindow(m_Hwnd, SW_SHOWDEFAULT);

    return true;
}

bool App::_CreateRenderer()
{
    if (!(Renderer::GetInst()->Init(m_Width, m_Height, m_WindowMode)))
        return false;

    return true;
}
