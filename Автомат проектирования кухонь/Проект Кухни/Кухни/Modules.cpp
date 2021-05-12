#include "Modules.h"

void Modules::ALLClear()
{
	Dsp.clear();
	Fasad.clear();
	Furniture.clear();
	BackW.clear();
}

Modules::Modules(double height, double width, double depth)
{
	this->height = abs(height);
	this->width = abs(width);
	this->depth = abs(depth);
	if (this->height < 500) this->height = 500;
	if (this->width < 350) this->width = 350;
	if (this->depth < 220) this->depth = 220;
	squareDSP = 0.0;//площадь ДСП для модуля
	squareFasades = 0.0;//площадь фасадов
	squareBackWall = 0.0;//площадь задней стенки
	lengthOfTorts = 0.0;//длина торцовки
	countHoles = 0;//количество отверсий
	countFixes = 0;//количество крепежных элементов (конфирматов)
	countFurniture = 0;//количество петель
}

Modules::~Modules()
{
}

double Modules::GetSquareDSP()
{
	return squareDSP;
}

double Modules::GetSquareFasades()
{
	return squareFasades;
}

double Modules::GetSquareBackWall()
{
	return squareBackWall;
}

double Modules::GetLengthOfTorts()
{
	return lengthOfTorts;
}

int Modules::GetCountHoles()
{
	return countHoles;
}

int Modules::GetCountFixes()
{
	return countFixes;
}

int Modules::GetCountFurniture()
{
	return countFurniture;
}

string Modules::toUserShort()
{
	
	string Text = Name;
	Text += "\nВысота шкафчика: "; Text += to_string(height); Text += " мм";
	Text += "\nШирина шкафчика: "; Text += to_string(width); Text += " мм";
	Text += "\nГлубина шкафчика: "; Text += to_string(depth); Text += " мм";
	Text += "\n\n";
	return Text;
	
}

void Modules::toTXT()
{

	for (vector<DSP>::iterator iter = Dsp.begin(); iter != Dsp.end(); iter++)
	{
		iter->toTXT(Name);
	}
	for (vector<BackWall>::iterator iter = BackW.begin(); iter != BackW.end(); iter++)
	{
		iter->toTXT(Name);
	}
	for (vector<Fasade>::iterator iter = Fasad.begin(); iter != Fasad.end(); iter++)
	{
		iter->toTXT(Name);
	}

}

string Modules::StringForTXT()
{
	string temp;
	for (vector<DSP>::iterator iter = Dsp.begin(); iter != Dsp.end(); iter++)
	{
		temp += iter->StringForTXT();
	}
	for (vector<BackWall>::iterator iter = BackW.begin(); iter != BackW.end(); iter++)
	{
		temp += iter->StringForTXT();
	}
	for (vector<Fasade>::iterator iter = Fasad.begin(); iter != Fasad.end(); iter++)
	{
		temp += iter->StringForTXT();
	}
	return temp;
}

string Modules::toUser()
{
	string temp = "NO STRING";
	return temp;
}
