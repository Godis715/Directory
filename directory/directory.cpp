#include "directory.h"

using namespace std;

/*реализация метода outputFile структуры contact
осуществляет вывод структуры в консоль в виде name number */
void contact::outputConsole() {
	cout << name << " " << number << endl;
}

/*функция преобразует строку(принимает на вход переменную типа string вида name;number)
в структуру contact и возвращает указатель на нее*/
contact* directoryLineToContact(string &str) {

	contact* newContact = new contact;

	int pos = str.find(';');

	*newContact = contact{ str.substr(0, pos), str.substr(pos + 1, str.length() - 1) };

	return newContact;
}

/*функция считывает имя и номер из консоли и создает на их основе структуру
типа contact, возвращает указатель на созданную структуру*/
contact* contactFromConsole() {

	string name = "";
	string number = "";

	cout << "Введите имя, сэр" << endl;
	cout << ">> ";

	cin >> name;

	cout << "Введите номер, сэр" << endl;
	cout << ">> ";

	cin >> number;

	contact *newContact = new contact{ name, number };

	cout << "Контакт записан" << endl;

	return newContact;
}

/*функция считывает словарь из файла
переводит все строки в контакты и сохраняет в вектор
возвращает указатель на вектор*/
vector<contact*>* readDirectory() {

	ifstream input;
	input.open(fileName, ios::in);

	string sizeStr = "";
	getline(input, sizeStr);

	if (sizeStr != "") {
		int size = stoi(sizeStr);

		vector<contact*>* directory = new vector<contact*>(size);

		for (int i = 0; i < size; ++i) {
			(*directory)[i] = new contact;
		}

		for (int i = 0; !input.eof(); ++i) {

			string str = "";
			getline(input, str);

			(*directory)[i] = directoryLineToContact(str);
		}

		input.close();

		return directory;
	}
	return nullptr;
}