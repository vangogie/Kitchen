/// /////////////////////����������� ����� ������ �� �������� ����������� ������ ��� � �������/////////////
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

using namespace std;

class Detail
{
protected:
	string NameOfDetail;
	Material Mater;
	double height; //������ ������
	double width; //������ ������
	double thickness; //������� ������
	map<string, Holes> holeFace; //������ ��������� (12 ��.)
public:
	Detail(string NameOfDetail, Material Mater, double height, double width, double thickness);
	virtual ~Detail()=0;

	void SetMaterial(Material Mater);
	void SetHeight(double height);
	void SetWidth(double width);
	void SetThickness(double thickness);
	void addHoleFace(string CodeHole, double diameter, double Xcoordinate, double Ycoordinate, double depth);

	string GetName();
	Material GetMaterial();
	double GetHeight();
	double GetWidth();
	double GetThickness();
	virtual int GetCountHoles();

	virtual void toTXT();
};

