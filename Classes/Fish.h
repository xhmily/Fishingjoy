#pragma once
#include "cocos2d.h"
USING_NS_CC;

typedef enum{
	k_Fish_Type_SmallFish = 0,
	k_Fish_Type_Croaker,
	k_Fish_Type_AngleFish,
	k_Fish_Type_Amphiprion,	
	k_Fish_Type_PufferS,
	k_Fish_Type_Bream,
	k_Fish_Type_Progy,
	
	k_Fish_Type_Chelonian,	
	k_Fish_Type_Lantern,
	k_Fish_Type_Ray,
	k_Fish_Type_Shark,	
	k_Fish_Type_GoldenTrout,
	k_Fish_Type_GShark,	
	k_Fish_Type_GMarlineFish,
	k_Fish_Type_GrouperFish,
	k_Fish_Type_JadePerch,
	k_Fish_Type_MarlineFish,
	k_Fish_Type_PufferB,
	k_Fish_Type_Count,
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
	void moveTo(CCPoint destination);
	void moveEnd();
	CCSize getSize();
protected:
	CCSprite* _fishSprite;
	void beCaught_CallFunc();
};

