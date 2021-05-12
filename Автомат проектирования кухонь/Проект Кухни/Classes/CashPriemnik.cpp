#include "CashPriemnik.h"

bool CashPriemnik::ValidMoney(int kupura)
{
	if (money.find(kupura) != money.end()) return true;
	return false;
}

CashPriemnik::CashPriemnik(int maxSize, int currentSize)
{
	this->maxSize = maxSize;
	money[1000] = money[500] = money[200] = money[100] = money[50] = money[20] = money[10] = money[5] = money[2] = money[1] = currentSize;
}

CashPriemnik::~CashPriemnik()
{
}

bool CashPriemnik::HavePlace(int kupura)
{
	if (!ValidMoney(kupura)) return false;
	if (money[kupura] < maxSize) return true;
	return false;
}

bool CashPriemnik::MoneyTake(int kupura)
{
	if (HavePlace(kupura))
	{
		money[kupura]++;
		return true;
	}
	return false;
}

int CashPriemnik::MoneyGive(int money)
{
	return 0;
}

void CashPriemnik::ShowMoney()
{
	for (map<int, int>::iterator iter = money.begin(); iter != money.end(); iter++)
	{
		cout << "Êóïþðà " << iter->first << " ãðí.: " << setw(4) << iter->second << " øò." << endl;
	}
}
