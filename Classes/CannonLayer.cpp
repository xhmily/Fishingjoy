#include "CannonLayer.h"
#include "PersonalAudioEngine.h"

CannonLayer::CannonLayer(void)
{
}

CannonLayer::~CannonLayer(void)
{
}

bool CannonLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}
	_weapon = Weapon::create(k_Cannon_Invalid);
	this->addChild(_weapon,1);
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	_weapon->setPosition(ccp(winSize.width/2 - 18, 0));

	_addMenuItem = CCMenuItemImage::create(
		"ui_button_65-ipadhd.png",
		"ui_button_65-ipadhd.png",
		this, menu_selector(CannonLayer::switchCannonCallback));

	_subMenuItem = CCMenuItemImage::create(
		"ui_button_63-ipadhd.png",
		"ui_button_63-ipadhd.png",
		this, menu_selector(CannonLayer::switchCannonCallback));

	CCMenu* menu = CCMenu::create(_subMenuItem, _addMenuItem, NULL);
	menu->alignItemsHorizontallyWithPadding(120);
	addChild(menu,0);
	menu->setPosition(ccp(winSize.width/2-20, _addMenuItem->getContentSize().height/2));
	return true;
}

void CannonLayer::switchCannonCallback(CCObject* sender)
{
	CannonOperate operate = k_Cannon_Operate_Up;
	if((CCMenuItemImage*)sender == _subMenuItem)
	{
		operate = k_Cannon_Operate_Down;
	}
	_weapon->changeCannon(operate);
	PersonalAudioEngine::sharedEngine()->playEffect("bgm_button.aif");
}

void CannonLayer::aimAt(CCPoint target)
{
	_weapon->aimAt(target);
}

bool CannonLayer::shootTo(CCPoint target)
{
	return _weapon->shootTo(target);
}
