#pragma once

#include <string>
#include <set>
#include <map>
#include <memory>
#include <utility> // needed for std::pair

class SyState;

class SyNonDeterministicFiniteAutomaton
{
	
public:
	typedef std::shared_ptr<SyState> SyStatePtr;
	typedef std::pair<std::shared_ptr<SyState>,char> StateInputPair;
	typedef std::set<std::shared_ptr<SyState>> SyStatesSet;
	

	SyNonDeterministicFiniteAutomaton(const std::string&);
	void addEdge(SyStatePtr,char,SyStatePtr);
	void removeEdge(SyStatePtr,char,SyStatePtr);

	SyStatesSet& getInitialStates();
	SyStatesSet& getNextStates(SyStatePtr,char);
	
	~SyNonDeterministicFiniteAutomaton();

private:	
	
	std::map<StateInputPair,SyStatesSet>mGraph;
	SyStatesSet mInitialStates;
};