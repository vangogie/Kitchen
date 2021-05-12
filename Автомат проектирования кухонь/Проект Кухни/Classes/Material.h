#pragma once
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <string> //���������� ������ � ��������
#include <fstream> //���������� ������ � �������

using namespace std;
/// /////////////////////////////////////////////////////////////////////////////////

class Material
{
private:
	string brand;			//�������������
	string typeOfMaterial;	//��� ���������, �������� ��� ��� �����
	string designation;		//����������� ���������
	string dimension;		//����������� (��, �2 � ��.)

public:
	Material();
	Material(string brand, string typeOfMaterial, string designation, string dimension);
	Material(const Material& M); //����������� �����������
	~Material();

	void SetBrand(string brand);
	void SetTypeOfMaterial(string typeOfMaterial);
	void SetDesignation(string designation);
	void SetDimension(string dimension);

	string GetBrand();
	string GetTypeOfMaterial();
	string GetDesignation();
	string GetDimension();

	string StringForTXT();
	
	bool operator == (const Material& obj); //������������ ����������� �� ���� �����: �����, ��� ��������� � �����������
	bool operator<(const Material & obj);
	friend ostream& operator<<(ostream& zout, Material& M);
};

