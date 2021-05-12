#include "CupBoard.h"


void CupBoard::ALLCount()
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
		double tempS = (iter->GetHeight()*iter->GetWidth())/1000000;//�2
		squareDSP += tempS;
		//������� ���������� ��������� � ���������� �� � ������ ���������� ���������:
		int tempH = iter->GetCountHoles();//��
		countHoles += tempH;
		//������� �������� � ���������� �� � ������ ������� ��������
		double tempT;
		if (iter->GetName() == "��������")
		{
			tempT = ((iter->GetHeight() * 2) + (iter->GetWidth() * 2))/1000;//�� ���������
		}
		else
		{
			tempT = (iter->GetHeight() * 2)/1000;//�� �������� � ������ ������� ������
		}
		lengthOfTorts += tempT;
	}
	//							��� ������ ������:
	for (vector<BackWall>::iterator iter = BackW.begin(); iter != BackW.end(); iter++)
	{
		double tempS = (iter->GetHeight()*iter->GetWidth())/1000000;//�2
		squareBackWall += tempS;
		int tempH = iter->GetCountHoles();//��
		countHoles += tempH;
	}
	//							��� �������:
	for (vector<Fasade>::iterator iter = Fasad.begin(); iter != Fasad.end(); iter++)
	{
		double tempF = (iter->GetHeight()*iter->GetWidth())/1000000;//�2
		squareFasades += tempF;
		int tempH = iter->GetCountHoles();//��
		countHoles += tempH;
	}
}

CupBoard::CupBoard(double height, double width, double depth, Material MatDsp, Material MatTorts, Material MatFas, Material FasPokr, int fasadtype, int fasadRadius, Material MatFurnit, Material BackWallMaterial, Material fix) : Modules(height, width, depth)
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

CupBoard::~CupBoard()
{
}

void CupBoard::TwoShelves()
{
	ALLClear();//������� ������� �� ������ ���� ��� ���������
	//////////������������� ��������//////////////////////////////////////
	Name = "������� � ����� �������";
	//////////////////��������� ��������/////////////////////////////////
	DSP DSPSide("��������", this->MatDsp, this->height, this->depth, thicknessDSP, MatTorts);
	//��������� ��� ��� ��������:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, this->depth - lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	//��������� ��� ������:
	DSPSide.addHoleFace("3", diamHead, lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, this->depth - lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	//�������� ��� ����� 1:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, this->depth - lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//��������� ��� ����� 2:
	DSPSide.addHoleFace("7", diamHead, lengthFromEdge, this->height-(((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("8", diamHead, this->depth - lengthFromEdge, this->height - (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//������ ��� �������� � ������
	Dsp.push_back(DSPSide);//��������� ���� ��������
	Dsp.push_back(DSPSide);//��������� ������ ��������
	//////////////////��������� �����////////////////////////////////////
	DSP DSPSelves("�����", this->MatDsp, this->width - (thicknessDSP * 2), this->depth, thicknessDSP, MatTorts);
	//��������� ��������� �� ����� ������:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, this->depth - lengthFromEdge, depthlength);
	//��������� ��������� �� ����� �����:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, this->depth - lengthFromEdge, depthlength);
	//������ ������ ����� (������ + ��� + ��� �����):
	Dsp.push_back(DSPSelves);//������
	Dsp.push_back(DSPSelves);//���
	Dsp.push_back(DSPSelves);//����� 1
	Dsp.push_back(DSPSelves);//����� 2
	//��������� ������� � ������ ������:
	BackWall BackWallone("������ ������", this->BackWallMaterial, this->height - HDFzazor, this->width- HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth()-1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//��������� �����:
	Fasade FasadeOne("�����", MatFas, this->height - 4, this->width - 4, thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight()-FASADfromEdge, FASADdepthHole);
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
	ALLCount();//������� ��� �������, ��������� � �.�.
}

void CupBoard::TwoShelvesTwoFasades()
{
	ALLClear();//������� ������� �� ������ ���� ��� ���������
	//////////������������� ��������//////////////////////////////////////
	Name = "������� � ����� ������� � ����� ��������";
	//////////////////��������� ��������/////////////////////////////////
	DSP DSPSide("��������", this->MatDsp, this->height, this->depth, thicknessDSP, MatTorts);
	//��������� ��� ��� ��������:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, this->depth - lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	//��������� ��� ������:
	DSPSide.addHoleFace("3", diamHead, lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, this->depth - lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	//�������� ��� ����� 1:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, this->depth - lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//��������� ��� ����� 2:
	DSPSide.addHoleFace("7", diamHead, lengthFromEdge, this->height - (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("8", diamHead, this->depth - lengthFromEdge, this->height - (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//������ ��� �������� � ������
	Dsp.push_back(DSPSide);//��������� ���� ��������
	Dsp.push_back(DSPSide);//��������� ������ ��������
	//////////////////��������� �����////////////////////////////////////
	DSP DSPSelves("�����", this->MatDsp, this->width - (thicknessDSP * 2), this->depth, thicknessDSP, MatTorts);
	//��������� ��������� �� ����� ������:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, this->depth - lengthFromEdge, depthlength);
	//��������� ��������� �� ����� �����:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, this->depth - lengthFromEdge, depthlength);
	//������ ������ ����� (������ + ��� + ��� �����):
	Dsp.push_back(DSPSelves);//������
	Dsp.push_back(DSPSelves);//���
	Dsp.push_back(DSPSelves);//����� 1
	Dsp.push_back(DSPSelves);//����� 2
	//��������� ������� � ������ ������:
	BackWall BackWallone("������ ������", this->BackWallMaterial, this->height - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//��������� ������:
	Fasade FasadeOne("�����", MatFas, this->height - 4, ((this->width/2) - 4), thicknessFasade, FasPokr, fasadtype1, fasadRadius);
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
	for (countFixes = 0; countFixes < 16; countFixes++)
	{
		Furniture.push_back(fix);
	}
	ALLCount();//������� ��� �������, ��������� � �.�.
}

void CupBoard::OneShelve()
{
	ALLClear();//������� ������� �� ������ ���� ��� ���������
	//////////������������� ��������//////////////////////////////////////
	Name = "������� � ����� ������";
	//////////////////��������� ��������/////////////////////////////////
	DSP DSPSide("��������", this->MatDsp, this->height, this->depth, thicknessDSP, MatTorts);
	//��������� ��� ��� ��������:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, this->depth - lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	//��������� ��� ������:
	DSPSide.addHoleFace("3", diamHead, lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, this->depth - lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	//�������� ��� �����:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 2) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, this->depth - lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 2) + thicknessDSP), thicknessDSP);
	//������ ��� �������� � ������
	Dsp.push_back(DSPSide);//��������� ���� ��������
	Dsp.push_back(DSPSide);//��������� ������ ��������
	//////////////////��������� �����////////////////////////////////////
	DSP DSPSelves("�����", this->MatDsp, this->width - (thicknessDSP * 2), this->depth, thicknessDSP, MatTorts);
	//��������� ��������� �� ����� ������:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, this->depth - lengthFromEdge, depthlength);
	//��������� ��������� �� ����� �����:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, this->depth - lengthFromEdge, depthlength);
	//������ ��� ����� (������ + ��� + �����):
	Dsp.push_back(DSPSelves);//������
	Dsp.push_back(DSPSelves);//���
	Dsp.push_back(DSPSelves);//����� 1
	//��������� ������� � ������ ������:
	BackWall BackWallone("������ ������", this->BackWallMaterial, this->height - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//��������� �����:
	Fasade FasadeOne("�����", MatFas, this->height - 4, this->width - 4, thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	//��������� ���������:
	for (countFurniture = 0; countFurniture < 2; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//��������� ����������:
	for (countFixes = 0; countFixes < 12; countFixes++)
	{
		Furniture.push_back(fix);
	}
	ALLCount();//������� ��� �������, ��������� � �.�.
}

void CupBoard::NoShelves()
{
	ALLClear();//������� ������� �� ������ ���� ��� ���������
	//////////������������� ��������//////////////////////////////////////
	Name = "������� ��� ������ (��� �����)";
	//////////////////��������� ��������/////////////////////////////////
	DSP DSPSide("��������", this->MatDsp, this->height, this->depth, thicknessDSP, MatTorts);
	//��������� ��� ��� ��������:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, this->depth - lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	//��������� ��� ������:
	DSPSide.addHoleFace("3", diamHead, lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, this->depth - lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	//������ ��� �������� � ������
	Dsp.push_back(DSPSide);//��������� ���� ��������
	Dsp.push_back(DSPSide);//��������� ������ ��������
	//////////////////��������� �����////////////////////////////////////
	DSP DSPSelves("�����", this->MatDsp, this->width - (thicknessDSP * 2), this->depth, thicknessDSP, MatTorts);
	//��������� ��������� �� ����� ������:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, this->depth - lengthFromEdge, depthlength);
	//��������� ��������� �� ����� �����:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, this->depth - lengthFromEdge, depthlength);
	//������ ��� ����� (������):
	Dsp.push_back(DSPSelves);//������
	Dsp.push_back(DSPSelves);//���
	//��������� ������� � ������ ������:
	BackWall BackWallone("������ ������", this->BackWallMaterial, this->height - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//��������� �����:
	Fasade FasadeOne("�����", MatFas, this->height - 4, this->width - 4, thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	//��������� ���������:
	for (countFurniture = 0; countFurniture < 2; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//��������� ����������:
	for (countFixes = 0; countFixes < 12; countFixes++)
	{
		Furniture.push_back(fix);
	}
	ALLCount();//������� ��� �������, ��������� � �.�.
}



string CupBoard::toUser()
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
	Text += "\n\n";
	return Text;
}


ostream & operator<<(ostream & zout, CupBoard & C)
{
	zout << C.Name << endl;
	for (vector<DSP>::iterator i = C.Dsp.begin(); i < C.Dsp.end(); i++)
	{
		zout << *i << endl << endl;
	}
	for (vector<Fasade>::iterator i = C.Fasad.begin(); i < C.Fasad.end(); i++)
	{
		zout << *i << endl << endl;
	}
	for (vector<BackWall>::iterator i = C.BackW.begin(); i < C.BackW.end(); i++)
	{
		zout << *i << endl << endl;
	}
	for (vector<Material>::iterator i = C.Furniture.begin(); i < C.Furniture.end(); i++)
	{
		zout << *i << endl << endl;
	}
	return zout;
}
