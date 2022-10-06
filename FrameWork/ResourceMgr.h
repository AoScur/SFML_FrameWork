#pragma once

#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

#include "../3rd/Singleton.h"
#include "../3rd/rapidcsv.h"

using namespace std;
using namespace sf;

/// <summary>
/// 싱글턴
/// 리소스 로드/릴리즈
/// Get()
/// </summary>

enum class ResourceTypes
{
	Texture,
	Font,
	SoundBuffer,
};

class ResourceMgr : public Singleton<ResourceMgr>
{

private:
	map<string, Texture*> texMap;
	map<string, Font*> fontMap;
	map<string, SoundBuffer*> soundMap;


public:
	ResourceMgr();
	~ResourceMgr();

	static string FilePath;

	void ReleaseAll();

	bool LoadAll();
	bool Load(ResourceTypes type, string id);

	bool LoadTecture(string id);
	bool LoadFont(string id);
	bool LoadSoundBuffer(string id);

	Texture* GetTexture(string id);
	Font* GetFont(string id);
	SoundBuffer* GetSoundBuffer(string id);
};
#define RESOURCE_MGR (ResourceMgr::GetInstance())
