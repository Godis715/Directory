#pragma once
#include "directory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string fileName = "directory.txt";

struct contact {

	string name;
	string number;

	void outputConsole();
};

/*преобразует строку из словаря в структуру contact, 
принимает string
возвращает *contact */
contact*  directoryLineToContact(string &str);

/*функция считывает данные с консоли, которые преобразует в contact
возвращает *contact */
contact* contactFromConsole();

/*считывает строки из словаря в вектор
возвращает vector<contact* >* */
vector<contact*>* readDirectory();