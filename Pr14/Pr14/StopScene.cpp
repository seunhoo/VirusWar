#include "stdafx.h"
#include "StopScene.h"
#include"MainMenu.h"
#include"Player.h"
StopScene::StopScene()
{
	m_Sprite = Sprite::Create(L"Painting/Scene/next.png");
	m_Sprite->SetParent(this);
	SetPosition(1700, 1080 / 2);

	m_cSprite = Sprite::Create(L"Painting/Scene/mainmenu.png");
	m_cSprite->SetPosition(400, 1080 / 2);
}


void StopScene::Update(float deltatime, float time)
{
	if (CollideMgr::GetInst()->MouseWithBoxSize(m_cSprite) && INPUT->GetButtonDown())
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new MainMenu());
		INPUT->ButtonDown(false);
	}

	if (CollideMgr::GetInst()->MouseWithBoxSize(this) && INPUT->GetButtonDown())
	{
		ObjMgr->RemoveObject(this);
		ObjMgr->AddObject(new Player(), "Player");
		INPUT->ButtonDown(false);
	}
}

void StopScene::Render()
{
	m_Sprite->Render();
	m_cSprite->Render();
}
