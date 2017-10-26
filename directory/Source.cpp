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

		cout << "0 - �����" << endl;
		cout << "1 - �������� ������" << endl;
		cout << "2 - ����������� ����������" << endl;
		cout << "3 - ����� ������� �� �����" << endl;
		cout << "4 - ����� ��� �� ������" << endl;
		cout << "5 - ��������� ��� ���������" << endl;

		cin >> item;

		switch (item) {
			default: {
				cout << "������������ ����� ����" << endl;
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
					cout << "������� ����" << endl;
				}
				break;

			}

			case 3: {

				if (directory != nullptr) {
					string strToFind = "";

					cout << "������� ���" << endl;
					cin >> strToFind;

					bool notFound = true;

					for (unsigned int i = 0; i < directory->size(); ++i) {
						if ((*directory)[i]->name == strToFind) {
							notFound = false;
							(*directory)[i]->outputConsole();
						}
					}

					if (notFound) {
						cout << "������� �� ������" << endl;
					}
				}
				else {
					cout << "������� ����" << endl;
				}
				break;
			}

			case 4: {

				if (directory != nullptr) {
					string strToFind = "";

					cout << "������� �����" << endl;
					cin >> strToFind;

					bool notFound = true;

					for (unsigned int i = 0; i < directory->size(); ++i) {
						if ((*directory)[i]->number == strToFind) {
							notFound = false;
							(*directory)[i]->outputConsole();
						}
					}

					if (notFound) {
						cout << "������� �� ������" << endl;
					}
				}
				else {
					cout << "������� ����";
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

				cout << "��������� ���������" << endl;

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
0 - �����
1 - �������� ������(��� � �������)
2 - ����������� ��� ��������� ������
3 - ����� ������� �� �����
4 - ����� ��� �� ��������
5 - ��������� ������� ������ � ���� */