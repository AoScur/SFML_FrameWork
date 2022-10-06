#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class FrameWork
	
{
protected:
	RenderWindow window;
	Vector2i windowSize;

	Clock clock;
	Time deltaTime;
	float timeScale;

public:
	FrameWork(int width, int height);
	virtual ~FrameWork();

	float GetDT() const;
	float GetRealDT() const;

	bool Init();
	bool Do();
};

