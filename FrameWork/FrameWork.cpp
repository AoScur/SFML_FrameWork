#include "FrameWork.h"
#include "InputMgr.h"
#include "../Scene/SceneMgr.h"
#include "ResourceMgr.h"
#include "../DataTable/DataTableMgr.h"
#include "../GameObject/SoundMgr.h"

FrameWork::FrameWork(int width, int height)
	:windowSize(width, height), timeScale(1.f)
{
	window.create(VideoMode(windowSize.x, windowSize.y), "Game");
}

FrameWork::~FrameWork()
{

}

float FrameWork::GetDT() const
{
    return deltaTime.asSeconds() * timeScale;
}

float FrameWork::GetRealDT() const
{
    return deltaTime.asSeconds();
}

bool FrameWork::Init()
{
    
    RESOURCE_MGR->LoadAll();
    //DATATABLE_MGR->Init();
    SCENE_MGR->Init();
    SOUND_MGR->Init();
    InputMgr::Init();
    return true;
}

bool FrameWork::Do()
{
    while (window.isOpen())
    {
        deltaTime = clock.restart();
        float dt = GetDT();

        InputMgr::ClearInput();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            InputMgr::UpdateInput(event);
        }
        SCENE_MGR->Update(dt);
        window.clear();
        //window.draw(shape);
        SCENE_MGR->Draw(window);
        window.display();
    }
    return true;
}
