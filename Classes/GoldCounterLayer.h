#ifndef _GOLDCOUNTERLAYER_H
#define _GOLDCOUNTERLAYER_H
#include "cocos2d.h"

USING_NS_CC;

class GoldCounterLayer:
	public CCNode
{
public:
    static GoldCounterLayer* create(int number = 0);
    void setNumber(int number,int ceiling = 999999);

protected:
	bool init(int number = 0);
	int _number;
};

#endif