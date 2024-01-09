#include "Shoe.h"
#include <iostream>
#include <random> //乱数生成

using namespace std;

//シャッフル（フィッシャーイェーツ）
void Shoe::_shuffle()
{
	//同じカードが引かれることが無いように修正
	//デッキ１単位ごとにシャッフル
	for (int j = DECK; j > 0 ; --j) {
		for (int i = j * CARD; i > ((j - 1) * CARD) + 1; --i) {
			int a = i - 1;
			int b = (rand() % CARD) + (j - 1) * CARD;
			swap(_cardShoe[a], _cardShoe[b]);
		}
	}
}

//コンストラクタ
Shoe::Shoe() {

	//カードを入れてく0.... /13でカード種類とする
	for (int i = 0; i < NUM; i++) {
		_cardShoe[i] = i;
	}
	_cardNum = NUM; //カード枚数の設定

	//シャッフル
	_shuffle();
}

//カードシューを表示(デバッグ用)
void Shoe::showShoe(SHOW_TYPE type) const 
{
	int roopCnt = NUM;
	if (type == CARD_ONLY) {	//カード枚数分表示
		//カードのみ表示にする。
		roopCnt = _cardNum;
	}

	for (int i = 0; i < roopCnt; i++) {
		cout << _cardShoe[i] << ' ';
	}
	cout << endl;
}

//カードを1枚取り出す
int Shoe::takeCard() {
	//カード枚数が0以下だった場合,エラーとして出力 -> 無限に引けるようにした
	if (_cardNum <= 0) {
		//カードが切れたら追加
		Shoe();
	}

	int card = _cardShoe[_cardNum];
	--_cardNum;//同じカードがずっと引かれるのを修正

	return card;
}
