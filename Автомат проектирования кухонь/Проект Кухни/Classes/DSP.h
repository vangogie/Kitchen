/// /////////////////////����� ���/////////////
#pragma once //��������� ��� ���������� ������������ ���������
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <fstream> //���������� ������ � �������
#include <stdio.h> //���������� ������ � ������ ������
#include <filesystem> //���������� ������ � �������
#include <string> //���������� ������ � ��������
#include <vector> //���������� ������ � ���������
#include <map> //���������� �������������� ������
#include <algorithm> //�������� ��� STL ���������
#include "Material.h"
#include "Holes.h"
#include "Detail.h"
#include "Groove.h"

using namespace std;

class DSP : public Detail
{
private:
	Material tortsovka;
	//Groove paz;
	//������� ��������� �� ������:
	map<string, Holes> holeUp; //������ ��������� ������ (4 ��.)
	map<string, Holes> holeRight; //������ ��������� ������ (4 ��.)
	map<string, Holes> holeDown; //������ ��������� ����� (4 ��.)
	map<string, Holes> holeLeft; //������ ��������� ����� (4 ��.)
public:
	DSP(string NameOfDetail, Material Mater, double height, double width, double thickness, Material tortsovka);
	~DSP();

	void AddHoleUp(string CodeHole, double diameter, double Xcoordinate, double depth);
	void AddHoleRight(string CodeHole, double diameter, double Xcoordinate, double depth);
	void AddHoleDown(string CodeHole, double diameter, double Xcoordinate, double depth);
	void AddHoleLeft(string CodeHole, double diameter, double Xcoordinate, double depth);

	int GetCountHoles();

	void toTXT(string folder);
	string StringForTXT();

	friend ostream& operator<<(ostream& zout, DSP& D);
};

