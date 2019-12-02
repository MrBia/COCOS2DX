#include "MenuSound.h"
#include"SettingScene.h"


cocos2d::Scene * MenuSound::createMenuSoundScene()
{
	return MenuSound::create();
}

bool MenuSound::init()
{
	if (!Scene::init()) {
		return false;
	}

	// slider
	static auto slider = ui::Slider::create();
	slider->loadBarTexture("slider_bar_bg.png");
	slider->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_pressed.png", "slider_ball_disable");
	slider->loadProgressBarTexture("slider_bar_pressed.png");
	slider->setPercent(10);
	slider->setPosition(Vec2(200, 140));
	slider->addClickEventListener([](Ref* event) {
		log("slider: %d", slider->getPercent());
	});
	this->addChild(slider);

	// checkbox
	auto checkbox = ui::CheckBox::create("checkbox_normal.png", "checkbox_pressed.png", "checkbox_checked_disable.png",
		"checkbox_normal_disable.png", "checkbox_checked.png");
	checkbox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN: {
			// do something
			break;
		}
		case ui::Widget::TouchEventType::ENDED: {
			// do something
			break;
		}
		default: break;
	}
	});
	checkbox->setScale(0.5);
	checkbox->setPosition(Vec2(200, 100));
	this->addChild(checkbox);

	// return
	auto btn_return = ui::Button::create("resume_normal.png", "resume_pressed.png");
	btn_return->setPosition(Vec2(10, 10));
	btn_return->setScale(0.3);
	btn_return->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN: {
			Director::getInstance()->replaceScene(SettingScene::createSettingScene());
			break;
		}
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});
	this->addChild(btn_return);

	return true;
}

MenuSound::MenuSound()
{
}


MenuSound::~MenuSound()
{
}
