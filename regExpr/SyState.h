#pragma once
class SyState
{
public:
	SyState(char,bool);

	void setState(char);
	char getState();


	void markAsEndState();
	void markAsOrdinaryState();

	bool isEndState();

	~SyState();

private:
	char mState;
	bool mIsEnd;
};

