#include "moveMap.h"

bool left = false;
bool right = false;
bool up = false;
bool down = false;


moveMap::moveMap()
{
}


moveMap::~moveMap()
{
}

Scene * moveMap::createMap()
{
	//return moveMap::create();
	Scene* scene = Scene::create();
	moveMap* layer = moveMap::create();
	scene->addChild(layer);
	return scene;
}

bool moveMap::init()
{
	if (!CCLayer::init()) {
		return false;
	}

	map = new TMXTiledMap();
	map->initWithTMXFile("Map_1/MapGame.tmx");
	background = map->layerNamed("BackGround");
	ForeGround = map->layerNamed("ForeGround");
	meta = map->layerNamed("Meta");
	meta->setVisible(true);
	this->addChild(map);

	
	auto objectgroup = map->objectGroupNamed("Object");
	if (objectgroup == NULL) {
		log("no object grouppppppppppppppppppppppppppp");
		return false;
	}
	auto spawPoint = objectgroup->objectNamed("SpawnPoint");
	int x = spawPoint.at("x").asInt();
	int y = spawPoint.at("y").asInt();



	

	/*sprite = Sprite::create("1_IDLE_000.png");
	
	sprite->setAnchorPoint(Vec2(0.5f, 0.0f));
	auto rotateCallBack = [=](float value) {
		sprite->setRotation3D(Vec3(0, value, 0));
	};
	auto runAction = ActionFloat::create(0.5f, 0.0f, 180.f, rotateCallBack);
	sprite->runAction(runAction);

	sprite->setPosition(ccp(x, y));
	this->addChild(sprite);
	this->setViewPointCenter(sprite->getPosition());*/


	sprite = Sprite::create();
	sprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	sprite->setScale(0.1);
	Vector<SpriteFrame*> animateFrame;
	animateFrame.pushBack(SpriteFrame::create("Sprite/2_WALK_000.png", Rect(0, 0, 928, 1074)));
	animateFrame.pushBack(SpriteFrame::create("Sprite/2_WALK_001.png", Rect(0, 0, 928, 1074)));
	animateFrame.pushBack(SpriteFrame::create("Sprite/2_WALK_002.png", Rect(0, 0, 928, 1074)));
	animateFrame.pushBack(SpriteFrame::create("Sprite/2_WALK_003.png", Rect(0, 0, 928, 1074)));
	animateFrame.pushBack(SpriteFrame::create("Sprite/2_WALK_004.png", Rect(0, 0, 928, 1074)));

	auto animation = Animation::createWithSpriteFrames(animateFrame, 0.1f);
	auto animate = Animate::create(animation);
	sprite->runAction(RepeatForever::create(animate));
	sprite->setPosition(ccp(x, y));
	this->addChild(sprite);
	this->setViewPointCenter(sprite->getPosition());

	// keyboard
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(moveMap::OnKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(moveMap::OnKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);


	// touch
	//this->setTouchEnabled(true);
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(moveMap::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	// update
	scheduleUpdate();

	return true;
}

void moveMap::OnKeyPressed(EventKeyboard::KeyCode keycode, Event * event)
{

	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW: {
		left = true;
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: {
		right = true;
		break;
	}
	case EventKeyboard::KeyCode::KEY_UP_ARROW: {
		up = true;
		break;
	}
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW: {
		down = true;
		break;
	}
	default:
		break;
	}
}

void moveMap::OnKeyReleased(EventKeyboard::KeyCode keycode, Event * event)
{
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW: {
		left = false;
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: {
		right = false;
		break;
	}
	case EventKeyboard::KeyCode::KEY_UP_ARROW: {
		up = false;
		break;
	}

	case EventKeyboard::KeyCode::KEY_DOWN_ARROW: {
		down = false;
		break;
	}
	default:
		break;
	}
}

void moveMap::setViewPointCenter(CCPoint position)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	int x = MAX(position.x, winSize.width / 2);
	int y = MAX(position.y, winSize.height / 2);
	x = MIN(x, (map->getMapSize().width * this->map->getTileSize().width) - winSize.width / 2);
	y = MIN(y, (map->getMapSize().height * map->getTileSize().height) - winSize.height / 2);
	CCPoint actualPosition = ccp(x, y);

	CCPoint centerOfView = ccp(winSize.width / 2, winSize.height / 2);
	CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
	this->setPosition(viewPoint);
}


void moveMap::setPlayerPosition(CCPoint position)
{
	CCPoint tileCoord = this->tileCoorforposition(position);
	int tileGid = meta->tileGIDAt(tileCoord);
	if (tileGid) {


		auto properties = map->propertiesForGID(tileGid);
		if (!properties.isNull()) {
			ValueMap dict = properties.asValueMap();
			Value collision = dict["collidable"];
			if (!collision.isNull() && collision.asString() == "true") {
				return;
			}

			Value collectible = dict["collectable"];
			if (!collectible.isNull() && collectible.asString() == "true") {
				meta->removeTileAt(tileCoord);
				ForeGround->removeTileAt(tileCoord);
			}


		}
	}



	sprite->setPosition(position);
}

bool moveMap::OnTouchBegan(Touch * touch, Event * event)
{
	auto touchLocation = touch->getLocationInView();
	touchLocation = Director::sharedDirector()->convertToGL(touchLocation);
	touchLocation = this->convertToNodeSpace(touchLocation);

	CCPoint playerPos = sprite->getPosition();
	CCPoint diff = ccpSub(touchLocation, playerPos);

	if (abs(diff.x) > abs(diff.y)) {
		if (diff.x > 0) {
			playerPos.x += map->getTileSize().width;
		}
		else {
			playerPos.x -= map->getTileSize().width;
		}
	}
	else {
		if (diff.y > 0) {
			playerPos.y += map->getTileSize().height;
		}
		else {
			playerPos.y -= map->getTileSize().height;
		}
	}

	// safety check on the bounds of the map
	if (playerPos.x <= (map->getMapSize().width * map->getTileSize().width) &&
		playerPos.y <= (map->getMapSize().height * map->getTileSize().height) &&
		playerPos.y >= 0 &&
		playerPos.x >= 0)
	{
		this->setPlayerPosition(playerPos);
	}

	this->setViewPointCenter(sprite->getPosition());
 
	return false;
}

CCPoint moveMap::tileCoorforposition(CCPoint position)
{
	int x = position.x / map->getTileSize().width;
	int y = ((map->getMapSize().height * map->getTileSize().height) - position.y) / map->getTileSize().height;

	return ccp(x, y);
}

void moveMap::update(float deltaTime)
{
	static float k = 0;
	k += deltaTime;
	if (k >= 0.1) {
		CCPoint playerPos = sprite->getPosition();
		if (left) {
			playerPos.x -= map->getTileSize().width;
		}
		else if (right) {
			playerPos.x += map->getTileSize().width;
		}
		else if (up) {
			playerPos.y += map->getTileSize().height;
		}
		else if (down) {
			playerPos.y -= map->getTileSize().height;
		}

		if (playerPos.x <= (map->getMapSize().width * map->getTileSize().width) &&
			playerPos.y <= (map->getMapSize().height * map->getTileSize().height) &&
			playerPos.y >= 0 && playerPos.x >= 0)
		{
			this->setPlayerPosition(playerPos);
		}
		this->setViewPointCenter(sprite->getPosition());
		k = 0;
	}
}
