#include "TextObj.h"
#include "../FrameWork/ResourceMgr.h"
#include "../GameObject/SpriteObj.h"

TextObj::TextObj()
{
	//font.loadFromFile("fonts/MaruBuri-Bold.ttf");
	scenename.setFont(*RESOURCE_MGR->GetFont("fonts/MaruBuri-Bold.ttf"));
	scenename.setCharacterSize(30);
	scenename.setFillColor(Color::Magenta);
	scenename.setPosition(1100, 0);
}

TextObj::~TextObj()
{
}

void TextObj::Init()
{
	
}

void TextObj::Update(float dt)
{
}

void TextObj::Draw(RenderWindow& window)
{
	window.draw(scenename);
}

void TextObj::SetText(string tex)
{
	scenename.setString(tex);
}
