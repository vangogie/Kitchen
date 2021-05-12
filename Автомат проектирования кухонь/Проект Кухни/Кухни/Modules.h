#pragma once
#include <iostream> //���������� ������ � ��������� � �������� �����-������
#include <vector> //���������� ������ � ���������
#include <algorithm> //�������� ��� STL ���������
#include "Material.h"
#include "Fasade.h"
#include "DSP.h"
#include "BackWall.h"

using namespace std;

class Modules
{
protected:
	//�������� ���������:
	double height;//������ ������
	double width; //������ ������
	double depth; //������� ������
	vector<DSP> Dsp; //������ �������
	vector<Material> Furniture; //���������
	vector<Fasade> Fasad; //������
	vector<BackWall> BackW; //������ ������
	//��������� �����
	string Name = "";//����������� ��������
	Material MatDsp;//�������� ���
	Material MatFas;//�������� �������
	Material FasPokr;//�������� �������
	int fasadtype1;//������ ���������� �������
	int fasadRadius;//������ ���������� ������ �������
	Material MatFurnit;//��������� (�����)
	Material MatTorts;//�������� ��������
	Material BackWallMaterial;//�������� ������ ������
	Material fix;//������ (����������)
	/////////////////////////////////////////////
	//���������� �������� ��������� ��� ��������� � ���������� ����������
	double squareDSP;//������� ��� ��� ������ �2
	double squareFasades;//������� ������� �2
	double squareBackWall;//������� ������ ������ �2
	double lengthOfTorts;//����� �������� �
	int countHoles;//���������� �������� ��
	int countFixes;//���������� ��������� ��������� (�����������) ��
	int countFurniture;//���������� ������ ��
	
	int thicknessDSP = 16; //������� ��� �� ���������
	int thicknessFasade = 19; //������� ������ �� ���������
	int thicknessHDF = 3; //������� ������ ������

	//��������� ����������
	const int diamHead = 7; //7 �� ��� ������ ����������
	const int diambody = 5; //5 �� ��� ���� ����������
	const int depthlength = 37; //37 �� ��� ������� ���������
	const int lengthFromEdge = 40;//���������� �� ���� ��� �� �������� ���������
	const int lengthFromEdgeSmall = 25; //���������� ��� ����� ���
	const int lengthFromEdgeSmall2 = 75; //���������� ��� ����� ��� ������ ���������
	const int FASADdiamHole = 35; //35 �� ������� ��� �����
	const int FASADdepthHole = 13; //������� ��������� ��� �����
	const int FASADfromEdge = 100; //���������� �� ���� ������ �� ��������� ��� �����
	const int FASADSmallEdge = 22; //22 �� ��������� ���������� �������� �� ���� �� ��������� ��� �����
	const int HDFdiamHole = 100; //��������� � ������ ������ ��� ����� ��� �����
	const int HDFzazor = 4; //������ ������ �� 4 �� ������ �������� �� ���� ��������

	void ALLClear();//����� ������� ���� ������� ������
public:
	Modules(double height, double width, double depth);
	virtual ~Modules()=0;

	double GetSquareDSP();//������� ��� ��� ������ �2
	double GetSquareFasades();//������� ������� �2
	double GetSquareBackWall();//������� ������ ������ �2
	double GetLengthOfTorts();//����� �������� �
	int GetCountHoles();//���������� �������� ��
	int GetCountFixes();//���������� ��������� ��������� (�����������) ��
	int GetCountFurniture();//���������� ������ ��
	string toUserShort();

	void toTXT();
	string StringForTXT();
	string toUser();
};

