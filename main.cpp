#include <SFML/Graphics.hpp>
#include "FrameWork/FrameWork.h"

int main()
{
    FrameWork framework(1280, 720);
    framework.Init();
    framework.Do();

    return 0;
}