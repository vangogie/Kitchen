#pragma once
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <vector> //���������� ������ � ���������
#include <algorithm> //�������� ��� STL ���������
#include <cctype>
#include <cstdlib>
#include "Material.h"
#include "Modules.h"
#include "CupBoard.h"
#include "DSP.h"

using namespace std;

class Cabinet : public Modules
{
protected:
	const int legHeight = 100; //100 �� ������ �����
	int countLegs = 0;//���������� ����� ��
	Material MatLegs;//�������� �����

	void ALLCount();//������� ��� �������, ��������� � �.�. (��������� �������)
public:
	Cabinet(double height, double width, double depth, Material MatDsp, Material MatTorts, Material MatFas, Material FasPokr, int fasadtype, int fasadRadius, Material MatFurnit, Material BackWallMaterial, Material fix, Material MatLegs);
	~Cabinet();

	void TwoShelves(); //�������� � ����� �������
	void TwoShelvesTwoFasades(); //�������� � ����� ������� � ����� ��������
	void OneShelve(); //�������� � ����� ������
	void OneShelveTwoFasades();//�������� � ����� ������ � ����� ��������
	string toUser();

	int GetCountLegs();//���������� ����� ��


	friend ostream& operator<<(ostream& zout, CupBoard& C);
};

