#pragma once
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <vector> //библиотека работы с массивами
#include <algorithm> //алгоритм для STL библиотек
#include <cctype>
#include <cstdlib>
#include "Material.h"
#include "Modules.h"
#include "DSP.h"

using namespace std;

class CupBoard : public Modules
{
protected:
	virtual void ALLCount();//считаем все площади, отверстия и т.д.
public:
	CupBoard(double height, double width, double depth, Material MatDsp, Material MatTorts, Material MatFas, Material FasPokr, int fasadtype, int fasadRadius, Material MatFurnit, Material BackWallMaterial, Material fix);
	~CupBoard();

	virtual void TwoShelves(); //шкафчик с двумя полками
	virtual void TwoShelvesTwoFasades(); //шкафчик с двумя полками и двумя фасадами
	virtual void OneShelve(); //шкафчик с одной полкой
	virtual void NoShelves(); //шкафчик без полок (под посуду) 
	
	virtual string toUser();


	friend ostream& operator<<(ostream& zout, CupBoard& C);
};

