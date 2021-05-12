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

using namespace std;

struct ParamBase
{
	Material Material;
	double QTY; //количество
	int article; //артикул
	double cost = 0; //стоимость материала (за единицу измерения)
};


class MaterialBASE
{
private:
	vector<ParamBase> BASE;
	int articleCounter = 0;
	void ToLibrary();
public:
	MaterialBASE();
	~MaterialBASE();

	void AddMaterial(Material NewMaterial, double QTY);
	void AddMaterial(Material NewMaterial, double QTY, double cost);

	bool HaveMaterial(Material NewMaterial, double QTY);//метод проверки, хватает ли материала в базе
	bool TakeMaterial(Material NewMaterial, double QTY);//метод проверки, хватает ли материала в базе + если хватает мы отнимаем его
	double CostMaterial(Material M);//метод принимающий материал и возвращающий его стоимость (если не нашло - возвращает ноль)
	double QTYcostMaterial(Material M, double QTY); //метод принимающий материал и количество и возвращающий стоимость этого количества материалов (если не нашло - возвращает ноль)
	
	int GetSize();
	string GetMaterial(string type, int i);
	bool isDSP(int i);
	string GetMaterial(int i);
	Material TakeMaterial(int i);
	void FromLibrary();
	
	
	friend ostream& operator<<(ostream& zout, MaterialBASE& M);
};

