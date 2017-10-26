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

/*����������� ������ �� ������� � ��������� contact, 
��������� string
���������� *contact */
contact*  directoryLineToContact(string &str);

/*������� ��������� ������ � �������, ������� ����������� � contact
���������� *contact */
contact* contactFromConsole();

/*��������� ������ �� ������� � ������
���������� vector<contact* >* */
vector<contact*>* readDirectory();