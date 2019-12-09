#include "ResourceManager.h"


ResourceManager* ResourceManager::instance = NULL;

ResourceManager::ResourceManager()
{

}


ResourceManager * ResourceManager::getInstance()
{
	if (!instance) {
		instance = new ResourceManager;
	}
	return instance;
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::Init(const std::string path)
{
	this->m_dataFolderPath = path;
	load(m_dataFolderPath);
}

void ResourceManager::load(string fileName)
{
	std::string s = FileUtils::getInstance()->getStringFromFile(fileName);
	
	std::vector<std::string> arr_source = split(s, "\r\n");
	
	for (size_t i = 0; i < arr_source.size(); i++) {
	
		std::vector<std::string> arr_sprite = split(arr_source[i], " ");
		if (arr_sprite[0] == "#SPRITE") {
			//Sprite* sprite;
			int num_sprite = atoi(arr_sprite[1].c_str());
			while (num_sprite > 0) {
				i++;                  // id
				int id = get_ID(arr_source[i]);

				i++;                  // path
				string path = get_Path(arr_source[i]);

				// create sprite
				auto sprite = Sprite::create(path);
				sprite->retain();

				// insert map
				m_sprites.insert(pair<int, Sprite*>(id, sprite));

				num_sprite--;
			}
		}
		else if (arr_sprite[0] == "#BUTTON") {
			int num_sprite = atoi(arr_sprite[1].c_str());
			while (num_sprite > 0) {
				i++;                  // id
				int id = get_ID(arr_source[i]);
				
				i++;                  // path1
				string path1 = get_Path(arr_source[i]);
				
				i++;                  // path2
				string path2 = get_Path(arr_source[i]);
				
				// create button
				auto button = ui::Button::create(path1, path2);
				button->retain();

				// insert map
				m_buttons.insert(pair<int, ui::Button*>(id, button));

				num_sprite--;
			}
		}
		else if (arr_sprite[0] == "#FONT") {
			int num_sprite = atoi(arr_sprite[1].c_str());
			while (num_sprite > 0) {
				i++;                  // id
				int id = get_ID(arr_source[i]);
				//log("%d", id);
				i++;                  // path
				string path = get_Path(arr_source[i]);
				//log("%s", path.c_str());


				num_sprite--;
			}
		}
		else if (arr_sprite[0] == "#UISPRITE") {
			int num_sprite = atoi(arr_sprite[1].c_str());
			while (num_sprite > 0) {
				i++;                  // id
				int id = get_ID(arr_source[i]);
				
				i++;                  // path
				string path = get_Path(arr_source[i]);

				// create sprite
				auto sprite = ui::LoadingBar::create(path);
				sprite->retain();

				// insert map
				m_loadings.insert(pair<int, ui::LoadingBar*>(id, sprite));

				num_sprite--;
			}
		}
		else if (arr_sprite[0] == "#ANIMATION") {
			int num_sprite = atoi(arr_sprite[1].c_str());

			while (num_sprite > 0) {
				i++;                  // id
				int id = get_ID(arr_source[i]);

				i++;                  // path
				string path1 = get_Path(arr_source[i]);
				i++;                  // path
				string path2 = get_Path(arr_source[i]);
				i++;                  // path
				string path3 = get_Path(arr_source[i]);
				i++;                  // path
				string path4 = get_Path(arr_source[i]);
				i++;                  // path
				string path5 = get_Path(arr_source[i]);
				i++;                  // path
				string path6 = get_Path(arr_source[i]);
				i++;                  // path
				string path7 = get_Path(arr_source[i]);
				i++;                  // path
				string path8 = get_Path(arr_source[i]);

				// create sprite
				auto sprite = Sprite::create();
				
				cocos2d::Vector<cocos2d::SpriteFrame*> animateFrames;
				animateFrames.pushBack(SpriteFrame::create(path1, Rect(0, 0, 128, 128)));
				animateFrames.pushBack(SpriteFrame::create(path2, Rect(0, 0, 128, 128)));
				animateFrames.pushBack(SpriteFrame::create(path3, Rect(0, 0, 128, 128)));
				animateFrames.pushBack(SpriteFrame::create(path4, Rect(0, 0, 128, 128)));
				animateFrames.pushBack(SpriteFrame::create(path5, Rect(0, 0, 128, 128)));
				animateFrames.pushBack(SpriteFrame::create(path6, Rect(0, 0, 128, 128)));
				animateFrames.pushBack(SpriteFrame::create(path7, Rect(0, 0, 128, 128)));
				animateFrames.pushBack(SpriteFrame::create(path8, Rect(0, 0, 128, 128)));

				auto animation = Animation::createWithSpriteFrames(animateFrames, 0.1f);
				auto animate = Animate::create(animation);
				auto repeatForeverAnimate = RepeatForever::create(animate);
				repeatForeverAnimate->retain();

				// insert map
				m_spriteAnimation.insert(pair<int, RepeatForever*>(id, repeatForeverAnimate));

				num_sprite--;
			}
		}
		else if (arr_sprite[0] == "#SOUND") {
			int num_sprite = atoi(arr_sprite[1].c_str());

			while (num_sprite > 0) {
				i++;                  // id
				int id = get_ID(arr_source[i]);

				i++;                  // path
				string path = get_Path(arr_source[i]);

				auto sound = CocosDenshion::SimpleAudioEngine::getInstance();
				//sound->playEffect(path.c_str());

				m_sounds.insert(pair<int, CocosDenshion::SimpleAudioEngine*>(id, sound));

				num_sprite--;
			}
		}
	}
}

Sprite * ResourceManager::loadSpriteById(int id)
{
	return m_sprites.at(id);
}

ui::Button * ResourceManager::getButtonById(int id)
{
	return m_buttons.at(id);
}

Label * ResourceManager::getLabelById(int id)
{
	return m_labels.at(id);
}

ui::LoadingBar * ResourceManager::getLoadingBarById(int id)
{
	return m_loadings.at(id);
}

RepeatForever * ResourceManager::getSpriteAnimationById(int id)
{
	return m_spriteAnimation.at(id);
}

CocosDenshion::SimpleAudioEngine * ResourceManager::getSoundById(int id)
{
	return m_sounds.at(id);
}

std::vector<std::string> ResourceManager::split(std::string str1, std::string str2)
{

	std::vector<std::string> arr;
	char *c = const_cast<char*>(str1.c_str());
	char* s1 = strtok(c, str2.c_str());

	while (s1 != NULL) {
		arr.push_back(s1);
		s1 = strtok(NULL, str2.c_str());
	}
	

	return arr;
}

int ResourceManager::get_ID(string s)
{
	int id;
	std::vector<std::string> arr_id = split(s, " ");
	id = atoi(arr_id[1].c_str());

	return id;
}

string ResourceManager::get_Path(string s)
{
	string path = "";
	std::vector<std::string> arr_path = split(s, " ");
	path = arr_path[1];
	//log("%s", path.c_str());
	return path;
}
