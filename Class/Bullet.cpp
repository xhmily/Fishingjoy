#include "Bullet.h"

Bullet::Bullet(void)
{
}

Bullet::~Bullet(void)
{
}

bool Bullet::init()
{
	if(!CCNode::init())
	{
		return false;
	}
	CCString* fileName = CCString::createWithFormat("weapon_bullet_%03d.png", 1);
	_bulletSprite = CCSprite::createWithSpriteFrameName(fileName->getCString());
	_bulletSprite->setAnchorPoint(ccp(0.5, 1));
	addChild(_bulletSprite);
	return true;
}

float Bullet::getSpeed(int type)
{
	float speed = 640;
	switch(type)
	{
	case 0:
		speed = 640;
		break;
	case 1:
		speed = 640;
		break;
	case 2:
		speed = 460;
		break;
	case 3:
		speed = 440;
		break;
	case 4:
		speed = 650;
		break;
	case 5:
		speed = 410;
		break;
	case 6:
		speed = 390;
		break;
	default:
		break;
	}
	return speed;
}
