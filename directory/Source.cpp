#include <iostream>
#include <fstream>
#include <string>
#include "directory.h"
#include <vector>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	vector<contact*>* directory = readDirectory();
	int item = 0;

	while (true) {

		cout << "0 - Выход" << endl;
		cout << "1 - Добавить запись" << endl;
		cout << "2 - Распечатать справочник" << endl;
		cout << "3 - Найти телефон по имени" << endl;
		cout << "4 - Найти имя по номеру" << endl;
		cout << "5 - Сохранить все изменения" << endl;

		cin >> item;

		switch (item) {
			default: {
				cout << "Некорректный пункт меню" << endl;
				break;
			}
			case 0: {

				delete directory;

				return 0;
				break;

			}
			case 1: {

				contact* newContact = contactFromConsole();
				if (directory == nullptr) {
					directory = new vector<contact*>;
				}
				(*directory).push_back(newContact);
				break;
			}

			case 2: {

				if (directory != nullptr) {
					for (unsigned int i = 0; i < directory->size(); ++i) {
						cout << (i + 1) << ") ";
						(*directory)[i]->outputConsole();
					}
				}
				else {
					cout << "Словарь пуст" << endl;
				}
				break;

			}

			case 3: {

				if (directory != nullptr) {
					string strToFind = "";

					cout << "Введите имя" << endl;
					cin >> strToFind;

					bool notFound = true;

					for (unsigned int i = 0; i < directory->size(); ++i) {
						if ((*directory)[i]->name == strToFind) {
							notFound = false;
							(*directory)[i]->outputConsole();
						}
					}

					if (notFound) {
						cout << "Контакт не найден" << endl;
					}
				}
				else {
					cout << "Словарь пуст" << endl;
				}
				break;
			}

			case 4: {

				if (directory != nullptr) {
					string strToFind = "";

					cout << "Введите номер" << endl;
					cin >> strToFind;

					bool notFound = true;

					for (unsigned int i = 0; i < directory->size(); ++i) {
						if ((*directory)[i]->number == strToFind) {
							notFound = false;
							(*directory)[i]->outputConsole();
						}
					}

					if (notFound) {
						cout << "Контакт не найден" << endl;
					}
				}
				else {
					cout << "Словарь пуст";
				}
				break;
			}

			case 5: {
				
				ofstream output;
				output.open(fileName, ios::out | ios::trunc);

				output << directory->size() << endl;

				for (unsigned int i = 0; i < directory->size() - 1; ++i) {
					output << (*directory)[i]->name << ";" << (*directory)[i]->number << endl;
				}
				output << (*directory)[directory->size() - 1]->name << ";" <<
					(*directory)[directory->size() - 1]->number;

				cout << "Изменения сохранены" << endl;

				output.close();
			}
		}
		system("pause");
		system("cls");
	}

	for (auto i : (*directory)) {
		delete i;
	}

	delete directory;

	return 0;
}

/*
0 - выйти
1 - добавить запись(имя и телефон)
2 - распечатать все имеющиеся записи
3 - найти телефон по имени
4 - найти имя по телефону
5 - сохранить текущие данные в файл */