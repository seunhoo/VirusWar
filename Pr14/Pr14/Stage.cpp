#include "stdafx.h"
#include "Stage.h"
#include"Player.h"
#include"Monster.h"
#include"Boss.h"
Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Init()
{
	m_Sprite = Sprite::Create(L"Painting/Stage1/BackGround/Back5.png");
	m_Sprite->SetPosition(1920 / 2, 1080/2);

	ObjMgr->AddObject(new Player(), "Player");


	ObjMgr->AddObject(new Monster(Vec2(1920/2 , 1080 /2  - 100),1), "Big");
	ObjMgr->AddObject(new Monster(Vec2(1920 / 2, 1080 / 2 + 100), 2), "Flash");
	ObjMgr->AddObject(new Monster(Vec2(1920 / 2 + 100, 1080 / 2), 3), "Speed");
	//ObjMgr->AddObject(new Boss(Vec2(1920 / 2, 1080 / 2)), "Boss");
}

void Stage::Release()
{
}

void Stage::Update(float deltatime, float time)
{
}

void Stage::Render()
{
	m_Sprite->Render();
}
