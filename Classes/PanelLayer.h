#pragma once
#include "cocos2d.h"
#include "GoldCounterLayer.h"
#include "ScheduleCounterDelegate.h"

USING_NS_CC;

class PanelLayer
	:public CCLayer, public ScheduleCounterDelegate
{
public:
	virtual bool init();
	PanelLayer(void);
	~PanelLayer(void);

    CREATE_FUNC(PanelLayer)
    CC_SYNTHESIZE_READONLY(GoldCounterLayer *, _goldCounter, GoldCounter);

	void scheduleTimeUp();

	void setScheduleNumber(int number);
protected:
	CCLabelTTF* _scheduleLabel;
};

