#pragma once
class Player : public Object
{
public:

	Sprite* m_Player;

	float m_PlayerSpeed;

	int i, m_Length;

	LineMgr* m_Line;

	Vec2 m_LinePos[3000];


	Player();

	float randomposx;
	float randomposy;

	void Update(float deltatime, float time);
	void Move();
	void Render();  
	void OnCollision(Object* obj, std::string tag);
};

