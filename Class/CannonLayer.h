#pragma once
#include "cocos2d.h"
#include "Weapon.h"

#define _CANNONLAYER_H

class CannonLayer :
	public CCLayer
{
public:
	CannonLayer(void);
	virtual ~CannonLayer(void);
	virtual bool init();
	void switchCannonCallback(cocos2d::CCObject* sender);
	CREATE_FUNC(CannonLayer);
	CC_SYNTHESIZE_READONLY(Weapon*, _weapon, Weapon);
protected:
	CCMenuItemImage *_addMenuItem, *_subMenuItem;

};

