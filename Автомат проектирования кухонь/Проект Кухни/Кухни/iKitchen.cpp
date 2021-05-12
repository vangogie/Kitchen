#include "iKitchen.h"

void iKitchen::MessageCost(string &temp, Material M, double QTY, double cost)
{
	temp += M.GetTypeOfMaterial(); temp += " ";
	temp += M.GetBrand(); temp += " ";
	temp += M.GetDesignation();
	temp += ", ��������� (�� 1 "; temp += M.GetDimension();
	temp += "): "; temp += to_string(Sklad.CostMaterial(M));
	temp += " ���.\n����������� ����������: ";
	temp += to_string(QTY); temp += " "; temp += M.GetDimension();
	temp += "\n��������� ���������: "; temp += to_string(cost); temp += " ���.\n\n";
}

iKitchen::iKitchen()
{
	Sklad.FromLibrary();//��������� ���� ������ � �������� �����
	//�������� ��������� (�� �����) ��������� ������ ���������:
	ifstream zin;
	zin.open("D:\\iKitchen\\Librares\\HolesCost.txt");
	if (zin.is_open())
	{
		string Temp = "";
		char ch = ' ';
		while (!zin.eof())
		{
			while (zin.get(ch) && ch != '\n')
			{
				Temp += ch;
			}
		}
		zin.close();
		holesCost = atof(Temp.c_str());
	}
	else holesCost = 1.8;
	AllCost = 0.0;
}

iKitchen::~iKitchen()
{
}

void iKitchen::SetMatDsp(Material MatDsp)
{
	this->MatDsp = MatDsp;
}

void iKitchen::SetMatTorts(Material MatTorts)
{
	this->MatTorts = MatTorts;
}

void iKitchen::SetMatFas(Material MatFas)
{
	this->MatFas = MatFas;
}

void iKitchen::SetFasPokr(Material FasPokr)
{
	this->FasPokr = FasPokr;
}

void iKitchen::Setfasadtype(int fasadtype)
{
	this->fasadtype = fasadtype;
}

void iKitchen::SetfasadRadius(int fasadRadius)
{
	this->fasadRadius = fasadRadius;
}

void iKitchen::SetMatFurnit(Material MatFurnit)
{
	this->MatFurnit = MatFurnit;
}

void iKitchen::SetBackWallMaterial(Material BackWallMaterial)
{
	this->BackWallMaterial = BackWallMaterial;
}

void iKitchen::Setfix(Material fix)
{
	this->fix = fix;
}

void iKitchen::SetLegs(Material legs)
{
	this->legs = legs;
}

void iKitchen::SetZeroAll()
{
	MyKitchenCupBoard.clear();
	MyKitchenCabinet.clear();
	Sklad.FromLibrary();
	AllCost = 0.0;
}

void iKitchen::intoHTML()
{
	string html;

	html += "�������� ���: " + GetMatDsp();
	html += "�������� ��������: " + GetMatTorts();
	html += "�������� �������: " + GetMatFas();
	html += "������ �����������: " + GetFasPokr();
	html += "��� ������: " + Getfasadtype();
	html += "������ ���������� ������ ������: " + GetfasadRadius();
	html += "���������: " + GetMatFurnit();
	html += "����� ������: " + GetBackWallMaterial();
	html += "������: " + Getfix();
	html += "�����: " + GetLegs();

	for (vector<CupBoard>::iterator iter = MyKitchenCupBoard.begin(); iter < MyKitchenCupBoard.end(); iter++)
	{
		html += iter->StringForTXT();
	}
	for (vector<Cabinet>::iterator iter = MyKitchenCabinet.begin(); iter < MyKitchenCabinet.end(); iter++)
	{
		html += iter->StringForTXT();
	}
	string newFolder = "C:\\iKitchen\\";
	_mkdir((newFolder.c_str()));
	ofstream zout(newFolder + "My iKitchen.doc");
	if (zout.is_open())
	{
		zout << html;
		zout.close();
	}
	
}

string iKitchen::Calculation()
{
	////////������������� ����������
	string temp;
	double totalSquareDSP = 0.0; //����� ������� ���, �2
	double totalSquareFasades = 0.0; //����� ������� �������, �2
	double totalSquareBackWall = 0.0; //����� ������� ������ ������, �2
	double totalLengthOfTorts = 0.0; //����� ����� �������� �
	int totalCountHoles = 0; //����� ���������� ��������, ��
	int totalCountFixes = 0; //����� ���������� ��������� ��������� (�����������), ��
	int totalCountFurniture = 0; //���������� ������, ��
	int totalCountLegs = 0; //���������� �����, ��

	//����������� ���������� ���� ����������, ������������ � ������ ��������:
	for (vector<CupBoard>::iterator iter = MyKitchenCupBoard.begin(); iter < MyKitchenCupBoard.end(); iter++)
	{
		totalSquareDSP+=iter->GetSquareDSP();
		totalSquareFasades += iter->GetSquareFasades();
		totalSquareBackWall += iter->GetSquareBackWall();
		totalLengthOfTorts += iter->GetLengthOfTorts();
		totalCountHoles += iter->GetCountHoles();
		totalCountFixes += iter->GetCountFixes();
		totalCountFurniture += iter->GetCountFurniture();
	}

	//����������� ���������� ���� ����������, ������������ � ������ ��������:
	for (vector<Cabinet>::iterator iter = MyKitchenCabinet.begin(); iter < MyKitchenCabinet.end(); iter++)
	{
		totalSquareDSP += iter->GetSquareDSP();
		totalSquareFasades += iter->GetSquareFasades();
		totalSquareBackWall += iter->GetSquareBackWall();
		totalLengthOfTorts += iter->GetLengthOfTorts();
		totalCountHoles += iter->GetCountHoles();
		totalCountFixes += iter->GetCountFixes();
		totalCountFurniture += iter->GetCountFurniture();
		totalCountLegs += iter->GetCountLegs();
	}
	
	//����������� ������� �� ���������� � ���� ����������
	int errorCounter = 0;//�������������� ������� ���������� ������� �� �������
	//�������� ������� �� ��� ���:
	if (!Sklad.HaveMaterial(MatDsp, totalSquareDSP))
	{
		temp += MatDsp.GetBrand(); temp += " ";
		temp += MatDsp.GetDesignation(); temp += " �� ������� �� ������!\n";
		errorCounter++;
	}
	//�������� ������� �� ��� ��� �������:
	if (!Sklad.HaveMaterial(MatFas, totalSquareFasades))
	{
		temp += MatFas.GetBrand(); temp += " ";
		temp += MatFas.GetDesignation(); temp += " �� ������� �� ������!\n";
		errorCounter++;
	}
	//�������� ������� �� ��� �������� �������:
	if (!Sklad.HaveMaterial(FasPokr, totalSquareFasades))
	{
		temp += FasPokr.GetBrand(); temp += " ";
		temp += FasPokr.GetDesignation(); temp += " �� ������� �� ������!\n";
		errorCounter++;
	}

	//�������� ������� �� ��� ��� ������ ������:
	if (!Sklad.HaveMaterial(BackWallMaterial, totalSquareBackWall))
	{
		temp += BackWallMaterial.GetBrand(); temp += " ";
		temp += BackWallMaterial.GetDesignation(); temp += " �� ������� �� ������!\n";
		errorCounter++;
	}
	//�������� ������� �� ��� ��������:
	if (!Sklad.HaveMaterial(MatTorts, totalLengthOfTorts))
	{
		temp += MatTorts.GetBrand(); temp += " ";
		temp += MatTorts.GetDesignation(); temp += " �� ������� �� ������!\n";
		errorCounter++;
	}
	//�������� ������� �� ��� �����������:
	if (!Sklad.HaveMaterial(fix, totalCountFixes))
	{
		temp += fix.GetBrand(); temp += " ";
		temp += fix.GetDesignation(); temp += " �� ������� �� ������!\n";
		errorCounter++;
	}
	//�������� ������� �� ��� ���������:
	if (!Sklad.HaveMaterial(MatFurnit, totalCountFurniture))
	{
		temp += MatFurnit.GetBrand(); temp += " ";
		temp += MatFurnit.GetDesignation(); temp += " �� ������� �� ������!\n";
		errorCounter++;
	}
	//�������� ������� �� ��� ����� ��� ��������:
	if (!Sklad.HaveMaterial(legs, totalCountLegs))
	{
		temp += legs.GetBrand(); temp += " ";
		temp += legs.GetDesignation(); temp += " �� ������� �� ������!\n";
		errorCounter++;
	}
	//��������� ����� �� ��� ������� � ���� ����� ������� ����� ������� ���������
	if (errorCounter == 0)
	{
		double costDSP = Sklad.QTYcostMaterial(MatDsp, totalSquareDSP); //��������� ���
		double costFasad = Sklad.QTYcostMaterial(MatFas, totalSquareFasades); //��������� �������
		double costFasPokr = Sklad.QTYcostMaterial(FasPokr, totalSquareFasades); //��������� �������� �������
		double costBackWall = Sklad.QTYcostMaterial(BackWallMaterial, totalSquareBackWall); //��������� ������ ������
		double costTorts = Sklad.QTYcostMaterial(MatTorts, totalLengthOfTorts); //��������� ��������
		double costFixes = Sklad.QTYcostMaterial(fix, totalCountFixes); //��������� �������(�����������)
		double costFurniture = Sklad.QTYcostMaterial(MatFurnit, totalCountFurniture); //��������� ���������
		double costHoles = totalCountHoles * holesCost; //��������� ��������� ���������
		double costLegs = Sklad.QTYcostMaterial(legs, totalCountLegs); //��������� �����

		AllCost = costDSP + costFasad + costBackWall + costTorts + costFixes + costFurniture + costHoles + costLegs;

		//���������� ��������� ������������ �� ��������� ������������ ��� �����
		//��� ���:
		MessageCost(temp, MatDsp, totalSquareDSP, costDSP);
		
		//��� �������:
		MessageCost(temp, MatFas, totalSquareFasades, costFasad);

		//��� �������� �������:
		MessageCost(temp, FasPokr, totalSquareFasades, costFasPokr);

		//��� ������ ������:
		MessageCost(temp, BackWallMaterial, totalSquareBackWall, costBackWall);

		//��� ��������:
		MessageCost(temp, MatTorts, totalLengthOfTorts, costTorts);

		//��� ������� (�����������):
		MessageCost(temp, fix, totalCountFixes, costFixes);

		//��� ���������:
		MessageCost(temp, MatFurnit, totalCountFurniture, costFurniture);

		//��� �����:
		MessageCost(temp, legs, totalCountLegs, costLegs);

		//��� ���������:
		temp += "����� ���������� ���������: ";
		temp += to_string(totalCountHoles); temp += " ��.\n��������� ��������� ������ ���������: ";
		temp += to_string(holesCost); temp += " ���.\n";
		temp += "��������� ���������: "; temp += to_string(costHoles); temp += " ���.\n\n";

		//����� ��������� ���� �����:
		temp += "����� ��������� ���� �����: ";
		temp += to_string(AllCost); temp += " ���.";
	}
	return temp; 
}

bool iKitchen::intoWork()
{
	////////������������� ����������
	double totalSquareDSP = 0.0; //����� ������� ���, �2
	double totalSquareFasades = 0.0; //����� ������� �������, �2
	double totalSquareBackWall = 0.0; //����� ������� ������ ������, �2
	double totalLengthOfTorts = 0.0; //����� ����� �������� �
	int totalCountHoles = 0; //����� ���������� ��������, ��
	int totalCountFixes = 0; //����� ���������� ��������� ��������� (�����������), ��
	int totalCountFurniture = 0; //���������� ������, ��
	int totalCountLegs = 0; //���������� �����, ��

	//����������� ���������� ���� ����������, ������������ � ������ ��������:
	for (vector<CupBoard>::iterator iter = MyKitchenCupBoard.begin(); iter < MyKitchenCupBoard.end(); iter++)
	{
		totalSquareDSP += iter->GetSquareDSP();
		totalSquareFasades += iter->GetSquareFasades();
		totalSquareBackWall += iter->GetSquareBackWall();
		totalLengthOfTorts += iter->GetLengthOfTorts();
		totalCountHoles += iter->GetCountHoles();
		totalCountFixes += iter->GetCountFixes();
		totalCountFurniture += iter->GetCountFurniture();
	}

	//����������� ���������� ���� ����������, ������������ � ������ ��������:
	for (vector<Cabinet>::iterator iter = MyKitchenCabinet.begin(); iter < MyKitchenCabinet.end(); iter++)
	{
		totalSquareDSP += iter->GetSquareDSP();
		totalSquareFasades += iter->GetSquareFasades();
		totalSquareBackWall += iter->GetSquareBackWall();
		totalLengthOfTorts += iter->GetLengthOfTorts();
		totalCountHoles += iter->GetCountHoles();
		totalCountFixes += iter->GetCountFixes();
		totalCountFurniture += iter->GetCountFurniture();
		totalCountLegs += iter->GetCountLegs();
	}
	int errorCounter = 0;//�������������� ������� ���������� ������� �� �������
	//�������� ������� �� ��� ���:
	if (!Sklad.HaveMaterial(MatDsp, totalSquareDSP))
	{
		errorCounter++;
	}
	//�������� ������� �� ��� ��� �������:
	if (!Sklad.HaveMaterial(MatFas, totalSquareFasades))
	{
		errorCounter++;
	}
	//�������� ������� �� ��� �������� �������:
	if (!Sklad.HaveMaterial(FasPokr, totalSquareFasades))
	{
		errorCounter++;
	}

	//�������� ������� �� ��� ��� ������ ������:
	if (!Sklad.HaveMaterial(BackWallMaterial, totalSquareBackWall))
	{
		errorCounter++;
	}
	//�������� ������� �� ��� ��������:
	if (!Sklad.HaveMaterial(MatTorts, totalLengthOfTorts))
	{
		errorCounter++;
	}
	//�������� ������� �� ��� �����������:
	if (!Sklad.HaveMaterial(fix, totalCountFixes))
	{
		errorCounter++;
	}
	//�������� ������� �� ��� ���������:
	if (!Sklad.HaveMaterial(MatFurnit, totalCountFurniture))
	{
		errorCounter++;
	}
	//�������� ������� �� ��� ����� ��� ��������:
	if (!Sklad.HaveMaterial(legs, totalCountLegs))
	{
		errorCounter++;
	}
	//��������� ����� �� ��� ������� � ���� ����� ������� ����� ������� ���������
	if (errorCounter == 0)
	{
		//����� �� ���� ����������� ���������� ���������
		Sklad.TakeMaterial(MatDsp, totalSquareDSP);
		Sklad.TakeMaterial(MatFas, totalSquareFasades);
		Sklad.TakeMaterial(FasPokr, totalSquareFasades);
		Sklad.TakeMaterial(BackWallMaterial, totalSquareBackWall);
		Sklad.TakeMaterial(MatTorts, totalLengthOfTorts);
		Sklad.TakeMaterial(fix, totalCountFixes);
		Sklad.TakeMaterial(MatFurnit, totalCountFurniture);
		Sklad.TakeMaterial(legs, totalCountLegs);
		intoHTML();//���������� � ���� HTML

		SetZeroAll();//�������� ��� �����
		return true;
	}
	else return false;
}

bool iKitchen::GenerateModule(int classModule, int typeModule, double height, double width, double depth)
{
	if (classModule == 1) //��������
	{
		Cabinet NewModule(height, width, depth, MatDsp, MatTorts, MatFas, FasPokr, fasadtype, fasadRadius, MatFurnit, BackWallMaterial, fix, legs);
		if (typeModule == 1)//���� �����
		{
			NewModule.OneShelve();
			NewModule.toTXT();
		}
		else if (typeModule == 2)//���� ����� � ����� ��������
		{
			NewModule.OneShelveTwoFasades();
			NewModule.toTXT();
		}
		else if (typeModule == 3)//��� ����� � ����� �������
		{
			NewModule.TwoShelves();
			NewModule.toTXT();
		}
		else if (typeModule == 4)//��� ����� � ����� ��������
		{
			NewModule.OneShelveTwoFasades();
			NewModule.toTXT();
		}
		MyKitchenCabinet.push_back(NewModule);
	}
	else if (classModule == 2) //��������
	{
		CupBoard NewModule(height, width, depth, MatDsp, MatTorts, MatFas, FasPokr, fasadtype, fasadRadius, MatFurnit, BackWallMaterial, fix);
		if (typeModule == 1)//��� ����� (��� ������)
		{
			NewModule.NoShelves();
			NewModule.toTXT();
		}
		else if (typeModule == 2)//� ����� ������
		{
			NewModule.OneShelve();
			NewModule.toTXT();
		}
		else if (typeModule == 3)
		{
			NewModule.TwoShelves();//� ����� �������
			NewModule.toTXT();
		}
		else if (typeModule == 4)
		{
			NewModule.TwoShelvesTwoFasades();//� ����� ������� � ����� ��������
			NewModule.toTXT();
		}
		MyKitchenCupBoard.push_back(NewModule);
	}
	return true;
}

string iKitchen::ShowModules()
{
	string Temp = "";
	for (vector<CupBoard>::iterator iter = MyKitchenCupBoard.begin(); iter < MyKitchenCupBoard.end(); iter++)
	{
		Temp += iter->toUser();
	}
	for (vector<Cabinet>::iterator iter = MyKitchenCabinet.begin(); iter < MyKitchenCabinet.end(); iter++)
	{
		Temp += iter->toUser();
	}
	return Temp;
}


string iKitchen::ShowModulesShort()
{
	string Temp = "";
	for (vector<CupBoard>::iterator iter = MyKitchenCupBoard.begin(); iter < MyKitchenCupBoard.end(); iter++)
	{
		Temp += iter->toUserShort();
	}
	for (vector<Cabinet>::iterator iter = MyKitchenCabinet.begin(); iter < MyKitchenCabinet.end(); iter++)
	{
		Temp += iter->toUserShort();
	}
	return Temp;
}

string iKitchen::GetMatDsp()
{
	string temp;
	temp = MatDsp.GetBrand() + " " + MatDsp.GetTypeOfMaterial() + " " + MatDsp.GetDesignation();
	return temp;
}

string iKitchen::GetMatTorts()
{
	string temp;
	temp = MatTorts.GetBrand() + " " + MatTorts.GetTypeOfMaterial() + " " + MatTorts.GetDesignation();
	return temp;
}

string iKitchen::GetMatFas()
{
	string temp;
	temp = MatFas.GetBrand() + " " + MatFas.GetTypeOfMaterial() + " " + MatFas.GetDesignation();
	return temp;
}

string iKitchen::GetFasPokr()
{
	string temp;
	temp = FasPokr.GetBrand() + " " + FasPokr.GetTypeOfMaterial() + " " + FasPokr.GetDesignation();
	return temp;
}

string iKitchen::Getfasadtype()
{
	string temp = "Not found type of fasade";
	switch (fasadtype)
	{
	case 1:
		temp = "�������";
		break;
	case 2:
		temp = "����������� ��������";
		break;
	case 3:
		temp = "��������";
		break;
	case 4:
		temp = "������";
		break;
	case 5:
		temp = "��������";
		break;
	default:
		break;
	}
	return temp;
}

string iKitchen::GetfasadRadius()
{
	return to_string(fasadRadius);
}

string iKitchen::GetMatFurnit()
{
	string temp;
	temp = MatFurnit.GetBrand() + " " + MatFurnit.GetTypeOfMaterial() + " " + MatFurnit.GetDesignation();
	return temp;
}

string iKitchen::GetBackWallMaterial()
{
	string temp;
	temp = BackWallMaterial.GetBrand() + " " + BackWallMaterial.GetTypeOfMaterial() + " " + BackWallMaterial.GetDesignation();
	return temp;
}

string iKitchen::Getfix()
{
	string temp;
	temp = fix.GetBrand() + " " + fix.GetTypeOfMaterial() + " " + fix.GetDesignation();
	return temp;
}

string iKitchen::GetLegs()
{
	string temp;
	temp = legs.GetBrand() + " " + legs.GetTypeOfMaterial() + " " + legs.GetDesignation();
	return temp;
}

double iKitchen::GetAllCost()
{
	return AllCost;
}
