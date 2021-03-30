#pragma once
#define dt App::GetInst()->DeltaTime
class App : public Singleton<App>
{
public:
	int m_Width, m_Height;
	bool m_WindowMode;
	HWND m_Hwnd;
	float DeltaTime, Time;

	HWND GetHwnd() { return m_Hwnd; }

	bool Init(int width, int height, bool windowMode);
	void Run();
	void Release();

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	bool _CreateWindow();
	bool _CreateRenderer();
};

