#include "Fasade.h"

Fasade::Fasade(string NameOfDetail, Material Mater, double height, double width, double thickness, Material covering, int fasadtype, int radius) : Detail(NameOfDetail, Mater, height, width, thickness)
{
	this->covering = covering;
	this->fasadtype = fasadtype;
	if (this->fasadtype < 1) this->fasadtype = 1;
	if (this->fasadtype > 5) this->fasadtype = 5;//������������ ���������� �������� �������
	this->radius = radius;
	if (this->radius < 1) this->radius = 1;//����������� ������ ����������
	if (this->radius > 6) this->radius = 6;//������������ ������ ����������
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
		temp = "�������";
		break;
	case 2:
		temp = "����������� ��������";
		break;
	case 3:
		temp = "��������";
		break;
	case 4:
		temp = "������";
		break;
	case 5:
		temp = "��������";
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
		Text = "�������";
		break;
	case 2:
		Text = "����������� ��������";
		break;
	case 3:
		Text = "��������";
		break;
	case 4:
		Text = "������";
		break;
	case 5:
		Text = "��������";
		break;
	default:
		break;
	}
	return Text;
}

string Fasade::toUser()
{
	string Text;
	Text = "�������� ������: "; Text += Mater.GetBrand(); Text += ", "; Text += Mater.GetDesignation();
	Text += "\n�������� ������: "; Text += covering.GetBrand(); Text += ", "; Text += covering.GetDesignation();
	Text += "\n������ ������: "; Text += ShowTypeOfFasade();
	Text += "\n���������� �� ���������: "; Text += to_string(radius); Text += " ��\n";
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
		zout << "��������: " << endl << Mater << endl;
		zout << "\"Height\" = " << height << endl;
		zout << "\"Width\" = " << width << endl;
		zout << "\"Thick\" = " << thickness << endl;
		//������� ��� ��������� �� ������:
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
	temp += "��������: \n" + Mater.StringForTXT() + "\n";
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
	zout << "��������: " << endl << F.Mater << endl;
	zout << "\"������\" = " << F.height << endl;
	zout << "\"������\" = " << F.width << endl;
	zout << "\"����.\" = " << F.thickness << endl;
	zout << "----------------------------------------" << endl << endl;
	//��� ����� �� ����� ������ ����
	return zout;
}
