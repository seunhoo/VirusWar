#include "stdafx.h"
#include "SceneMain.h"
#include"MainMenu.h"

SceneMain::SceneMain()
{

}

void SceneMain::Init()
{
	m_Sprite = Sprite::Create(L"Painting/Intro/Intro1.png");
	m_Sprite->SetPosition(1920 / 2, 1080 / 2);
	i = 2;
}

void SceneMain::Update(float deltatime, float time)
{
	if (i <= 6)
	{
		m_NextTime += dt / 2;
		m_Sprite->A -= m_NextTime;
	}
	if (m_Sprite->A <= 10)
	{
		m_Sprite = Sprite::Create(L"Painting/Intro/Intro" + std::to_wstring(i) + L".png");
		m_Sprite->SetPosition(1920 / 2, 1080 / 2);
		m_Sprite->A = 255;
		m_NextTime = 0;
		i++;
	}

	if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN)
	{
		SceneDirector::GetInst()->ChangeScene(new MainMenu());
	}

}

void SceneMain::Render()
{
	m_Sprite->Render();
}

void SceneMain::Release()
{
}
