#pragma once
#include "cocos2d.h"

USING_NS_CC;

class BackgroundLayer :
	public CCLayer
{
public:
	BackgroundLayer(void);
	CREATE_FUNC(BackgroundLayer)
	virtual bool init();
	virtual ~BackgroundLayer(void);
};

