#include "Scene.h"

Scene::Scene(Scenes type)
	:type(type)
{
}

Scene::~Scene()
{
}

void Scene::Update(float dt)
{
	for (const auto& obj : objList)
	{
		if (obj->GetActive())
		{
			obj->Update(dt);
		}
	}
	for (const auto& uiobj : uiObjList)
	{
		if (uiobj->GetActive())
		{
			uiobj->Update(dt);
		}
	}
}

void Scene::Draw(RenderWindow& window)
{
	for (const auto& obj : objList)
	{
		if (obj->GetActive())
		{
			obj->Draw(window);
		}
	}
	for (const auto& uiobj : uiObjList)
	{
		if (uiobj->GetActive())
		{
			uiobj->Draw(window);
		}
	}
}

