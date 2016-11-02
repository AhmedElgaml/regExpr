#include "SyNonDeterministicFiniteAutomatonController.h"


SyNonDeterministicFiniteAutomatonController::SyNonDeterministicFiniteAutomatonController(
										std::shared_ptr<SyNonDeterministicFiniteAutomaton> fNFA):mNFA(fNFA)
{
	mCurrentStates= fNFA->getInitialStates();
}


bool SyNonDeterministicFiniteAutomatonController::evaluate(const std::string& fText){
	
		for(auto &currentChar : fText){
		SyNonDeterministicFiniteAutomaton::SyStatesSet newStates;

			for(auto &state : mCurrentStates){
				SyNonDeterministicFiniteAutomaton::SyStatesSet
				currentStateNewStates = mNFA->getNextStates(state,currentChar);

				mergeStates(newStates,currentStateNewStates);
				
			}

			mCurrentStates = newStates;
	}

	bool res = static_cast<bool>(mCurrentStates.size());

	mCurrentStates = mNFA->getInitialStates();

	return res;
}

void SyNonDeterministicFiniteAutomatonController::mergeStates(
	SyNonDeterministicFiniteAutomaton::SyStatesSet fDestination,SyNonDeterministicFiniteAutomaton::SyStatesSet fSource){
		fDestination.insert(fDestination.begin(),fSource.end());
}
SyNonDeterministicFiniteAutomatonController::~SyNonDeterministicFiniteAutomatonController()
{
}
