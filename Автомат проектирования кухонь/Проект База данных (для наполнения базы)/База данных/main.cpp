#include "Header.h"


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//srand(time(0));
	system("color 70");
	setlocale(LC_CTYPE, "rus");
	//
	
	MaterialBASE NewBase;
	NewBase.FromLibrary();
	//
	//�����
	Material temp;
	vector<string> brand;
	brand.push_back("Egger");
	brand.push_back("Kronospan");
	brand.push_back("SwissKrono");
	brand.push_back("Blum");
	brand.push_back("Haffele");
	brand.push_back("LinkeLn");
	brand.push_back("Italy Color");
	brand.push_back("Vinil");
	brand.push_back("Grundwand");


	vector<string> typeMaterial;
	typeMaterial.push_back("��� 16 ��");
	typeMaterial.push_back("��� 18 ��");
	typeMaterial.push_back("��� 19 ��");
	typeMaterial.push_back("��� 18 ��");
	typeMaterial.push_back("�������� 0,4 ��");
	typeMaterial.push_back("�����");
	typeMaterial.push_back("������");
	typeMaterial.push_back("������");
	typeMaterial.push_back("����� 100 ��");

	vector<string> Razm;
	Razm.push_back("��");
	Razm.push_back("�");
	Razm.push_back("�2");

	while (true)
	{
		cout << "���� ������� � ���� ������" << endl;
		cin.ignore(32767, '\n');
		for (int i = 0; i < brand.size(); i++)
		{
			cout << i + 1 << "-" << brand[i] << "; ";
		}
		int selectBrand;
		cin >> selectBrand;
		if (selectBrand > 9 || selectBrand < 1) selectBrand = 1;
		switch (selectBrand)
		{
		case 1:
			temp.SetBrand(brand[0]);
			break;
		case 2:
			temp.SetBrand(brand[1]);
			break;
		case 3:
			temp.SetBrand(brand[2]);
			break;
		case 4:
			temp.SetBrand(brand[3]);
			break;
		case 5:
			temp.SetBrand(brand[4]);
			break;
		case 6:
			temp.SetBrand(brand[5]);
			break;
		case 7:
			temp.SetBrand(brand[6]);
			break;
		case 8:
			temp.SetBrand(brand[7]);
			break;
		case 9:
			temp.SetBrand(brand[8]);
			break;
		default:
			break;
		}

		//��� ���������:
		cout << "�������� ��� ������� (����, ��� � �.�.): "<<endl;
		
		for (int i = 0; i < typeMaterial.size(); i++)
		{
			cout << i + 1 << "-" << typeMaterial[i] << "; ";
		}
		int selectType;
		cin >> selectType;
		if (selectType > 9 || selectType < 1) selectType = 1;
		switch (selectType)
		{
		case 1:
			temp.SetTypeOfMaterial(typeMaterial[0]);
			break;
		case 2:
			temp.SetTypeOfMaterial(typeMaterial[1]);
			break;
		case 3:
			temp.SetTypeOfMaterial(typeMaterial[2]);
			break;
		case 4:
			temp.SetTypeOfMaterial(typeMaterial[3]);
			break;
		case 5:
			temp.SetTypeOfMaterial(typeMaterial[4]);
			break;
		case 6:
			temp.SetTypeOfMaterial(typeMaterial[5]);
			break;
		case 7:
			temp.SetTypeOfMaterial(typeMaterial[6]);
			break;
		case 8:
			temp.SetTypeOfMaterial(typeMaterial[7]);
			break;
		case 9:
			temp.SetTypeOfMaterial(typeMaterial[8]);
			break;
		}

		//�����������

		cout << "�������� ����������� �������: " << endl;
		
		for (int i = 0; i < Razm.size(); i++)
		{
			cout << i + 1 << "-" << Razm[i] << "; ";
		}
		int selectRazm;
		cin >> selectRazm;
		if (selectRazm > 3 || selectRazm < 1) selectRazm = 1;
		switch (selectRazm)
		{
		case 1:
			temp.SetDimension(Razm[0]);
			break;
		case 2:
			temp.SetDimension(Razm[1]);
			break;
		case 3:
			temp.SetDimension(Razm[2]);
			break;
		default:
			break;
		}

		//�����������:
		char design[201];
		cout << "������� �������������� ������� (����, ��� � �.�.): " << endl;
		cin.ignore(32767, '\n');
		gets_s(design);
		string d = design;
		temp.SetDesignation(d);

		//���������:
		int cost = 0;
		cout << "������� ��������� �������: ";
		cin >> cost;

		//����������
		int QTY = 0;
		cout << "������� ���������� �������: ";
		cin >> QTY;

		system("cls");
		cout << "�������� ��������? 1 - ��, ������ ����� - ���" << endl<<endl;
		cout << temp;
		cout << "����������: " << QTY <<" " << Razm[selectRazm - 1] << endl;
		cout << "���������: " << cost << " ���/" << Razm[selectRazm-1] << endl;

		char yesNo;
		cin >> yesNo;
		if (yesNo == '1')
		{
			NewBase.AddMaterial(temp, QTY, cost);
		}
		system("cls");
	}

	system("pause");
	return 0;
}