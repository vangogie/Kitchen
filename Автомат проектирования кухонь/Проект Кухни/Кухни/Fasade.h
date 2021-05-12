/// /////////////////////КЛАСС ФАСАДОВ/////////////
#pragma once //директива для отключения дублирования библиотек
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <fstream> //библиотека работы с файлами
#include <stdio.h> //библиотека записи и чтения файлов
#include <filesystem> //библиотека работы с файлами
#include <string> //библиотека работы с строками
#include <vector> //библиотека работы с массивами
#include <algorithm> //алгоритм для STL библиотек
#include "Material.h"
#include "Holes.h"
#include "Detail.h"

using namespace std;



class Fasade : public Detail
{
protected:
	Material covering; //покрытие фасада (может быть как пленка так и краска)
	int fasadtype = 1; //тип фасада: 1 - пустой, 2 - классический вырез, 3 - классический вырез + классический остров, 4 - модерн, 5 - Магнолия
	int radius = 1; //минимально 1, максимально - 6.
public:
	Fasade(string NameOfDetail, Material Mater, double height, double width, double thickness, Material covering, int fasadtype, int radius);
	~Fasade();

	string TypeFasad(int fasadtype);

	void SetCovering(Material covering);

	Material GetCovering();

	string ShowTypeOfFasade();
	string toUser();

	void toTXT(string folder);
	string StringForTXT();

	friend ostream& operator<<(ostream& zout, Fasade& F);
};

