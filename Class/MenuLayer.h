#pragma once
#include "cocos2d.h"
USING_NS_CC;

class MenuLayer :
	public CCLayer
{
public:
	MenuLayer(void);
	CREATE_FUNC(MenuLayer)
	virtual bool init();
	virtual ~MenuLayer(void);
};

