#pragma once
class Square : public Object
{
public:

	Sprite* m_Sprite;

	Square();

	Square(Vec2 pos, Vec2 scale);

	Vec2 m_Pos;
	Vec2 m_cScale;

	RECT m_Minus;
	Vec2 m_mScale;

	float m_NextScale;

	int i, j;

	float m_BasicScale;

	bool m_MinusCheck;
	bool m_bMinusCheck;

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

