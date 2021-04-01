#pragma once
#define GM GameMgr::GetInst()
class GameMgr : public Singleton<GameMgr>
{
public:
	
	int m_Hp = 5;



	bool m_ItemSpeed;
	bool m_ItemHeal;
	bool m_ItemDefence;
	bool m_ItemInvincible;


	void AddHp(int hp) { m_Hp += hp; }
	void MinusHp(int hp) { m_Hp -= hp; }

	void SetHp() { m_Hp = 5; }
	int GetHp() { return m_Hp; }

	void SetIn(bool in) { m_ItemInvincible = in; }
	bool GetIn() { return m_ItemInvincible; }

	void SetSpeed(bool speed) { m_ItemSpeed = speed; }
	bool GetSpeed() { return m_ItemSpeed; }

	void SetHeal(bool heal) { m_ItemHeal = heal; }
	bool GetHeal() { return m_ItemHeal; }

	void SetDefence(bool defence) { m_ItemDefence = defence; }
	bool GetDefence() { return m_ItemDefence; }




	int m_ItemCount[5] = { 3,3,1,2,5 };

	// Speed 1
	// Def   2
	// inv   3
	// heal  4
	// random 5



};

