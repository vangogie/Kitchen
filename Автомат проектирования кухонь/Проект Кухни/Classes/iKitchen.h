#pragma once //��������� ��� ���������� ������������ ���������
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <cstdlib> //���������� ��� �������
#include <ctime> //���������� ��� �������
#include <iomanip> //���������� ��������
#include <windows.h> //���������� ��� �������� �������
#include <conio.h> //���������� ������� ������� ��������� ������� (getch)
#include <fstream> //���������� ������ � �������
#include <stdio.h> //���������� ������ � ������ ������
#include <filesystem> //���������� ������ � �������
#include <string> //���������� ������ � ��������
#include <vector> //���������� ������ � ���������
#include <algorithm> //�������� ��� STL ���������
#include <map> //���������� �������������� ������
#include "MaterialBASE.h"
#include "Material.h"
#include "Modules.h"
#include "CupBoard.h"
#include "Cabinet.h"

using namespace std;

class iKitchen
{
private:
	vector<CupBoard> MyKitchenCupBoard;//������ ��������� �����
	vector<Cabinet> MyKitchenCabinet; //������ �������� �����
	MaterialBASE Sklad; //���� ����������
	//���������������� ����������
	Material MatDsp;//�������� ��������
	Material MatTorts;//�������� ��������
	Material MatFas;//�������� �������
	Material FasPokr;//�������� �������� ������� 
	int fasadtype;//����� �������
	int fasadRadius;//������ ���������� ��������� �������
	Material MatFurnit;//�������� ���������
	Material BackWallMaterial;//�������� ������ ������
	Material fix;//����������
	Material legs;//�����
	double holesCost;//��������� ��������� ������ ���������
	double AllCost;//����� ��������� �����
	void MessageCost(string &temp, Material M, double QTY, double cost);
	void SetZeroAll();
	void intoHTML();
public:
	iKitchen();
	~iKitchen();
	
	void SetMatDsp(Material MatDsp);
	void SetMatTorts(Material MatTorts);
	void SetMatFas(Material MatFas);
	void SetFasPokr(Material FasPokr);
	void Setfasadtype(int fasadtype);
	void SetfasadRadius(int fasadRadius);
	void SetMatFurnit(Material MatFurnit);
	void SetBackWallMaterial(Material BackWallMaterial);
	void Setfix(Material fix);
	void SetLegs(Material legs);

	

	string Calculation();
	bool intoWork();

	bool GenerateModule(int classModule, int typeModule, double height, double width, double depth);
	string ShowModules();

	string ShowModulesShort();

	string GetMatDsp();
	string GetMatTorts();
	string GetMatFas();
	string GetFasPokr();
	string Getfasadtype();
	string GetfasadRadius();
	string GetMatFurnit();
	string GetBackWallMaterial();
	string Getfix();
	string GetLegs();
	double GetAllCost();
};

