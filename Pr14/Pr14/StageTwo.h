#pragma once
class StageTwo : public Scene
{
public:

	Sprite* m_Sprite;

	StageTwo();

	void Init();
	void Release();
	void Update(float deltatime, float time);
	void Render();
};

