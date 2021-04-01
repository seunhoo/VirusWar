#include "stdafx.h"
#include "Boss.h"

Boss::Boss()

{

}

Boss::Boss(Vec2 pos)
	: m_OutCheck(true)
{
	m_Sprite = Sprite::Create(L"Painting/Enemy/Boss.png");
	m_Sprite->SetParent(this);
	SetPosition(pos);

	m_Sprite->A = 1;
}

void Boss::Update(float deltatime, float time)
{
	if (m_OutCheck == true)
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
}

void Boss::Render()
{
	m_Sprite->Render();
}

void Boss::OnCollision(Object* obj, std::string tag)
{
}
