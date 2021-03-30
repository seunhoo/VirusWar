#include "stdafx.h"
#include "Player.h"

Player::Player()
	:m_PlayerSpeed(10)
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
		SetPosition(50, 980);
	}
	else if (a == 3)
	{
		SetPosition(1840, 50);
	}
	else if (a == 4)
	{
		SetPosition(1840, 980);
	}

	m_Line = new LineMgr();
	m_Line->Init(1, true);
	m_Line->Setcolor(255, 255, 255, 255);

	i = 1;
	m_Length = 1;
}

void Player::Update(float deltatime, float time)
{
	Move();
}

void Player::Move()
{
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Position.y > 50)
	{
		m_Position.y -= m_PlayerSpeed;
		i++;
		m_Length++;
	}
	else if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS && m_Position.y < 1030)
	{
		m_Position.y += m_PlayerSpeed;
		i++;
		m_Length++;
	}
	else if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_Position.x < 1870)
	{
		m_Position.x += m_PlayerSpeed;
		i++;
		m_Length++;
	}
	else if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_Position.x > 50)
	{
		m_Position.x -= m_PlayerSpeed;
		i++;
		m_Length++;
	}
}
	
void Player::Render()
{
	m_Player->Render();
	m_Line->DrawLine(m_LinePos, m_Length);
}

void Player::OnCollision(Object* obj, std::string tag)
{
}
