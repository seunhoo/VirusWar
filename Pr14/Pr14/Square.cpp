#include "stdafx.h"
#include "Square.h"

Square::Square()
{
}

Square::Square(Vec2 pos, Vec2 scale)
{
	m_Sprite = Sprite::Create(L"Painting/Player/Square.png");
	m_Sprite->SetParent(this);

	SetPosition(pos);
	SetScale(scale);
	std::cout << pos.x << " " << pos.y << std::endl;
	std::cout << scale.x << " " << scale.y << std::endl;

	m_Sprite->A = 100;
}

void Square::Update(float deltatime, float time)
{
}

void Square::Render()
{
	m_Sprite->Render();
}

void Square::OnCollision(Object* obj, std::string tag)
{
}
