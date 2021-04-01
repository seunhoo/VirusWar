#include "stdafx.h"
#include "Animation.h"

void Animation::Init(float delay, bool autoplay)
{
	m_Delay = delay;
	m_AutoPlay = autoplay;
}

void Animation::Add(std::wstring filname, int first, int last)
{
	if (first < last)
	{
		for (int i = first; i < last; i++)
		{
			auto sprite = Sprite::Create(filname.c_str() + std::to_wstring(i) + L".png");
			sprite->SetParent(this);
			if (sprite)
				m_Anim.push_back(sprite);
		}
	}
}

void Animation::Update(float deltatime, float time)
{
	if (m_Destroy)
	{
		m_Anim.at(m_CurrentFrame)->SetDestroy(true);
	}
	m_FrameCount++;

	if (m_AutoPlay == true)
		if (m_FrameCount > m_Delay)
		{
			m_CurrentFrame++;
			m_FrameCount = 0;
		}

	if (m_CurrentFrame > m_Anim.size() - 1)
	{
		m_CurrentFrame = 0;
	}
	m_Anim.at(m_CurrentFrame)->A = A;
	m_Anim.at(m_CurrentFrame)->R = R;
	m_Anim.at(m_CurrentFrame)->G = G;
	m_Anim.at(m_CurrentFrame)->B = B;

	m_Anim.at(m_CurrentFrame)->Update(deltatime, time);


}

void Animation::Render()
{
	if (m_Parent)
	{
		SetRect(&m_Parent->m_Collision,
			m_Parent->m_Position.x - (m_Size.x * m_Parent->m_Scale.x) / 2,
			m_Parent->m_Position.y - (m_Size.y * m_Parent->m_Scale.y) / 2,
			m_Parent->m_Position.x + (m_Size.x * m_Parent->m_Scale.x) / 2,
			m_Parent->m_Position.y + (m_Size.y * m_Parent->m_Scale.y) / 2);
		m_Parent->m_Size = m_Size;
	}
	else
	{
		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.y / 2,
			m_Position.x + m_Size.x / 2, m_Position.y + m_Size.y / 2);
	}

	m_Anim.at(m_CurrentFrame)->Render();
}
