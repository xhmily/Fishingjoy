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
		CCSprite* bgSprite = CCSprite::create(STATIC_DATA_STRING("game_menu_background"));
		CC_BREAK_IF(!bgSprite);
		this->addChild(bgSprite);
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		bgSprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));
		CCSprite* titleSprite = CCSprite::create(STATIC_DATA_STRING("game_menu_title"));
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
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(STATIC_DATA_STRING("game_menu_ui"));
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(STATIC_DATA_STRING("game_menu_text"));
	
	//"开始游戏"按钮正常
	CCSprite* startNormalBgSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("game_menu_start_normal"));
	CCSprite* startNormalTextSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("game_menu_start_text"));

	CCSize startNormalBgSize = startNormalBgSprite->getContentSize();

	startNormalBgSprite->addChild(startNormalTextSprite);
	startNormalTextSprite->setPosition(ccp(startNormalBgSize.width / 2, startNormalBgSize.height / 2 + 20));
	
	//"开始游戏"按钮选中
	CCSprite* startSelectedBgSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("game_menu_start_selected"));
	CCSprite* startSelectedTextSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("game_menu_start_text"));

	startSelectedBgSprite->addChild(startSelectedTextSprite);
	startSelectedTextSprite->setPosition(ccp(startNormalBgSize.width / 2, startNormalBgSize.height / 2 + 20));

	CCMenuItemSprite* startMenuItem = CCMenuItemSprite::create(startNormalBgSprite, 
		startSelectedBgSprite, this, menu_selector(GameMenuLayer::menuCallbackStartGame));

	//"选择场景"按钮正常
	CCSprite* sceneNormalBgSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("game_menu_scene_normal"));
	CCSprite* sceneNormalTextSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("game_menu_scene_text"));

	CCSize sceneNormalBgSize = sceneNormalBgSprite->getContentSize();

	sceneNormalBgSprite->addChild(sceneNormalTextSprite);
	sceneNormalTextSprite->setPosition(ccp(sceneNormalBgSize.width / 2, sceneNormalBgSize.height / 2 + 3));

	//"选择场景"按钮选中
	CCSprite* sceneSelectedBgSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("game_menu_scene_selected"));
	CCSprite* sceneSelectedTextSprite = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("game_menu_scene_text"));

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