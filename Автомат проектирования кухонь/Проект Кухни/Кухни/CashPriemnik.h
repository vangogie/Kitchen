#pragma once //��������� ��� ���������� ������������ ���������
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <iomanip> //���������� ��������
#include <algorithm> //�������� ��� STL ���������
#include <map> //���������� �������������� ������

using namespace std;

class CashPriemnik
{
private:
	int maxSize;//������������� ������������ ���������� ������ ������� � �����
	map<int, int> money;
	bool ValidMoney(int kupura); //����� �������� ������������� ����� ������

public:
	CashPriemnik(int maxSize, int currentSize); //currentSize ������������� ������� ���������� �����
	~CashPriemnik();

	bool HavePlace(int kupura); //��������� ���� �� ����� ��� ������
	bool MoneyTake(int kupura); //��������� ������
	int MoneyGive(int money); //������ ����� ������� (�������� ��� ��� �������)!!!!!!
	void ShowMoney(); //���������� ��� ��� ��������� � ���������������
};

