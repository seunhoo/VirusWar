#pragma once
class Scene
{
public:
	Scene();
	~Scene();

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update(float deltatime, float time) = 0;
	virtual void Render() =0;
};

