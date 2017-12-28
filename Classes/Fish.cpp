#include "Fish.h"

enum{
	k_Action_Animate = 0,
	k_Action_MoveTo
};

Fish::Fish(void)
{
}

Fish::~Fish(void)
{
}

Fish* Fish::create(FishType type/* = k_Fish_Type_SmallFish */)
{
	Fish* fish = new Fish;
	if (fish && fish->init(type))
	{
		fish->autorelease();
		return fish;
	}
	else
	{
		CC_SAFE_DELETE(fish);
		return NULL;
	}
}

bool Fish::init(FishType type /* = k_Fish_Type_SmallFish */)
{
	do 
	{
		if (!CCNode::init())
		{
			return false;
		}
		if (type < k_Fish_Type_SmallFish || type >= k_Fish_Type_Count)
		{
			type = k_Fish_Type_SmallFish;
		}
		setType(type);
		CCString* animationName = CCString::createWithFormat("fish_animation_%02d", _type + 1);
		CCAnimation* animation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
		CC_BREAK_IF(!animation);
		CCAnimate* animate = CCAnimate::create(animation);
		_fishSprite = CCSprite::create();
		addChild(_fishSprite);
		_fishSprite->runAction(CCRepeatForever::create(animate));
		return true;
	} while (0);
	return false;
}

int Fish::getScore(void)
{
	return 0;
}

int Fish::getSpeed(void)
{
	return 200;
}

CCRect Fish::getCollisionArea()
{
	CCSize size = _fishSprite->getContentSize();
	CCPoint pos = getParent()->convertToWorldSpace(getPosition());
	return CCRect(pos.x - size.width / 2, pos.y - size.height/2, size.width, size.height);
}

void Fish::beCaught(){
	stopActionByTag(k_Action_MoveTo);
	CCCallFunc* callFunc = CCCallFunc::create(this,callfunc_selector(Fish::beCaught_CallFunc));
	CCSequence* sequence = CCSequence::create(CCDelayTime::create(1.0f),callFunc,NULL);
	CCBlink* blink = CCBlink::create(1.0f, 8);
	CCSpawn* spawn = CCSpawn::create(sequence, blink, NULL);
	_fishSprite->runAction(spawn);
}

void Fish::beCaught_CallFunc()
{
	if(isRunning())
	{
		getParent()->removeChild(this,false);
	}
}

void Fish::moveTo(CCPoint destination)
{
	CCPoint point = getParent()->convertToWorldSpace(this->getPosition());
	float duration = ccpDistance(destination, point) / getSpeed();
	CCMoveTo *moveTo = CCMoveTo::create(duration, destination);
	CCCallFunc *callFunc = CCCallFunc::create(this, callfunc_selector(Fish::moveEnd));
	CCSequence *sequence = CCSequence::create(moveTo, callFunc, NULL);
	sequence->setTag(k_Action_MoveTo);
	this->runAction(sequence);
}

void Fish::moveEnd()
{
	if (isRunning())
	{
		this->stopActionByTag(k_Action_MoveTo);
		getParent()->removeChild(this, false);
	}
}

CCSize Fish::getSize()
{
	return _fishSprite -> displayFrame() -> getRect().size;
}
