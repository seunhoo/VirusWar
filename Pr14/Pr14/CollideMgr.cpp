#include "stdafx.h"
#include "CollideMgr.h"



bool CollideMgr::MouseWithBoxSize(Object* obj)
{
	POINT Mouse;
	Mouse.x = (LONG)INPUT->GetMousePos().x;
	Mouse.y = (LONG)INPUT->GetMousePos().y;

	if (PtInRect(&obj->m_Collision, Mouse))
	{
		return true;
	}

	return false;
}