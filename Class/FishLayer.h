#pragma once
#include "cocos2d.h"
#include "StaticData.h"
USING_NS_CC;

#define FISH_MAX_COUNT 50

class FishLayer :
	public CCLayer
{
public:
	FishLayer(void);
	CREATE_FUNC(FishLayer)
	virtual bool init();
	virtual ~FishLayer(void);

protected:
	CCArray* _fishes;
	void addFish(float delta);
};
