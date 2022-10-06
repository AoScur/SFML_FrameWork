#include "SceneDev1.h"
#include "SceneMgr.h"
#include "../FrameWork/InputMgr.h"
#include "../FrameWork/ResourceMgr.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/SoundMgr.h"

SceneDev1::SceneDev1()
	:Scene(Scenes::Dev1)
{
	SpriteObj* obj = new SpriteObj();
	obj->SetTexture(*RESOURCE_MGR->GetTexture("graphics/player3.png"));
	objList.push_back(obj);
	
	TextObj* text = new TextObj();
	text->SetText("SceneDev1");
	uiObjList.push_back(text);

}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Enter()
{
	SOUND_MGR->Play("sounds/Hennesis.ogg", true);
}

void SceneDev1::Exit()
{
	SOUND_MGR->StopAll();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Return))
	{
		SOUND_MGR->Play("sounds/select.wav");
	}
	if (InputMgr::GetKeyDown(Keyboard::Space))
	{
		SCENE_MGR->ChangeScene(Scenes::Dev2);
	}

	Scene::Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
	Scene::Draw(window);
}
