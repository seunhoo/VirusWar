#include "stdafx.h"
#include "Way.h"
#include"MainMenu.h"

Way::Way(int v)
{

	m_V = v;
}

void Way::Init()
{

	if (m_V == 1)
	{
		m_Sprite = Sprite::Create(L"Painting/Scene/Way.png");
		m_Sprite->SetPosition(1920 / 2, 1080 / 2); 
	}
	else if (m_V == 2)
	{
		m_Sprite = Sprite::Create(L"Painting/Scene/Ranking.png");
		m_Sprite->SetPosition(1920 / 2, 1080 / 2);
	}
	else if (m_V == 3)
	{
		m_Sprite = Sprite::Create(L"Painting/Scene/Report.png");
		m_Sprite->SetPosition(1920 / 2, 1080 / 2);
	}
	else if (m_V == 4)
	{
		m_Sprite = Sprite::Create(L"Painting/Scene/credit.png");
		m_Sprite->SetPosition(1920 / 2, 1080 / 2);
	}


}

void Way::Update(float deltatime, float time)
{

	if (INPUT->GetKey(VK_SPACE) == KeyState::UP)
	{
		SceneDirector::GetInst()->ChangeScene(new MainMenu());
	}
}

void Way::Render()
{
	m_Sprite->Render();
}

void Way::Release()
{
}
