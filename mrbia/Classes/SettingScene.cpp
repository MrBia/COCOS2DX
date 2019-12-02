#include "SettingScene.h"


SettingScene::SettingScene()
{
}


SettingScene::~SettingScene()
{
}

cocos2d::Scene * SettingScene::createSettingScene()
{
	return SettingScene::create();
}

bool SettingScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	// Menu Item Sound
	itemSound = MenuItemFont::create("Sound", CC_CALLBACK_1(SettingScene::menuSound, this));
	itemSound->setPosition(200, 300);

	// Menu Item About
	itemAbout = MenuItemFont::create("About", CC_CALLBACK_1(SettingScene::menuAbout, this));
	itemAbout->setPosition(200, 250);

	// Menu
	myMenu = Menu::create(itemSound, itemAbout, nullptr);
	myMenu->setPosition(0, 0);
	this->addChild(myMenu);

	// slider
	slider = ui::Slider::create();
	slider->loadBarTexture("slider_bar_bg.png");
	slider->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_pressed.png", "slider_ball_disable");
	slider->loadProgressBarTexture("slider_bar_pressed.png");
	slider->setPercent(50);
	slider->setPosition(Vec2(300, 300));
	slider->addClickEventListener([](Ref* event) {
		//log("slider: %d", slider->getPercent());
	});
	this->addChild(slider);
	slider->setVisible(false);

	// checkbox
	checkbox = ui::CheckBox::create("checkbox_normal.png", "checkbox_pressed.png", "checkbox_checked.png"
		,"checkbox_checked_disable.png", "checkbox_normal_disable.png");

	checkbox->addTouchEventListener([&](Ref* render, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN: {
			
			break;
		}
		case cocos2d::ui::Widget::TouchEventType::ENDED: {
			break;
		}
		default:
			break;
		}
	});
	checkbox->setScale(0.5);
	checkbox->setPosition(Vec2(300, 250));
	this->addChild(checkbox);
	checkbox->setVisible(false);

	// scroll view
	scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(300, 200));
	scrollView->setInnerContainerSize(Size(1280, 2500));
	scrollView->setBounceEnabled(true);
	scrollView->setPosition(Vec2(100, 100));

	for (int i = 0; i < 10; i++) {
		auto label = Label::createWithSystemFont("hao bia", "Arial", 20);
		label->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, i * 20));
		scrollView->addChild(label);
	}
	this->addChild(scrollView);
	scrollView->setVisible(false);

	// return
	btn_return = ui::Button::create("resume_normal.png", "resume_pressed.png");
	btn_return->setPosition(Vec2(10, 10));
	btn_return->setScale(0.2);
	btn_return->addTouchEventListener([&](Ref* render, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN: {
			myMenu->setVisible(true);
			btn_return->setVisible(false);
			btn_return_mainMenu->setVisible(true);
			slider->setVisible(false);
			checkbox->setVisible(false);
			scrollView->setVisible(false);
			break;
		}
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});
	this->addChild(btn_return);
	btn_return->setVisible(false);

	// return main menu
	btn_return_mainMenu = ui::Button::create("resume_normal.png", "resume_pressed.png");
	btn_return_mainMenu->setPosition(Vec2(10, 10));
	btn_return_mainMenu->setScale(0.2);
	btn_return_mainMenu->addTouchEventListener([&](Ref* render, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN: {
			Director::getInstance()->replaceScene(MainMenuScene::createMainMenu());
			break;
		}
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});
	this->addChild(btn_return_mainMenu);
	btn_return_mainMenu->setVisible(true);
	return true;
}

void SettingScene::menuSound(Ref * pSender)
{
	myMenu->setVisible(false);
	btn_return_mainMenu->setVisible(false);
	btn_return->setVisible(true);
	slider->setVisible(true);
	checkbox->setVisible(true);
}

void SettingScene::menuAbout(Ref * pSender)
{
	myMenu->setVisible(false);
	btn_return->setVisible(true);
	btn_return_mainMenu->setVisible(false);
	slider->setVisible(false);
	checkbox->setVisible(false);
	scrollView->setVisible(true);
}

