#pragma once
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <vector> //библиотека работы с массивами
#include <algorithm> //алгоритм для STL библиотек
#include <cctype>
#include <cstdlib>
#include "Material.h"
#include "Modules.h"
#include "CupBoard.h"
#include "DSP.h"

using namespace std;

class Cabinet : public Modules
{
protected:
	const int legHeight = 100; //100 мм высота ножек
	int countLegs = 0;//количество ножек шт
	Material MatLegs;//материал ножек

	void ALLCount();//считаем все площади, отверстия и т.д. (дополнено ножками)
public:
	Cabinet(double height, double width, double depth, Material MatDsp, Material MatTorts, Material MatFas, Material FasPokr, int fasadtype, int fasadRadius, Material MatFurnit, Material BackWallMaterial, Material fix, Material MatLegs);
	~Cabinet();

	void TwoShelves(); //тумбочка с двумя полками
	void TwoShelvesTwoFasades(); //тумбочка с двумя полками и двумя фасадами
	void OneShelve(); //тумбочка с одной полкой
	void OneShelveTwoFasades();//тумбочка с одной полкой и двумя фасадами
	string toUser();

	int GetCountLegs();//количество ножек шт


	friend ostream& operator<<(ostream& zout, CupBoard& C);
};

