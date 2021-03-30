#pragma once
class LineMgr
{
public:
	
	D3DXCOLOR m_Color;
	LPD3DXLINE m_pLine;
	Matrix m_wMat;



	void Init(float width, bool an);
	void DrawLine(Vec2* vec, int size);

	void Setcolor(int a, int r, int g, int b);
};

