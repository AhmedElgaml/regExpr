#pragma once

#include <string>
#include "SyNonDeterministicFiniteAutomaton.h"

class SyNonDeterministicFiniteAutomatonController
{
public:
	SyNonDeterministicFiniteAutomatonController(std::shared_ptr<SyNonDeterministicFiniteAutomaton>);

	bool evaluate(const std::string&);

	~SyNonDeterministicFiniteAutomatonController();
private:
	 static void mergeStates(SyNonDeterministicFiniteAutomaton::SyStatesSet,SyNonDeterministicFiniteAutomaton::SyStatesSet);

	std::shared_ptr<SyNonDeterministicFiniteAutomaton> mNFA;
	SyNonDeterministicFiniteAutomaton::SyStatesSet mCurrentStates;
};

