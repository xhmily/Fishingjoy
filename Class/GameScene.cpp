#include "GameScene.h"
#include "CannonLayer.h"

GameScene::GameScene()
{
}

bool GameScene::init()
{
	do
	{
		CC_BREAK_IF(!CCScene::init());
		preloadResources();
		//因为~GameScene()中需要CC_SAFE_RELEASE(_menuLayer)， 如果其它层创建失败，_menuLayer将不创建，
		//所以_menuLayer要先于其他层创建， 否则将报 "reference count greater than 0" 错误
		_menuLayer = MenuLayer::create(); 
		CC_BREAK_IF(!_menuLayer);
		CC_SAFE_RETAIN(_menuLayer); 
		_backgroundLayer = BackgroundLayer::create();
		CC_BREAK_IF(!_backgroundLayer);
		addChild(_backgroundLayer);
		_fishLayer = FishLayer::create();
		CC_BREAK_IF(!_fishLayer);
		addChild(_fishLayer);
		CannonLayer* cannonLayer = CannonLayer::create();
		addChild(cannonLayer);
		return true;
	} while (0);
	return false;
}

void GameScene::preloadResources(void)
{
	CCSpriteFrameCache* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	//修改以下plist文件， 删除key中的中文， 否则spriteFrameByName函数无法找到Frame，将返回NULL
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Large-ipadhd.plist");		//修改metadata->realTextureFileName->FishActor-Large-ipadhdhd.png, textureFileName->FishActor-Large-ipadhd.png
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Marlin-ipadhd.plist");		//修改metadata->realTextureFileName->FishActor-Marlin-ipadhdhd.png, textureFileName->FishActor-Marlin-ipadhd.png
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Shark-ipadhd.plist");		//同上
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Small-ipadhd.plist");		//同上
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Mid-ipadhd.plist");			//同上
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
	
}

GameScene::~GameScene()
{
	CC_SAFE_RELEASE(_menuLayer);
}
