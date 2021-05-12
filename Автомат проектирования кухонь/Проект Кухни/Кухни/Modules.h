#pragma once
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <vector> //библиотека работы с массивами
#include <algorithm> //алгоритм для STL библиотек
#include "Material.h"
#include "Fasade.h"
#include "DSP.h"
#include "BackWall.h"

using namespace std;

class Modules
{
protected:
	//основные параметры:
	double height;//высота модуля
	double width; //ширина модуля
	double depth; //глубина модуля
	vector<DSP> Dsp; //детали каркаса
	vector<Material> Furniture; //фурнитура
	vector<Fasade> Fasad; //фасады
	vector<BackWall> BackW; //задняя стенка
	//параметры шкафа
	string Name = "";//обозначение шкафчика
	Material MatDsp;//Материал ДСП
	Material MatFas;//материал фасадов
	Material FasPokr;//покрытие фасадов
	int fasadtype1;//модель фрезеровки фасадов
	int fasadRadius;//радиус скругления торцов фасадов
	Material MatFurnit;//фурнитура (петли)
	Material MatTorts;//материал торцовки
	Material BackWallMaterial;//материал задней стенки
	Material fix;//крепеж (конфирматы)
	/////////////////////////////////////////////
	//Переменные хранящие параметры для стоимости и количества материалов
	double squareDSP;//площадь ДСП для модуля м2
	double squareFasades;//площадь фасадов м2
	double squareBackWall;//площадь задней стенки м2
	double lengthOfTorts;//длина торцовки м
	int countHoles;//количество отверсий шт
	int countFixes;//количество крепежных элементов (конфирматов) шт
	int countFurniture;//количество петель шт
	
	int thicknessDSP = 16; //толщина ДСП по умолчанию
	int thicknessFasade = 19; //толщина фасада по умолчанию
	int thicknessHDF = 3; //толщина задней стенки

	//статичные переменные
	const int diamHead = 7; //7 мм под шляпку конфирмата
	const int diambody = 5; //5 мм под тело конфирмата
	const int depthlength = 37; //37 мм под глубину сверления
	const int lengthFromEdge = 40;//расстояние от края ДСП по середины отверстия
	const int lengthFromEdgeSmall = 25; //расстояние под узкое ДСП
	const int lengthFromEdgeSmall2 = 75; //расстояние под узкое ДСП второе отверстие
	const int FASADdiamHole = 35; //35 мм диаметр под петлю
	const int FASADdepthHole = 13; //глубина сверления под петли
	const int FASADfromEdge = 100; //расстояние от края фасада до отверстия под петлю
	const int FASADSmallEdge = 22; //22 мм статичное расстояние смещения от края до отверстия под петлю
	const int HDFdiamHole = 100; //отверстия в задней стенке под петли для стены
	const int HDFzazor = 4; //задняя стенка на 4 мм меньше шкафчика по всем сторонам

	void ALLClear();//метод очистки всех деталей модуля
public:
	Modules(double height, double width, double depth);
	virtual ~Modules()=0;

	double GetSquareDSP();//площадь ДСП для модуля м2
	double GetSquareFasades();//площадь фасадов м2
	double GetSquareBackWall();//площадь задней стенки м2
	double GetLengthOfTorts();//длина торцовки м
	int GetCountHoles();//количество отверсий шт
	int GetCountFixes();//количество крепежных элементов (конфирматов) шт
	int GetCountFurniture();//количество петель шт
	string toUserShort();

	void toTXT();
	string StringForTXT();
	string toUser();
};

