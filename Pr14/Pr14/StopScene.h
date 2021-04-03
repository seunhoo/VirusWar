#pragma once
class StopScene : public Object
{
public:

	Sprite* m_Sprite;
	Sprite* m_cSprite;

	StopScene();


	void Update(float deltatime, float time);
	void Render();
};

