#include "MaterialBASE.h"

MaterialBASE::MaterialBASE()
{
}

MaterialBASE::~MaterialBASE()
{
}

void MaterialBASE::AddMaterial(Material NewMaterial, double QTY)
{
	bool find = false;
	for (vector<ParamBase>::iterator iter = BASE.begin(); iter != BASE.end(); iter++)
	{
		if (iter->Material == NewMaterial)
		{
			iter->QTY += QTY;
			find = true;
			break;
		}
	}
	if (!find)
	{
		this->articleCounter++;
		ParamBase temp;
		temp.Material = NewMaterial;
		temp.QTY = abs(QTY);
		temp.article = articleCounter;
		BASE.push_back(temp);
	}
	ToLibrary();
}

void MaterialBASE::AddMaterial(Material NewMaterial, double QTY, double cost)
{
	bool find = false;
	for (vector<ParamBase>::iterator iter = BASE.begin(); iter != BASE.end(); iter++)
	{
		if (iter->Material == NewMaterial)
		{
			iter->QTY += QTY;
			iter->cost = abs(cost);
			find = true;
			break;
		}
	}
	if (!find)
	{
		this->articleCounter++;
		ParamBase temp;
		temp.Material = NewMaterial;
		temp.QTY = abs(QTY);
		temp.article = articleCounter;
		temp.cost = cost;
		BASE.push_back(temp);
	}
	ToLibrary();
}

bool MaterialBASE::HaveMaterial(Material NewMaterial, double QTY)
{
	for (vector<ParamBase>::iterator iter = BASE.begin(); iter != BASE.end(); iter++)
	{
		if (iter->Material == NewMaterial && iter->QTY >= QTY)
		{
			return true;
		}
	}
	return false;
}

bool MaterialBASE::TakeMaterial(Material NewMaterial, double QTY)
{
	for (vector<ParamBase>::iterator iter = BASE.begin(); iter != BASE.end(); iter++)
	{
		if (iter->Material == NewMaterial && iter->QTY >= QTY)
		{
			iter->QTY -= QTY;
			return true;
		}
	}
	return false;
}

double MaterialBASE::CostMaterial(Material M)
{
	for (vector<ParamBase>::iterator iter = BASE.begin(); iter != BASE.end(); iter++)
	{
		if (iter->Material == M)
		{
			return iter->cost;
		}
	}
	return 0.0;
}

double MaterialBASE::QTYcostMaterial(Material M, double QTY)
{
	return CostMaterial(M)*QTY;
}


void MaterialBASE::ToLibrary()
{
	string newFolder = "D:\\iKitchen\\Librares\\";
	_mkdir((newFolder.c_str()));
	ofstream zout(newFolder + "BASE.lib");
	if (zout.is_open())
	{
		for (int i = 0; i < BASE.size(); i++)
		{
			zout << BASE[i].Material.GetBrand(); zout << "\n";
			zout << BASE[i].Material.GetTypeOfMaterial(); zout << "\n";
			zout << BASE[i].Material.GetDesignation(); zout << "\n";
			zout << BASE[i].Material.GetDimension(); zout << "\n";
			zout << BASE[i].article; zout << "\n";
			zout << BASE[i].cost; zout << "\n";
			zout << BASE[i].QTY; zout << "\n";
		}
		zout.close();
	}

}

int MaterialBASE::GetSize()
{
	return BASE.size();
}

string MaterialBASE::GetMaterial(string type, int i)
{
	string temp;
	if (BASE[i].Material.GetTypeOfMaterial() == type)
	{
		return BASE[i].Material.GetBrand() + ", " + BASE[i].Material.GetDesignation();
	}
	return temp;
}

bool MaterialBASE::isDSP(int i)
{
	size_t digits = BASE[i].Material.GetTypeOfMaterial().find("ДСП");
	if (digits <= BASE[i].Material.GetTypeOfMaterial().size())
	{
		return true;
	}
	return false;
}

string MaterialBASE::GetMaterial(int i)
{
	return BASE[i].Material.GetTypeOfMaterial() + " " + BASE[i].Material.GetBrand() + ", " + BASE[i].Material.GetDesignation();
}

Material MaterialBASE::TakeMaterial(int i)
{
	return BASE[i].Material;
}

void MaterialBASE::FromLibrary()
{
	BASE.clear();//очищаем базу
	ParamBase temp;//создаем структуру базы данных
	ifstream zin;
	zin.open("D:\\iKitchen\\Librares\\BASE.lib");
	if (zin.is_open())
	{
		string Temp="";
		char ch = ' ';
		while (!zin.eof())
		{
			////////Brand/////////////////////
			while (zin.get(ch) && ch != '\n')
			{
				Temp += ch;
			}
			temp.Material.SetBrand(Temp);
			Temp.clear();
			///////Type of material////////////
			while (zin.get(ch) && ch != '\n')
			{
				Temp += ch;
			}
			temp.Material.SetTypeOfMaterial(Temp);
			Temp.clear();
			///////Designation////////////
			while (zin.get(ch) && ch != '\n')
			{
				Temp += ch;
			}
			temp.Material.SetDesignation(Temp);
			Temp.clear();
			///////Dimension////////////
			while (zin.get(ch) && ch != '\n')
			{
				Temp += ch;
			}
			temp.Material.SetDimension(Temp);
			Temp.clear();
			///////Article////////////
			while (zin.get(ch) && ch != '\n')
			{
				Temp += ch;
			}
			temp.article = atoi(Temp.c_str());
			Temp.clear();
			///////Costing////////////
			while (zin.get(ch) && ch != '\n')
			{
				Temp += ch;
			}
			temp.cost = atof(Temp.c_str());
			Temp.clear();
			///////QTY////////////
			while (zin.get(ch) && ch != '\n')
			{
				Temp += ch;
			}
			temp.QTY = atoi(Temp.c_str());
			Temp.clear();
			BASE.push_back(temp);
		}
		BASE.pop_back(); //удаляем последний пустой элемент из базы
		zin.close();
	}
}

ostream & operator<<(ostream & zout, MaterialBASE & M)
{
	for (int i = 0; i < M.BASE.size(); i++)
	{
		zout << M.BASE[i].Material
			<< "Артикул: " << M.BASE[i].article << endl
			<< "Количество на складе: " << M.BASE[i].QTY << " " << M.BASE[i].Material.GetDimension() << endl
			<< "Стоимость (за " << M.BASE[i].Material.GetDimension() << ") " << fixed << setprecision(2) << M.BASE[i].cost << " грн."<< endl << endl;
	}
	return zout;
}
