#include "stdafx.h"
#include "StageTwo.h"

StageTwo::StageTwo()
{
}

void StageTwo::Init()
{
	m_Sprite = Sprite::Create(L"Painting/Stage2/BackGround/Stage3.png");
	m_Sprite->SetPosition(1920 / 2, 1080 / 2);
}

void StageTwo::Release()
{
}

void StageTwo::Update(float deltatime, float time)
{
}

void StageTwo::Render()
{
	m_Sprite->Render();	
}
