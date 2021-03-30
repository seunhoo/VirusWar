#pragma once
class Renderer : public Singleton<Renderer>
{
public:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pDevice;
	LPD3DXSPRITE m_pSp;

public:

	void Release();
	bool Init(int widht, int height, bool windowMode);

	LPDIRECT3DDEVICE9 GetDevice() { return m_pDevice; }
	LPD3DXSPRITE GetSprite() { return m_pSp; }

	void Begin();

	void End();
};

