#include "Material.h"

Material::Material()
{
	brand = "No data";
	typeOfMaterial = "No data";
	designation = "No data";
	dimension = "No data";
}

Material::Material(string brand, string typeOfMaterial, string designation, string dimension)
{
	this->brand = brand;
	this->typeOfMaterial = typeOfMaterial;
	this->designation = designation;
	this->dimension = dimension;
}

Material::Material(const Material & M)
{
	this->brand = M.brand;
	this->designation = M.designation;
	this->dimension = M.dimension;
	this->typeOfMaterial = M.typeOfMaterial;
}

Material::~Material()
{
}

void Material::SetBrand(string brand)
{
	this->brand = brand;
}

void Material::SetTypeOfMaterial(string typeOfMaterial)
{
	this->typeOfMaterial = typeOfMaterial;
}

void Material::SetDesignation(string designation)
{
	this->designation = designation;
}


void Material::SetDimension(string dimension)
{
	this->dimension = dimension;
}

string Material::GetBrand()
{
	return brand;
}

string Material::GetTypeOfMaterial()
{
	return typeOfMaterial;
}

string Material::GetDesignation()
{
	return designation;
}

string Material::GetDimension()
{
	return dimension;
}

string Material::StringForTXT()
{
	string temp;
	temp += "Производитель: " + brand + "\n";
	temp += "Тип: " + typeOfMaterial + "\n";
	temp += "Обозначение: " + designation + "\n";
	return temp;
}

bool Material::operator==(const Material & obj)
{
	if (this->brand == obj.brand && this->typeOfMaterial == obj.typeOfMaterial
		&& this->designation == obj.designation)
	{
		return true;
	}
	return false;
}

bool Material::operator<(const Material & obj)
{
	string temp = this->brand + " " + this->typeOfMaterial +" " + this->designation;
	string temp2 = obj.brand + " " + obj.typeOfMaterial + " " + obj.designation;
	if (temp < temp2)
	{
		return true;
	}
	return false;
}


ostream & operator<<(ostream & zout, Material & M)
{
	zout << "Производитель: " << M.brand << endl
		<< "Тип: " << M.typeOfMaterial << endl
		<< "Обозначение: " << M.designation << endl;
		return zout;
}
