#include "iKitchen.h"

void iKitchen::MessageCost(string &temp, Material M, double QTY, double cost)
{
	temp += M.GetTypeOfMaterial(); temp += " ";
	temp += M.GetBrand(); temp += " ";
	temp += M.GetDesignation();
	temp += ", стоимость (за 1 "; temp += M.GetDimension();
	temp += "): "; temp += to_string(Sklad.CostMaterial(M));
	temp += " грн.\nНеобходимое количество: ";
	temp += to_string(QTY); temp += " "; temp += M.GetDimension();
	temp += "\nРасчетная стоимость: "; temp += to_string(cost); temp += " грн.\n\n";
}

iKitchen::iKitchen()
{
	Sklad.FromLibrary();//загружаем базу данных с внешнего файла
	//загрузка стоимости (из файла) сверления одного отверстия:
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

	html += "Материал ДСП: " + GetMatDsp();
	html += "Материал торцовки: " + GetMatTorts();
	html += "Материал фасадов: " + GetMatFas();
	html += "Фасады покрываются: " + GetFasPokr();
	html += "Тип фасада: " + Getfasadtype();
	html += "Радиус скругления торцов фасада: " + GetfasadRadius();
	html += "Фурнитура: " + GetMatFurnit();
	html += "Заняя стенка: " + GetBackWallMaterial();
	html += "Крепеж: " + Getfix();
	html += "Ножки: " + GetLegs();

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
	////////инициализация переменных
	string temp;
	double totalSquareDSP = 0.0; //общая площадь ДСП, м2
	double totalSquareFasades = 0.0; //общая площадь фасадов, м2
	double totalSquareBackWall = 0.0; //общая площадь задних стенок, м2
	double totalLengthOfTorts = 0.0; //общая длина торцовки м
	int totalCountHoles = 0; //общее количество отверсий, шт
	int totalCountFixes = 0; //общее количество крепежных элементов (конфирматов), шт
	int totalCountFurniture = 0; //количество петель, шт
	int totalCountLegs = 0; //количество ножек, шт

	//вытягивание количества всех материалов, используемых в каждом шкафчике:
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

	//вытягивание количества всех материалов, используемых в каждой тумбочке:
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
	
	//определение хватает ли материалов в базе материалов
	int errorCounter = 0;//инициализируем счетчик материалов которых не хватает
	//проверка хватает ли нам ДСП:
	if (!Sklad.HaveMaterial(MatDsp, totalSquareDSP))
	{
		temp += MatDsp.GetBrand(); temp += " ";
		temp += MatDsp.GetDesignation(); temp += " не хватает на складе!\n";
		errorCounter++;
	}
	//проверка хватает ли нам МДФ фасадов:
	if (!Sklad.HaveMaterial(MatFas, totalSquareFasades))
	{
		temp += MatFas.GetBrand(); temp += " ";
		temp += MatFas.GetDesignation(); temp += " не хватает на складе!\n";
		errorCounter++;
	}
	//проверка хватает ли нам покрытия фасадов:
	if (!Sklad.HaveMaterial(FasPokr, totalSquareFasades))
	{
		temp += FasPokr.GetBrand(); temp += " ";
		temp += FasPokr.GetDesignation(); temp += " не хватает на складе!\n";
		errorCounter++;
	}

	//проверка хватает ли нам ХДФ задней стенки:
	if (!Sklad.HaveMaterial(BackWallMaterial, totalSquareBackWall))
	{
		temp += BackWallMaterial.GetBrand(); temp += " ";
		temp += BackWallMaterial.GetDesignation(); temp += " не хватает на складе!\n";
		errorCounter++;
	}
	//проверка хватает ли нам торцовки:
	if (!Sklad.HaveMaterial(MatTorts, totalLengthOfTorts))
	{
		temp += MatTorts.GetBrand(); temp += " ";
		temp += MatTorts.GetDesignation(); temp += " не хватает на складе!\n";
		errorCounter++;
	}
	//проверка хватает ли нам конфирматов:
	if (!Sklad.HaveMaterial(fix, totalCountFixes))
	{
		temp += fix.GetBrand(); temp += " ";
		temp += fix.GetDesignation(); temp += " не хватает на складе!\n";
		errorCounter++;
	}
	//проверка хватает ли нам фурнитуры:
	if (!Sklad.HaveMaterial(MatFurnit, totalCountFurniture))
	{
		temp += MatFurnit.GetBrand(); temp += " ";
		temp += MatFurnit.GetDesignation(); temp += " не хватает на складе!\n";
		errorCounter++;
	}
	//проверка хватает ли нам ножек для тумбочек:
	if (!Sklad.HaveMaterial(legs, totalCountLegs))
	{
		temp += legs.GetBrand(); temp += " ";
		temp += legs.GetDesignation(); temp += " не хватает на складе!\n";
		errorCounter++;
	}
	//проверяем всего ли нам хватало и если всего хватало пишем считаем стоимость
	if (errorCounter == 0)
	{
		double costDSP = Sklad.QTYcostMaterial(MatDsp, totalSquareDSP); //стоимость ДСП
		double costFasad = Sklad.QTYcostMaterial(MatFas, totalSquareFasades); //стоимость фасадов
		double costFasPokr = Sklad.QTYcostMaterial(FasPokr, totalSquareFasades); //стоимость покрытия фасадов
		double costBackWall = Sklad.QTYcostMaterial(BackWallMaterial, totalSquareBackWall); //стоимость задних стенок
		double costTorts = Sklad.QTYcostMaterial(MatTorts, totalLengthOfTorts); //стоимость торцовок
		double costFixes = Sklad.QTYcostMaterial(fix, totalCountFixes); //стоимость крепежа(конфирматов)
		double costFurniture = Sklad.QTYcostMaterial(MatFurnit, totalCountFurniture); //стоимость фурнитуры
		double costHoles = totalCountHoles * holesCost; //стоимость сверления отверстий
		double costLegs = Sklad.QTYcostMaterial(legs, totalCountLegs); //стоимость ножек

		AllCost = costDSP + costFasad + costBackWall + costTorts + costFixes + costFurniture + costHoles + costLegs;

		//генерируем сообщение пользователю по стоимости составляющих его кухни
		//для ДСП:
		MessageCost(temp, MatDsp, totalSquareDSP, costDSP);
		
		//для Фасадов:
		MessageCost(temp, MatFas, totalSquareFasades, costFasad);

		//для покрытия фасадов:
		MessageCost(temp, FasPokr, totalSquareFasades, costFasPokr);

		//для задних стенок:
		MessageCost(temp, BackWallMaterial, totalSquareBackWall, costBackWall);

		//для торцовок:
		MessageCost(temp, MatTorts, totalLengthOfTorts, costTorts);

		//для крепежа (конфирматов):
		MessageCost(temp, fix, totalCountFixes, costFixes);

		//для фурнитуры:
		MessageCost(temp, MatFurnit, totalCountFurniture, costFurniture);

		//для ножек:
		MessageCost(temp, legs, totalCountLegs, costLegs);

		//для отверстий:
		temp += "Общее количество отверстий: ";
		temp += to_string(totalCountHoles); temp += " шт.\nСтоимость обработки одного отверстия: ";
		temp += to_string(holesCost); temp += " грн.\n";
		temp += "Расчетная стоимость: "; temp += to_string(costHoles); temp += " грн.\n\n";

		//общая стоимость всей кухни:
		temp += "Общая стоимость всей кухни: ";
		temp += to_string(AllCost); temp += " грн.";
	}
	return temp; 
}

bool iKitchen::intoWork()
{
	////////инициализация переменных
	double totalSquareDSP = 0.0; //общая площадь ДСП, м2
	double totalSquareFasades = 0.0; //общая площадь фасадов, м2
	double totalSquareBackWall = 0.0; //общая площадь задних стенок, м2
	double totalLengthOfTorts = 0.0; //общая длина торцовки м
	int totalCountHoles = 0; //общее количество отверсий, шт
	int totalCountFixes = 0; //общее количество крепежных элементов (конфирматов), шт
	int totalCountFurniture = 0; //количество петель, шт
	int totalCountLegs = 0; //количество ножек, шт

	//вытягивание количества всех материалов, используемых в каждом шкафчике:
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

	//вытягивание количества всех материалов, используемых в каждой тумбочке:
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
	int errorCounter = 0;//инициализируем счетчик материалов которых не хватает
	//проверка хватает ли нам ДСП:
	if (!Sklad.HaveMaterial(MatDsp, totalSquareDSP))
	{
		errorCounter++;
	}
	//проверка хватает ли нам МДФ фасадов:
	if (!Sklad.HaveMaterial(MatFas, totalSquareFasades))
	{
		errorCounter++;
	}
	//проверка хватает ли нам покрытия фасадов:
	if (!Sklad.HaveMaterial(FasPokr, totalSquareFasades))
	{
		errorCounter++;
	}

	//проверка хватает ли нам ХДФ задней стенки:
	if (!Sklad.HaveMaterial(BackWallMaterial, totalSquareBackWall))
	{
		errorCounter++;
	}
	//проверка хватает ли нам торцовки:
	if (!Sklad.HaveMaterial(MatTorts, totalLengthOfTorts))
	{
		errorCounter++;
	}
	//проверка хватает ли нам конфирматов:
	if (!Sklad.HaveMaterial(fix, totalCountFixes))
	{
		errorCounter++;
	}
	//проверка хватает ли нам фурнитуры:
	if (!Sklad.HaveMaterial(MatFurnit, totalCountFurniture))
	{
		errorCounter++;
	}
	//проверка хватает ли нам ножек для тумбочек:
	if (!Sklad.HaveMaterial(legs, totalCountLegs))
	{
		errorCounter++;
	}
	//проверяем всего ли нам хватало и если всего хватало пишем считаем стоимость
	if (errorCounter == 0)
	{
		//берем из базы необходимое количество материала
		Sklad.TakeMaterial(MatDsp, totalSquareDSP);
		Sklad.TakeMaterial(MatFas, totalSquareFasades);
		Sklad.TakeMaterial(FasPokr, totalSquareFasades);
		Sklad.TakeMaterial(BackWallMaterial, totalSquareBackWall);
		Sklad.TakeMaterial(MatTorts, totalLengthOfTorts);
		Sklad.TakeMaterial(fix, totalCountFixes);
		Sklad.TakeMaterial(MatFurnit, totalCountFurniture);
		Sklad.TakeMaterial(legs, totalCountLegs);
		intoHTML();//записываем в файл HTML

		SetZeroAll();//обнуляем всю кухню
		return true;
	}
	else return false;
}

bool iKitchen::GenerateModule(int classModule, int typeModule, double height, double width, double depth)
{
	if (classModule == 1) //тумбочки
	{
		Cabinet NewModule(height, width, depth, MatDsp, MatTorts, MatFas, FasPokr, fasadtype, fasadRadius, MatFurnit, BackWallMaterial, fix, legs);
		if (typeModule == 1)//одна полка
		{
			NewModule.OneShelve();
			NewModule.toTXT();
		}
		else if (typeModule == 2)//одна полка с двумя фасадами
		{
			NewModule.OneShelveTwoFasades();
			NewModule.toTXT();
		}
		else if (typeModule == 3)//две полки с одним фасадом
		{
			NewModule.TwoShelves();
			NewModule.toTXT();
		}
		else if (typeModule == 4)//две полки с двумя фасадами
		{
			NewModule.OneShelveTwoFasades();
			NewModule.toTXT();
		}
		MyKitchenCabinet.push_back(NewModule);
	}
	else if (classModule == 2) //шкафчики
	{
		CupBoard NewModule(height, width, depth, MatDsp, MatTorts, MatFas, FasPokr, fasadtype, fasadRadius, MatFurnit, BackWallMaterial, fix);
		if (typeModule == 1)//без полок (под посуду)
		{
			NewModule.NoShelves();
			NewModule.toTXT();
		}
		else if (typeModule == 2)//с одной полкой
		{
			NewModule.OneShelve();
			NewModule.toTXT();
		}
		else if (typeModule == 3)
		{
			NewModule.TwoShelves();//с двумя полками
			NewModule.toTXT();
		}
		else if (typeModule == 4)
		{
			NewModule.TwoShelvesTwoFasades();//с двумя полками с двумя фасадами
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
		temp = "Практик";
		break;
	case 2:
		temp = "Соверменная классика";
		break;
	case 3:
		temp = "Классика";
		break;
	case 4:
		temp = "Модерн";
		break;
	case 5:
		temp = "Магнолия";
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
