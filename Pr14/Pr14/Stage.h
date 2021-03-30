#pragma once
class Stage : public Scene
{
	Sprite* m_Sprite;
public:
	Stage();
	~Stage();

	void Init();
	void Release();
	void Update(float deltatime, float time);
	void Render();
};

