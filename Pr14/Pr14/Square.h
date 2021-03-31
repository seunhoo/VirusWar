#pragma once
class Square : public Object
{
public:

	Sprite* m_Sprite;

	Square();

	Square(Vec2 pos, Vec2 scale);

	Vec2 m_Pos, m_cScale;

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

