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

void core(vector<Worker>& v)   //основное меню
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
int menu() // (ф-ция для выбора действия из основного меню) передаёт выбор
{
	int input;
	cout << "1 - ВОЙТИ " << endl;
	cout << "2 - ЗАРЕГИСТРИРОВАТЬСЯ" << endl;
	cout << "0- ВЫЙТИ" << endl;
	input = check_Input();
	return input;
}

int menu_for_admin() // (ф-ция для выбора действия из меню администратора) передаёт выбор
{
	int input;
	cout << "        МЕНЮ  АДМИНИСТРАТОРА           " << endl;
	cout << "1 - Просмотр учётных записей" << endl;
	cout << "2 - Добавление новой учётной записи" << endl;
	cout << "3 - Редактирование своей учётной записи" << endl;
	cout << "4 - Удаление учётной записи" << endl;
	cout << "5 - Подтверждение или блокировка учётной записи" << endl;
	cout << "6 - Поиск работника по ... " << endl;//по доступу //по фамилии//по логину 
	cout << "0 - ВЫЙТИ" << endl;

	input = check_Input();
	return input;
}
bool core_for_admin(vector<Worker>& v, int index) // меню администратора
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
int menu_for_employee() //(ф-ция для выбора действия из меню сотрудника) передаёт выбор
{
	int input;
	cout << "           МЕНЮ  СОТРУДНИКА         " << endl;
	cout << "1 - Просмотр своей учётной записи" << endl;
	cout << "2 - Редактирование личных данных в учётной записи" << endl;
	cout << "0 - ВЫЙТИ" << endl;

	input = check_Input();
	return input;
}
bool core_for_employee(vector<Worker>& v, int index) // меню сотрудника
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
int menu_for_chief()//(ф-ция для выбора действия из меню начальника) передаёт выбор
{
	int input;
	cout << "          МЕНЮ  НАЧАЛЬНИКА            " << endl;
	cout << "1 - Просмотр учётных записей" << endl;
	cout << "2 - Редактировать информацию о сотруднике" << endl;
	cout << "3 - Просмотр своей учётной записи" << endl;
	cout << "4 - Редактирование личных данных в учётной записи" << endl;
	cout << "5 - Поиск сотрудника по ..." << endl;//Фамилия//должность//отделу
	cout << "6 - Сортировка сотрудников по ..." << endl;//стаж//по отделу (1-начальник, 2-администратор,3-сотрудники)//возрасту(пенсионного возраста,и нет)
	cout << "0 - ВЫЙТИ" << endl;

	input = check_Input();
	return input;
}
bool core_for_chief(vector<Worker>& v, int index) // меню начальника
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

string choose_role(vector<Worker>& v)  //(ф-ция для выбора роли) передаёт роль 
{
	int rol;
	string role;
	cout << "Выберите роль: 1 - администратор, 2 - cотрудник, 3 - начальник " << endl;
	do {
		cout << "Введите: ";
		cin >> rol;
	} while (rol != 2 && rol != 1 && rol != 3);
	if (rol == 1)role = "администратор";
	if (rol == 2)role = "сотрудник";
	if (rol == 3)role = "начальник";
	cout << endl;
	return role;
}

void show_workers_admin(const vector<Worker> v)// показывает информацию о работнике(ФИО,логин,роль,доступ) в ф-циях администратора
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "ФИО " << i + 1 << "-го пользователя: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
		cout << "Логин: " << v.at(i).login << endl;
		cout << "Роль: " << v.at(i).role << endl;
		cout << "Доступ: ";
		if (v.at(i).access == 0)
			cout << "закрыт";
		else cout << "открыт";
		cout << endl;
	}
}
void show_worker_admin(const vector<Worker> v, int i)// показывает информацию о работниках(ФИО,логин,роль,доступ) в ф-циях администратора
{
	cout << "ФИО " << i + 1 << "-го пользователя: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "Логин: " << v.at(i).login << endl;
	cout << "Роль: " << v.at(i).role << endl;
	cout << "Доступ: ";
	if (v.at(i).access == 0)
		cout << "закрыт";
	else cout << "открыт";
	cout << endl;
}
void show_worker_him(const vector<Worker> v, int i)// показывает работнику информацию о нём (ФИО,логин,пароль,дата рождения) в ф-циях для редактирования
{
	cout << "1 - ФИО : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "2 - Логин: " << v.at(i).login << endl;
	cout << "3 - Пароль: " << " ********    (колтчество символов в пароле может не совпадать с выведенным количеством звёздочек)" << endl;
	cout << "4 - Дата рождения: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;

}
void see_himself(vector<Worker> v, int i) // показывае работнику информацию о нём(ФИО,логин,дата рождения,должность)
{
	cout << "ФИО : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "Логин: " << v.at(i).login << endl;
	cout << "Дата рождения: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;
	cout << "Должность: " << v[i].position << " отдела " << v[i].department << endl;
	if (v.at(i).start_work.day == 0) cout << "Дата начала работы не заполнена!";
	else
	{
		get_work_experience(v, i);
	}
	cout << endl;
}
void show_workers_chief(vector<Worker> v)//показывает информацию о работниках (ФИО,логин,роль,стаж) в ф-циях начальника
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "ФИО " << i + 1 << "-го пользователя: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
		cout << "Логин: " << v.at(i).login << endl;
		cout << "Должность: " << v.at(i).position << " в отделе " << v.at(i).department << endl;
		if (v.at(i).start_work.day == 0) cout << "Дата начала работы не заполнена!";
		else
		{
		    get_work_experience(v, i);
		}
		cout << endl;
	}
}
void show_worker_chief(vector<Worker> v, int i)//показывает информацию о работнике (ФИО,логин,роль,доступ,стаж) в ф-циях начальника
{

	cout << "ФИО : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "1- Должность: " << v.at(i).position << endl;
	cout << "2 - Отдел : " << v.at(i).department << endl;
	cout << "3 - Дата начала работы : ";
	if (v.at(i).start_work.day == 0) cout << "не заполнена.";
	else
	{
		cout << v.at(i).start_work.day << "." << v.at(i).start_work.month << "." << v.at(i).start_work.year;
	}
	cout << endl;
}

void read_workers_from_File(vector<Worker>& v)//считывает информацию из файла в вектор
{
	int i = 0;
	ifstream fin(FILE_WORKERS, ios::in);
	if (!fin.is_open())
	{
		Worker temp;
		temp.login = "admin_admin";
		temp.role = "администратор";
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
void write_Workers_in_File(vector<Worker>v)//записывает информацию из вектора в файл
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

		if (i < v.size() - 1) // не переставляет на новую строку,если это последняя запись
		{
			fout << endl;
		}
	}
	fout.close();
}

int authorization(const vector<Worker> v)//ф-ция авторизации пользователя(возвращает индекс пользователя в векторе)
{
	string login, pass;
	int index = -1, k = 0;
	int input;
	do {
		cout << "Введите ваш логин: ";
		login = check_Login();
		cout << "Введите пароль: ";
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
			cout << "\nВы ввели неверный логин или пароль.\nНажмите 0 - выйти в главное меню. Другую цифру - попробовать снова." << endl;
			input=check_Input();
			system("cls");
		}
	} while (input != 0);
	return index;
}
void entrance(vector<Worker>& v)// ф-ция "ВОЙТИ" (обеспечивает навигацию по ролевым меню) 
{
	int index = authorization(v);
	bool flag = true;
	if (index == -1) {
		cout << "Вы не авторизовались " << endl; flag = false;
	}
	system("cls");
	while (flag)
	{
		if (v.at(index).access == 0) {
			cout << "У вас нет доступа. Подождите, пожалуйста, пока администратор открое его" << endl;
			flag = false;
		}
		else
		{
			if (v.at(index).role == "администратор")
			{
				flag = core_for_admin(v, index);
			}
			else if (v.at(index).role == "начальник")
			{
				flag = core_for_chief(v, index);
			}
			else if (v.at(index).role == "сотрудник")
			{
				flag = core_for_employee(v, index);
			}
		}
	}
}

void registration(vector<Worker>& v)//ф-ция "ЗАРЕГИСТРИРОВАТЬСЯ" (создание нового элемента вектора Worker)
{
	Worker temp;
	bool flag = true;
	temp.role = choose_role(v);
	cout << "Придумайте логин(не менее 8-ми символов): ";
	while (flag) {
		temp.login = imagen_Login();
		flag = check_individuality(v, temp.login);
	}
	cout << "Придумайте пароль: ";
	temp.password = imagen_Password();
	cout << "Фамилия: ";
	temp.fio.surname = check_String();
	cout << "Имя: ";
	temp.fio.name = check_String();
	cout << "Отчество: ";
	temp.fio.patronymic = check_String();
	cout << "Дата рождения " << endl;
	temp.birth.day = check_day();
	temp.birth.month = check_month();
	temp.birth.year = check_year();
	if (temp.role == "администратор")
	{
		reg_admin(v, temp);
	}
	else if (temp.role == "сотрудник")
	{
		reg_employee(v, temp);

	}
	else if (temp.role == "начальник")
	{
		reg_chief(v, temp);

	}
	temp.access = 0;
	v.push_back(temp);
	cout << "Ваши данные записаны, подождите пока администратор открое вам доступ " << endl;
}
void registration_admin(vector<Worker>& v)// ф-ция для регистрации нового сотрудника администратором (используется в меню администратора)
{
	Worker temp;
	bool flag = true;
	temp.role = choose_role(v);
	cout << "Придумайте логин(не менее 8-ми символов): ";
	while (flag) {
		temp.login = imagen_Login();
		flag = check_individuality(v, temp.login);
	}
	cout << "Придумайте пароль: ";
	temp.password = imagen_Password();
	cout << "Фамилия: ";
	temp.fio.surname = check_line();
	cout << "Имя: ";
	temp.fio.name = check_line();
	cout << "Отчество: ";
	temp.fio.patronymic = check_line();
	cout << "Дата рождения " << endl;
	temp.birth.day = check_day();
	temp.birth.month = check_month();
	temp.birth.year = check_year();
	cout << "Доступ (1-открыт,0-закрыт): ";
	int input;
	do {
		cin >> input;
		if (input != 1 && input != 0) cout << "Вы ничего не выбрали. 1 - открыть, 0 - закрыть " << endl;
	} while (input != 1 && input != 0);
	temp.access = input;
	reg_employee(v, temp);
	v.push_back(temp);

}
void reg_admin(vector<Worker>& v, Worker& temp) // дополняет ф-цию registration(vector<Worker> v) в соответствие с ролью администратора
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
void reg_employee(vector<Worker>& v, Worker& temp) // дополняет ф-цию registration(vector<Worker> v) в соответствие с ролью сотрудника
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
void reg_chief(vector<Worker>& v, Worker& temp) // дополняет ф-цию registration(vector<Worker> v) в соответствие с ролью начальника
{

	temp.position = temp.role;
	cout << "Введите название отдела: ";
	temp.department = check_line();
	cout << "Дата начала работы " << endl;
	temp.start_work.day = check_day();
	temp.start_work.month = check_month();
	temp.start_work.year = check_year();
	temp.work_experience.day = 0;
	temp.work_experience.month = 0;
	temp.work_experience.year = 0;

}

void del(vector<Worker>& v)//ф-ция для удаления определённого работника
{
	show_workers_admin(v);
	cout << "Введите номер того, кого хотите удалить: ";
	int index_delete = check_Input();
	index_delete--;
	if (index_delete<0 || index_delete>v.size()) cout << "\nТакого сотрудника не существует!" << endl;
	else
	{
		v.erase(v.begin() + index_delete);
		cout << "\nУдаление прошло успешно" << endl;
	}

}
void update_for_chief(vector<Worker>& v) // ф-ция изменения/дополнения информации(должность,отдел,дата начала работы) о работниках для начальника
{
	int num, numeric = 0;
	bool flag = true;
	show_workers_chief(v);
	cout << "\n\nВведите номер сотрудника, которого хотите редактировать: " << endl;
	num = check_Input() - 1;
	while (flag)
	{
		show_worker_chief(v, num);
		cout << "Введите номер того, что хотите редактировать " << endl;
		numeric = check_Input();
		cout << endl;
		switch (numeric)
		{
		case 1:cout << "Должность: ";
			v.at(num).position = check_line();
			break;
		case 2:cout << "Отдел: ";
			v.at(num).department = check_line();
			break;
		case 3:cout << "Дата начала работы " << endl;
			v.at(num).start_work.day = check_day();
			v.at(num).start_work.month = check_month();
			v.at(num).start_work.year = check_year();
			break;
		default:cout << "Вы ничего не выбрали! " << endl;
		}
		
		cout << endl;
		cout << endl;
		cout << "Продолжить редактировать или Выйти в главное меню" << endl;
		cout << endl;
		flag = exit_or_not();
	}

}
void update_himself(vector<Worker>& v, int index) // ф-ция редактирования личной информации (ФИО,логин,пароль,дата рождения)
{
	int input;
	bool flag = true;
	while (flag)
	{
		show_worker_him(v, index);
		cout << "Выберите какую информацию вы хотите редактировать " << endl;
		input = check_Input();
		switch (input) {
		case 1:
			cout << " Фамилия: ";
			v[index].fio.surname = check_String();
			cout << " Имя: ";
			v[index].fio.name = check_String();
			cout << " Отчество: ";
			v[index].fio.patronymic = check_String();
			break;
		case 2:cout << "Логин: ";
			while (flag) {
				v[index].login = imagen_Login();
				flag = check_individuality(v, v[index].login);
			}
			break;
		case 3:cout << "Пароль: ";
			v[index].password = check_Password();
			break;
		case 4:cout << "Дата рождения " << endl;
			v[index].birth.day = check_day();
			v[index].birth.month = check_month();
			v[index].birth.year = check_year();
			break;
		default:cout << "Вы ничего не выбрали!" << endl;
		}
		cout << endl;
		cout << "Продолжить редактировать или Выйти в главное меню" << endl;
		flag = exit_or_not();
		system("cls");
	}
}
void confirm_or_block(vector<Worker>& v)//ф-ция открытия/блокировки доступа используется в меню администратора
{
	show_workers_admin(v);
	int index;
	int input;
	cout << "\n\nВведите номер того, чей доступ вы хотите изменить: ";
	index = check_Input();
	index--;
	if (index > v.size() || index < 0) cout << "Вы никого не выбрали" << endl;
	else {
		system("cls");
		show_worker_admin(v, index);
		cout << "Доступ данного пользователя ";
		if (v.at(index).access == 0) {
			cout << "закрыт" << endl;
			cout << endl;
			cout << "Хотите открыть доступ? Если да,то нажмите 1 " << endl;
			cin >> input;
			if (input == 1) {
				v.at(index).access = 1;
				cout << "Доступ открыт" << endl;
			}
			else cout << "Доступ остался прежним" << endl;
		}
		else {
			cout << "открыт" << endl;
			cout << endl;
			cout << "Хотите закрыть доступ? Если да,то нажмите 0" << endl;
			cin >> input;
			if (input == 0) {
				v.at(index).access = 0;
				cout << "Доступ закрыт" << endl;
			}
			else cout << "Доступ остался прежним" << endl;
		}
	}

	system("pause");
	system("cls");
}

void get_work_experience(vector<Worker>& v, int i) //ф-ция для вычисления стажа используется в меню начальника
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
    cout << "Стаж: ";
	if (year % 10 >= 5 || (year % 10 == 0 && year!=0)|| (year <= 19 && year >= 11)) cout << year << " лет ";
	else if (year % 10 == 1)cout << year << " год ";
	else if (year % 10 <= 4 && year % 10 >= 2)cout << year << " года ";

	if (mon == 1)cout << mon << " месяц ";
	if (mon <= 4 && mon >= 2) cout << mon << " месяца ";
	if (mon <= 12 && mon >= 5)cout << mon << " месяцев ";

	if (day % 10 >= 5 || day % 10 == 0 || (day <= 19 && day >= 11)) cout << day << " дней " << endl;
	else if (day % 10 == 1)cout << day << " день" << endl;
	else if (day % 10 <= 4 && day % 10 >= 2)cout << day << " дня " << endl;

	v.at(i).work_experience.day = day;
	v.at(i).work_experience.month = mon;
	v.at(i).work_experience.year = year;
}

bool check_individuality(const vector<Worker> v, string log) //проверка уникальности логина
{
	bool flag = false;
	for (int j = 0; j < v.size(); j++) {
		if (log == v.at(j).login) {
			cout << "Пользователь с таким логином уже существует. Придумайте другой логин: ";
			flag = true;
		}
	}
	return flag;
}
bool exit_or_not()//ф-ция вход/выход (возвращает boll)
{
	int num;
	cout << "1 - ПРОДОЛЖИТЬ              0 - ВЫХОД" << endl;
	cout << "Введите 0 или 1: ";
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