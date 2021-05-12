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

using namespace std;

struct ParamBase
{
	Material Material;
	double QTY; //����������
	int article; //�������
	double cost = 0; //��������� ��������� (�� ������� ���������)
};


class MaterialBASE
{
protected:
	vector<ParamBase> BASE;
	int articleCounter = 0;
	void ToLibrary();
public:
	MaterialBASE();
	~MaterialBASE();

	void AddMaterial(Material NewMaterial, double QTY);
	void AddMaterial(Material NewMaterial, double QTY, double cost);

	bool HaveMaterial(Material NewMaterial, double QTY);//����� ��������, ������� �� ��������� � ����
	bool TakeMaterial(Material NewMaterial, double QTY);//����� ��������, ������� �� ��������� � ���� + ���� ������� �� �������� ���
	double CostMaterial(Material M);//����� ����������� �������� � ������������ ��� ��������� (���� �� ����� - ���������� ����)
	double QTYcostMaterial(Material M, double QTY); //����� ����������� �������� � ���������� � ������������ ��������� ����� ���������� ���������� (���� �� ����� - ���������� ����)
	
	int GetSize();//���������� ������ ����
	string GetMaterial(string type, int i); //���������� ������������ ������� ��� ����� ��� ���� � �������
	double GetCosting(int i); //���������� ���� ���������
	double GetQTY(int i);//���������� ���������� ���������
	bool isDSP(int i);//���������, �������� �� ������� ���
	bool isMDF(int i);//���������, �������� �� ������� ���
	bool isHDF(int i);//���������, �������� �� ������� ��� (������ �������)
	bool isFurniture(int i);//���������, �������� �� ������� ���������� (������)
	bool isFix(int i);//���������, �������� �� ������� ��������
	bool isTorts(int i);//���������, �������� �� ������� ���������
	bool isFasadCover(int i);//���������, �������� �� ������� �������
	bool isLeg(int i);//���������, �������� �� ������� �������
	string GetMaterial(int i);//�������� �������� � ���� ������
	Material TakeMaterial(int i);//�������� �������� � ���� ���������
	void FromLibrary();//������ �� ����������

	
	
	friend ostream& operator<<(ostream& zout, MaterialBASE& M);
};

