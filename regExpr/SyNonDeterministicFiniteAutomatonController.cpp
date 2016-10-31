#include "SyNonDeterministicFiniteAutomatonController.h"


SyNonDeterministicFiniteAutomatonController::SyNonDeterministicFiniteAutomatonController(
										std::shared_ptr<SyNonDeterministicFiniteAutomaton> fNFA):mNFA(fNFA)
{
	mCurrentStates= fNFA->getInitialStates();
}


bool SyNonDeterministicFiniteAutomatonController::evaluate(const std::string& fText){
	
	for(std::size_t textIdx = 0 ;textIdx < fText.size();++textIdx){
		SyNonDeterministicFiniteAutomaton::SyStatesSet newStates;

			for(auto &state : mCurrentStates){
				SyNonDeterministicFiniteAutomaton::SyStatesSet
				currentStateNewStates = mNFA->getNextStates(state,fText[textIdx]);

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
