#pragma once
#include "Object.h"
class TextObj : public Object
{
protected:
	//Font font;
	Text scenename;
public:
	TextObj();
	virtual ~TextObj();

	virtual void Init() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	void SetText(string tex);
	
};

