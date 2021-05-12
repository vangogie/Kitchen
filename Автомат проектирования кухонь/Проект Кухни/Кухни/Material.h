#pragma once
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <string> //библиотека работы с строками
#include <fstream> //библиотека работы с файлами

using namespace std;
/// /////////////////////////////////////////////////////////////////////////////////

class Material
{
private:
	string brand;			//производитель
	string typeOfMaterial;	//тип материала, например ДСП или петли
	string designation;		//обозначение материала
	string dimension;		//размерность (шт, м2 и тд.)

public:
	Material();
	Material(string brand, string typeOfMaterial, string designation, string dimension);
	Material(const Material& M); //конструктор копирования
	~Material();

	void SetBrand(string brand);
	void SetTypeOfMaterial(string typeOfMaterial);
	void SetDesignation(string designation);
	void SetDimension(string dimension);

	string GetBrand();
	string GetTypeOfMaterial();
	string GetDesignation();
	string GetDimension();

	string StringForTXT();
	
	bool operator == (const Material& obj); //соответствие проверяется по трем полям: Бренд, Тип материала и обозначение
	bool operator<(const Material & obj);
	friend ostream& operator<<(ostream& zout, Material& M);
};

