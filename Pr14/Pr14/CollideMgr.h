#pragma once
class CollideMgr : public Singleton<CollideMgr>
{
public:

	bool MouseWithBoxSize(Object* obj);
};

