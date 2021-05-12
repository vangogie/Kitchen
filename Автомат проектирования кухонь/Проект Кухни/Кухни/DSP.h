/// /////////////////////КЛАСС ДСП/////////////
#pragma once //директива для отключения дублирования библиотек
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <fstream> //библиотека работы с файлами
#include <stdio.h> //библиотека записи и чтения файлов
#include <filesystem> //библиотека работы с файлами
#include <string> //библиотека работы с строками
#include <vector> //библиотека работы с массивами
#include <map> //библиотека ассоциативного массив
#include <algorithm> //алгоритм для STL библиотек
#include "Material.h"
#include "Holes.h"
#include "Detail.h"
#include "Groove.h"

using namespace std;

class DSP : public Detail
{
private:
	Material tortsovka;
	//Groove paz;
	//массивы отверстий по торцам:
	map<string, Holes> holeUp; //массив отверстий сверху (4 шт.)
	map<string, Holes> holeRight; //массив отверстий справа (4 шт.)
	map<string, Holes> holeDown; //массив отверстий снизу (4 шт.)
	map<string, Holes> holeLeft; //массив отверстий слева (4 шт.)
public:
	DSP(string NameOfDetail, Material Mater, double height, double width, double thickness, Material tortsovka);
	~DSP();

	void AddHoleUp(string CodeHole, double diameter, double Xcoordinate, double depth);
	void AddHoleRight(string CodeHole, double diameter, double Xcoordinate, double depth);
	void AddHoleDown(string CodeHole, double diameter, double Xcoordinate, double depth);
	void AddHoleLeft(string CodeHole, double diameter, double Xcoordinate, double depth);

	int GetCountHoles();

	void toTXT(string folder);
	string StringForTXT();

	friend ostream& operator<<(ostream& zout, DSP& D);
};

