#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//

// ★★★★★★★★★★★★★★★★
static void showResult(Person** p)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	cout << "player" << endl;
	p[0]->showHand();
	cout << "============================" << endl;
	cout << "dealer" << endl;
	p[1]->showHand();
	cout << "============================" << endl;

	if (p[0]->getScore() > p[1]->getScore()) {
		cout << "Player Win!" << endl;
	}
	else if (p[0]->getScore() < p[1]->getScore()) {
		cout << "Player Lose" << endl;
	}
	else {
		cout << "Push" << endl;
	}
}

static void showHand(Person* p)
{
	//手札の表示
	cout << "====================" << endl;
	cout << p->get_pName() << endl;
	p->showHand();
	cout << "====================" << endl;
}

//メイン関数
int main() {

	srand((unsigned int)time(NULL));

	enum PERSON
	{
		DEALER,
		PLAYER1,
		PLAYER2,
		PLAYER3,
	};

	//各オブジェクトの生成
	Shoe shoe;
	const char* name[] = { "dealer", "player1", "player2" ,"player3" };
	Person* persons[] = { new Dealer(name[0]), new Player(name[1]), new Player(name[2]), new Player(name[3])};
	const int num = sizeof(persons) / sizeof(Person*);

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(shoe);
		showHand(persons[i]);
	}
	//プレイヤーに2枚目を配布
	for (int i = PLAYER1; i < PLAYER3 + 1; ++i) {
		persons[i]->hit(shoe);
		showHand(persons[i]);
	}

	//ディーラーに2枚目を配布
	persons[DEALER]->hit(shoe);





	//以下は１対多に対応してません





	// ----　勝負開始
	//プレイヤーの実行
	//バーストしているかどうか判別
	if (persons[PLAYER1]->play(shoe)) {
		//バーストせずstandした

		//ディーラーの手札を表示
		showHand(persons[DEALER]);

		//ディーラーの自動実行
		persons[DEALER]->play(shoe);

		//結果の表示
		showResult(persons);
	}
	else {
		cout << "============================" << endl;
		cout << "            result          " << endl;
		cout << "============================" << endl;
		showHand(persons[PLAYER1]);
		showHand(persons[DEALER]);
		cout << "Burst player Lose" << endl;
	}
	cout << "====================" << endl;
	return 0;
}