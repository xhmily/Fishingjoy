#include "cocos2d.h"

USING_NS_CC;

class Counter
	:public CCNode
{
public:
    static Counter* create(CCArray* presenters, int digit = 0); 
    CC_PROPERTY(int, _digit, Digit)
protected:
	bool init(CCArray* presenters, int digit = 0);

    virtual void visit();

    CCNode* _presenters;

    void animation();
};
