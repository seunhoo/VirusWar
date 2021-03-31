#pragma once
class Boss : public Object
{
public:

	Sprite* m_Sprite;

	Boss();
	Boss(Vec2 pos);
	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

