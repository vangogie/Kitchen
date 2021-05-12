#include "Groove.h"

Groove::Groove()
{
	width = 0;
	depth = 0;
	Xcoordinate = 0;
}

Groove::Groove(double width, double depth, double Xcoordinate)
{
	this->width = width;
	this->depth = depth;
	this->Xcoordinate = Xcoordinate;
}

Groove::~Groove()
{
}

Groove::Groove(const Groove & G)
{
	this->depth = G.depth;
	this->width = G.width;
	this->Xcoordinate = Xcoordinate;
}

void Groove::SetWidth(double width)
{
	this->width = abs(width);
}

void Groove::SetDepth(double depth)
{
	this->depth = abs(depth);
}

void Groove::SetXcoordinate(double Xcoordinate)
{
	this->Xcoordinate = abs(Xcoordinate);
}

double Groove::GetWidth()
{
	return width;
}

double Groove::GetDepth()
{
	return depth;
}

double Groove::GetXcoodrinate()
{
	return Xcoordinate;
}
