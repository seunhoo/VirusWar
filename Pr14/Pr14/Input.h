#pragma once
enum class KeyState
{
	DOWN,
	UP,
	PRESS,
	NONE
};
#define INPUT Input::GetInst()
class Input : public Singleton<Input>
{
public:
	int m_CurrentState[256];
	int m_PrevState[256];
	bool m_bCurrentState;
	bool m_bPrevState;
	bool m_ButtonDown;
	Vec2 m_Mousepos;

public:

	Input();

	void Update();

	KeyState GetKey(int key);

	bool GetButtonDown() { return m_ButtonDown; }

	Vec2 GetMousePos() { return m_Mousepos; }

	void ButtonDown(bool down) { m_ButtonDown = down; }

	void KeyBoardUpdate();
	void MouseUpdate();
};

