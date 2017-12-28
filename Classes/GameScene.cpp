#include "GameScene.h"
#include "FishingJoyData.h"
#include "PersonalAudioEngine.h"
#include "GameMenuLayer.h"

GameScene::GameScene()
{
}

bool GameScene::init()
{
	do
	{
		CC_BREAK_IF(!CCScene::init());

		_backgroundLayer = BackgroundLayer::create();
		CC_BREAK_IF(!_backgroundLayer);
		this->addChild(_backgroundLayer);

		_fishLayer = FishLayer::create();
		CC_BREAK_IF(!_fishLayer);
		this->addChild(_fishLayer);

		_cannonLayer = CannonLayer::create();
		CC_BREAK_IF(!_cannonLayer);
		this->addChild(_cannonLayer);

		_panelLayer = PanelLayer::create();
		CC_BREAK_IF(!_panelLayer);
		this->addChild(_panelLayer);

		_menuLayer = MenuLayer::create(); 
		CC_BREAK_IF(!_menuLayer);
		CC_SAFE_RETAIN(_menuLayer); 

		_touchLayer = TouchLayer::create();
		CC_BREAK_IF(!_touchLayer);
		this->addChild(_touchLayer);

		int gold = FishingJoyData::sharedFishingJoyData()->getGold();

		_panelLayer->getGoldCounter()->setNumber(gold);

		this->scheduleUpdate();

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI_GameMenuLayer-ipadhd.plist");

		_pauseSprite = CCSprite::createWithSpriteFrameName("ui_button_02.png");
		 
		CCMenuItemSprite* pause = CCMenuItemSprite::create(_pauseSprite, 
			_pauseSprite, this, menu_selector(GameScene::pause));

		_menu = CCMenu::create(pause, NULL);
		this->addChild(_menu);

		CCSize pauseSize = pause->getContentSize();
		_menu->setPosition(CCPointMake(winSize.width-pauseSize.width, winSize.height - pauseSize.height));
		
		FishingJoyData::sharedFishingJoyData()->setMusic(true);
		PersonalAudioEngine::sharedEngine()->playBackgroundMusic("music_1.mp3", true);
		return true;
	} while (0);
	return false;
}

GameScene::~GameScene()
{
	CC_SAFE_RELEASE(_menuLayer);
}

void GameScene::cannonAimAt(CCPoint target)
{
	_cannonLayer->aimAt(target);
}

void GameScene::cannonShootTo(CCPoint target)
{
	int type = _cannonLayer->getWeapon()->getCannon()->getType();
	int cost = (type+1) * 1;
	int currentGold = FishingJoyData::sharedFishingJoyData()->getGold();
	if(currentGold >= cost && _cannonLayer->shootTo(target)){
		PersonalAudioEngine::sharedEngine()->playEffect("bgm_fire.aif");
		this->alterGold(-cost);
	}
}

bool GameScene::checkOutCollisionBetweenFishesAndBullet(Bullet* bullet)
{
	CCPoint bulletPos = bullet->getCollosionPoint();
	CCArray* fishArray = _fishLayer->getFishArray();
	CCObject* obj = NULL;
	CCARRAY_FOREACH(fishArray, obj)
	{
		Fish* fish =(Fish*)obj;
		if(fish->isRunning() && fish->getCollisionArea().containsPoint(bulletPos))
		{
			bullet->end();
			return true;
		}
	}
	return false;
}

void GameScene::checkOutCollision()
{
	CCArray* bullets = _cannonLayer->getWeapon()->getBullets();
	CCObject* obj = NULL;
	CCARRAY_FOREACH(bullets, obj)
	{
		Bullet* bullet = (Bullet*)obj;
		if(bullet->isVisible())
		{
			if(checkOutCollisionBetweenFishesAndBullet(bullet))
			{
				checkOutCollisionBetweenFishesAndFishingNet(bullet);
			}
		}
	}	
}

void GameScene::update(float delta)
{
	checkOutCollision();
}

void GameScene::fishWillBeCaught(Fish* fish)
{
	float weaponPercents[k_Cannon_Count] = { 0.3f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f, 1.1f };
	float fishPercents[	k_Fish_Type_Count] = { 1.0f, 0.9f, 0.8f, 0.7f, 0.6f, 0.5f, 0.4f };
	int cannonType = _cannonLayer->getWeapon()->getCannonType();
	int fishType = fish->getType();
	if(CCRANDOM_0_1() < 1.1)
	{
		fish->beCaught();
		PersonalAudioEngine::sharedEngine()->playEffect("bgm_net.mp3");
		int reward = (fishType+1)*10;
		this->alterGold(reward);
	}
}

void GameScene::checkOutCollisionBetweenFishesAndFishingNet(Bullet* bullet)
{
	Weapon* weapon = _cannonLayer->getWeapon();
	CCRect rect = weapon->getCollisionArea(bullet);
	CCArray* fishArray = _fishLayer->getFishArray();
	CCObject* obj = NULL;
	CCARRAY_FOREACH(fishArray, obj)
	{
		Fish* fish = (Fish*)obj;
		if(fish->isRunning() && rect.intersectsRect(fish->getCollisionArea()))
		{
			fishWillBeCaught(fish);
		}
	}
}

void GameScene::alterGold(int delta)
{
	FishingJoyData::sharedFishingJoyData()->alterGold(delta);
	_panelLayer->getGoldCounter()->setNumber(FishingJoyData::sharedFishingJoyData()->getGold());
}

void GameScene::scheduleTimeUp()
{
	this->alterGold(200);
}

void GameScene::pause(CCObject *sender)
{
	PersonalAudioEngine::sharedEngine()->pauseBackgroundMusic();

	PersonalAudioEngine::sharedEngine()->playEffect("bgm_button.aif");

	this->operateAllSchedulerAndActions(this, k_Operate_Pause);

	_touchLayer->setTouchEnabled(false);

	_menu->setTouchEnabled(false);

	this->addChild(_menuLayer);
}

void GameScene::resume()
{
	this->operateAllSchedulerAndActions(this, k_Operate_Resume);

	FishingJoyData::sharedFishingJoyData()->getMusic() ? PersonalAudioEngine::sharedEngine()->resumeBackgroundMusic() : PersonalAudioEngine::sharedEngine()->pauseBackgroundMusic();

	this->removeChild(_menuLayer, false);

	_touchLayer->setTouchEnabled(true);

	_menu->setTouchEnabled(true);
}

void GameScene::music()
{
	PersonalAudioEngine::sharedEngine()->setBackgroundMusic(FishingJoyData::sharedFishingJoyData()->getMusic());
}

void GameScene::reset()
{
	FishingJoyData::sharedFishingJoyData()->reset();

	_panelLayer->getGoldCounter()->setNumber(FishingJoyData::sharedFishingJoyData()->getGold());

	this->_cannonLayer->getWeapon()->getCannon()->setType(k_Cannon_Type_1);

	this->resume();
}

void GameScene::mainMenu()
{
	PersonalAudioEngine::sharedEngine()->pauseBackgroundMusic();
	CCDirector::sharedDirector()->replaceScene(GameMenuLayer::scene());
}

void GameScene::operateAllSchedulerAndActions(CCNode* node, OperateFlag flag)
{
	if(node->isRunning()){
		switch (flag) {
		case k_Operate_Pause:
			node->pauseSchedulerAndActions();
			break;
		case k_Operate_Resume:
			node->resumeSchedulerAndActions();
			break;
		default:
			break;
		}

		CCArray* children = node->getChildren();

		if(children != NULL && children->count()>0){

			CCObject* item;

			CCARRAY_FOREACH(children, item){
				CCNode* child = (CCNode*)item;
				this->operateAllSchedulerAndActions(child, flag);
			}
		}
	}
}
