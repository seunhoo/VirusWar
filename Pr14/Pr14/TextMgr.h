#pragma once
class TextMgr
{
public:

	D3DXCOLOR m_Color;
	LPD3DXFONT m_pFont;
	RECT m_FontRect;
	Matrix m_wMat;

	TextMgr();

	bool Init(float height, const std::string& fontname);
	int print(const std::string& str, int x, int y);
	void SetColor(int a, int r, int g, int b) { m_Color = D3DCOLOR_ARGB(a, r, g, b); }
};

