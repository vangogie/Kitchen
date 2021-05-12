/// /////////////////////ВИРТУАЛЬНЫЙ КЛАСС ДЕТАЛЬ ИЗ КОТОРОГО НАСЛЕДУЮТСЯ ДЕТАЛИ ДСП И ФАСАДОВ/////////////
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

using namespace std;

class Detail
{
protected:
	string NameOfDetail;
	Material Mater;
	double height; //высота детали
	double width; //ширина детали
	double thickness; //толщина детали
	map<string, Holes> holeFace; //массив отверстий (12 шт.)
public:
	Detail(string NameOfDetail, Material Mater, double height, double width, double thickness);
	virtual ~Detail()=0;

	void SetMaterial(Material Mater);
	void SetHeight(double height);
	void SetWidth(double width);
	void SetThickness(double thickness);
	void addHoleFace(string CodeHole, double diameter, double Xcoordinate, double Ycoordinate, double depth);

	string GetName();
	Material GetMaterial();
	double GetHeight();
	double GetWidth();
	double GetThickness();
	virtual int GetCountHoles();

	virtual void toTXT();
};

