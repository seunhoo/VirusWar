#pragma once
enum class MoveState
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	NONE
};
class Player : public Object
{
public:


	MoveState m_State;

	Sprite* m_Player;

	Animation* m_Item;

	float m_PlayerSpeed;
	float m_InTime;
	float m_ItemTime;
	float m_HealTime;

	int i, m_Length;

	LineMgr* m_Line;

	TextMgr* m_Text;
	TextMgr* m_ScoreText;
	TextMgr* m_PerCent;

	float m_DefenceTime;


	bool m_CollideCheck;
	bool m_HpCheck;

	float m_CollideTime;


	int j;

	Vec2 m_LinePos[3000];

	float a, b, c, dist, x1,x2,y1,y2 ;

	Player();

	float randomposx;
	float randomposy;

	int m_PlayerHp;

	void Update(float deltatime, float time);
	void Move();
	void MakeSquare();
	void Cheat();
	void Item(float deltatime, float time);
	void Render();  
	void OnCollision(Object* obj, std::string tag);
};

