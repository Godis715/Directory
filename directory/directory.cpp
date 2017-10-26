#include "directory.h"

using namespace std;

/*���������� ������ outputFile ��������� contact
������������ ����� ��������� � ������� � ���� name number */
void contact::outputConsole() {
	cout << name << " " << number << endl;
}

/*������� ����������� ������(��������� �� ���� ���������� ���� string ���� name;number)
� ��������� contact � ���������� ��������� �� ���*/
contact* directoryLineToContact(string &str) {

	contact* newContact = new contact;

	int pos = str.find(';');

	*newContact = contact{ str.substr(0, pos), str.substr(pos + 1, str.length() - 1) };

	return newContact;
}

/*������� ��������� ��� � ����� �� ������� � ������� �� �� ������ ���������
���� contact, ���������� ��������� �� ��������� ���������*/
contact* contactFromConsole() {

	string name = "";
	string number = "";

	cout << "������� ���, ���" << endl;
	cout << ">> ";

	cin >> name;

	cout << "������� �����, ���" << endl;
	cout << ">> ";

	cin >> number;

	contact *newContact = new contact{ name, number };

	cout << "������� �������" << endl;

	return newContact;
}

/*������� ��������� ������� �� �����
��������� ��� ������ � �������� � ��������� � ������
���������� ��������� �� ������*/
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