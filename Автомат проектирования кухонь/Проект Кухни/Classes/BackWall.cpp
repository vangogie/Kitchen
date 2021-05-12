#include "BackWall.h"

BackWall::BackWall(string NameOfDetail, Material Mater, double height, double width, double thickness) : Detail(NameOfDetail, Mater, height, width, thickness)
{
}

BackWall::~BackWall()
{
}

void BackWall::toTXT(string folder)
{
	ofstream zout("D:\\iKitchen\\" + folder + "\\" + NameOfDetail + ".txt");
	if (!zout.is_open())
	{
		//cout << "File can't opened" << endl;
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
		zout.close();
	}
}

string BackWall::StringForTXT()
{
	string temp;
	temp += NameOfDetail + "\n";
	temp += "��������: \n" + Mater.StringForTXT() + "\n";
	temp += "\"Height\" = " + to_string(height) + "\n";
	temp += "\"Width\" = " + to_string(width) + "\n";
	temp += "\"Thick\" = " + to_string(thickness) + "\n";
	//������� ��� ��������� �� ������ ������ ������:
	for (map<string, Holes>::iterator iter = holeFace.begin(); iter != holeFace.end(); iter++)
	{
		temp += "\"D" + iter->first + "\" = " + to_string(iter->second.GetDiameter()) + "\n";
		temp += "\"X" + iter->first + "\" = " + to_string(iter->second.GetXcoordinate()) + "\n";
		temp += "\"Y" + iter->first + "\" = " + to_string(iter->second.GetYcoordinate()) + "\n";
		temp += "\"H" + iter->first + "\" = " + to_string(iter->second.GetDepth()) + "\n";
	}
	return temp;
}

ostream & operator<<(ostream & zout, BackWall & B)
{
	zout << B.NameOfDetail << endl;
	zout << "��������: " << endl << B.Mater << endl;
	zout << "\"������\" = " << B.height << endl;
	zout << "\"������\" = " << B.width << endl;
	zout << "\"����.\" = " << B.thickness << endl;
	zout << "----------------------------------------" << endl << endl;
	return zout;
}
