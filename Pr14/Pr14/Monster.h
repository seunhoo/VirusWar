#pragma once
class Monster : public Object
{
public:

	Sprite* m_Sprite;


	Monster();

	Monster(Vec2 pos, int v);


	int m_V;

	float m_Speed;

	float m_Delay;
	float m_MoveTime;
	bool m_MoveCheck;
	bool m_RandomCheck;

	float m_OutEffect;
	bool m_OutCheck;

	Vec2 m_RPos;

	int m_q;

	void Update(float deltatime, float time);
	void Big();	
	void Flash();
	void Speed();
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

