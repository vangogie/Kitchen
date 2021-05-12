/// /////////////����� ���������� ��������� � �������
#pragma once //��������� ��� ���������� ������������ ���������
#include <iostream> //���������� ������ � ��������� � �������� �����-������

using namespace std;

class Holes
{
private:
	double diameter; //������� ���������
	double Xcoordinate;//������ ������� � �������� ������ ���� - � �� ����������� �����-�������
	double Ycoordinate;//������ ������� � �������� ������ ���� - Y �� ��������� ������-����
	double depth; //������� ���������
public:
	Holes();
	Holes(double diameter, double Xcoordinate, double Ycoordinate, double depth);
	~Holes();

	void SetDiameter(double diameter);
	void SetXcoordinate(double Xcoordinate);
	void SetYcoordinate(double Ycoordinate);
	void SetDepth(double depth);

	double GetDiameter();
	double GetXcoordinate();
	double GetYcoordinate();
	double GetDepth();

	friend ostream& operator<<(ostream& zout, Holes& H);
};

