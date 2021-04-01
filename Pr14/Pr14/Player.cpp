#include "stdafx.h"
#include "Player.h"
#include"Square.h"
#include"Stage.h"
#include"StageTwo.h"
#include"MainMenu.h"
#include"GameMgr.h"
Player::Player()
	:m_PlayerSpeed(10)
	,m_State(MoveState::NONE)
{
	m_Player = Sprite::Create(L"Painting/Player/Player1.png");
	m_Player->SetParent(this);

	int a = rand() % 4 + 1;
	if (a == 1)
	{
		SetPosition(50, 50);
	}
	else if (a == 2)
	{
		SetPosition(50, 1030);
	}
	else if (a == 3)
	{
		SetPosition(1870, 50);
	}
	else if (a == 4)
	{
		SetPosition(1870, 1030);
	}

	m_Line = new LineMgr();
	m_Line->Init(1, true);
	if (SceneDirector::GetInst()->m_Stage== STAGE::STAGEONE)
		m_Line->Setcolor(255, 255, 255, 255);
	else if(SceneDirector::GetInst()->m_Stage == STAGE::STAGETWO)
		m_Line->Setcolor(255, 255, 0, 0);

	i = 0;
	m_Length = 1;
	m_LinePos[0] = m_Position;
	
	m_Layer = 100;

	m_Text = new TextMgr();
	m_Text->Init(35, "±Ã¼­Ã¼");
	m_Text->SetColor(255, 255, 255,0 );
	
	m_ScoreText = new TextMgr();
	m_ScoreText->Init(35, "±Ã¼­Ã¼");
	m_ScoreText->SetColor(255, 255, 255, 0);

	m_Item = new Animation();
	m_Item->Init(1, 1);
	m_Item->Add(L"Painting/Effect/Invincible", 0, 5);
	m_Item->SetPosition(m_Position);


	GM->SetIn(false);
}

void Player::Update(float deltatime, float time)
{
	Cheat();
	Item(deltatime,time);
	Move();
	MakeSquare();
	if (GameMgr::GetInst()->GetIn() == false)
	{
		ObjMgr->CollisionCheak(this, "Monster");
	}
	
	if (m_CollideCheck == true)
	{
		m_CollideTime += dt;
		if (m_CollideTime >= 1)
		{
			GM->SetIn(false);
			m_CollideTime = 0;
		}
	}

}

void Player::Move()
{
	m_LinePos[i] = m_Position;
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Position.y > 50)
	{
		m_LinePos[i] = m_Position;
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_State = MoveState::UP;
			i++;
			m_Length++;
		}
		m_Position.y -= m_PlayerSpeed;
	}
	else if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS && m_Position.y < 1030)
	{
		m_LinePos[i] = m_Position;
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_State = MoveState::DOWN;
			i++;
			m_Length++;
		}
		m_Position.y += m_PlayerSpeed;
	}
	else if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_Position.x < 1870)
	{
		m_LinePos[i] = m_Position;
		if (m_State != MoveState::RIGHT && m_State != MoveState::LEFT)
		{
			m_State = MoveState::RIGHT;
			i++;
			m_Length++;
		}
		m_Position.x += m_PlayerSpeed;
	}
	else if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_Position.x > 50)
	{
		m_LinePos[i] = m_Position;
		if (m_State != MoveState::RIGHT && m_State != MoveState::LEFT)
		{
			m_State = MoveState::LEFT;
			i++;
			m_Length++;
		}
		m_Position.x -= m_PlayerSpeed;
	}
}

void Player::MakeSquare()
{


	if (dist <= 0 && i >= 3 && m_Length >= 4)
	{
		x1 = m_LinePos[0].x < m_LinePos[1].x ? m_LinePos[0].x : m_LinePos[1].x;
		y1 = m_LinePos[0].y < m_LinePos[1].y ? m_LinePos[0].y : m_LinePos[1].y;
		x2 = m_LinePos[0].x > m_LinePos[1].x ? m_LinePos[0].x : m_LinePos[1].x; 
		y2 = m_LinePos[0].y > m_LinePos[1].y ? m_LinePos[0].y : m_LinePos[1].y;

		if (dist < 10 && m_Position.x >= x1 - 10 && m_Position.x <= x2 + 10 && m_Position.y >= y1 - 10 && m_Position.y <= y2 + 10)
		{
			m_LinePos[0] = m_LinePos[4];
			
			if (m_LinePos[0] == m_LinePos[1])
			{
				float posx, posy;
				posx = (m_LinePos[0].x + m_LinePos[3].x) / 2;
				posy = (m_LinePos[0].y + m_LinePos[3].y) / 2;

				float scalex, scaley;
				scalex = (m_LinePos[3].x - m_LinePos[0].x) / 10;
				scaley = (m_LinePos[3].y - m_LinePos[0].y) / 10;


				ObjMgr->AddObject(new Square(Vec2(posx, posy), Vec2(std::abs(scalex), std::abs(scaley))), "Square");

			}
			else
			{
				float posx, posy;
				posx = (m_LinePos[0].x + m_LinePos[2].x) / 2;
				posy = (m_LinePos[0].y + m_LinePos[2].y) / 2;

				float scalex, scaley;
				scalex = (m_LinePos[2].x - m_LinePos[0].x) / 10;
				scaley = (m_LinePos[2].y - m_LinePos[0].y) / 10;


				ObjMgr->AddObject(new Square(Vec2(posx, posy), Vec2(std::abs(scalex), std::abs(scaley))), "Square");

			}
			
			i = 1;
			m_Length = 2;

		
			m_LinePos[0] = m_LinePos[4];
			std::cout << i << std::endl << m_Length << std::endl;
		}
	}
	if (m_LinePos[0] == m_LinePos[1])
	{
		a = m_LinePos[0].y - m_LinePos[2].y;
		b = m_LinePos[2].x - m_LinePos[0].x;
		c = m_LinePos[0].x * m_LinePos[2].y - m_LinePos[2].x * m_LinePos[0].y;
	}
	else
	{
		a = m_LinePos[0].y - m_LinePos[1].y;
		b = m_LinePos[1].x - m_LinePos[0].x;
		c = m_LinePos[0].x * m_LinePos[1].y - m_LinePos[1].x * m_LinePos[0].y;
	}
	dist = (float)std::abs(a * m_Position.x + b * m_Position.y + c) / (float)std::sqrt(a * a + b * b);
}

void Player::Cheat()
{
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
	{
		GameMgr::GetInst()->SetIn(true);
	}
	if (GameMgr::GetInst()->GetIn() == true)
	{

	}
	
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN)
	{
		int random = rand() % 4 + 1;
		if (random == 1)
		{
			GM->SetSpeed(true);
		}
		else if (random == 2)
		{
			GM->SetDefence(true);
		}
		else if (random == 3)
		{
			GM->SetIn(true);
		}
		else if (random == 4)
		{
			GM->SetHeal(true);
		}
	}
	if (INPUT->GetKey(VK_F3) == KeyState::DOWN)
	{
		GameMgr::GetInst()->AddHp(1);
	}
	if (INPUT->GetKey(VK_F4) == KeyState::DOWN)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new MainMenu());
	}
	

}

void Player::Item(float deltatime, float time)
{
	if (GM->GetSpeed() == true)
	{
		m_ItemTime += dt;

		m_PlayerSpeed = 20;
		if (m_ItemTime >= 2)
		{
			m_PlayerSpeed = 10;
			GM->SetSpeed(false);
			m_ItemTime = 0;
		}
		m_Item->Update(deltatime, time);
	}
	if (GM->GetDefence() == true)
	{
		

		m_Item = new Animation();
		m_Item->Init(1, 1);
		m_Item->Add(L"Painting/Effect/Defence", 0, 1);
		m_Item->SetPosition(m_Position);
		m_Item->Update(deltatime, time);


	}
	if (GM->GetIn() == true)
	{
		m_DefenceTime += dt;

		if (m_DefenceTime >= 2)
		{
			m_DefenceTime = 0;
			GM->SetIn(false);
		}
		GM->SetIn(true);
	}
	if (GM->GetHeal() == true)
	{
		m_Item = new Animation();
		m_Item->Init(1, 1);
		m_Item->Add(L"Painting/Effect/Invincible", 0, 5);
		m_Item->SetPosition(m_Position);
		m_Item->Update(deltatime, time);

		if (m_Item->m_CurrentFrame >=4)
		{
			GM->SetHeal(false);

			m_HealTime = 0;

			GM->AddHp(1);

			if (GM->GetHp() > 5)
			{
				RankMgr::GetInst()->AddScore(100);
				GM->SetHp();

			}
		}

	
	}

}
	
void Player::Render()
{
	m_Player->Render();
	m_Line->DrawLine(m_LinePos, m_Length);

	if (GM->GetSpeed() == true)
	{
		m_Item->Render();
	}
	if (GM->GetDefence() == true)
	{
		m_Item->Render();
	}
	if (GM->GetIn() == true)
	{
		m_Item->Render();
	}
	if (GM->GetHeal() == true)
	{
		m_Item->Render();
	}

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("HP : " + std::to_string(GameMgr::GetInst()->GetHp()),1700,10);
	m_ScoreText->print("SCORE : " + std::to_string(RankMgr::GetInst()->GetScore()), 1920 / 2 -50, 10);
	Renderer::GetInst()->GetSprite()->End();
}

void Player::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Monster")
	{
		m_CollideCheck = true;
	}
}
