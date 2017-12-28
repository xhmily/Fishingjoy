#ifndef _COUNTER_H
#define _COUNTER_H
#include "cocos2d.h"

USING_NS_CC;

class Counter
	:public CCNode
{
public:
    static Counter* create(CCArray* presenters, int digit = 0); 
    CC_PROPERTY(int, _digit, Digit)
protected:
	bool init(CCArray* presenters, int digit = 0);
    virtual void visit();

    //存放0-9数字对应的节点
    CCNode* _presenters;

    //改变数字时播放滚动动画
//改变数字时播放滚动动画
    void animation();
};

#endif