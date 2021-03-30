#pragma once
class Way : public Scene
{
public:

	Sprite* m_Sprite;
	

	Way(int v);

	int m_V;

	void Init();
	void Update(float deltatime, float time);
	void Render();
	void Release();
};

