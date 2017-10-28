#include "FishLayer.h"

FishLayer::FishLayer(void)
{
}

bool FishLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	return true;
}

FishLayer::~FishLayer(void)
{
}
