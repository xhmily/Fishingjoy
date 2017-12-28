#pragma once
class ProgressDelegate
{
public:
	virtual void loadingFinished() = 0;

	virtual void progressPercentageSetter(float percentage)=0;
};
