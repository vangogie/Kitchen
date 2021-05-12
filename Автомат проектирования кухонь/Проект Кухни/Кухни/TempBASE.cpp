#include "TempBASE.h"

TempBASE::TempBASE()
{
}

TempBASE::~TempBASE()
{
}

void TempBASE::AddTempMaterial(Material NewMaterial, double QTY, double cost)
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
}
