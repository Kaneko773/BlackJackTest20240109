#pragma once

#include "Person.h"

//ディーラークラス
class Dealer : public Person 
{
public:
	Dealer(const char* pName) : Person(pName) {};

protected:
	//ゲーム実行
	void playBase(Shoe* shoe);

};