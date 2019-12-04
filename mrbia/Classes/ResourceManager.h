#pragma once
#include<iostream>
#include<string.h>
#include<map>
#include"cocos2d.h"
#include<ui\CocosGUI.h>
using namespace std;
USING_NS_CC;
class ResourceManager
{
private:
	std::string m_dataFolderPath;
	std::map<int, Sprite*> m_sprites;
	std::map<int, ui::Button*> m_buttons;
	std::map<int, Label*> m_labels;
	ResourceManager();
	static ResourceManager* instance;
public:
	static ResourceManager* getInstance();
	~ResourceManager();
	void Init(const std::string path);
	void load(string fileName);
	Sprite* loadSpriteById(int id);
	ui::Button* getButtonById(int id);
	Label* getLabelById(int id);

	std::vector<std::string> split(std::string str1, std::string str2);
	int get_ID(string s);
	string get_Path(string s);
};

