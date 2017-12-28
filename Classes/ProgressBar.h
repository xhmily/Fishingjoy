#pragma once
#include "cocos2d.h"
#include "ProgressDelegate.h"

USING_NS_CC;

class ProgressBar
	:public CCProgressTimer
{
public:

	static ProgressBar* create(ProgressDelegate* target, CCSprite *sprite);
	bool init(ProgressDelegate* target, CCSprite *sprite);
	
	void progressBy(float delta);

	void progressTo();

	void setBackground(CCNode* bg);

	void setForeground(CCNode* fg);

	CC_SYNTHESIZE(ProgressDelegate*, _target, Target);

	CC_SYNTHESIZE(float, _speed, Speed);

protected:

	CCNode* _background;

	CCNode* _foreground;

	void updatePercentage();

	void loadingFinished();
};
