#pragma once
class StageTwo : public Scene
{
public:

	Sprite* m_Sprite;


	StageTwo();

	float m_OutEffect;

	bool m_OutCheck;

	void Init();
	void Release();
	void Update(float deltatime, float time);
	void Render();
};

