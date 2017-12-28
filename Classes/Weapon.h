#pragma once
#include "cocos2d.h"
#include "Cannon.h"
#include "Bullet.h"
#include "FishNet.h"

USING_NS_CC;

#define _WEAPON_H

class Weapon :
	public CCNode
{
public:
	static Weapon* create(CannonType type = k_Cannon_Type_1);
	bool init(CannonType type = k_Cannon_Type_1);
	CannonType getCannonType();
	CCSize getCannonSize();
	void changeCannon(CannonOperate operate);
	~Weapon(void);
	void aimAt(CCPoint target);
	bool shootTo(CCPoint target);
	CCRect getCollisionArea(Bullet* bullet);
protected:
	CC_SYNTHESIZE_READONLY(Cannon*, _cannon, Cannon);
	CC_SYNTHESIZE_READONLY(CCArray*, _bullets, Bullets);
	CC_SYNTHESIZE_READONLY(CCArray*, _fishNets, FishNets);
	CC_SYNTHESIZE_READONLY(CCArray*, _particils, CCParticleSystemQuad);
	Bullet* getBulletToShoot();
};
