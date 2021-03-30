#include "stdafx.h"
#include "Stage.h"
#include"Player.h"
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
