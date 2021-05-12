#include "Holes.h"

Holes::Holes()
{
	this->diameter = 0;
	this->Xcoordinate = 0;
	this->Ycoordinate = 0;
	this->depth = 0;
}

Holes::Holes(double diameter, double Xcoordinate, double Ycoordinate, double depth)
{
    this->diameter = (abs(diameter));
    this->Xcoordinate = (abs(Xcoordinate));
    this->Ycoordinate = (abs(Ycoordinate));
    this->depth = (abs(depth));
}

Holes::~Holes()
{
}

void Holes::SetDiameter(double diameter)
{
	this->diameter = abs(diameter);
}

void Holes::SetXcoordinate(double Xcoordinate)
{
	this->Xcoordinate = abs(Xcoordinate);
}

void Holes::SetYcoordinate(double Ycoordinate)
{
	this->Ycoordinate = abs(Ycoordinate);
}

void Holes::SetDepth(double depth)
{
	this->depth = abs(depth);
}

double Holes::GetDiameter()
{
	return diameter;
}

double Holes::GetXcoordinate()
{
	return Xcoordinate;
}

double Holes::GetYcoordinate()
{
	return Ycoordinate;
}

double Holes::GetDepth()
{
	return depth;
}

ostream & operator<<(ostream & zout, Holes & H)
{
	zout << "D: " << H.diameter << "; ";
	zout << "X: " << H.Xcoordinate << "; ";
	zout << "Y: " << H.Ycoordinate << "; ";
	zout << "H: " << H.depth << "; ";
	return zout;
}
