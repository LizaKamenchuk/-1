#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<ctime>
#include"validation.h"
#include "sha1.h"
#include "sha256.h"

using namespace std;

struct FIO {
	string surname;
	string name;
	string patronymic;
};
struct Date {
	int day;
	int month;
	int year;
};
struct Worker {
	string login;
	string role;
	string password;
	int access;
	FIO fio;
	Date birth;
	string department;
	string position;
	Date start_work;
	Date work_experience;
};

const string FILE_WORKERS = "Data.txt";
const string FILE_ADMIN = "admin.txt";
void core(vector<Worker>& v);
int menu();
string choose_role(vector<Worker>& v);
int menu_for_admin();
bool core_for_admin(vector<Worker>& v, int index);
int menu_for_employee();
bool core_for_employee(vector<Worker>& v, int index);
int menu_for_chief();
bool core_for_chief(vector<Worker>& v, int index);


void see_himself(vector<Worker> v, int i);
void show_workers_admin(const vector<Worker> v);
void show_worker_admin(const vector<Worker> v, int i);
void show_worker_him(const vector<Worker> v, int i);
void show_workers_chief(vector<Worker> v);
void show_worker_chief(vector<Worker> v, int i);
void see_himself(vector<Worker> v, int i);
void read_workers_from_File(vector<Worker>& v);
void write_Workers_in_File(vector<Worker>v);

int authorization(const vector<Worker> v);
void entrance(vector<Worker>& v);

void registration(vector<Worker>& v);
void registration_admin(vector<Worker>& v);
void reg_admin(vector<Worker>& v, Worker& temp);
void reg_employee(vector<Worker>& v, Worker& temp);
void reg_chief(vector<Worker>& v, Worker& temp);

void del(vector<Worker>& v);
void update_for_chief(vector<Worker>& v);
void update_himself(vector<Worker>& v, int index);
void confirm_or_block(vector<Worker>& v);
void get_work_experience(vector<Worker>& v, int i);


bool check_individuality(const vector<Worker> v, string log);
bool exit_or_not();

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 30, number = 0;
	vector<Worker> v;
	v.reserve(n);

	read_workers_from_File(v);
	core(v);
	write_Workers_in_File(v);
}

void core(vector<Worker>& v)   //�������� ����
{
	int input;
	bool flag = true;

	while (flag)
	{
		input = menu();
		switch (input)
		{
		case 1:entrance(v);
			break;
		case 2:registration(v);
			exit_or_not();
			break;
		case 0:flag = false;
			break;
		}
	}
}
int menu() // (�-��� ��� ������ �������� �� ��������� ����) ������� �����
{
	int input;
	cout << "1 - ����� " << endl;
	cout << "2 - ������������������" << endl;
	cout << "0- �����" << endl;
	input = check_Input();
	return input;
}

int menu_for_admin() // (�-��� ��� ������ �������� �� ���� ��������������) ������� �����
{
	int input;
	cout << "        ����  ��������������           " << endl;
	cout << "1 - �������� ������� �������" << endl;
	cout << "2 - ���������� ����� ������� ������" << endl;
	cout << "3 - �������������� ����� ������� ������" << endl;
	cout << "4 - �������� ������� ������" << endl;
	cout << "5 - ������������� ��� ���������� ������� ������" << endl;
	cout << "6 - ����� ��������� �� ... " << endl;//�� ������� //�� �������//�� ������ 
	cout << "0 - �����" << endl;

	input = check_Input();
	return input;
}
bool core_for_admin(vector<Worker>& v, int index) // ���� ��������������
{
	bool flag = true;
	while (flag)
	{
		int item = menu_for_admin();
		switch (item)
		{
		case 1:system("cls");
			show_workers_admin(v);
			break;
		case 2:system("cls");
			registration_admin(v);
			break;
		case 3:system("cls");
			update_himself(v, index);
			break;
		case 4:system("cls");
			del(v);
			break;
		case 5:system("cls");
			confirm_or_block(v);
			break;
		case 6:
			break;
		case 0: flag = false;
			break;
		}
	}
	return flag;
}
int menu_for_employee() //(�-��� ��� ������ �������� �� ���� ����������) ������� �����
{
	int input;
	cout << "           ����  ����������         " << endl;
	cout << "1 - �������� ����� ������� ������" << endl;
	cout << "2 - �������������� ������ ������ � ������� ������" << endl;
	cout << "0 - �����" << endl;

	input = check_Input();
	return input;
}
bool core_for_employee(vector<Worker>& v, int index) // ���� ����������
{
	bool flag = true;
	while (flag)
	{
		int item = menu_for_employee();
		switch (item)
		{
		case 1:system("cls");
			see_himself(v, index);
			break;
		case 2:system("cls");
			update_himself(v, index);
			break;
		case 0: flag = false;
			break;
		}
	}
	return flag;
}
int menu_for_chief()//(�-��� ��� ������ �������� �� ���� ����������) ������� �����
{
	int input;
	cout << "          ����  ����������            " << endl;
	cout << "1 - �������� ������� �������" << endl;
	cout << "2 - ������������� ���������� � ����������" << endl;
	cout << "3 - �������� ����� ������� ������" << endl;
	cout << "4 - �������������� ������ ������ � ������� ������" << endl;
	cout << "5 - ����� ���������� �� ..." << endl;//�������//���������//������
	cout << "6 - ���������� ����������� �� ..." << endl;//����//�� ������ (1-���������, 2-�������������,3-����������)//��������(����������� ��������,� ���)
	cout << "0 - �����" << endl;

	input = check_Input();
	return input;
}
bool core_for_chief(vector<Worker>& v, int index) // ���� ����������
{
	bool flag = true;
	while (flag)
	{
		int item = menu_for_chief();
		switch (item)
		{
		case 1:system("cls");
			show_workers_chief(v);
			break;
		case 2:system("cls");
			update_for_chief(v);
			break;
		case 3:system("cls");
			see_himself(v, index);
			break;
		case 4:system("cls");
			update_himself(v, index);
			break;
		case 5:
			break;
		case 6:
			break;
		case 0: flag = false;
			break;
		}
	}
	return flag;
}

string choose_role(vector<Worker>& v)  //(�-��� ��� ������ ����) ������� ���� 
{
	int rol;
	string role;
	cout << "�������� ����: 1 - �������������, 2 - c��������, 3 - ��������� " << endl;
	do {
		cout << "�������: ";
		cin >> rol;
	} while (rol != 2 && rol != 1 && rol != 3);
	if (rol == 1)role = "�������������";
	if (rol == 2)role = "���������";
	if (rol == 3)role = "���������";
	cout << endl;
	return role;
}

void show_workers_admin(const vector<Worker> v)// ���������� ���������� � ���������(���,�����,����,������) � �-���� ��������������
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
		cout << "�����: " << v.at(i).login << endl;
		cout << "����: " << v.at(i).role << endl;
		cout << "������: ";
		if (v.at(i).access == 0)
			cout << "������";
		else cout << "������";
		cout << endl;
	}
}
void show_worker_admin(const vector<Worker> v, int i)// ���������� ���������� � ����������(���,�����,����,������) � �-���� ��������������
{
	cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "�����: " << v.at(i).login << endl;
	cout << "����: " << v.at(i).role << endl;
	cout << "������: ";
	if (v.at(i).access == 0)
		cout << "������";
	else cout << "������";
	cout << endl;
}
void show_worker_him(const vector<Worker> v, int i)// ���������� ��������� ���������� � �� (���,�����,������,���� ��������) � �-���� ��� ��������������
{
	cout << "1 - ��� : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "2 - �����: " << v.at(i).login << endl;
	cout << "3 - ������: " << " ********    (���������� �������� � ������ ����� �� ��������� � ���������� ����������� ��������)" << endl;
	cout << "4 - ���� ��������: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;

}
void see_himself(vector<Worker> v, int i) // ��������� ��������� ���������� � ��(���,�����,���� ��������,���������)
{
	cout << "��� : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "�����: " << v.at(i).login << endl;
	cout << "���� ��������: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;
	cout << "���������: " << v[i].position << " ������ " << v[i].department << endl;
	if (v.at(i).start_work.day == 0) cout << "���� ������ ������ �� ���������!";
	else
	{
		get_work_experience(v, i);
	}
	cout << endl;
}
void show_workers_chief(vector<Worker> v)//���������� ���������� � ���������� (���,�����,����,����) � �-���� ����������
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
		cout << "�����: " << v.at(i).login << endl;
		cout << "���������: " << v.at(i).position << " � ������ " << v.at(i).department << endl;
		if (v.at(i).start_work.day == 0) cout << "���� ������ ������ �� ���������!";
		else
		{
		    get_work_experience(v, i);
		}
		cout << endl;
	}
}
void show_worker_chief(vector<Worker> v, int i)//���������� ���������� � ��������� (���,�����,����,������,����) � �-���� ����������
{

	cout << "��� : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "1- ���������: " << v.at(i).position << endl;
	cout << "2 - ����� : " << v.at(i).department << endl;
	cout << "3 - ���� ������ ������ : ";
	if (v.at(i).start_work.day == 0) cout << "�� ���������.";
	else
	{
		cout << v.at(i).start_work.day << "." << v.at(i).start_work.month << "." << v.at(i).start_work.year;
	}
	cout << endl;
}

void read_workers_from_File(vector<Worker>& v)//��������� ���������� �� ����� � ������
{
	int i = 0;
	ifstream fin(FILE_WORKERS, ios::in);
	if (!fin.is_open())
	{
		Worker temp;
		temp.login = "admin_admin";
		temp.role = "�������������";
		temp.password = "1";
		temp.access = 1;
		temp.fio.surname = "--- "; temp.fio.name = " --- "; temp.fio.patronymic = " ---";
		temp.birth.day = 0; temp.birth.month = 0; temp.birth.year = 0;
		temp.position = temp.role; temp.department = " ---";
		temp.start_work.day = 0; temp.start_work.month = 0; temp.start_work.year = 0;
		v.push_back(temp);
		write_Workers_in_File(v);
	}

	else
	{
		while (!fin.eof())
		{
			Worker temp;
			fin >> temp.login;
			fin >> temp.role;
			fin >> temp.password;
			fin >> temp.access;
			fin >> temp.fio.surname >> temp.fio.name >> temp.fio.patronymic;
			fin >> temp.birth.day >> temp.birth.month >> temp.birth.year;
			fin >> temp.position >> temp.department;
			fin >> temp.start_work.day >> temp.start_work.month >> temp.start_work.year;
			v.push_back(temp);
		}
	}
	fin.close();
}
void write_Workers_in_File(vector<Worker>v)//���������� ���������� �� ������� � ����
{
	ofstream fout(FILE_WORKERS, ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fout << v.at(i).login << " "
			<< v.at(i).role << " "
			<< v.at(i).password << " "
			<< v.at(i).access << " "
			<< v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << " "
			<< v.at(i).birth.day << " " << v.at(i).birth.month << " " << v.at(i).birth.year
			<< v.at(i).position << " " << v.at(i).department << " "
			<< v.at(i).start_work.day << " " << v.at(i).start_work.month << " " << v.at(i).start_work.year;

		if (i < v.size() - 1) // �� ������������ �� ����� ������,���� ��� ��������� ������
		{
			fout << endl;
		}
	}
	fout.close();
}

int authorization(const vector<Worker> v)//�-��� ����������� ������������(���������� ������ ������������ � �������)
{
	string login, pass;
	int index = -1, k = 0;
	int input;
	do {
		cout << "������� ��� �����: ";
		login = check_Login();
		cout << "������� ������: ";
		pass = check_Password();
		for (int i = 0; i < v.size(); i++) {
			if (login == v.at(i).login && pass == v.at(i).password)
			{
				index = i;
				k++;
				input = 0;
			}
        }
		if (k == 0)
		{
			cout << "\n�� ����� �������� ����� ��� ������.\n������� 0 - ����� � ������� ����. ������ ����� - ����������� �����." << endl;
			input=check_Input();
			system("cls");
		}
	} while (input != 0);
	return index;
}
void entrance(vector<Worker>& v)// �-��� "�����" (������������ ��������� �� ������� ����) 
{
	int index = authorization(v);
	bool flag = true;
	if (index == -1) {
		cout << "�� �� �������������� " << endl; flag = false;
	}
	system("cls");
	while (flag)
	{
		if (v.at(index).access == 0) {
			cout << "� ��� ��� �������. ���������, ����������, ���� ������������� ������ ���" << endl;
			flag = false;
		}
		else
		{
			if (v.at(index).role == "�������������")
			{
				flag = core_for_admin(v, index);
			}
			else if (v.at(index).role == "���������")
			{
				flag = core_for_chief(v, index);
			}
			else if (v.at(index).role == "���������")
			{
				flag = core_for_employee(v, index);
			}
		}
	}
}

void registration(vector<Worker>& v)//�-��� "������������������" (�������� ������ �������� ������� Worker)
{
	Worker temp;
	bool flag = true;
	temp.role = choose_role(v);
	cout << "���������� �����(�� ����� 8-�� ��������): ";
	while (flag) {
		temp.login = imagen_Login();
		flag = check_individuality(v, temp.login);
	}
	cout << "���������� ������: ";
	temp.password = imagen_Password();
	cout << "�������: ";
	temp.fio.surname = check_String();
	cout << "���: ";
	temp.fio.name = check_String();
	cout << "��������: ";
	temp.fio.patronymic = check_String();
	cout << "���� �������� " << endl;
	temp.birth.day = check_day();
	temp.birth.month = check_month();
	temp.birth.year = check_year();
	if (temp.role == "�������������")
	{
		reg_admin(v, temp);
	}
	else if (temp.role == "���������")
	{
		reg_employee(v, temp);

	}
	else if (temp.role == "���������")
	{
		reg_chief(v, temp);

	}
	temp.access = 0;
	v.push_back(temp);
	cout << "���� ������ ��������, ��������� ���� ������������� ������ ��� ������ " << endl;
}
void registration_admin(vector<Worker>& v)// �-��� ��� ����������� ������ ���������� ��������������� (������������ � ���� ��������������)
{
	Worker temp;
	bool flag = true;
	temp.role = choose_role(v);
	cout << "���������� �����(�� ����� 8-�� ��������): ";
	while (flag) {
		temp.login = imagen_Login();
		flag = check_individuality(v, temp.login);
	}
	cout << "���������� ������: ";
	temp.password = imagen_Password();
	cout << "�������: ";
	temp.fio.surname = check_line();
	cout << "���: ";
	temp.fio.name = check_line();
	cout << "��������: ";
	temp.fio.patronymic = check_line();
	cout << "���� �������� " << endl;
	temp.birth.day = check_day();
	temp.birth.month = check_month();
	temp.birth.year = check_year();
	cout << "������ (1-������,0-������): ";
	int input;
	do {
		cin >> input;
		if (input != 1 && input != 0) cout << "�� ������ �� �������. 1 - �������, 0 - ������� " << endl;
	} while (input != 1 && input != 0);
	temp.access = input;
	reg_employee(v, temp);
	v.push_back(temp);

}
void reg_admin(vector<Worker>& v, Worker& temp) // ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ��������������
{

	temp.position = temp.role;
	temp.department = "---";
	temp.start_work.day = 0;
	temp.start_work.month = 0;
	temp.start_work.year = 0;
	temp.work_experience.day = 0;
	temp.work_experience.month = 0;
	temp.work_experience.year = 0;

}
void reg_employee(vector<Worker>& v, Worker& temp) // ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ����������
{

	temp.position = "---";
	temp.department = "---";
	temp.start_work.day = 0;
	temp.start_work.month = 0;
	temp.start_work.year = 0;
	temp.work_experience.day = 0;
	temp.work_experience.month = 0;
	temp.work_experience.year = 0;

}
void reg_chief(vector<Worker>& v, Worker& temp) // ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ����������
{

	temp.position = temp.role;
	cout << "������� �������� ������: ";
	temp.department = check_line();
	cout << "���� ������ ������ " << endl;
	temp.start_work.day = check_day();
	temp.start_work.month = check_month();
	temp.start_work.year = check_year();
	temp.work_experience.day = 0;
	temp.work_experience.month = 0;
	temp.work_experience.year = 0;

}

void del(vector<Worker>& v)//�-��� ��� �������� ������������ ���������
{
	show_workers_admin(v);
	cout << "������� ����� ����, ���� ������ �������: ";
	int index_delete = check_Input();
	index_delete--;
	if (index_delete<0 || index_delete>v.size()) cout << "\n������ ���������� �� ����������!" << endl;
	else
	{
		v.erase(v.begin() + index_delete);
		cout << "\n�������� ������ �������" << endl;
	}

}
void update_for_chief(vector<Worker>& v) // �-��� ���������/���������� ����������(���������,�����,���� ������ ������) � ���������� ��� ����������
{
	int num, numeric = 0;
	bool flag = true;
	show_workers_chief(v);
	cout << "\n\n������� ����� ����������, �������� ������ �������������: " << endl;
	num = check_Input() - 1;
	while (flag)
	{
		show_worker_chief(v, num);
		cout << "������� ����� ����, ��� ������ ������������� " << endl;
		numeric = check_Input();
		cout << endl;
		switch (numeric)
		{
		case 1:cout << "���������: ";
			v.at(num).position = check_line();
			break;
		case 2:cout << "�����: ";
			v.at(num).department = check_line();
			break;
		case 3:cout << "���� ������ ������ " << endl;
			v.at(num).start_work.day = check_day();
			v.at(num).start_work.month = check_month();
			v.at(num).start_work.year = check_year();
			break;
		default:cout << "�� ������ �� �������! " << endl;
		}
		
		cout << endl;
		cout << endl;
		cout << "���������� ������������� ��� ����� � ������� ����" << endl;
		cout << endl;
		flag = exit_or_not();
	}

}
void update_himself(vector<Worker>& v, int index) // �-��� �������������� ������ ���������� (���,�����,������,���� ��������)
{
	int input;
	bool flag = true;
	while (flag)
	{
		show_worker_him(v, index);
		cout << "�������� ����� ���������� �� ������ ������������� " << endl;
		input = check_Input();
		switch (input) {
		case 1:
			cout << " �������: ";
			v[index].fio.surname = check_String();
			cout << " ���: ";
			v[index].fio.name = check_String();
			cout << " ��������: ";
			v[index].fio.patronymic = check_String();
			break;
		case 2:cout << "�����: ";
			while (flag) {
				v[index].login = imagen_Login();
				flag = check_individuality(v, v[index].login);
			}
			break;
		case 3:cout << "������: ";
			v[index].password = check_Password();
			break;
		case 4:cout << "���� �������� " << endl;
			v[index].birth.day = check_day();
			v[index].birth.month = check_month();
			v[index].birth.year = check_year();
			break;
		default:cout << "�� ������ �� �������!" << endl;
		}
		cout << endl;
		cout << "���������� ������������� ��� ����� � ������� ����" << endl;
		flag = exit_or_not();
		system("cls");
	}
}
void confirm_or_block(vector<Worker>& v)//�-��� ��������/���������� ������� ������������ � ���� ��������������
{
	show_workers_admin(v);
	int index;
	int input;
	cout << "\n\n������� ����� ����, ��� ������ �� ������ ��������: ";
	index = check_Input();
	index--;
	if (index > v.size() || index < 0) cout << "�� ������ �� �������" << endl;
	else {
		system("cls");
		show_worker_admin(v, index);
		cout << "������ ������� ������������ ";
		if (v.at(index).access == 0) {
			cout << "������" << endl;
			cout << endl;
			cout << "������ ������� ������? ���� ��,�� ������� 1 " << endl;
			cin >> input;
			if (input == 1) {
				v.at(index).access = 1;
				cout << "������ ������" << endl;
			}
			else cout << "������ ������� �������" << endl;
		}
		else {
			cout << "������" << endl;
			cout << endl;
			cout << "������ ������� ������? ���� ��,�� ������� 0" << endl;
			cin >> input;
			if (input == 0) {
				v.at(index).access = 0;
				cout << "������ ������" << endl;
			}
			else cout << "������ ������� �������" << endl;
		}
	}

	system("pause");
	system("cls");
}

void get_work_experience(vector<Worker>& v, int i) //�-��� ��� ���������� ����� ������������ � ���� ����������
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	int check;
	int day = t.wDay - v.at(i).start_work.day;
	int mon = t.wMonth - v.at(i).start_work.month;
	int year = t.wYear - v.at(i).start_work.year;
	if (mon < 0) {
		check = year * 12 + mon;
		year = check / 12;
		mon = check % 12;
	}
	if (day < 0) {
		mon = mon - 1;
		day = t.wDay;
	}
    cout << "����: ";
	if (year % 10 >= 5 || (year % 10 == 0 && year!=0)|| (year <= 19 && year >= 11)) cout << year << " ��� ";
	else if (year % 10 == 1)cout << year << " ��� ";
	else if (year % 10 <= 4 && year % 10 >= 2)cout << year << " ���� ";

	if (mon == 1)cout << mon << " ����� ";
	if (mon <= 4 && mon >= 2) cout << mon << " ������ ";
	if (mon <= 12 && mon >= 5)cout << mon << " ������� ";

	if (day % 10 >= 5 || day % 10 == 0 || (day <= 19 && day >= 11)) cout << day << " ���� " << endl;
	else if (day % 10 == 1)cout << day << " ����" << endl;
	else if (day % 10 <= 4 && day % 10 >= 2)cout << day << " ��� " << endl;

	v.at(i).work_experience.day = day;
	v.at(i).work_experience.month = mon;
	v.at(i).work_experience.year = year;
}

bool check_individuality(const vector<Worker> v, string log) //�������� ������������ ������
{
	bool flag = false;
	for (int j = 0; j < v.size(); j++) {
		if (log == v.at(j).login) {
			cout << "������������ � ����� ������� ��� ����������. ���������� ������ �����: ";
			flag = true;
		}
	}
	return flag;
}
bool exit_or_not()//�-��� ����/����� (���������� boll)
{
	int num;
	cout << "1 - ����������              0 - �����" << endl;
	cout << "������� 0 ��� 1: ";
	cin >> num;
	cout << endl;
	switch (num)
	{
	case 1:system("cls"); return true;
		break;
	case 2: system("cls"); return false;
		break;
	}
}