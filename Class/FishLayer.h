#pragma once
#include "cocos2d.h"
#include "StaticData.h"
USING_NS_CC;

class FishLayer :
	public CCLayer
{
public:
	FishLayer(void);
	CREATE_FUNC(FishLayer)
	virtual bool init();
	virtual ~FishLayer(void);
};
