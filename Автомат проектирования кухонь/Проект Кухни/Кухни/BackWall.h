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

using namespace std;

class BackWall : public Detail
{
public:
	BackWall(string NameOfDetail, Material Mater, double height, double width, double thickness);
	~BackWall();

	void toTXT(string folder);
	string StringForTXT();

	friend ostream& operator<<(ostream& zout, BackWall& B);
};

