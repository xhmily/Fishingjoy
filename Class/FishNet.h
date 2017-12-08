#pragma once
#include "cocos2d.h"
USING_NS_CC;

#define _FishNet_H

class FishNet :
	public CCNode
{
public:
	FishNet(void);
	virtual ~FishNet(void);
	CREATE_FUNC(FishNet);
	bool init();
	void showAt(CCPoint pos,int type = 0);
	CCRect getCollisionArea();
protected:
	float getSpeed(int type);
	CCSprite* _fishNetSprite;
};
