#pragma once
class MainMenu : public Scene
{
public:

	Sprite* m_Sprite;

	Sprite* m_Start;
	Sprite* m_Credit;
	Sprite* m_Rank;
	Sprite* m_Report;
	Sprite* m_Way;

	MainMenu();
	~MainMenu();

	void Init();
	void Release();
	void Update(float deltatime, float time);
	void Render();
};

