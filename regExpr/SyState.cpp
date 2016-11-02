#include "SyState.h"


SyState::SyState(char fState,bool fIsEnd):mState(fState)
{
}

char SyState::getState(){
	return mState;
}

void SyState::setState(char fState){
	mState = fState;
}

bool SyState::operator<(const SyState& fState){
	return mState < fState.mState;
}
SyState::~SyState(void)
{
}
