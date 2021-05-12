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

using namespace std;

class BackWall : public Detail
{
public:
	BackWall(string NameOfDetail, Material Mater, double height, double width, double thickness);
	~BackWall();

	void toTXT(string folder);
	string StringForTXT();

	friend ostream& operator<<(ostream& zout, BackWall& B);
};

