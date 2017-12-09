#include "Counter.h"
enum{
    k_Counter_Action = 0
};
Counter* Counter::create(CCArray* presenters, int digit/* = 0 */)
{
	CCAssert(digit>=0 && digit<=10,"金币数字只能为0至9之间的数字");
    Counter *counter = new Counter;
	if (counter && counter->init(presenters,digit) )
	{   
		counter->autorelease();
		return counter;
	}
	else
	{
		CC_SAFE_DELETE(counter);
		return NULL;
	}

}
bool Counter::init(CCArray* presenters, int digit/* = 0 */)
{
	if (!CCNode::init())
	{
		return false;
	}
    _presenters = CCNode::create();
	/*CCSize size = ((CCNode *) presenters->objectAtIndex(0))->getContentSize();
	   for (int i = 0; i < 10; i++) {
	       CCNode* node = (CCNode*)presenters->objectAtIndex(i);
	       int y = node->getContentSize().height*i;
	       node->setPosition(CCPointMake(0, y));
	       _presenters->addChild(node, 0, i);
		_presenters->addChild(node,0,i);
		node->setPosition(ccp(0,size,height * i));
	   }*/
	CCObject *obj = NULL;
	int i = 0;
	CCARRAY_FOREACH(presenters,obj)
	{
		CCNode *node = (CCNode *)obj;
		_presenters->addChild(node,0,i);
		node->setPosition(ccp(0,node->getContentSize().height * i));
		i++;
	}
    this->addChild(_presenters);
    setDigit(digit);
    return true;
}
void Counter::setDigit(int digit)
{
    if(_digit != digit)
	{
        _digit = digit;
        animation();
    }
}
int Counter::getDigit()
{
    return _digit;
}
void Counter::animation()
{
	CCNode *node = (CCNode *)_presenters->getChildByTag(_digit);
    CCPoint position = node->getPosition();
    _presenters->stopActionByTag(k_Counter_Action);
    CCMoveTo* moveTo = CCMoveTo::create(0.3f, ccp(0, -position.y));
	moveTo->setTag(k_Counter_Action);
    _presenters->runAction(moveTo);
}
void Counter::visit()
{
	//float scale = CCDirector::sharedDirector()->getContentScaleFactor();
	//CCLOG("scale = %f",scale);
    glEnable(GL_SCISSOR_TEST);
    //CCNode* presenter = _presenters->getChildByTag(_digit);
    CCSize size = ((CCNode *)_presenters->getChildByTag(_digit))->getContentSize();
    CCPoint position = getParent()->convertToWorldSpace(getPosition());
    glScissor((position.x - size.width / 2) * 0.4, (position.y - size.height / 2) * 0.4, size.width* 0.4, size.height* 0.4);

    CCNode::visit();
    glDisable(GL_SCISSOR_TEST);
}