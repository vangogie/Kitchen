#include "Header.h"


int main()
{
	//srand(time(0));
	system("color 70");
	setlocale(LC_CTYPE, "rus");
	//
	//
	Material DSP("Egger", "ДСП 16 мм", "Береза светлая", "м2");
	Material DSP2("Egger", "ДСП 16 мм", "Ясень", "м2");
	Material DSP3("Egger", "ДСП 16 мм", "Бук", "м2");
	Material DSP4("Kronospan", "ДСП 18 мм", "Дуб сонома", "м2");
	Material Tortsovka1("SwissKrono", "Торцовка 0,4 мм", "Бук", "м");
	Material MDF1("Kronospan", "МДФ 19 мм", "МДФ", "м2");
	Material Blum1("Blum", "Петля", "Внутренняя петля 93 градуса", "шт");
	Material ZadnyayaStenka("SwissKrono", "ХДФ 3 мм", "Белая", "м2");
	Material Confirmat("Apex", "Крепеж", "Конфирмат", "шт");
	Material Kraska1("BelViso", "Краска", "RAL 1013", "м2");
	Material Leg1("Kitchen Furniture", "Ножка 100 мм", "Черная", "м2");
	Material MDF2("Hubo", "МДФ 19 мм", "МДФ", "м2");
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

	//cout << "Площадь ДСП: " << PodHlam.GetSquareDSP() << " м2" << endl;
	//cout << "Площадь Фасадов: " << PodHlam.GetSquareFasades() << " м2" << endl;
	//cout << "Площадь ХДФ: " << PodHlam.GetSquareBackWall() << " м2" << endl;
	//cout << "Длина торцовки: " << PodHlam.GetLengthOfTorts() << " м" << endl;
	//cout << "Общее количество отверстий: " << PodHlam.GetCountHoles() << " шт." << endl;
	//cout << "Количество конфирматов: " << PodHlam.GetCountFixes() << " шт." << endl;
	//cout << "Количество петель: " << PodHlam.GetCountFurniture() << " шт." << endl;



	/*CashPriemnik CP(200, 198);
	CP.MoneyTake(200);
	CP.MoneyTake(200);
	CP.MoneyTake(200);
	CP.MoneyTake(200);
	CP.MoneyTake(50);
	CP.ShowMoney();*/

	
	iKitchen FirstKitchen;
	//ДСП:
	FirstKitchen.SetMatDsp(DSP);
	//Торцовка:
	FirstKitchen.SetMatTorts(Tortsovka1);
	//МДФ:
	FirstKitchen.SetMatFas(MDF1);
	FirstKitchen.Setfasadtype(5);
	FirstKitchen.SetfasadRadius(4);
	FirstKitchen.SetFasPokr(Kraska1);
	//ХДФ:
	FirstKitchen.SetBackWallMaterial(ZadnyayaStenka);
	//Фурнитура:
	FirstKitchen.SetMatFurnit(Blum1);
	//Конфирматы:
	FirstKitchen.Setfix(Confirmat);
	//Ножки:
	FirstKitchen.SetLegs(Leg1);
	//генерация модуля
	
	FirstKitchen.GenerateModule(2, 2, 800.0, 700.0, 310.0);
	FirstKitchen.GenerateModule(2, 1, 800.0, 500.0, 310.0);
	FirstKitchen.GenerateModule(1, 1, 850.0, 600.0, 560.0);
	cout<<FirstKitchen.ShowModules();

	cout << FirstKitchen.Calculation() << endl;
	


	system("pause");
	return 0;
}