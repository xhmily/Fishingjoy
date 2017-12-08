#include "FishNet.h"

FishNet::FishNet(void)
{
}

FishNet::~FishNet(void)
{
}

bool FishNet::init()
{
	if(!CCNode::init())
	{
		return false;
	}

	CCString *fileName = CCString::createWithFormat("weapon_net_%03d.png",1);
	_fishNetSprite = CCSprite::createWithSpriteFrameName(fileName->getCString());
	_fishNetSprite->setAnchorPoint(ccp(0.5, 0.5));
	addChild(_fishNetSprite);
	return true;
}
float FishNet::getSpeed(int type)
{
	float speed=640;
	switch(type)
	{
	case 0:
		speed=640;
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

void FishNet::showAt(CCPoint pos,int type/*= 0*/)
{
	setVisible(true);
	setPosition(pos);
	CCString* fishNetFrameName = CCString::createWithFormat("weapon_net_%03d.png", type + 1);
	this->_fishNetSprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(fishNetFrameName->getCString()));
	stopAllActions();
	CCSequence* sequence = CCSequence::create(CCDelayTime::create(1), CCHide::create(),NULL);
	CCParticleSystemQuad* particle = (CCParticleSystemQuad*)getUserObject();
	particle->setPosition(pos);
	particle->resetSystem();
	runAction(sequence);
}

CCRect FishNet::getCollisionArea()
{
	CCSize size = _fishNetSprite->getContentSize();
	CCPoint pos = getParent()->convertToWorldSpace(getPosition());
	return CCRect(pos.x - size.width / 2, pos.y - size.height/2, size.width, size.height);
}
