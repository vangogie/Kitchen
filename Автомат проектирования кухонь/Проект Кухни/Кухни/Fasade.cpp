#include "Fasade.h"

Fasade::Fasade(string NameOfDetail, Material Mater, double height, double width, double thickness, Material covering, int fasadtype, int radius) : Detail(NameOfDetail, Mater, height, width, thickness)
{
	this->covering = covering;
	this->fasadtype = fasadtype;
	if (this->fasadtype < 1) this->fasadtype = 1;
	if (this->fasadtype > 5) this->fasadtype = 5;//максимальное количество вариаций фасадов
	this->radius = radius;
	if (this->radius < 1) this->radius = 1;//минимальный радиус скругления
	if (this->radius > 6) this->radius = 6;//максимальный радиус скругления
}

Fasade::~Fasade()
{
}

string Fasade::TypeFasad(int fasadtype)
{
	string temp = "Not found type of fasade";
	switch (fasadtype)
	{
	case 1:
		temp = "Практик";
		break;
	case 2:
		temp = "Соверменная классика";
		break;
	case 3:
		temp = "Классика";
		break;
	case 4:
		temp = "Модерн";
		break;
	case 5:
		temp = "Магнолия";
		break;
	default:
		break;
	}
	return temp;
}

void Fasade::SetCovering(Material covering)
{
	this->covering = covering;
}

Material Fasade::GetCovering()
{
	return covering;
}

string Fasade::ShowTypeOfFasade()
{
	string Text;
	switch (fasadtype)
	{
	case 1:
		Text = "Практик";
		break;
	case 2:
		Text = "Современная классика";
		break;
	case 3:
		Text = "Классика";
		break;
	case 4:
		Text = "Модерн";
		break;
	case 5:
		Text = "Магнолия";
		break;
	default:
		break;
	}
	return Text;
}

string Fasade::toUser()
{
	string Text;
	Text = "Материал фасада: "; Text += Mater.GetBrand(); Text += ", "; Text += Mater.GetDesignation();
	Text += "\nПокрытие фасада: "; Text += covering.GetBrand(); Text += ", "; Text += covering.GetDesignation();
	Text += "\nМодель фасада: "; Text += ShowTypeOfFasade();
	Text += "\nСкругление по периметру: "; Text += to_string(radius); Text += " мм\n";
	return Text;
}

void Fasade::toTXT(string folder)
{
	ofstream zout("D:\\iKitchen\\" + folder + "\\" + NameOfDetail + ".txt");
	if (!zout.is_open())
	{
		cout << "File can't opened" << endl;
	}
	else
	{
		zout << NameOfDetail << endl;
		zout << "Материал: " << endl << Mater << endl;
		zout << "\"Height\" = " << height << endl;
		zout << "\"Width\" = " << width << endl;
		zout << "\"Thick\" = " << thickness << endl;
		//выводим все отверстия на фасаде:
		for (map<string, Holes>::iterator iter = holeFace.begin(); iter != holeFace.end(); iter++)
		{
			zout << "\"D" << iter->first << "\" = " << iter->second.GetDiameter() << endl;
			zout << "\"X" << iter->first << "\" = " << iter->second.GetXcoordinate() << endl;
			zout << "\"Y" << iter->first << "\" = " << iter->second.GetYcoordinate() << endl;
			zout << "\"H" << iter->first << "\" = " << iter->second.GetDepth() << endl;
		}
		int Classic = 0;
		int Classicisland = 0;
		int Modern = 0;
		int Magnolia = 0;
		switch (fasadtype)
		{
		case 2:
			Classic = 1;
			break;
		case 3:
			Classic = 1;
			Classicisland = 1;
			break;
		case 4:
			Modern = 1;
			break;
		case 5:
			Magnolia = 1;
			break;
		default:
			break;
		}
		if (height < 170 || width < 170) Classicisland = 0;
		if (height < 140 || width < 140) Classic = Classicisland = Modern = Magnolia = 0;
		zout << "\"Classic\" = " << Classic << endl;
		zout << "\"Classicisland\" = " << Classicisland << endl;
		zout << "\"Modern\" = " << Modern << endl;
		zout << "\"Magnolia\" = " << Magnolia << endl;
		zout << "\"Radius\" = " << radius << endl;
		zout.close();
	}
}

string Fasade::StringForTXT()
{
	string temp;
	temp += NameOfDetail + "\n";
	temp += "Материал: \n" + Mater.StringForTXT() + "\n";
	temp += "\"Height\" = " + to_string(height) + "\n";
	temp += "\"Width\" = " + to_string(width) + "\n";
	temp += "\"Thick\" = " + to_string(thickness) + "\n";
	for (map<string, Holes>::iterator iter = holeFace.begin(); iter != holeFace.end(); iter++)
	{
		temp += "\"D" + iter->first + "\" = " + to_string(iter->second.GetDiameter()) + "\n";
		temp += "\"X" + iter->first + "\" = " + to_string(iter->second.GetXcoordinate()) + "\n";
		temp += "\"Y" + iter->first + "\" = " + to_string(iter->second.GetYcoordinate()) + "\n";
		temp += "\"H" + iter->first + "\" = " + to_string(iter->second.GetDepth()) + "\n";
	}
	int Classic = 0;
	int Classicisland = 0;
	int Modern = 0;
	int Magnolia = 0;
	switch (fasadtype)
	{
	case 2:
		Classic = 1;
		break;
	case 3:
		Classic = 1;
		Classicisland = 1;
		break;
	case 4:
		Modern = 1;
		break;
	case 5:
		Magnolia = 1;
		break;
	default:
		break;
	}
	if (height < 170 || width < 170) Classicisland = 0;
	if (height < 140 || width < 140) Classic = Classicisland = Modern = Magnolia = 0;
	temp += "\"Classic\" = " + to_string(Classic) + "\n";
	temp += "\"Classicisland\" = " + to_string(Classicisland) + "\n";
	temp += "\"Modern\" = " + to_string(Modern) + "\n";
	temp += "\"Magnolia\" = " + to_string(Magnolia) + "\n";
	temp += "\"Radius\" = " + to_string(radius) + "\n";
	return temp;
}

ostream & operator<<(ostream & zout, Fasade & F)
{
	zout << F.NameOfDetail << endl;
	zout << "Материал: " << endl << F.Mater << endl;
	zout << "\"Высота\" = " << F.height << endl;
	zout << "\"Ширина\" = " << F.width << endl;
	zout << "\"Толщ.\" = " << F.thickness << endl;
	zout << "----------------------------------------" << endl << endl;
	//ТУТ ВЫВОД НА ЭКРАН ДОЛЖЕН БЫТЬ
	return zout;
}
