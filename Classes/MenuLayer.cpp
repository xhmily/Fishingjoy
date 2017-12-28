#include "MenuLayer.h"
#include "GameScene.h"
USING_NS_CC;

bool MenuLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}
	this->createBackground();
	this->createMenu();
	return true;
}

void MenuLayer::createBackground()
{
	CCLayerColor* colorBackground = CCLayerColor::create(ccc4(0, 0, 0, 128));
	this->addChild(colorBackground);
}

void MenuLayer::createMenu()
{
	int fontSize = 70;
	CCString* fontName = CCString::create("Thonburi");

	CCMenuItemLabel* resume = CCMenuItemLabel::create(CCLabelTTF::create("Resume", fontName->getCString(), fontSize), this, menu_selector(MenuLayer::resume));

	CCMenuItemLabel* reset = CCMenuItemLabel::create(CCLabelTTF::create("Reset", fontName->getCString(), fontSize), this, menu_selector(MenuLayer::reset));

	CCMenuItemLabel* mainMenu = CCMenuItemLabel::create(CCLabelTTF::create("Return to Menu", fontName->getCString(), fontSize), this, menu_selector(MenuLayer::mainMenu));

	CCMenuItemLabel* musicOn = CCMenuItemLabel::create(CCLabelTTF::create("Music On", fontName->getCString(), fontSize));
	CCMenuItemLabel* musicOff = CCMenuItemLabel::create(CCLabelTTF::create("Music Off", fontName->getCString(), fontSize));
	_music = CCMenuItemToggle::createWithTarget(this, menu_selector(MenuLayer::music), musicOff, musicOn, NULL);

	

	CCMenu* menu = CCMenu::create(resume, mainMenu, _music, reset, NULL);
	menu->alignItemsVerticallyWithPadding(10);
	this->addChild(menu);
}

void MenuLayer::resume(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->resume();
}

void MenuLayer::mainMenu(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->mainMenu();
}

void MenuLayer::music(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->music();
}

void MenuLayer::reset(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->reset();
}
