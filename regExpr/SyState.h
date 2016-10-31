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

	bool operator <(const SyState&);
	~SyState();

private:
	char mState;
	bool mIsEnd;
};

