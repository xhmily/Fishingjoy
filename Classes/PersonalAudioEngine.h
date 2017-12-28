#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;


class PersonalAudioEngine :
	public SimpleAudioEngine
{
public:
	PersonalAudioEngine(void);
	~PersonalAudioEngine(void);
	static PersonalAudioEngine* sharedEngine();
	
	bool init();
	void setBackgroundMusic(bool flag);
};
