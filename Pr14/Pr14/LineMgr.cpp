#include "stdafx.h"
#include "LineMgr.h"

void LineMgr::Init(float width, bool an)
{
	D3DXCreateLine(Renderer::GetInst()->GetDevice(), &m_pLine);

	m_pLine->SetWidth(width);
	m_pLine->SetAntialias(an);
	m_pLine->SetPattern(0xfffffffff);
}

void LineMgr::DrawLine(Vec2* vec, int size)
{
	m_pLine->Begin();
	m_pLine->Draw(vec, size, m_Color);
	m_pLine->End();
}

void LineMgr::Setcolor(int a, int r, int g, int b)
{
	m_Color = D3DCOLOR_ARGB(a, r, g, b);
}
