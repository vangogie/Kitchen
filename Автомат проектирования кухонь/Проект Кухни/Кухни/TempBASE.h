#pragma once //��������� ��� ���������� ������������ ���������
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <iomanip> //���������� ��������
#include <fstream> //���������� ������ � �������
#include <stdio.h> //���������� ������ � ������ ������
#include <filesystem> //���������� ������ � �������
#include <string> //���������� ������ � ��������
#include <vector> //���������� ������ � ���������
#include <algorithm> //�������� ��� STL ���������
#include <map> //���������� �������������� �������
#include <direct.h> //���������� ������ � �������
#include "Material.h" //����� ����������
#include "MaterialBASE.h"

using namespace std;

class TempBASE : public MaterialBASE
{
private:
public:
	TempBASE();
	~TempBASE();
	void AddTempMaterial(Material NewMaterial, double QTY, double cost);
};

