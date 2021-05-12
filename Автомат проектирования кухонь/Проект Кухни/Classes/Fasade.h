/// /////////////////////����� �������/////////////
#pragma once //��������� ��� ���������� ������������ ���������
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <fstream> //���������� ������ � �������
#include <stdio.h> //���������� ������ � ������ ������
#include <filesystem> //���������� ������ � �������
#include <string> //���������� ������ � ��������
#include <vector> //���������� ������ � ���������
#include <algorithm> //�������� ��� STL ���������
#include "Material.h"
#include "Holes.h"
#include "Detail.h"

using namespace std;



class Fasade : public Detail
{
protected:
	Material covering; //�������� ������ (����� ���� ��� ������ ��� � ������)
	int fasadtype = 1; //��� ������: 1 - ������, 2 - ������������ �����, 3 - ������������ ����� + ������������ ������, 4 - ������, 5 - ��������
	int radius = 1; //���������� 1, ����������� - 6.
public:
	Fasade(string NameOfDetail, Material Mater, double height, double width, double thickness, Material covering, int fasadtype, int radius);
	~Fasade();

	string TypeFasad(int fasadtype);

	void SetCovering(Material covering);

	Material GetCovering();

	string ShowTypeOfFasade();
	string toUser();

	void toTXT(string folder);
	string StringForTXT();

	friend ostream& operator<<(ostream& zout, Fasade& F);
};

