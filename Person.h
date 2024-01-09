#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	int _hand[HAND_SIZE];	// 理論上これくらい持てばOK...に今回はしちゃう
	bool _calcUpdate;
	int _cardNum;
	int _score;
	char* _pName;//名前を保持

public:
	// コンストラクタ
	Person(const char* pName);
	virtual ~Person();

	//スコアの取得(hitされた時のみ再計算される)
	int getScore();

	//カードの追加
	void hit(Shoe& shoe);

	//手札を表示
	void showHand();

	//ターン処理
	bool play(Shoe& shoe);

	//名前の取得
	char* get_pName() const{
		return _pName;
	}

protected:
	void playBase(Shoe& shoe);	//ターン処理本体

};

