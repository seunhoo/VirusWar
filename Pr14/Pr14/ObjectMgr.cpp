#include "stdafx.h"
#include "ObjectMgr.h"

void ObjectMgr::Release()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
	{
		(*iter)->SetDestroy(true);
	}
}

void ObjectMgr::DeleteCheak()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		if ((*iter)->GetDestroy())
		{
			Object* temp = (*iter);
			iter = m_Objects.erase(iter);
			SafeDelete(temp);
		}
		else
		{
			++iter;
		}
	}
}
void ObjectMgr::Update(float deltaTime, float time)
{
	DeleteCheak();
	for (const auto& iter : m_Objects)
	{
		(iter)->Update(deltaTime, time);
	}
}

void ObjectMgr::Render()
{
	m_Objects.sort(stLISTsort());

	for (const auto& iter : m_Objects)
	{
		(iter)->Render();
	}
}

void ObjectMgr::AddObject(Object* obj, const std::string tag)
{
	m_Objects.push_back(obj);
	obj->SetTag(tag);
}

void ObjectMgr::RemoveObject(Object* obj)
{
	if (obj)
		obj->SetDestroy(true);
}

void ObjectMgr::CollisionCheak(Object* obj, const std::string tag)
{
	for (auto& iter : m_Objects)
	{
			if (iter->m_Tag == tag)
			{
				RECT rc;
				if (IntersectRect(&rc, &obj->m_Collision, &iter->m_Collision))
				{
					obj->OnCollision(iter, iter->m_Tag);
					iter->OnCollision(obj, obj->m_Tag);
				}
			}
	}
}

void ObjectMgr::SqureCollisionCheak(Object* obj, const std::string tag)
{
	for (auto& iter : m_Objects)
	{
		if (iter->m_Tag != "Player" && iter->m_Tag != "Monster")
		{
			if (iter->m_Tag != tag)
			{
				
				if (IntersectRect(&rcc, &obj->m_Collision, &iter->m_Collision))
				{
					obj->OnCollision(iter, iter->m_Tag);
					iter->OnCollision(obj, obj->m_Tag);
				}
			}
		}
	}
}

void ObjectMgr::DeleteObject(std::string tag)
{
	for (auto& iter : m_Objects)
	{
		if (iter->m_Tag == tag)
		{
			iter->SetDestroy(true);
		}
	}
}