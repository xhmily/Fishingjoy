#pragma once
#include "cocos2d.h"
USING_NS_CC;

#define _CANNON_H

typedef enum{
	k_Cannon_Type_1 = 0,
	k_Cannon_Type_2,
	k_Cannon_Type_3,
	k_Cannon_Type_4,
	k_Cannon_Type_5,
	k_Cannon_Type_6,
	k_Cannon_Type_7,
	k_Cannon_Count,
	k_Cannon_Invalid,
}CannonType;

typedef enum{
	k_Cannon_Operate_Up = 1,
	k_Cannon_Operate_Down = -1
}CannonOperate;

class Cannon :
	public CCNode
{
public:
	Cannon(void);
	static Cannon* create(CannonType type = k_Cannon_Type_1);
	bool init(CannonType type = k_Cannon_Type_1);
	CCSize getSize();
	float getFireRange();
	CC_PROPERTY(CannonType, _type, Type);
	virtual ~Cannon(void);

protected:
	CCArray* _cannonSprites;
};
