#include "GameMenuLayer.h"

GameMenuLayer::GameMenuLayer(void)
{
}

CCScene* GameMenuLayer::scene(void)
{
	CCScene* scene = CCScene::create();
	GameMenuLayer* gameMenuLayer = GameMenuLayer::create();
	scene->addChild(gameMenuLayer);
	return scene;
}

bool GameMenuLayer::init()
{
	do 
	{
		if(!CCLayer::init())
		{
			return false;
		}
		CCSprite* bgSprite = CCSprite::create("ui_background_normal-ipadhd.png");
		CC_BREAK_IF(!bgSprite);
		this->addChild(bgSprite);
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		bgSprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		CCSprite* titleSprite = CCSprite::create("main_ui_title_cn-ipadhd.png");
		CC_BREAK_IF(!titleSprite);
		this->addChild(titleSprite);
		titleSprite->setPosition(ccp(winSize.width/2, winSize.height * 0.75));
		this->createMenu();
		return true;
	} while (0);
	return false;
}

void GameMenuLayer::createMenu(void)
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI_GameStartMenuLayer-ipadhd.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI_GameMenuText_cn-ipadhd.plist");
	
	//"开始游戏"按钮正常
	//"开始游戏"按钮正常
	CCSprite* startNormalBgSprite = CCSprite::createWithSpriteFrameName("ui_button_box02_02.png");
	CCSprite* startNormalTextSprite = CCSprite::createWithSpriteFrameName("ui_2p_010.png");

	CCSize startNormalBgSize = startNormalBgSprite->getContentSize();

	startNormalBgSprite->addChild(startNormalTextSprite);
	startNormalTextSprite->setPosition(ccp(startNormalBgSize.width / 2, startNormalBgSize.height / 2 + 20));
	
	//"开始游戏"按钮选中
	CCSprite* startSelectedBgSprite = CCSprite::createWithSpriteFrameName("ui_button_box02_01.png");
	CCSprite* startSelectedTextSprite = CCSprite::createWithSpriteFrameName("ui_2p_010.png");

	startSelectedBgSprite->addChild(startSelectedTextSprite);
	startSelectedTextSprite->setPosition(ccp(startNormalBgSize.width / 2, startNormalBgSize.height / 2 + 20));

	CCMenuItemSprite* startMenuItem = CCMenuItemSprite::create(startNormalBgSprite, 
		startSelectedBgSprite, this, menu_selector(GameMenuLayer::menuCallbackStartGame));

	//"选择场景"按钮正常
	CCSprite* sceneNormalBgSprite = CCSprite::createWithSpriteFrameName("ui_button_box01_02.png");
	CCSprite* sceneNormalTextSprite = CCSprite::createWithSpriteFrameName("button_other_014.png");

	CCSize sceneNormalBgSize = sceneNormalBgSprite->getContentSize();

	sceneNormalBgSprite->addChild(sceneNormalTextSprite);
	sceneNormalTextSprite->setPosition(ccp(sceneNormalBgSize.width / 2, sceneNormalBgSize.height / 2 + 3));

	//"选择场景"按钮选中
	CCSprite* sceneSelectedBgSprite = CCSprite::createWithSpriteFrameName("ui_button_box01_01.png");
	CCSprite* sceneSelectedTextSprite = CCSprite::createWithSpriteFrameName("button_other_014.png");

	sceneSelectedBgSprite->addChild(sceneSelectedTextSprite);
	sceneSelectedTextSprite->setPosition(ccp(sceneNormalBgSize.width / 2, sceneNormalBgSize.height / 2 + 3));

	CCMenuItemSprite* sceneMenuItem = CCMenuItemSprite::create(sceneNormalBgSprite, 
		sceneSelectedBgSprite, this, menu_selector(GameMenuLayer::menuCallbackStartGame));

	CCMenu* menu = CCMenu::create(startMenuItem, sceneMenuItem, NULL);
	this->addChild(menu);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	menu->setPosition(ccp(winSize.width / 2, winSize.height * 0.4));
	menu->alignItemsVerticallyWithPadding(50);
}

void GameMenuLayer::menuCallbackSelectScene(CCObject* sender)
{

}

void GameMenuLayer::menuCallbackStartGame(CCObject* sender)
{

}

GameMenuLayer::~GameMenuLayer()
{
}