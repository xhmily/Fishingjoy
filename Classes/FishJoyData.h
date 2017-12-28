#pragma once
#include "cocos2d.h"



class FishJoyData :
	public cocos2d::CCObject
{
public:
	static FishJoyData* sharedFishJoyData();
	static void destoryInstance();

	FishJoyData();
	~FishJoyData();

	void reset();

	void flush();

	CC_SYNTHESIZE(bool, _isBeginer, IsBeginer)
	CC_SYNTHESIZE(int, _gold, Gold)
	CC_SYNTHESIZE(bool, _isMusic, IsMusic)
	CC_SYNTHESIZE(bool, _isSound, IsSound)

	void alterGold(int golds);

	void purge();

protected:
	bool init();

private:

};

