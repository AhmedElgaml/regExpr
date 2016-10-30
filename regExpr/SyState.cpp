#include "SyState.h"


SyState::SyState(char fState,bool fIsEnd):mState(fState),mIsEnd(fIsEnd)
{
}

char SyState::getState(){
	return mState;
}

void SyState::setState(char fState){
	mState = fState;
}

void SyState::markAsEndState(){
	mIsEnd = true;
}
void SyState::markAsOrdinaryState(){
	mIsEnd = false;
}

bool SyState::isEndState(){
	return mIsEnd ;
}

SyState::~SyState(void)
{
}
