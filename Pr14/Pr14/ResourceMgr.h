#pragma once
class Texture;
class ResourceMgr : public Singleton<ResourceMgr>
{
public:
	std::map<std::wstring, Texture*>m_TextureMap;

public:

	Texture* Create(std::wstring fileName);
};

