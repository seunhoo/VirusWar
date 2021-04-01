#pragma once
enum class STAGE
{
	STAGEONE,
	STAGETWO,
	NONE
};
class SceneDirector : public Singleton<SceneDirector>
{
	Scene* m_CurrentScene;

public:

	STAGE m_Stage;
	
	SceneDirector();

	void ChangeScene(Scene* newScene);
	
	void Update(float deltatime, float time);

	void Render();

};

