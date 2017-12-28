#pragma once
#include "cocos2d.h"
#include "ScheduleCounterDelegate.h"

USING_NS_CC;

class ScheduleCountDown :
	public CCNode
{
public:
	static ScheduleCountDown* create(ScheduleCounterDelegate* target, int perimeter = 30, bool loop = true);

	bool init (ScheduleCounterDelegate* target, int perimeter = 30, bool loop = true);

	CC_SYNTHESIZE(bool, _loop, Loop);

protected:
	ScheduleCounterDelegate* _target;
	int _currTime;
	int _maxTime;
	void schedulePerSecond(float delta);
};

