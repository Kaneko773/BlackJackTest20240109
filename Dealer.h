#pragma once

#include "Person.h"

//�f�B�[���[�N���X
class Dealer : public Person 
{
public:
	Dealer(const char* pName) : Person(pName) {};

protected:
	//�Q�[�����s
	void playBase(Shoe* shoe);

};