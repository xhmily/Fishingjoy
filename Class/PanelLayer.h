#pragma once
#include "cocos2d.h"
#include "GoldCounterLayer.h"

USING_NS_CC;

class PanelLayer
	:public cocos2d::CCLayer
{
public:
	virtual bool init();
	PanelLayer(void);
	~PanelLayer(void);

    CREATE_FUNC(PanelLayer)
    CC_SYNTHESIZE_READONLY(GoldCounterLayer *, _goldCounter, GoldCounter)
};

