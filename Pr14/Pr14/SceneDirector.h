#pragma once
class SceneDirector : public Singleton<SceneDirector>
{
	Scene* m_CurrentScene;
public:

	void ChangeScene(Scene* newScene);
	
	void Update(float deltatime, float time);

	void Render();

};

