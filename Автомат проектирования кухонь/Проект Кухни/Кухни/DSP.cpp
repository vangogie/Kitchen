#include "DSP.h"



DSP::DSP(string NameOfDetail, Material Mater, double height, double width, double thickness, Material tortsovka) : Detail(NameOfDetail, Mater, height, width, thickness)
{
	this->tortsovka = tortsovka;
	Holes notHole;
	//������� 4 ��������� � �������� ���������� ��� ���� ������:
	for (size_t i = 1; i <= 4; i++)
	{
		string tempA = "A";
		tempA += to_string(i); //��������� �������� � ������
		holeUp.insert(make_pair(tempA, notHole));

		string tempB = "B";
		tempB += to_string(i); //��������� �������� � ������
		holeRight.insert(make_pair(tempB, notHole));

		string tempC = "C";
		tempC += to_string(i); //��������� �������� � ������
		holeDown.insert(make_pair(tempC, notHole));

		string tempD = "D";
		tempD += to_string(i); //��������� �������� � ������
		holeLeft.insert(make_pair(tempD, notHole));
	}
}

DSP::~DSP()
{
}

void DSP::AddHoleUp(string CodeHole, double diameter, double Xcoordinate, double depth)
{
	Holes temph(diameter, Xcoordinate, (this->thickness / 2), depth);
	holeUp[CodeHole]=temph;
}

void DSP::AddHoleRight(string CodeHole, double diameter, double Xcoordinate, double depth)
{
	Holes temph(diameter, Xcoordinate, (this->thickness / 2), depth);
	holeRight[CodeHole] = temph;
}

void DSP::AddHoleDown(string CodeHole, double diameter, double Xcoordinate, double depth)
{
	Holes temph(diameter, Xcoordinate, (this->thickness / 2), depth);
	holeDown[CodeHole] = temph;
}

void DSP::AddHoleLeft(string CodeHole, double diameter, double Xcoordinate, double depth)
{
	Holes temph(diameter, Xcoordinate, (this->thickness / 2), depth);
	holeLeft[CodeHole] = temph;
}

int DSP::GetCountHoles()
{
	int temp = 0;
	//��������� �� ������� �������
	for (map<string, Holes>::iterator i = holeFace.begin(); i != holeFace.end(); i++)
	{
		if (i->second.GetDiameter()) //���� ������� ������ ����
		{
			temp++;
		}
	}
	//��������� ������
	for (map<string, Holes>::iterator i = holeUp.begin(); i != holeUp.end(); i++)
	{
		if (i->second.GetDiameter()) //���� ������� ������ ����
		{
			temp++;
		}
	}
	//��������� ������
	for (map<string, Holes>::iterator i = holeRight.begin(); i != holeRight.end(); i++)
	{
		if (i->second.GetDiameter()) //���� ������� ������ ����
		{
			temp++;
		}
	}
	//��������� �����
	for (map<string, Holes>::iterator i = holeDown.begin(); i != holeDown.end(); i++)
	{
		if (i->second.GetDiameter()) //���� ������� ������ ����
		{
			temp++;
		}
	}
	//��������� �����
	for (map<string, Holes>::iterator i = holeLeft.begin(); i != holeLeft.end(); i++)
	{
		if (i->second.GetDiameter()) //���� ������� ������ ����
		{
			temp++;
		}
	}
	return temp;
}

void DSP::toTXT(string folder)
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

		//������� ��� ��������� ������:
		for (map<string, Holes>::iterator iter = holeUp.begin(); iter != holeUp.end(); iter++)
		{
			zout << "\"D" << iter->first << "\" = " << iter->second.GetDiameter() << endl;
			zout << "\"X" << iter->first << "\" = " << iter->second.GetXcoordinate() << endl;
			zout << "\"Y" << iter->first << "\" = " << iter->second.GetYcoordinate() << endl;
			zout << "\"H" << iter->first << "\" = " << iter->second.GetDepth() << endl;
		}

		//������� ��� ��������� ������:
		for (map<string, Holes>::iterator iter = holeRight.begin(); iter != holeRight.end(); iter++)
		{
			zout << "\"D" << iter->first << "\" = " << iter->second.GetDiameter() << endl;
			zout << "\"X" << iter->first << "\" = " << iter->second.GetXcoordinate() << endl;
			zout << "\"Y" << iter->first << "\" = " << iter->second.GetYcoordinate() << endl;
			zout << "\"H" << iter->first << "\" = " << iter->second.GetDepth() << endl;
		}

		//������� ��� ��������� �����:
		for (map<string, Holes>::iterator iter = holeDown.begin(); iter != holeDown.end(); iter++)
		{
			zout << "\"D" << iter->first << "\" = " << iter->second.GetDiameter() << endl;
			zout << "\"X" << iter->first << "\" = " << iter->second.GetXcoordinate() << endl;
			zout << "\"Y" << iter->first << "\" = " << iter->second.GetYcoordinate() << endl;
			zout << "\"H" << iter->first << "\" = " << iter->second.GetDepth() << endl;
		}

		//������� ��� ��������� �����:
		for (map<string, Holes>::iterator iter = holeLeft.begin(); iter != holeLeft.end(); iter++)
		{
			zout << "\"D" << iter->first << "\" = " << iter->second.GetDiameter() << endl;
			zout << "\"X" << iter->first << "\" = " << iter->second.GetXcoordinate() << endl;
			zout << "\"Y" << iter->first << "\" = " << iter->second.GetYcoordinate() << endl;
			zout << "\"H" << iter->first << "\" = " << iter->second.GetDepth() << endl;
		}
		zout.close();
	}
}

string DSP::StringForTXT()
{
	string temp;
	temp += NameOfDetail + "\n";
	temp += "��������: \n" + Mater.StringForTXT() + "\n";
	temp += "\"Height\" = " + to_string(height) + "\n";
	temp += "\"Width\" = " + to_string(width) + "\n";
	temp += "\"Thick\" = " + to_string(thickness) + "\n";
	//������� ��� ��������� �� ������ ������ ���:
	for (map<string, Holes>::iterator iter = holeFace.begin(); iter != holeFace.end(); iter++)
	{
		temp += "\"D" + iter->first + "\" = " + to_string(iter->second.GetDiameter()) + "\n";
		temp += "\"X" + iter->first + "\" = " + to_string(iter->second.GetXcoordinate()) + "\n";
		temp += "\"Y" + iter->first + "\" = " + to_string(iter->second.GetYcoordinate()) + "\n";
		temp += "\"H" + iter->first + "\" = " + to_string(iter->second.GetDepth()) + "\n";
	}

	//������� ��� ��������� ������:
	for (map<string, Holes>::iterator iter = holeUp.begin(); iter != holeUp.end(); iter++)
	{
		temp += "\"D" + iter->first + "\" = " + to_string(iter->second.GetDiameter()) + "\n";
		temp += "\"X" + iter->first + "\" = " + to_string(iter->second.GetXcoordinate()) + "\n";
		temp += "\"Y" + iter->first + "\" = " + to_string(iter->second.GetYcoordinate()) + "\n";
		temp += "\"H" + iter->first + "\" = " + to_string(iter->second.GetDepth()) + "\n";
	}

	//������� ��� ��������� ������:
	for (map<string, Holes>::iterator iter = holeRight.begin(); iter != holeRight.end(); iter++)
	{
		temp += "\"D" + iter->first + "\" = " + to_string(iter->second.GetDiameter()) + "\n";
		temp += "\"X" + iter->first + "\" = " + to_string(iter->second.GetXcoordinate()) + "\n";
		temp += "\"Y" + iter->first + "\" = " + to_string(iter->second.GetYcoordinate()) + "\n";
		temp += "\"H" + iter->first + "\" = " + to_string(iter->second.GetDepth()) + "\n";
	}

	//������� ��� ��������� �����:
	for (map<string, Holes>::iterator iter = holeDown.begin(); iter != holeDown.end(); iter++)
	{
		temp += "\"D" + iter->first + "\" = " + to_string(iter->second.GetDiameter()) + "\n";
		temp += "\"X" + iter->first + "\" = " + to_string(iter->second.GetXcoordinate()) + "\n";
		temp += "\"Y" + iter->first + "\" = " + to_string(iter->second.GetYcoordinate()) + "\n";
		temp += "\"H" + iter->first + "\" = " + to_string(iter->second.GetDepth()) + "\n";
	}

	//������� ��� ��������� �����:
	for (map<string, Holes>::iterator iter = holeLeft.begin(); iter != holeLeft.end(); iter++)
	{
		temp += "\"D" + iter->first + "\" = " + to_string(iter->second.GetDiameter()) + "\n";
		temp += "\"X" + iter->first + "\" = " + to_string(iter->second.GetXcoordinate()) + "\n";
		temp += "\"Y" + iter->first + "\" = " + to_string(iter->second.GetYcoordinate()) + "\n";
		temp += "\"H" + iter->first + "\" = " + to_string(iter->second.GetDepth()) + "\n";
	}
	return temp;
}

ostream & operator<<(ostream & zout, DSP & D)
{
	zout << D.NameOfDetail << endl;
	zout << "��������: " << endl << D.Mater << endl;
	zout << "\"������\" = " << D.height << endl;
	zout << "\"������\" = " << D.width << endl;
	zout << "\"����.\" = " << D.thickness << endl;
	zout << "----------------------------------------" << endl << endl;
	//��� ����� �� ����� ������ ����
	return zout;
}
