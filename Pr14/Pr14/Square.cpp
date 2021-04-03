#include "stdafx.h"
#include "Square.h"

Square::Square()
{
}

Square::Square(Vec2 pos, Vec2 scale)
	:j(0)
	,m_bMinusCheck(true)
	,m_MinusCheck(0)
{
	m_cScale = scale;

	m_Sprite = Sprite::Create(L"Painting/Player/Square.png");
	m_Sprite->SetParent(this);

	SetPosition(pos);
	SetScale(scale);
	std::cout << pos.x << " " << pos.y << std::endl;
	std::cout << scale.x << " " << scale.y << std::endl;

	m_BasicScale = ((m_cScale.x * m_cScale.y) / (1820 * 980)) * 100;

	GM->AddPerCent(m_BasicScale);

	m_Sprite->A = 100;
}

void Square::Update(float deltatime, float time)
{
	// Square 1 
	if (m_MinusCheck == true && m_bMinusCheck == true)
	{
		m_mScale.x = m_Minus.right - m_Minus.left;
		m_mScale.y = m_Minus.bottom - m_Minus.top;

		m_NextScale = ((m_mScale.x * m_mScale.y) / (1820 * 980)) * 100;

		GM->MinusPerCent(m_NextScale);
		m_MinusCheck = false;
		m_bMinusCheck = false;
	}
	for (auto iter = ObjMgr->m_Objects.begin(); iter != ObjMgr->m_Objects.end(); ++iter)
	{
		if (-1 != (*iter)->m_Tag.find("Square")) // Square0 1
		{
			ObjMgr->SqureCollisionCheak((*iter), (*iter)->m_Tag);
			m_Minus = ObjMgr->rcc;
			m_MinusCheck = true;
		}
	}








	
	
	//ObjMgr->CollisionCheak(this, "Square");
}

void Square::Render()
{
	m_Sprite->Render();
}

void Square::OnCollision(Object* obj, std::string tag)
{

}
