#include "FishJoyData.h"
#include "StaticData.h"

USING_NS_CC;

#define IS_BEGINER "isBeginer"
#define MUSIC "music"
#define SOUND "sound"
#define GOLD "gold"

static FishJoyData* _sharedFishJoyData = NULL;

FishJoyData::FishJoyData(void)
{
}


FishJoyData::~FishJoyData(void)
{
}

FishJoyData* FishJoyData::sharedFishJoyData()
{
	if(NULL == _sharedFishJoyData)
	{
		_sharedFishJoyData = new FishJoyData();
		_sharedFishJoyData -> init();
	}
	return _sharedFishJoyData;
}

void FishJoyData::destoryInstance()
{
	CC_SAFE_DELETE(_sharedFishJoyData);
}

bool FishJoyData::init()
{
	_isBeginer = CCUserDefault::sharedUserDefault() -> getBoolForKey(IS_BEGINER, true);
	if (_isBeginer)
	{
		reset();
		flush();
	}
	else
	{
		CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
		this -> setGold(userDefault -> getDoubleForKey(GOLD));
		this -> setIsMusic(userDefault -> getBoolForKey(MUSIC));
		this -> setIsSound(userDefault -> getBoolForKey(SOUND));
	}
	return true;
}

void FishJoyData::reset()
{
	this -> setIsMusic(true);
	this -> setIsSound(true);
	this -> setGold(200);
	this -> setIsBeginer(false);
}

void FishJoyData::flush()
{
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	
	userDefault -> setBoolForKey(IS_BEGINER, _isBeginer);
	userDefault -> setIntegerForKey(GOLD, _gold);
	userDefault -> setBoolForKey(MUSIC, _isMusic);
	userDefault -> setBoolForKey(SOUND, _isSound);

	userDefault -> flush();
}

void FishJoyData::alterGold(int golds)
{
	int num = getGold();
	num += golds;
	setGold(num);
	flush();
}
