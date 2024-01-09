#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	int _hand[HAND_SIZE];	// ���_�ケ�ꂭ�炢���Ă�OK...�ɍ���͂����Ⴄ
	bool _calcUpdate;
	int _cardNum;
	int _score;
	char* _pName;//���O��ێ�

public:
	// �R���X�g���N�^
	Person(const char* pName);
	virtual ~Person();

	//�X�R�A�̎擾(hit���ꂽ���̂ݍČv�Z�����)
	int getScore();

	//�J�[�h�̒ǉ�
	void hit(Shoe& shoe);

	//��D��\��
	void showHand();

	//�^�[������
	bool play(Shoe& shoe);

	//���O�̎擾
	char* get_pName() const{
		return _pName;
	}

protected:
	void playBase(Shoe& shoe);	//�^�[�������{��

};

