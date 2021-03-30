#pragma once
class Texture
{
public:
	LPDIRECT3DDEVICE9 m_pDev;
	LPDIRECT3DTEXTURE9 m_pTexture;
	Vec2 m_Size;

public:
	Texture();
	bool Init(std::wstring fileName);

	LPDIRECT3DTEXTURE9 GetTexture() { return m_pTexture; }
	Vec2 GetSize() { return m_Size; }
};

