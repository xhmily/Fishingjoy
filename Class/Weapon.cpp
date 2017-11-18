#include "Weapon.h"

#define BULLET_COUNT 10

Weapon* Weapon::create(CannonType type)
{
	Weapon* weapon = new Weapon();
	if(weapon && weapon->init(type))
	{
		weapon->autorelease();
		return weapon;
	}
	else
	{
		CC_SAFE_DELETE(weapon); 
		return NULL;
	}
}

bool Weapon::init(CannonType type)
{
	do
	{
		CC_BREAK_IF(!CCNode::init());
		_cannon = Cannon::create(type);
		CC_BREAK_IF(!_cannon);
		addChild(_cannon, 1);
		
		_bullets = CCArray::createWithCapacity(BULLET_COUNT);
		CC_BREAK_IF(!_bullets);
		CC_SAFE_RETAIN(_bullets);
		
		_fishNets=CCArray::createWithCapacity(BULLET_COUNT);
		CC_BREAK_IF(!_fishNets);
		CC_SAFE_RETAIN(_fishNets);
		
		for(int i = 0; i < BULLET_COUNT; i++)
		{
			Bullet* bullet = Bullet::create();
			_bullets->addObject(bullet);
			addChild(bullet);
			bullet->setVisible(false);
			
			FishNet* fishNet = FishNet::create();
			_fishNets->addObject(fishNet);
			addChild(fishNet);
			fishNet->setVisible(false);
			bullet->setUserObject(fishNet);
		}
		return true;
	}while(0);

	return false;
}

CCSize Weapon::getCannonSize()
{
	return _cannon->getSize();
}

CannonType Weapon::getCannonType()
{
	return _cannon->getType();
}

void Weapon::changeCannon(CannonOperate operate)
{
	int type = (int) _cannon->getType();
	type += operate;
	_cannon->setType((CannonType)type);
}

Weapon::~Weapon(void)
{
	CC_SAFE_RELEASE(_bullets);
	CC_SAFE_RELEASE(_fishNets);
}
