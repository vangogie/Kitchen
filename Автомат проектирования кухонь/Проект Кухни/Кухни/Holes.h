/// ///////////// ласс параметров отверстий в детал€х
#pragma once //директива дл€ отключени€ дублировани€ библиотек
#include <iostream> //библиотека работы с функци€ми и потоками ввода-вывода

using namespace std;

class Holes
{
private:
	double diameter; //диаметр отверсти€
	double Xcoordinate;//начало отсчета с верхнего левого угла - ’ по горизонтали слева-направо
	double Ycoordinate;//начало отсчета с верхнего левого угла - Y по вертикали сверху-вниз
	double depth; //глубина отверсти€
public:
	Holes();
	Holes(double diameter, double Xcoordinate, double Ycoordinate, double depth);
	~Holes();

	void SetDiameter(double diameter);
	void SetXcoordinate(double Xcoordinate);
	void SetYcoordinate(double Ycoordinate);
	void SetDepth(double depth);

	double GetDiameter();
	double GetXcoordinate();
	double GetYcoordinate();
	double GetDepth();

	friend ostream& operator<<(ostream& zout, Holes& H);
};

