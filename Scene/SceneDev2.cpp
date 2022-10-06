#include "SceneDev2.h"
#include "SceneMgr.h"
#include "../FrameWork/InputMgr.h"
#include "../FrameWork/ResourceMgr.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"

SceneDev2::SceneDev2()
	:Scene(Scenes::Dev2)
{
	SpriteObj* obj = new SpriteObj();
	obj->SetTexture(*RESOURCE_MGR->GetTexture("graphics/player5.png"));
	objList.push_back(obj);
	string scenename("SceneDev2");
	TextObj* text = new TextObj();
	text->SetText(scenename);
	uiObjList.push_back(text);
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Enter()
{

}

void SceneDev2::Exit()
{
}

void SceneDev2::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Space))
	{
		SCENE_MGR->ChangeScene(Scenes::Dev1);
	}
	Scene::Update(dt);
}

void SceneDev2::Draw(RenderWindow& window)
{
	Scene::Draw(window);
}
