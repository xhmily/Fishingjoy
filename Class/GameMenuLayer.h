#pragma once
#include "cocos2d.h"
USING_NS_CC;

class GameMenuLayer :
	public CCLayer
{
public:
	GameMenuLayer(void);
	CREATE_FUNC(GameMenuLayer);
	static CCScene* scene(void);
	void menuCallbackSelectScene(CCObject* sender);
	void menuCallbackStartGame(CCObject* sender);
	virtual bool init();
	virtual ~GameMenuLayer(void);
protected:
	void createMenu(void);
};

