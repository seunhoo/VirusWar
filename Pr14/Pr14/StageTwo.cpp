#include "stdafx.h"
#include "StageTwo.h"
#include"Player.h"
#include"Monster.h"
#include"Boss.h"
#include"Stage.h"
#include"StageTwo.h"
StageTwo::StageTwo()
	:m_OutCheck(0)
{
}

void StageTwo::Init()
{
	SceneDirector::GetInst()->m_Stage = STAGE::STAGETWO;
	m_Sprite = Sprite::Create(L"Painting/Stage2/BackGround/Stage3.png");
	m_Sprite->SetPosition(1920 / 2, 1080 / 2);

	ObjMgr->AddObject(new Player(), "Player");


}

void StageTwo::Release()
{
}

void StageTwo::Update(float deltatime, float time)
{
	if (m_OutCheck == false)
	{
		m_OutEffect += dt;

		m_Sprite->A -= 30;
		m_Sprite->G -= 50;
		m_Sprite->B -= 50;

		if (m_OutEffect >= 1)
		{
			m_OutCheck = true;

			m_Sprite->A = 255;
			m_Sprite->R = 255;
			m_Sprite->G = 255;
			m_Sprite->B = 255;

			ObjMgr->AddObject(new Monster(Vec2(1920 / 2, 1080 / 2 - 200), 1), "Monster");
			ObjMgr->AddObject(new Monster(Vec2(1920 / 2, 1080 / 2 + 200), 2), "Monster");
			ObjMgr->AddObject(new Monster(Vec2(1920 / 2 + 200, 1080 / 2), 3), "Monster");
			ObjMgr->AddObject(new Boss(Vec2(1920 / 2, 1080 / 2)), "Monster");
			
		}
	}

	if (INPUT->GetKey(VK_F5) == KeyState::DOWN && SceneDirector::GetInst()->m_Stage == STAGE::STAGETWO)
	{
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new Stage());
	}

}

void StageTwo::Render()
{
	m_Sprite->Render();	
}
