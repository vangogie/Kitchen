#include "Detail.h"

Detail::Detail(string NameOfDetail, Material Mater, double height, double width, double thickness)
{
	this->NameOfDetail = NameOfDetail;
	this->Mater = Mater;
	this->height = height;
	this->width = width;
	this->thickness = thickness;
	Holes notHole;
	//создаем 12 отверстий с нулевыми значениями:
	for (size_t i = 1; i <= 12; i++)
	{
		string temp = to_string(i); //переводим значение в строку
		holeFace.insert(make_pair(temp, notHole));
	}
}

Detail::~Detail()
{
}

void Detail::SetMaterial(Material Mater)
{
	this->Mater = Mater;
}

void Detail::SetHeight(double height)
{
	this->height = height;
}

void Detail::SetWidth(double width)
{
	this->width = width;
}

void Detail::SetThickness(double thickness)
{
	this->thickness = thickness;
}

void Detail::addHoleFace(string CodeHole, double diameter, double Xcoordinate, double Ycoordinate, double depth)
{
	Holes temp(diameter, Xcoordinate, Ycoordinate, depth);
	//if (CodeHole>"0" && CodeHole<"12")//Achtung
	//{
		holeFace[CodeHole] = temp;
	//}
	
}

string Detail::GetName()
{
	return NameOfDetail;
}

Material Detail::GetMaterial()
{
	return Mater;
}

double Detail::GetHeight()
{
	return height;
}

double Detail::GetWidth()
{
	return width;
}

double Detail::GetThickness()
{
	return thickness;
}

int Detail::GetCountHoles()
{
	int temp = 0;
	for (map<string, Holes>::iterator i = holeFace.begin(); i != holeFace.end(); i++)
	{
		if (i->second.GetDiameter()) //если диаметр больше нуля
		{
			temp++;
		}
	}
	return temp;
}

void Detail::toTXT()
{
}

ostream & operator<<(ostream & zout, Detail & C)
{
	return zout;// TODO: insert return statement here
}
