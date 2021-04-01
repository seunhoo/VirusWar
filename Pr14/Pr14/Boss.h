#pragma once
class Boss : public Object
{
public:

	Sprite* m_Sprite;

	bool m_OutCheck;
	float m_OutEffect;

	Boss();
	Boss(Vec2 pos);
	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

