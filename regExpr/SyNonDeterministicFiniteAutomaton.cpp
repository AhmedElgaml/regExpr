#include "SyNonDeterministicFiniteAutomaton.h"
#include <iostream>

SyNonDeterministicFiniteAutomaton::SyNonDeterministicFiniteAutomaton(const std::string& fPattern)
{

	std::cout<<" building NFA for "<<fPattern<<std::endl;
}

void SyNonDeterministicFiniteAutomaton::addEdge(SyStatePtr fFrom,char fChar,SyStatePtr fTo){
	mGraph[make_pair(fFrom,fChar)].insert(fTo);
}

void SyNonDeterministicFiniteAutomaton::removeEdge(SyStatePtr fFrom,char fChar,SyStatePtr fTo){
	StateInputPair key = make_pair(fFrom,fChar);

	if(mGraph.find(key) != mGraph.end()){
		mGraph[key].erase(fTo);

		if(!mGraph[key].size())
			mGraph.erase(key);
	}
}

SyNonDeterministicFiniteAutomaton::SyStatesSet& 
	SyNonDeterministicFiniteAutomaton::getInitialStates(){
	return mInitialStates;
}
SyNonDeterministicFiniteAutomaton::SyStatesSet& 
	SyNonDeterministicFiniteAutomaton::getNextStates(SyStatePtr fState,char fChar){
		return mGraph[make_pair(fState,fChar)];
}

SyNonDeterministicFiniteAutomaton::~SyNonDeterministicFiniteAutomaton()
{
}
