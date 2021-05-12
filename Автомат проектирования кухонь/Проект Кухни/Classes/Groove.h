/// /////////////����� ���������� ���� � ������� ���
#pragma once //��������� ��� ���������� ������������ ���������
#include <iostream> //���������� ������ � ��������� � �������� �����-������

using namespace std;

class Groove
{
private:
	double width; //������ ����
	double depth; //������� ����
	double Xcoordinate;//������ ������� � �������� ������ ���� - Y �� ��������� ������-����
public:
	Groove();
	Groove(double width, double depth, double Xcoordinate);
	~Groove();
	Groove(const Groove& G); //����������� �����������

	void SetWidth(double width);
	void SetDepth(double depth);
	void SetXcoordinate(double Xcoordinate);

	double GetWidth();
	double GetDepth();
	double GetXcoodrinate();
};

