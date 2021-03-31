#include "stdafx.h"
#include "Boss.h"

Boss::Boss()
{

}

Boss::Boss(Vec2 pos)
{
	m_Sprite = Sprite::Create(L"Painting/Enemy/Boss.png");
	m_Sprite->SetParent(this);
	SetPosition(pos);
}

void Boss::Update(float deltatime, float time)
{
}

void Boss::Render()
{
	m_Sprite->Render();
}

void Boss::OnCollision(Object* obj, std::string tag)
{
}
