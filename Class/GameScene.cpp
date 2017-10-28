#include "GameScene.h"

GameScene::GameScene()
{
}

bool GameScene::init()
{
	do
	{
		if (!CCScene::init())
		{
			break;
		}
		backgroundLayer = BackgroundLayer::create();
		CC_BREAK_IF(!backgroundLayer);
		this->addChild(backgroundLayer);
		fishLayer = FishLayer::create();
		CC_BREAK_IF(!fishLayer);
		this->addChild(fishLayer);
		menuLayer = MenuLayer::create();
		CC_BREAK_IF(!menuLayer);
		CC_SAFE_RETAIN(menuLayer);
		return true;
	} while (0);
	return false;
}

GameScene::~GameScene()
{
	CC_SAFE_RELEASE_NULL(menuLayer);
}
