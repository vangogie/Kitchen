#include "CupBoard.h"


void CupBoard::ALLCount()
{
	//обнуляем все значения
	squareDSP = 0.0;//площадь ДСП для модуля
	squareFasades = 0.0;//площадь фасадов
	squareBackWall = 0.0;//площадь задней стенки
	lengthOfTorts = 0.0;//длина торцовки
	countHoles = 0;//количество отверсий
	//считаем текущие значения:
	//							для ДСП:
	for (vector<DSP>::iterator iter = Dsp.begin(); iter != Dsp.end(); iter++)
	{
		//считаем площадь ДСП и прибавляем ее к общей площади:
		double tempS = (iter->GetHeight()*iter->GetWidth())/1000000;//м2
		squareDSP += tempS;
		//считаем количество отверстий и прибавляем их к общему количеству отверстий:
		int tempH = iter->GetCountHoles();//шт
		countHoles += tempH;
		//считаем торцовку и прибавляем ее к общему метражу торцовки
		double tempT;
		if (iter->GetName() == "Боковина")
		{
			tempT = ((iter->GetHeight() * 2) + (iter->GetWidth() * 2))/1000;//по периметру
		}
		else
		{
			tempT = (iter->GetHeight() * 2)/1000;//по передней и задней стороне детали
		}
		lengthOfTorts += tempT;
	}
	//							для задней стенки:
	for (vector<BackWall>::iterator iter = BackW.begin(); iter != BackW.end(); iter++)
	{
		double tempS = (iter->GetHeight()*iter->GetWidth())/1000000;//м2
		squareBackWall += tempS;
		int tempH = iter->GetCountHoles();//шт
		countHoles += tempH;
	}
	//							для фасадов:
	for (vector<Fasade>::iterator iter = Fasad.begin(); iter != Fasad.end(); iter++)
	{
		double tempF = (iter->GetHeight()*iter->GetWidth())/1000000;//м2
		squareFasades += tempF;
		int tempH = iter->GetCountHoles();//шт
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
	//присвоение толщин плитных материалов из наименования материала:
	//для ДСП:
	size_t digits = MatDsp.GetTypeOfMaterial().find_first_of("1234567890");
	if (digits <= MatDsp.GetTypeOfMaterial().size()) 
	{
		thicknessDSP = atoi(MatDsp.GetTypeOfMaterial().c_str() + digits);
	}
	//для фасада:
	size_t digits2 = MatFas.GetTypeOfMaterial().find_first_of("1234567890");
	if (digits2 <= MatFas.GetTypeOfMaterial().size())
	{
		thicknessFasade = atoi(MatFas.GetTypeOfMaterial().c_str() + digits2);
	}
	//для задней стенки
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
	ALLClear();//очищаем массивы на случай если они заполнены
	//////////ИНИЦИАЛИЗАЦИЯ ШКАФЧИКА//////////////////////////////////////
	Name = "Шкафчик с двумя полками";
	//////////////////ДОБАВЛЯЕМ БОКОВИНЫ/////////////////////////////////
	DSP DSPSide("Боковина", this->MatDsp, this->height, this->depth, thicknessDSP, MatTorts);
	//отверстия под дно шкафчика:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, this->depth - lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	//отверстия под крышку:
	DSPSide.addHoleFace("3", diamHead, lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, this->depth - lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	//оверстия под полку 1:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, this->depth - lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//отверстия под полку 2:
	DSPSide.addHoleFace("7", diamHead, lengthFromEdge, this->height-(((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("8", diamHead, this->depth - lengthFromEdge, this->height - (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//вносим две боковины в массив
	Dsp.push_back(DSPSide);//добавляем одну боковину
	Dsp.push_back(DSPSide);//добавляем вторую боковину
	//////////////////ДОБАВЛЯЕМ ПОЛКИ////////////////////////////////////
	DSP DSPSelves("Полка", this->MatDsp, this->width - (thicknessDSP * 2), this->depth, thicknessDSP, MatTorts);
	//добавляем отверстия на торце сверху:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, this->depth - lengthFromEdge, depthlength);
	//добавляем отверстия на торце снизу:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, this->depth - lengthFromEdge, depthlength);
	//вносим четыре полки (крышка + дно + две полки):
	Dsp.push_back(DSPSelves);//крышка
	Dsp.push_back(DSPSelves);//дно
	Dsp.push_back(DSPSelves);//полка 1
	Dsp.push_back(DSPSelves);//полка 2
	//добавляем размеры в заднюю стенку:
	BackWall BackWallone("Задняя стенка", this->BackWallMaterial, this->height - HDFzazor, this->width- HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth()-1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//добавляем фасад:
	Fasade FasadeOne("Фасад", MatFas, this->height - 4, this->width - 4, thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight()-FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	//добавляем фурнитуру:
	for (countFurniture = 0; countFurniture < 2; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//добавляем конфирматы:
	for (countFixes = 0; countFixes < 16; countFixes++)
	{
		Furniture.push_back(fix);
	}
	ALLCount();//считаем все площади, отверстия и т.д.
}

void CupBoard::TwoShelvesTwoFasades()
{
	ALLClear();//очищаем массивы на случай если они заполнены
	//////////ИНИЦИАЛИЗАЦИЯ ШКАФЧИКА//////////////////////////////////////
	Name = "Шкафчик с двумя полками и двумя фасадами";
	//////////////////ДОБАВЛЯЕМ БОКОВИНЫ/////////////////////////////////
	DSP DSPSide("Боковина", this->MatDsp, this->height, this->depth, thicknessDSP, MatTorts);
	//отверстия под дно шкафчика:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, this->depth - lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	//отверстия под крышку:
	DSPSide.addHoleFace("3", diamHead, lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, this->depth - lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	//оверстия под полку 1:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, this->depth - lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//отверстия под полку 2:
	DSPSide.addHoleFace("7", diamHead, lengthFromEdge, this->height - (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("8", diamHead, this->depth - lengthFromEdge, this->height - (((this->height - (thicknessDSP * 2)) / 3) + thicknessDSP), thicknessDSP);
	//вносим две боковины в массив
	Dsp.push_back(DSPSide);//добавляем одну боковину
	Dsp.push_back(DSPSide);//добавляем вторую боковину
	//////////////////ДОБАВЛЯЕМ ПОЛКИ////////////////////////////////////
	DSP DSPSelves("Полка", this->MatDsp, this->width - (thicknessDSP * 2), this->depth, thicknessDSP, MatTorts);
	//добавляем отверстия на торце сверху:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, this->depth - lengthFromEdge, depthlength);
	//добавляем отверстия на торце снизу:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, this->depth - lengthFromEdge, depthlength);
	//вносим четыре полки (крышка + дно + две полки):
	Dsp.push_back(DSPSelves);//крышка
	Dsp.push_back(DSPSelves);//дно
	Dsp.push_back(DSPSelves);//полка 1
	Dsp.push_back(DSPSelves);//полка 2
	//добавляем размеры в заднюю стенку:
	BackWall BackWallone("Задняя стенка", this->BackWallMaterial, this->height - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//добавляем фасады:
	Fasade FasadeOne("Фасад", MatFas, this->height - 4, ((this->width/2) - 4), thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	Fasad.push_back(FasadeOne);
	//добавляем фурнитуру:
	for (countFurniture = 0; countFurniture < 4; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//добавляем конфирматы:
	for (countFixes = 0; countFixes < 16; countFixes++)
	{
		Furniture.push_back(fix);
	}
	ALLCount();//считаем все площади, отверстия и т.д.
}

void CupBoard::OneShelve()
{
	ALLClear();//очищаем массивы на случай если они заполнены
	//////////ИНИЦИАЛИЗАЦИЯ ШКАФЧИКА//////////////////////////////////////
	Name = "Шкафчик с одной полкой";
	//////////////////ДОБАВЛЯЕМ БОКОВИНЫ/////////////////////////////////
	DSP DSPSide("Боковина", this->MatDsp, this->height, this->depth, thicknessDSP, MatTorts);
	//отверстия под дно шкафчика:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, this->depth - lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	//отверстия под крышку:
	DSPSide.addHoleFace("3", diamHead, lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, this->depth - lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	//оверстия под полку:
	DSPSide.addHoleFace("5", diamHead, lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 2) + thicknessDSP), thicknessDSP);
	DSPSide.addHoleFace("6", diamHead, this->depth - lengthFromEdge, (((this->height - (thicknessDSP * 2)) / 2) + thicknessDSP), thicknessDSP);
	//вносим две боковины в массив
	Dsp.push_back(DSPSide);//добавляем одну боковину
	Dsp.push_back(DSPSide);//добавляем вторую боковину
	//////////////////ДОБАВЛЯЕМ ПОЛКИ////////////////////////////////////
	DSP DSPSelves("Полка", this->MatDsp, this->width - (thicknessDSP * 2), this->depth, thicknessDSP, MatTorts);
	//добавляем отверстия на торце сверху:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, this->depth - lengthFromEdge, depthlength);
	//добавляем отверстия на торце снизу:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, this->depth - lengthFromEdge, depthlength);
	//вносим три полки (крышка + дно + полка):
	Dsp.push_back(DSPSelves);//крышка
	Dsp.push_back(DSPSelves);//дно
	Dsp.push_back(DSPSelves);//полка 1
	//добавляем размеры в заднюю стенку:
	BackWall BackWallone("Задняя стенка", this->BackWallMaterial, this->height - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//добавляем фасад:
	Fasade FasadeOne("Фасад", MatFas, this->height - 4, this->width - 4, thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	//добавляем фурнитуру:
	for (countFurniture = 0; countFurniture < 2; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//добавляем конфирматы:
	for (countFixes = 0; countFixes < 12; countFixes++)
	{
		Furniture.push_back(fix);
	}
	ALLCount();//считаем все площади, отверстия и т.д.
}

void CupBoard::NoShelves()
{
	ALLClear();//очищаем массивы на случай если они заполнены
	//////////ИНИЦИАЛИЗАЦИЯ ШКАФЧИКА//////////////////////////////////////
	Name = "Шкафчик под посуду (без полок)";
	//////////////////ДОБАВЛЯЕМ БОКОВИНЫ/////////////////////////////////
	DSP DSPSide("Боковина", this->MatDsp, this->height, this->depth, thicknessDSP, MatTorts);
	//отверстия под дно шкафчика:
	DSPSide.addHoleFace("1", diamHead, lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("2", diamHead, this->depth - lengthFromEdge, (thicknessDSP / 2), thicknessDSP);
	//отверстия под крышку:
	DSPSide.addHoleFace("3", diamHead, lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	DSPSide.addHoleFace("4", diamHead, this->depth - lengthFromEdge, this->height - (thicknessDSP / 2), thicknessDSP);
	//вносим две боковины в массив
	Dsp.push_back(DSPSide);//добавляем одну боковину
	Dsp.push_back(DSPSide);//добавляем вторую боковину
	//////////////////ДОБАВЛЯЕМ ПОЛКИ////////////////////////////////////
	DSP DSPSelves("Полка", this->MatDsp, this->width - (thicknessDSP * 2), this->depth, thicknessDSP, MatTorts);
	//добавляем отверстия на торце сверху:
	DSPSelves.AddHoleUp("A1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleUp("A2", diambody, this->depth - lengthFromEdge, depthlength);
	//добавляем отверстия на торце снизу:
	DSPSelves.AddHoleDown("C1", diambody, lengthFromEdge, depthlength);
	DSPSelves.AddHoleDown("C2", diambody, this->depth - lengthFromEdge, depthlength);
	//вносим две полки (крышки):
	Dsp.push_back(DSPSelves);//крышка
	Dsp.push_back(DSPSelves);//дно
	//добавляем размеры в заднюю стенку:
	BackWall BackWallone("Задняя стенка", this->BackWallMaterial, this->height - HDFzazor, this->width - HDFzazor, thicknessHDF);
	BackWallone.addHoleFace("1", HDFdiamHole, 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackWallone.addHoleFace("2", HDFdiamHole, BackWallone.GetWidth() - 1, BackWallone.GetHeight(), BackWallone.GetThickness());
	BackW.push_back(BackWallone);
	//добавляем фасад:
	Fasade FasadeOne("Фасад", MatFas, this->height - 4, this->width - 4, thicknessFasade, FasPokr, fasadtype1, fasadRadius);
	FasadeOne.addHoleFace("1", FASADdiamHole, FASADSmallEdge, FASADfromEdge, FASADdepthHole);
	FasadeOne.addHoleFace("2", FASADdiamHole, FASADSmallEdge, FasadeOne.GetHeight() - FASADfromEdge, FASADdepthHole);
	Fasad.push_back(FasadeOne);
	//добавляем фурнитуру:
	for (countFurniture = 0; countFurniture < 2; countFurniture++)
	{
		Furniture.push_back(MatFurnit);
	}
	//добавляем конфирматы:
	for (countFixes = 0; countFixes < 12; countFixes++)
	{
		Furniture.push_back(fix);
	}
	ALLCount();//считаем все площади, отверстия и т.д.
}



string CupBoard::toUser()
{
	Fasade tempF("Проверочный фасад", MatFas, 1000, 500, 19, FasPokr, fasadtype1, fasadRadius);//временный фасад для использования метода toUser чтоб не переписывать все что в нем выводится
	string Text = Name;
	Text += "\nВысота шкафчика: "; Text += to_string(height); Text += " мм";
	Text += "\nШирина шкафчика: "; Text += to_string(width); Text += " мм";
	Text += "\nГлубина шкафчика: "; Text += to_string(depth); Text += " мм";
	Text += "\nМатериал корпуса: "; Text += MatDsp.GetBrand(); Text += ", "; Text += MatDsp.GetDesignation();
	Text += "\nТорцовка: "; Text += MatTorts.GetBrand(); Text += ", "; Text += MatTorts.GetDesignation();
	Text += "\nЗадняя стенка: "; Text += BackWallMaterial.GetBrand(); Text += ", "; Text += BackWallMaterial.GetDesignation();
	Text += "\n";
	Text += tempF.toUser();
	Text += "Фурнитура: "; Text += MatFurnit.GetBrand(); Text += ", "; Text += MatFurnit.GetDesignation();
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
