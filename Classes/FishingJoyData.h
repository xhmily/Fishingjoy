#pragma once
#include "cocos2d.h"



class FishingJoyData :
	public cocos2d::CCObject
{
public:
	static FishingJoyData* sharedFishingJoyData();

	FishingJoyData();
	~FishingJoyData();

	void reset();

	void flush();
	
	CC_SYNTHESIZE(int, _gold, Gold);
	CC_SYNTHESIZE(bool, _isBeginer, IsBeginer);
	CC_SYNTHESIZE(bool, _music, Music);
	CC_SYNTHESIZE(bool, _sound, Sound);

	void alterGold(int golds);

	void purge();

protected:
	bool init();

};

