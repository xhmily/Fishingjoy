#pragma once
#include "cocos2d.h"
USING_NS_CC;

typedef enum{
	k_Fish_Type_SmallFish = 0,
	k_Fish_Type_Croaker,
	//k_Fish_Type_Count,//鱼的数量，可以根据测试的需要调整位置，在这里值是2
	k_Fish_Type_AngleFish,
	k_Fish_Type_Amphiprion,	//小丑鱼
	k_Fish_Type_PufferS,	//刺豚
	k_Fish_Type_Bream,		//蓝色
	k_Fish_Type_Progy,		//红色
	k_Fish_Type_Count,
	k_Fish_Type_Chelonian,	//乌龟
	k_Fish_Type_Lantern,	//灯笼鱼
	k_Fish_Type_Ray,		//魔鬼鱼
	k_Fish_Type_Shark,		//蓝色鲨鱼
	k_Fish_Type_GoldenTrout,
	k_Fish_Type_GShark,		//金色鲨鱼
	k_Fish_Type_GMarlineFish,
	k_Fish_Type_GrouperFish,
	k_Fish_Type_JadePerch,	//宝石鱼
	k_Fish_Type_MarlineFish,
	k_Fish_Type_PufferB,	//刺豚受到攻击
}FishType;


class Fish :
	public CCNode
{
public:
	Fish(void);
	static Fish* create(FishType type = k_Fish_Type_SmallFish);
	virtual bool init(FishType type = k_Fish_Type_SmallFish);
	int getScore();
	int getSpeed();
	CC_SYNTHESIZE(FishType, _type, Type);
	virtual ~Fish(void);
	CCRect getCollisionArea();
	void beCaught();
protected:
	CCSprite* _fishSprite;
	void beCaught_CallFunc();
};

