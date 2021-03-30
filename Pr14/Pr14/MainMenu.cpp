#include "stdafx.h"
#include "MainMenu.h"
#include"Stage.h"
#include"Way.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{

	m_Sprite = Sprite::Create(L"Painting/Stage1/BackGround/Back.png");
	m_Sprite->SetPosition(1920 / 2, 1080 / 2);

	m_Start = Sprite::Create(L"Painting/Button/start.png");
	m_Start->SetPosition(300, 100);

	m_Way = Sprite::Create(L"Painting/Button/way.png");
	m_Way->SetPosition(300, 300);

	m_Rank = Sprite::Create(L"Painting/Button/rank.png");
	m_Rank->SetPosition(300, 500);

	m_Report = Sprite::Create(L"Painting/Button/report.png");
	m_Report->SetPosition(300, 700);

	m_Credit = Sprite::Create(L"Painting/Button/credit.png");
	m_Credit->SetPosition(300, 900);

}

void MainMenu::Release()
{
}

void MainMenu::Update(float deltatime, float time)
{

	if (CollideMgr::GetInst()->MouseWithBoxSize(m_Start) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Stage);
	}
	else if ( CollideMgr::GetInst()->MouseWithBoxSize(m_Way) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Way(1));
	}
	else if (CollideMgr::GetInst()->MouseWithBoxSize(m_Rank) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Way(2));
	}
	else if ( CollideMgr::GetInst()->MouseWithBoxSize(m_Report) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Way(3));
	}
	else if (CollideMgr::GetInst()->MouseWithBoxSize(m_Credit) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Way(4));
	}
}

void MainMenu::Render()
{
	m_Sprite->Render();

	m_Start->Render();

	m_Rank->Render();

	m_Credit->Render();

	m_Report->Render();

	m_Way->Render();
}
