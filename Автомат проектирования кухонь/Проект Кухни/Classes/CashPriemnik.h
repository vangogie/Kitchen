#pragma once //директива для отключения дублирования библиотек
#include <iostream> //библиотека работы с функциями и потоками ввода-вывода
#include <iomanip> //библиотека разметки
#include <algorithm> //алгоритм для STL библиотек
#include <map> //библиотека ассоциативного массив

using namespace std;

class CashPriemnik
{
private:
	int maxSize;//устанавливает максимальное количество каждой купуюры в лотке
	map<int, int> money;
	bool ValidMoney(int kupura); //метод проверки существования такой купюры

public:
	CashPriemnik(int maxSize, int currentSize); //currentSize устанавливает текущее количество денег
	~CashPriemnik();

	bool HavePlace(int kupura); //проверяет есть ли место для купюры
	bool MoneyTake(int kupura); //принимает купюру
	int MoneyGive(int money); //выдает сдачу целиком (ДОДУМАТЬ КАК ЭТО СДЕЛАТЬ)!!!!!!
	void ShowMoney(); //показывает все что находится в купюроприемнике
};

