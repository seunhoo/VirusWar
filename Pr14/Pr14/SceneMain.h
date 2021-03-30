#pragma once
class SceneMain : public Scene
{
public:

	Sprite* m_Sprite;


	float m_NextTime;

	int i;

	SceneMain();

	void Init();
	void Update(float deltatime, float time);
	void Render();
	void Release();
};

