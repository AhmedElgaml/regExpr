#include <iostream>
#include <string>
#include <memory>
#include "SyNonDeterministicFiniteAutomatonController.h"


int main(){
	std::string pattern;
	std::cout<<"please insert a pattern \n";
	std::cin>>pattern;

	std::shared_ptr<SyNonDeterministicFiniteAutomaton> NFA(
		std::make_shared<SyNonDeterministicFiniteAutomaton>(SyNonDeterministicFiniteAutomaton(pattern)));

	std::shared_ptr<SyNonDeterministicFiniteAutomatonController> controller(
		std::make_shared<SyNonDeterministicFiniteAutomatonController>(
		SyNonDeterministicFiniteAutomatonController(NFA)));

	std::string word;
	std::cout<<"please insert a word \n";
	std::cin>>word;

	bool res = controller->evaluate("abc");

	if(res)
		std::cout<<" the word matches the pattern !\n";
	else
		std::cout<<" the word doesn't matche the pattern :( \n";
	
	system("pause");
	return 0;
		
}