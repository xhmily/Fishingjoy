#include "Bullet.h"
#include "FishNet.h"

enum{
	k_Bullet_Action = 0
};

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
	_bulletSprite->setAnchorPoint(ccp(0.5, 1.0));
	this->addChild(_bulletSprite);
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

void Bullet::flyTo(CCPoint targetInWorldSpace, int type/* =0 */)
{
	CCPoint startInNodeSpace = CCPointZero;
	CCPoint startInWorldSpace = this->getParent()->convertToWorldSpace(startInNodeSpace);
	CCPoint targetInNodeSpace = this->getParent()->convertToNodeSpace(targetInWorldSpace);

	this->setPosition(startInNodeSpace);
	this->setVisible(true);

	float angle = ccpAngleSigned(ccpSub(targetInWorldSpace, startInWorldSpace), CCPointMake(0, 1));
	this->setRotation(CC_RADIANS_TO_DEGREES(angle));
	this->setTag(type);
	CCString* bulletFrameName = CCString::createWithFormat("weapon_bullet_%03d.png", type + 1);
	_bulletSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(bulletFrameName->getCString()));

	float duration = ccpDistance(targetInWorldSpace, startInWorldSpace) / getSpeed(type);

	CCMoveTo* moveTo = CCMoveTo::create(duration, targetInNodeSpace);
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Bullet::end));
	CCSequence* sequence = CCSequence::create(moveTo, callFunc, NULL);
	sequence->setTag(k_Bullet_Action);
	runAction(sequence);
}

void Bullet::end()
{
	stopActionByTag(k_Bullet_Action);
	this->setVisible(false);
	FishNet* fishNet = (FishNet*)getUserObject();
	fishNet->showAt(getPosition(), getTag());
}

CCPoint Bullet::getCollosionPoint()
{
	return getParent()->convertToWorldSpace(getPosition());
}
