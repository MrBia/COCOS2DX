#include "MenuAbout.h"



cocos2d::Scene * MenuAbout::createMenuAboutScene()
{
	return MenuAbout::create();
}

bool MenuAbout::init()
{
	if (!Scene::init()) {
		return false;
	}

	auto scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(300, 200));
	scrollView->setInnerContainerSize(Size(1280, 2500));
	scrollView->setBounceEnabled(true);
	scrollView->setPosition(Vec2(100, 100));

	for (int i = 0; i < 10; i++) {
		auto label = Label::createWithSystemFont("line ", "Arial", 20);
		label->setPosition(Vec2(scrollView->getContentSize().width / 2, i* 20));
		scrollView->addChild(label);
	}

	this->addChild(scrollView);

	
	return true;
}

MenuAbout::MenuAbout()
{
}


MenuAbout::~MenuAbout()
{
}
