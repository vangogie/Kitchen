#pragma once //директива для отключения дублирования библиотек
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <cstdlib> //библиотека для рандома
#include <ctime> //библиотека для рандома
#include <iomanip> //библиотека разметки
#include <windows.h> //библиотека для задержки времени
#include <conio.h> //библиотека функции захвата координат курсора (getch)
#include <fstream> //библиотека работы с файлами
#include <stdio.h> //библиотека записи и чтения файлов
#include <filesystem> //библиотека работы с файлами
#include <string> //библиотека работы с строками
#include <vector> //библиотека работы с массивами
#include <algorithm> //алгоритм для STL библиотек
#include <map> //библиотека ассоциативного массив
#include "MaterialBASE.h"
#include "Material.h"
#include "Modules.h"
#include "CupBoard.h"
#include "Cabinet.h"

using namespace std;

class iKitchen
{
private:
	vector<CupBoard> MyKitchenCupBoard;//массив шкафчиков кухни
	vector<Cabinet> MyKitchenCabinet; //массив тумбочек кухни
	MaterialBASE Sklad; //база материалов
	//Пользовательские переменные
	Material MatDsp;//Материал корпусов
	Material MatTorts;//Материал торцовки
	Material MatFas;//Материал фасадов
	Material FasPokr;//Материал покрытия фасадов 
	int fasadtype;//стиль фасадов
	int fasadRadius;//радиус скругления оконтовки фасадов
	Material MatFurnit;//материал фурнитуры
	Material BackWallMaterial;//материал задней стенки
	Material fix;//конфирматы
	Material legs;//ножки
	double holesCost;//стоимость сверления одного отверстия
	double AllCost;//общая стоимость кухни
	void MessageCost(string &temp, Material M, double QTY, double cost);
	void SetZeroAll();
	void intoHTML();
public:
	iKitchen();
	~iKitchen();
	
	void SetMatDsp(Material MatDsp);
	void SetMatTorts(Material MatTorts);
	void SetMatFas(Material MatFas);
	void SetFasPokr(Material FasPokr);
	void Setfasadtype(int fasadtype);
	void SetfasadRadius(int fasadRadius);
	void SetMatFurnit(Material MatFurnit);
	void SetBackWallMaterial(Material BackWallMaterial);
	void Setfix(Material fix);
	void SetLegs(Material legs);

	

	string Calculation();
	bool intoWork();

	bool GenerateModule(int classModule, int typeModule, double height, double width, double depth);
	string ShowModules();

	string ShowModulesShort();

	string GetMatDsp();
	string GetMatTorts();
	string GetMatFas();
	string GetFasPokr();
	string Getfasadtype();
	string GetfasadRadius();
	string GetMatFurnit();
	string GetBackWallMaterial();
	string Getfix();
	string GetLegs();
	double GetAllCost();
};

