#include "Cabinet.h"


void Cabinet::ALLCount()
{
	//�������� ��� ��������
	squareDSP = 0.0;//������� ��� ��� ������
	squareFasades = 0.0;//������� �������
	squareBackWall = 0.0;//������� ������ ������
	lengthOfTorts = 0.0;//����� ��������
	countHoles = 0;//���������� ��������
	//������� ������� ��������:
	//							��� ���:
	for (vector<DSP>::iterator iter = Dsp.begin(); iter != Dsp.end(); iter++)
	{
		//������� ������� ��� � ���������� �� � ����� �������:
		double tempS = (iter->GetHeight()*iter->GetWidth()) / 1000000;//�2
		squareDSP += tempS;
		//������� ���������� ��������� � ���������� �� � ������ ���������� ���������:
		int tempH = iter->GetCountHoles();//��
		countHoles += tempH;
		//������� �������� � ���������� �� � ������ ������� ��������
		double tempT;
		if (iter->GetName() == "���")
		{
			tempT = ((iter->GetHeight() * 2) + (iter->GetWidth() * 2)) / 1000;//�� ���������
		}
		else
		{
			tempT = (iter->GetHeight() * 2) / 1000;//�� �������� � ������ ������� ������
		}
		lengthOfTorts += tempT;
	}
	//							��� ������ ������:
	for (vector<BackWall>::iterator iter = BackW.begin(); iter != BackW.end(); iter++)
	{
		double tempS = (iter->GetHeight()*iter->GetWidth()) / 1000000;//�2
		squareBackWall += tempS;
		int tempH = iter->GetCountHoles();//��
		countHoles += tempH;
	}
	//							��� �������:
	for (vector<Fasade>::iterator iter = Fasad.begin(); iter != Fasad.end(); iter++)
	{
		double tempF = (iter->GetHeight()*iter->GetWidth()) / 1000000;//�2
		squareFasades += tempF;
		int tempH = iter->GetCountHoles();//��
		countHoles += tempH;
	}
}

Cabinet::Cabinet(double height, double width, double depth, Material MatDsp, Material MatTorts, Material MatFas, Material FasPokr, int fasadtype, int fasadRadius, Material MatFurnit, Material BackWallMaterial, Material fix, Material MatLegs) : Modules(height, width, depth)
{
	this->MatDsp = MatDsp;
	this->MatFas = MatFas;
	this->FasPokr = FasPokr;
	this->MatTorts = MatTorts;
	this->fasadtype1 = fasadtype;
	this->fasadRadius = fasadRadius;
	this->MatFurnit = MatFurnit;
	this->fix = fix;
	this->BackWallMaterial = BackWallMaterial;
	this->MatLegs = MatLegs;
	//���������� ������ ������� ���������� �� ������������ ���������:
	//��� ���:
	size_t digits = MatDsp.GetTypeOfMaterial().find_first_of("1234567890");
	if (digits <= MatDsp.GetTypeOfMaterial().size())
	{
		thicknessDSP = atoi(MatDsp.GetTypeOfMaterial().c_str() + digits);
	}
	//��� ������:
	size_t digits2 = MatFas.GetTypeOfMaterial().find_first_of("1234567890");
	if (digits2 <= MatFas.GetTypeOfMaterial().size())
	{
		thicknessFasade = atoi(MatFas.GetTypeOfMaterial().c_str() + digits2);
	}
	//��� ������ ������
	size_t digits3 = BackWallMaterial.GetTypeOfMaterial().find_first_of("1234567890");
	if (digits3 <= BackWallMaterial.GetTypeOfMaterial().size())
	{
		thicknessHDF = atoi(BackWallMaterial.GetTypeOfMaterial().c_str() + digits3);
	}
}

Cabinet::~Cabinet()
{
}

void Cabinet::TwoShelves()
{
	ALLClear();//������� ������� �� ������ ���� ��� ���������
	//////////������������� ��������//////////////////////////////////////
	//��������������� ����������:
	double H = (this->height - legHeight - thicknessDSP);//������ ��������
	double Dpth = (this->depth - thicknessFasade);//������ ��������
	Name = "�������� � ����� �������";
	//////////////////��������� ��������/////////////////////////////////
	DSP DSPSide("��������", this->MatDsp, H, Dpth, thicknessDSP, MatTorts);
	//��������� ��� ������:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdgeSmall, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, lengthFromEdgeSmall2, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("3", diamHead, Dpth - lengthFromEdgeSmall, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, Dpth - lengthFromEdgeSmall2, H - (thicknessDSP / 2), thicknessDSP);
	//�������� ��� ����� 1:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((H - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, Dpth - lengthFromEdge, (((H - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//��������� ��� ����� 2:
	DSPSide.addHoleFace("7", diamHead, lengthFromEdge, H - (((H - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("8", diamHead, Dpth - lengthFromEdge, H - (((H - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//������ ��������� ����� ��� ��������� � ���
	//��������� ��������� �� ����� �����:
	DSPSide.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSide.AddHoleDown("C2", diambody, Dpth - lengthFromEdge, depthlength);
	//������ ��� �������� � ������
	Dsp.push_back(DSPSide);//��������� ���� ��������
	Dsp.push_back(DSPSide);//��������� ������ ��������
	//////////////////��������� �����////////////////////////////////////
	DSP DSPSelves("�����", this->MatDsp, this->width - (thicknessDSP * 2), Dpth, thicknessDSP, MatTorts);
	//��������� ��������� �� ����� ������:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, Dpth - lengthFromEdge, depthlength);
	//��������� ��������� �� ����� �����:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, Dpth - lengthFromEdge, depthlength);
	//������ ��� �����:
	Dsp.push_back(DSPSelves);//����� 1
	Dsp.push_back(DSPSelves);//����� 2
	////////////////////��������� ������� ���������/////////////////////
	DSP DSPBridge("���������", this->MatDsp, this->width - (thicknessDSP * 2), 100.0, thicknessDSP, MatTorts);//achtung
	//��������� ��������� �� ����� ������:
	DSPBridge.AddHoleUp("A1", diambody, lengthFromEdgeSmall, depthlength);
	DSPBridge.AddHoleUp("A2", diambody, lengthFromEdgeSmall2, depthlength);
	//��������� ��������� �� ����� �����:
	DSPBridge.AddHoleDown("C1", diambody, lengthFromEdgeSmall, depthlength);
	DSPBridge.AddHoleDown("C2", diambody, lengthFromEdgeSmall2, depthlength);
	//������ ��� ���������:
	Dsp.push_back(DSPBridge);//��������� 1
	Dsp.push_back(DSPBridge);//��������� 2
	///////////////////��������� ���///////////////////////////////////
	DSP DSPBottom("���", this->MatDsp, Dpth, this->width, thicknessDSP, MatTorts);
	//��������� ��� ������:
	DSPBottom.addHoleFace("1", diamHead, (thicknessDSP / 2), lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("2", diamHead, (thicknessDSP / 2), Dpth - lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("3", diamHead, this->width - (thicknessDSP / 2), lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("4", diamHead, this->width - (thicknessDSP / 2), Dpth - lengthFromEdge, thicknessDSP);
	Dsp.push_back(DSPBottom);//���
	/////////////////��������� ������ ������:
	BackWall BackWallone("������ ������", this->BackWallMaterial, H - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//��������� �����:
	Fasade FasadeOne("�����", MatFas, (this->height - legHeight - 4), this->width - 4, thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	//��������� ���������:
	for (countFurniture = 0; countFurniture < 2; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//��������� ����������:
	for (countFixes = 0; countFixes < 20; countFixes++)
	{
		Furniture.push_back(fix);
	}
	for (countLegs = 0; countLegs < 4; countLegs++)
	{
		Furniture.push_back(MatLegs);
	}
	ALLCount();//������� ��� �������, ��������� � �.�.
}

void Cabinet::TwoShelvesTwoFasades()
{
	ALLClear();//������� ������� �� ������ ���� ��� ���������
	//////////������������� ��������//////////////////////////////////////
	//��������������� ����������:
	double H = (this->height - legHeight - thicknessDSP);//������ ��������
	double Dpth = (this->depth - thicknessFasade);//������ ��������
	Name = "�������� � ����� ������� � ����� ��������";
	//////////////////��������� ��������/////////////////////////////////
	DSP DSPSide("��������", this->MatDsp, H, Dpth, thicknessDSP, MatTorts);
	//��������� ��� ������:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdgeSmall, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, lengthFromEdgeSmall2, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("3", diamHead, Dpth - lengthFromEdgeSmall, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, Dpth - lengthFromEdgeSmall2, H - (thicknessDSP / 2), thicknessDSP);
	//�������� ��� ����� 1:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((H - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, Dpth - lengthFromEdge, (((H - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//��������� ��� ����� 2:
	DSPSide.addHoleFace("7", diamHead, lengthFromEdge, H - (((H - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("8", diamHead, Dpth - lengthFromEdge, H - (((H - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//������ ��������� ����� ��� ��������� � ���
	//��������� ��������� �� ����� �����:
	DSPSide.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSide.AddHoleDown("C2", diambody, Dpth - lengthFromEdge, depthlength);
	//������ ��� �������� � ������
	Dsp.push_back(DSPSide);//��������� ���� ��������
	Dsp.push_back(DSPSide);//��������� ������ ��������
	//////////////////��������� �����////////////////////////////////////
	DSP DSPSelves("�����", this->MatDsp, this->width - (thicknessDSP * 2), Dpth, thicknessDSP, MatTorts);
	//��������� ��������� �� ����� ������:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, Dpth - lengthFromEdge, depthlength);
	//��������� ��������� �� ����� �����:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, Dpth - lengthFromEdge, depthlength);
	//������ ��� �����:
	Dsp.push_back(DSPSelves);//����� 1
	Dsp.push_back(DSPSelves);//����� 2
	////////////////////��������� ������� ���������/////////////////////
	DSP DSPBridge("���������", this->MatDsp, this->width - (thicknessDSP * 2), 100.0, thicknessDSP, MatTorts);//achtung
	//��������� ��������� �� ����� ������:
	DSPBridge.AddHoleUp("A1", diambody, lengthFromEdgeSmall, depthlength);
	DSPBridge.AddHoleUp("A2", diambody, lengthFromEdgeSmall2, depthlength);
	//��������� ��������� �� ����� �����:
	DSPBridge.AddHoleDown("C1", diambody, lengthFromEdgeSmall, depthlength);
	DSPBridge.AddHoleDown("C2", diambody, lengthFromEdgeSmall2, depthlength);
	//������ ��� ���������:
	Dsp.push_back(DSPBridge);//��������� 1
	Dsp.push_back(DSPBridge);//��������� 2
	///////////////////��������� ���///////////////////////////////////
	DSP DSPBottom("���", this->MatDsp, Dpth, this->width, thicknessDSP, MatTorts);
	//��������� ��� ������:
	DSPBottom.addHoleFace("1", diamHead, (thicknessDSP / 2), lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("2", diamHead, (thicknessDSP / 2), Dpth - lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("3", diamHead, this->width - (thicknessDSP / 2), lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("4", diamHead, this->width - (thicknessDSP / 2), Dpth - lengthFromEdge, thicknessDSP);
	Dsp.push_back(DSPBottom);//���
	/////////////////��������� ������ ������:
	BackWall BackWallone("������ ������", this->BackWallMaterial, H - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//��������� ������:
	Fasade FasadeOne("�����", MatFas, (this->height - legHeight - 4), ((this->width/2) - 8), thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	Fasad.push_back(FasadeOne);
	//��������� ���������:
	for (countFurniture = 0; countFurniture < 4; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//��������� ����������:
	for (countFixes = 0; countFixes < 20; countFixes++)
	{
		Furniture.push_back(fix);
	}
	for (countLegs = 0; countLegs < 4; countLegs++)
	{
		Furniture.push_back(MatLegs);
	}
	ALLCount();//������� ��� �������, ��������� � �.�.
}

void Cabinet::OneShelve()
{
	ALLClear();//������� ������� �� ������ ���� ��� ���������
	//////////������������� ��������//////////////////////////////////////
	//��������������� ����������:
	double H = (this->height - legHeight - thicknessDSP);//������ ��������
	double Dpth = (this->depth - thicknessFasade);//������ ��������
	Name = "�������� � ����� ������";
	//////////////////��������� ��������/////////////////////////////////
	DSP DSPSide("��������", this->MatDsp, H, Dpth, thicknessDSP, MatTorts);
	//��������� ��� ������:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdgeSmall, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, lengthFromEdgeSmall2, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("3", diamHead, Dpth - lengthFromEdgeSmall, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, Dpth - lengthFromEdgeSmall2, H - (thicknessDSP / 2), thicknessDSP);
	//�������� ��� ����� 1:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((H - thicknessDSP) / 2) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, Dpth - lengthFromEdge, (((H - thicknessDSP) / 2) + thicknessDSP), thicknessDSP);
	//������ ��������� ����� ��� ��������� � ���
	//��������� ��������� �� ����� �����:
	DSPSide.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSide.AddHoleDown("C2", diambody, Dpth - lengthFromEdge, depthlength);
	//������ ��� �������� � ������
	Dsp.push_back(DSPSide);//��������� ���� ��������
	Dsp.push_back(DSPSide);//��������� ������ ��������
	//////////////////��������� �����////////////////////////////////////
	DSP DSPSelves("�����", this->MatDsp, this->width - (thicknessDSP * 2), Dpth, thicknessDSP, MatTorts);
	//��������� ��������� �� ����� ������:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, Dpth - lengthFromEdge, depthlength);
	//��������� ��������� �� ����� �����:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, Dpth - lengthFromEdge, depthlength);
	//������ ���� �����:
	Dsp.push_back(DSPSelves);//����� 1
	////////////////////��������� ������� ���������/////////////////////
	DSP DSPBridge("���������", this->MatDsp, this->width - (thicknessDSP * 2), 100.0, thicknessDSP, MatTorts);//achtung
	//��������� ��������� �� ����� ������:
	DSPBridge.AddHoleUp("A1", diambody, lengthFromEdgeSmall, depthlength);
	DSPBridge.AddHoleUp("A2", diambody, lengthFromEdgeSmall2, depthlength);
	//��������� ��������� �� ����� �����:
	DSPBridge.AddHoleDown("C1", diambody, lengthFromEdgeSmall, depthlength);
	DSPBridge.AddHoleDown("C2", diambody, lengthFromEdgeSmall2, depthlength);
	//������ ��� ���������:
	Dsp.push_back(DSPBridge);//��������� 1
	Dsp.push_back(DSPBridge);//��������� 2
	///////////////////��������� ���///////////////////////////////////
	DSP DSPBottom("���", this->MatDsp, Dpth, this->width, thicknessDSP, MatTorts);
	//��������� ��� ������:
	DSPBottom.addHoleFace("1", diamHead, (thicknessDSP / 2), lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("2", diamHead, (thicknessDSP / 2), Dpth - lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("3", diamHead, this->width - (thicknessDSP / 2), lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("4", diamHead, this->width - (thicknessDSP / 2), Dpth - lengthFromEdge, thicknessDSP);
	Dsp.push_back(DSPBottom);//���
	/////////////////��������� ������ ������:
	BackWall BackWallone("������ ������", this->BackWallMaterial, H - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//��������� �����:
	Fasade FasadeOne("�����", MatFas, (this->height - legHeight - 4), this->width - 4, thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	//��������� ���������:
	for (countFurniture = 0; countFurniture < 2; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//��������� ����������:
	for (countFixes = 0; countFixes < 16; countFixes++)
	{
		Furniture.push_back(fix);
	}
	for (countLegs = 0; countLegs < 4; countLegs++)
	{
		Furniture.push_back(MatLegs);
	}
	ALLCount();//������� ��� �������, ��������� � �.�.
}

void Cabinet::OneShelveTwoFasades()
{
	ALLClear();//������� ������� �� ������ ���� ��� ���������
	//////////������������� ��������//////////////////////////////////////
	//��������������� ����������:
	double H = (this->height - legHeight - thicknessDSP);//������ ��������
	double Dpth = (this->depth - thicknessFasade);//������ ��������
	Name = "�������� � ����� ������ � ����� ��������";
	//////////////////��������� ��������/////////////////////////////////
	DSP DSPSide("��������", this->MatDsp, H, Dpth, thicknessDSP, MatTorts);
	//��������� ��� ������:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdgeSmall, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, lengthFromEdgeSmall2, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("3", diamHead, Dpth - lengthFromEdgeSmall, H - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, Dpth - lengthFromEdgeSmall2, H - (thicknessDSP / 2), thicknessDSP);
	//�������� ��� ����� 1:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((H - thicknessDSP) / 2) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, Dpth - lengthFromEdge, (((H - thicknessDSP) / 2) + thicknessDSP), thicknessDSP);
	//������ ��������� ����� ��� ��������� � ���
	//��������� ��������� �� ����� �����:
	DSPSide.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSide.AddHoleDown("C2", diambody, Dpth - lengthFromEdge, depthlength);
	//������ ��� �������� � ������
	Dsp.push_back(DSPSide);//��������� ���� ��������
	Dsp.push_back(DSPSide);//��������� ������ ��������
	//////////////////��������� �����////////////////////////////////////
	DSP DSPSelves("�����", this->MatDsp, this->width - (thicknessDSP * 2), Dpth, thicknessDSP, MatTorts);
	//��������� ��������� �� ����� ������:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, Dpth - lengthFromEdge, depthlength);
	//��������� ��������� �� ����� �����:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, Dpth - lengthFromEdge, depthlength);
	//������ ���� �����:
	Dsp.push_back(DSPSelves);//����� 1
	////////////////////��������� ������� ���������/////////////////////
	DSP DSPBridge("���������", this->MatDsp, this->width - (thicknessDSP * 2), 100.0, thicknessDSP, MatTorts);//achtung
	//��������� ��������� �� ����� ������:
	DSPBridge.AddHoleUp("A1", diambody, lengthFromEdgeSmall, depthlength);
	DSPBridge.AddHoleUp("A2", diambody, lengthFromEdgeSmall2, depthlength);
	//��������� ��������� �� ����� �����:
	DSPBridge.AddHoleDown("C1", diambody, lengthFromEdgeSmall, depthlength);
	DSPBridge.AddHoleDown("C2", diambody, lengthFromEdgeSmall2, depthlength);
	//������ ��� ���������:
	Dsp.push_back(DSPBridge);//��������� 1
	Dsp.push_back(DSPBridge);//��������� 2
	///////////////////��������� ���///////////////////////////////////
	DSP DSPBottom("���", this->MatDsp, Dpth, this->width, thicknessDSP, MatTorts);
	//��������� ��� ������:
	DSPBottom.addHoleFace("1", diamHead, (thicknessDSP / 2), lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("2", diamHead, (thicknessDSP / 2), Dpth - lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("3", diamHead, this->width - (thicknessDSP / 2), lengthFromEdge, thicknessDSP);
	DSPBottom.addHoleFace("4", diamHead, this->width - (thicknessDSP / 2), Dpth - lengthFromEdge, thicknessDSP);
	Dsp.push_back(DSPBottom);//���
	/////////////////��������� ������ ������:
	BackWall BackWallone("������ ������", this->BackWallMaterial, H - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//��������� ������:
	Fasade FasadeOne("�����", MatFas, (this->height - legHeight - 4), ((this->width / 2) - 8), thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	Fasad.push_back(FasadeOne);
	//��������� ���������:
	for (countFurniture = 0; countFurniture < 2; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//��������� ����������:
	for (countFixes = 0; countFixes < 16; countFixes++)
	{
		Furniture.push_back(fix);
	}
	for (countLegs = 0; countLegs < 4; countLegs++)
	{
		Furniture.push_back(MatLegs);
	}
	ALLCount();//������� ��� �������, ��������� � �.�.
}

string Cabinet::toUser()
{
	Fasade tempF("����������� �����", MatFas, 1000, 500, 19, FasPokr, fasadtype1, fasadRadius);//��������� ����� ��� ������������� ������ toUser ���� �� ������������ ��� ��� � ��� ���������
	string Text = Name;
	Text += "\n������ ��������: "; Text += to_string(height); Text += " ��";
	Text += "\n������ ��������: "; Text += to_string(width); Text += " ��";
	Text += "\n������� ��������: "; Text += to_string(depth); Text += " ��";
	Text += "\n�������� �������: "; Text += MatDsp.GetBrand(); Text += ", "; Text += MatDsp.GetDesignation();
	Text += "\n��������: "; Text += MatTorts.GetBrand(); Text += ", "; Text += MatTorts.GetDesignation();
	Text += "\n������ ������: "; Text += BackWallMaterial.GetBrand(); Text += ", "; Text += BackWallMaterial.GetDesignation();
	Text += "\n";
	Text += tempF.toUser();
	Text += "���������: "; Text += MatFurnit.GetBrand(); Text += ", "; Text += MatFurnit.GetDesignation();
	Text += "\n";
	Text += "�����: "; Text += MatLegs.GetBrand(); Text += ", "; Text += MatLegs.GetDesignation();
	Text += "\n\n";
	return Text;
}

int Cabinet::GetCountLegs()
{
	return countLegs;
}
