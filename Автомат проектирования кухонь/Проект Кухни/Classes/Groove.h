/// /////////////Класс параметров паза в деталях ДСП
#pragma once //директива для отключения дублирования библиотек
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода

using namespace std;

class Groove
{
private:
	double width; //ширина паза
	double depth; //глубина паза
	double Xcoordinate;//начало отсчета с верхнего левого угла - Y по вертикали сверху-вниз
public:
	Groove();
	Groove(double width, double depth, double Xcoordinate);
	~Groove();
	Groove(const Groove& G); //конструктор копирования

	void SetWidth(double width);
	void SetDepth(double depth);
	void SetXcoordinate(double Xcoordinate);

	double GetWidth();
	double GetDepth();
	double GetXcoodrinate();
};

