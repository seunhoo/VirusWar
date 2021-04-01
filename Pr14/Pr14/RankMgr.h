#pragma once
class RankMgr : public Singleton<RankMgr>
{
public:

	int m_Score;
	
	void AddScore(int score) { m_Score += score; }
	int GetScore() { return m_Score; }

};

