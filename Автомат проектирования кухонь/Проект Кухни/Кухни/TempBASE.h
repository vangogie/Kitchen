#pragma once //директива для отключения дублирования библиотек
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <iomanip> //библиотека разметки
#include <fstream> //библиотека работы с файлами
#include <stdio.h> //библиотека записи и чтения файлов
#include <filesystem> //библиотека работы с файлами
#include <string> //библиотека работы с строками
#include <vector> //библиотека работы с массивами
#include <algorithm> //алгоритм для STL библиотек
#include <map> //библиотека ассоциативного массива
#include <direct.h> //библиотека работы с папками
#include "Material.h" //класс материалов
#include "MaterialBASE.h"

using namespace std;

class TempBASE : public MaterialBASE
{
private:
public:
	TempBASE();
	~TempBASE();
	void AddTempMaterial(Material NewMaterial, double QTY, double cost);
};

