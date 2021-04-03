#include "stdafx.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(Vec2 pos, int v)
	:m_OutCheck(true)
{
	m_V = v;
	if (v == 1)
	{
		m_Speed = 1;
		m_Sprite = Sprite::Create(L"Painting/Enemy/BigMonster.png");
		m_Sprite->SetParent(this);
		SetPosition(pos);
	}
	else if (v == 2)
	{
		m_Speed = 20;
		m_Sprite = Sprite::Create(L"Painting/Enemy/FlashMonster.png");
		m_Sprite->SetParent(this);
		SetPosition(pos);
	}
	else if (v == 3)
	{
		m_Speed = 15;
		m_Sprite = Sprite::Create(L"Painting/Enemy/SpeedMonster.png");
		m_Sprite->SetParent(this);
		SetPosition(pos);
	}
	if(SceneDirector::GetInst()->m_Stage == STAGE::STAGETWO)
		m_Sprite->A = 1;
	
}

void Monster::Update(float deltatime, float time)
{
	if ( SceneDirector::GetInst()->m_Stage == STAGE::STAGETWO && m_OutCheck == true)
	{
		m_OutEffect += dt;

			m_Sprite->A += 1;
			if (m_Sprite->A >= 254)
			{
				m_Sprite->A = 255;
				m_OutCheck = false;
				m_OutEffect = 0;
			}
	}
	
	else if (SceneDirector::GetInst()->m_Stage == STAGE::STAGEONE)
	{
		m_OutCheck = false;
	}

	if(m_OutCheck == false)
	{
		if (m_V == 1)
		{
			Big();
		}
		else if (m_V == 2)
		{
			Flash();
		}
		else if (m_V == 3)
		{	
			Speed();
		}
	}
	
}

void Monster::Big()
{
	if(m_MoveCheck == false)
		m_Delay+=dt;

	if (m_Delay >= 3)
	{
		m_MoveCheck = true;
		m_RandomCheck = true;
		m_Delay = 0;
	}
	if (m_MoveCheck == true)
	{
		m_MoveTime += dt;

		if (m_RandomCheck == true)
		{
			int q = rand() % 8 + 1;
			m_q = q;
			m_RandomCheck = false;
		}
		if (m_MoveTime <= 1)
		{
			if (m_q == 1 && m_Position.x > 100 && m_Position.y > 80)
			{
				m_Position.x -= m_Speed;
				m_Position.y -= m_Speed;
			}
			else if (m_q == 2 && m_Position.x < 1820 && m_Position.y > 80)
			{
				m_Position.x += m_Speed;
				m_Position.y -= m_Speed;
			}
			else if (m_q == 3 && m_Position.x > 100 && m_Position.y < 1000)
			{
				m_Position.x -= m_Speed;
				m_Position.y += m_Speed;
			}
			else if (m_q == 4 && m_Position.x < 1820 && m_Position.y < 1000)
			{
				m_Position.x += m_Speed;
				m_Position.y += m_Speed;
			}
			else if (m_q == 5 && m_Position.x > 100)
			{
				m_Position.x -= m_Speed;
			}
			else if (m_q == 6 && m_Position.x < 1820)
			{
				m_Position.x += m_Speed;
			}
			else if (m_q == 7 && m_Position.y < 1000)
			{
				m_Position.y += m_Speed;
			}
			else if (m_q == 8 && m_Position.y > 80)
			{
				m_Position.y -= m_Speed;
			}
		}
		else if (m_MoveTime > 1)
		{
			m_MoveCheck = false;
			m_MoveTime = 0;
		}
	}


}

void Monster::Flash()
{
	if (m_MoveCheck == false)
	{
		m_Delay += dt;
	}
	
	if (m_Sprite->A > 1 && m_MoveCheck == false && m_Delay > 1)
	{

		m_Sprite->A -= dt * 100;
	}

	if (m_Sprite->A <= 1 && m_Delay >= 1)
	{
		m_MoveCheck = true;
		m_RandomCheck = true;
		m_Delay = 0;
	}
	if (m_MoveCheck == true)
	{
		m_MoveTime += dt;
		if (m_RandomCheck == true)
		{
			int q = rand() % 8 + 1;
			m_q = q;
			m_RandomCheck = false;
		}
		if (m_MoveTime <= 0.5)	
		{
			if (m_q == 1 && m_Position.x >100 && m_Position.y > 80)
			{
				m_Position.x -= m_Speed;
				m_Position.y -= m_Speed;
			}
			else if (m_q == 2 && m_Position.x < 1820 && m_Position.y > 80)
			{
				m_Position.x += m_Speed;
				m_Position.y -= m_Speed;
			}
			else if (m_q == 3 && m_Position.x > 100 && m_Position.y < 1000)
			{
				m_Position.x -= m_Speed;
				m_Position.y += m_Speed;
			}
			else if (m_q == 4 && m_Position.x < 1820 && m_Position.y < 1000)
			{
				m_Position.x += m_Speed;
				m_Position.y += m_Speed;
			}
			else if (m_q == 5 && m_Position.x > 100)
			{
				m_Position.x -= m_Speed;
			}
			else if (m_q == 6 && m_Position.x <1820 )
			{
				m_Position.x += m_Speed;
			}
			else if (m_q == 7 && m_Position.y < 1000)
			{
				m_Position.y += m_Speed;
			}
			else if (m_q == 8  && m_Position.y > 80)
			{
				m_Position.y -= m_Speed;
			}
		}
		else if (m_MoveTime > 0.5)
		{
			m_Sprite->A = 255;
			m_MoveCheck = false;
			m_MoveTime = 0;
		}
	}





}

void Monster::Speed()
{
	if (m_MoveCheck == false)
		m_Delay += dt;

	if (m_Delay >= 1)
	{
		m_MoveCheck = true;
		m_RandomCheck = true;
		m_Delay = 0;
	}
	if (m_MoveCheck == true)
	{
		m_MoveTime += dt;

		if (m_RandomCheck == true)
		{
			int q = rand() % 8 + 1;
			m_q = q;
			m_RandomCheck = false;
		}
		if (m_MoveTime <= 1)
		{
			if (m_q == 1 && m_Position.x > 100 && m_Position.y > 80)
			{
				m_Position.x -= m_Speed;
				m_Position.y -= m_Speed;
			}
			else if (m_q == 2 && m_Position.x < 1820 && m_Position.y > 80)
			{
				m_Position.x += m_Speed;
				m_Position.y -= m_Speed;
			}
			else if (m_q == 3 && m_Position.x > 100 && m_Position.y < 1000)
			{
				m_Position.x -= m_Speed;
				m_Position.y += m_Speed;
			}
			else if (m_q == 4 && m_Position.x < 1820 && m_Position.y < 1000)
			{
				m_Position.x += m_Speed;
				m_Position.y += m_Speed;
			}
			else if (m_q == 5 && m_Position.x > 100)
			{
				m_Position.x -= m_Speed;
			}
			else if (m_q == 6 && m_Position.x < 1820)
			{
				m_Position.x += m_Speed;
			}
			else if (m_q == 7 && m_Position.y < 1000)
			{
				m_Position.y += m_Speed;
			}
			else if (m_q == 8 && m_Position.y > 80)
			{
				m_Position.y -= m_Speed;
			}
		}
		else if (m_MoveTime > 1)
		{
			m_MoveCheck = false;
			m_MoveTime = 0;
		}
	}


}

void Monster::Render()
{
	m_Sprite->Render();
}

void Monster::OnCollision(Object* obj, std::string tag)
{
}
