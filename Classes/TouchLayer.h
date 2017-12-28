#pragma once
#include "cocos2d.h"

USING_NS_CC;
class GameScene;
class TouchLayer :
	public CCLayer
{
public:
	TouchLayer(void);
	virtual ~TouchLayer(void);
	CREATE_FUNC(TouchLayer);
	bool init();
protected:
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void registerWithTouchDispatcher();
	GameScene* getGameScene(); 
};

