#include "LoadingLayer.h"
#include "GameScene.h"
#include "PersonalAudioEngine.h"
#include "FishingJoyData.h"
LoadingLayer::LoadingLayer(void)
{
	_loadedSp = 0;

	_progressBar = NULL;

	_progressFg = NULL;
}

CCScene* LoadingLayer::scene(void)
{
	CCScene* scene = CCScene::create();
	LoadingLayer* loadingLayer = LoadingLayer::create();
	scene->addChild(loadingLayer);
	return scene;
}


bool LoadingLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite* background = CCSprite::create("loading_1-ipadhd.png");
	background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.6));
	this->addChild(background);

	this->initProgressBar();

	this->scheduleOnce(schedule_selector(LoadingLayer::cacheInit), 0.5f);

	return true;
}


void LoadingLayer::initProgressBar()
{
	CCSprite* progressBg = CCSprite::create("loading_4-ipadhd.png");
	_progressFg = CCLabelTTF::create("0/100", "Thonburi", 65);

	_progressFg->setColor(ccc3(255, 255, 255));

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	_progressBar = ProgressBar::create(this, CCSprite::create("loading_5-ipadhd.png"));
	
	_progressBar->setBackground(progressBg);

	_progressBar->setForeground(_progressFg);

	_progressBar->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.25));
	
	_progressBar->setSpeed(100.0f);

	this->addChild(_progressBar);
}

void LoadingLayer::progressPercentageSetter(float percentage)
{
	CCString* str = CCString::createWithFormat("%d/100", (int)percentage);
	
	_progressFg->setString(str->getCString());
}

void LoadingLayer::loadingFinished()
{
	CCScene* gameScene = GameScene::create();
	CCDirector::sharedDirector()->replaceScene(gameScene);
}

void LoadingLayer::cacheInit(float delta)
{
	CCSpriteFrameCache* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Large-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Marlin-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Shark-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Small-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Mid-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("cannon-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("Item-chaojiwuqi-ipadhd.plist");

	CCTextureCache *textureCache = CCTextureCache::sharedTextureCache();
	textureCache->addImage("ui_button_63-ipadhd.png");
	textureCache->addImage("ui_button_65-ipadhd.png");

	char str[][50] = { "SmallFish", "Croaker", "AngelFish", "Amphiprion", "PufferS", 
		"Bream", "Porgy", "Chelonian", "Lantern", "Ray", "Shark", "GoldenTrout", "GShark", 
		"GMarlinsFish", "GrouperFish", "JadePerch", "MarlinsFish", "PufferB" };
	for (int i = 0; i < 18; i++)
	{
		CCArray* array = CCArray::createWithCapacity(10);
		for (int j = 0; j < 10; j++)
		{
			CCString* spriteFrameName = CCString::createWithFormat("%s_actor_%03d.png", str[i], j + 1);
			CCSpriteFrame* spriteFrame = spriteFrameCache->spriteFrameByName(spriteFrameName->getCString());
			CC_BREAK_IF(!spriteFrame);
			array->addObject(spriteFrame);
		}
		if (array->count() == 0)
		{
			continue;
		}
		CCAnimation* animation = CCAnimation::createWithSpriteFrames(array, 0.15f);
		CCString* animationName = CCString::createWithFormat("fish_animation_%02d", i + 1);
		CCAnimationCache::sharedAnimationCache()->addAnimation(animation, animationName->getCString());
	}

	PersonalAudioEngine::sharedEngine();
	FishingJoyData::sharedFishingJoyData()->setMusic(true);

	_progressBar->progressTo();
}
