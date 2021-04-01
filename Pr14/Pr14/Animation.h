#pragma once
class Animation : public Object
{
public:

	float m_CurrentFrame;

	bool m_AutoPlay;

	float m_Delay;

	float m_FrameCount;


	std::vector<Sprite*>m_Anim;

	int A, R, G, B;


	void Init(float delay, bool autoplay);

	void Add(std::wstring filname, int first, int last);

	void Update(float deltatime, float time);
	void Render();



};
