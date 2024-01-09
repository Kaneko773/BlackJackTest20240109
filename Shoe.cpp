#include "Shoe.h"
#include <iostream>
#include <random> //��������

using namespace std;

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
void Shoe::_shuffle()
{
	//�����J�[�h��������邱�Ƃ������悤�ɏC��
	//�f�b�L�P�P�ʂ��ƂɃV���b�t��
	for (int j = DECK; j > 0 ; --j) {
		for (int i = j * CARD; i > ((j - 1) * CARD) + 1; --i) {
			int a = i - 1;
			int b = (rand() % CARD) + (j - 1) * CARD;
			swap(_cardShoe[a], _cardShoe[b]);
		}
	}
}

//�R���X�g���N�^
Shoe::Shoe() {

	//�J�[�h�����Ă�0.... /13�ŃJ�[�h��ނƂ���
	for (int i = 0; i < NUM; i++) {
		_cardShoe[i] = i;
	}
	_cardNum = NUM; //�J�[�h�����̐ݒ�

	//�V���b�t��
	_shuffle();
}

//�J�[�h�V���[��\��(�f�o�b�O�p)
void Shoe::showShoe(SHOW_TYPE type) const 
{
	int roopCnt = NUM;
	if (type == CARD_ONLY) {	//�J�[�h�������\��
		//�J�[�h�̂ݕ\���ɂ���B
		roopCnt = _cardNum;
	}

	for (int i = 0; i < roopCnt; i++) {
		cout << _cardShoe[i] << ' ';
	}
	cout << endl;
}

//�J�[�h��1�����o��
int Shoe::takeCard() {
	//�J�[�h������0�ȉ��������ꍇ,�G���[�Ƃ��ďo�� -> �����Ɉ�����悤�ɂ���
	if (_cardNum <= 0) {
		//�J�[�h���؂ꂽ��ǉ�
		Shoe();
	}

	int card = _cardShoe[_cardNum];
	--_cardNum;//�����J�[�h�������ƈ������̂��C��

	return card;
}
