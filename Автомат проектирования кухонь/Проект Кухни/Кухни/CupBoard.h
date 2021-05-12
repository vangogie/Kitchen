#pragma once
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <vector> //���������� ������ � ���������
#include <algorithm> //�������� ��� STL ���������
#include <cctype>
#include <cstdlib>
#include "Material.h"
#include "Modules.h"
#include "DSP.h"

using namespace std;

class CupBoard : public Modules
{
protected:
	virtual void ALLCount();//������� ��� �������, ��������� � �.�.
public:
	CupBoard(double height, double width, double depth, Material MatDsp, Material MatTorts, Material MatFas, Material FasPokr, int fasadtype, int fasadRadius, Material MatFurnit, Material BackWallMaterial, Material fix);
	~CupBoard();

	virtual void TwoShelves(); //������� � ����� �������
	virtual void TwoShelvesTwoFasades(); //������� � ����� ������� � ����� ��������
	virtual void OneShelve(); //������� � ����� ������
	virtual void NoShelves(); //������� ��� ����� (��� ������) 
	
	virtual string toUser();


	friend ostream& operator<<(ostream& zout, CupBoard& C);
};

