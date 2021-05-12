#include "Header.h"


int main()
{
	//srand(time(0));
	system("color 70");
	setlocale(LC_CTYPE, "rus");
	//
	//
	Material DSP("Egger", "��� 16 ��", "������ �������", "�2");
	Material DSP2("Egger", "��� 16 ��", "�����", "�2");
	Material DSP3("Egger", "��� 16 ��", "���", "�2");
	Material DSP4("Kronospan", "��� 18 ��", "��� ������", "�2");
	Material Tortsovka1("SwissKrono", "�������� 0,4 ��", "���", "�");
	Material MDF1("Kronospan", "��� 19 ��", "���", "�2");
	Material Blum1("Blum", "�����", "���������� ����� 93 �������", "��");
	Material ZadnyayaStenka("SwissKrono", "��� 3 ��", "�����", "�2");
	Material Confirmat("Apex", "������", "���������", "��");
	Material Kraska1("BelViso", "������", "RAL 1013", "�2");
	Material Leg1("Kitchen Furniture", "����� 100 ��", "������", "�2");
	Material MDF2("Hubo", "��� 19 ��", "���", "�2");
	//
	MaterialBASE Sklad1;
	//
	Sklad1.AddMaterial(DSP, 10, 285);
	Sklad1.AddMaterial(DSP2, 15, 274);
	Sklad1.AddMaterial(Blum1, 17, 97);
	Sklad1.AddMaterial(DSP3, 11, 330);
	Sklad1.AddMaterial(DSP2, 12, 290);
	Sklad1.AddMaterial(Confirmat, 308, 0.5);
	Sklad1.AddMaterial(Blum1, 154);
	Sklad1.AddMaterial(ZadnyayaStenka, 55, 105);
	Sklad1.AddMaterial(Kraska1, 800, 1200);
	Sklad1.AddMaterial(MDF1, 1300, 1000);
	Sklad1.AddMaterial(Tortsovka1, 800, 7);
	Sklad1.AddMaterial(Leg1, 200, 7.5);
	Sklad1.AddMaterial(DSP4, 25, 335);
	//
	////Sklad1.FromLibrary();
	//cout << Sklad1 << endl;
	//
	//
	//CupBoard PodHlam(720, 600, 300, DSP3, Tortsovka1, MDF1, Kraska1, 4, 5, Blum1, ZadnyayaStenka, Confirmat);
	//PodHlam.TwoShelves();
	//PodHlam.toTXT();

	
	
	//cout << PodHlam << endl;

	//cout<<PodHlam.toUser()<<endl<<endl;

	//cout << "������� ���: " << PodHlam.GetSquareDSP() << " �2" << endl;
	//cout << "������� �������: " << PodHlam.GetSquareFasades() << " �2" << endl;
	//cout << "������� ���: " << PodHlam.GetSquareBackWall() << " �2" << endl;
	//cout << "����� ��������: " << PodHlam.GetLengthOfTorts() << " �" << endl;
	//cout << "����� ���������� ���������: " << PodHlam.GetCountHoles() << " ��." << endl;
	//cout << "���������� �����������: " << PodHlam.GetCountFixes() << " ��." << endl;
	//cout << "���������� ������: " << PodHlam.GetCountFurniture() << " ��." << endl;



	/*CashPriemnik CP(200, 198);
	CP.MoneyTake(200);
	CP.MoneyTake(200);
	CP.MoneyTake(200);
	CP.MoneyTake(200);
	CP.MoneyTake(50);
	CP.ShowMoney();*/

	
	iKitchen FirstKitchen;
	//���:
	FirstKitchen.SetMatDsp(DSP);
	//��������:
	FirstKitchen.SetMatTorts(Tortsovka1);
	//���:
	FirstKitchen.SetMatFas(MDF1);
	FirstKitchen.Setfasadtype(5);
	FirstKitchen.SetfasadRadius(4);
	FirstKitchen.SetFasPokr(Kraska1);
	//���:
	FirstKitchen.SetBackWallMaterial(ZadnyayaStenka);
	//���������:
	FirstKitchen.SetMatFurnit(Blum1);
	//����������:
	FirstKitchen.Setfix(Confirmat);
	//�����:
	FirstKitchen.SetLegs(Leg1);
	//��������� ������
	
	FirstKitchen.GenerateModule(2, 2, 800.0, 700.0, 310.0);
	FirstKitchen.GenerateModule(2, 1, 800.0, 500.0, 310.0);
	FirstKitchen.GenerateModule(1, 1, 850.0, 600.0, 560.0);
	cout<<FirstKitchen.ShowModules();

	cout << FirstKitchen.Calculation() << endl;
	


	system("pause");
	return 0;
}