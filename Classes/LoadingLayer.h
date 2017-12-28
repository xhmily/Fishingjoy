#pragma once
#include "cocos2d.h" 
#include "ProgressDelegate.h"
#include "ProgressBar.h"

USING_NS_CC;

class LoadingLayer :
	public CCLayer, public ProgressDelegate
{
public:
	LoadingLayer();

	CREATE_FUNC(LoadingLayer);

	bool init();

	static CCScene* scene();

protected:

	ProgressBar* _progressBar;

	CCLabelTTF* _progressFg;

	int _loadedSp;

	void initProgressBar();

	void loadingFinished();

	void progressPercentageSetter(float percentage);

	void cacheInit(float delta);
};
