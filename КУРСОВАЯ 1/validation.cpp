#include<string>
#include<iostream>
#include<conio.h>

using namespace std;

int check_Input()//проверка ввода типа int (возвращает число типа int)
{
	int num;
	while (true)
	{
		cin >> num;
		if (cin.good()) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Вводимые данные должны состоять только из цифр, повторите: " << endl;
		}
	}
	return num;
}
int check_day()//проверка числа месяца 
{
	int a;
	cout << " Число: ";
	while (true) {
		a = check_Input();
		if (!(a < 32 && a>0)) cout << "Вы ошиблись с числом,попробуйте ещё раз (оно может быть с 1 по 31)" << endl;
		else
		{
			return a;
		}
	}
}
int check_month()//проверка месяца 
{
	int a;
	cout << " Месяц: ";
	while (true) {
		a = check_Input();
		if (!(a < 13 && a>0)) cout << "Вы ошиблись с месяцем ,попробуйте ещё раз (он может быть от 1 до 12)" << endl;
		else
		{
			return a;
		}
	}
}
int check_year()//проверка года
{
	int a;
	cout << " Год: ";
	while (true) {
		a = check_Input();
		if (!(a<= 2022 && a > 1922)) cout << "Вы ошиблись с годом ,попробуйте ещё раз (он может быть с 1922 по 2022)" << endl;
		else
		{
			return a;
		}
	}
}
string imagen_Login() //ф-ция для создания логина (возвращает логин типа string)
{
	string log;
	int i = 0;
	char*login= new char [20];//динамический массив символов для хранения логина во время создания
	while (true)
	{
		if (i > 18) {
			do {
				login[i] = _getch();
			} while (login[i] != 8 && login[i] != 13);
		}
		else login[i] = _getch();

		if (login[i] == 13 && i > 7) break;
		if (login[i] == 8 && i > 0) //back spase
		{
			cout << "\b \b";
			i--;
			continue;
		}
		//проверка, разрешающая ввод латинских букв,цифр и ".", "_", "@", "-"
		if (!((login[i] <= 'Z' && login[i] >= 'A') || (login[i] <= 'z' && login[i] >= 'a') ||  (login[i] <= '9' && login[i] >= '0') || login[i] == '.'
			|| login[i] == '_' || login[i] == '@' || login[i] == '-')) {
			continue;
		}

		cout << login[i];
		i++;
	}
	login[i] = '\0';
	log = login;
	delete[] login;
	cout << endl;
	return log;
}
string check_Login() {
	string log;
	int i = 0;
	char*login = new char[20];//динамический массив символов для хранения логина во время создания
	while (true)
	{
		if (i > 18) {
			do {
				login[i] = _getch();
			} while (login[i] != 8 && login[i] != 13);
		}
		else login[i] = _getch();

		if (login[i] == 13) break;
		if (login[i] == 8 && i > 0) //back spase
		{
			cout << "\b \b";
			i--;
			continue;
		}
		//проверка, разрешающая ввод латинских букв,цифр и ".", "_", "@", "-"
		if (!((login[i] <= 'Z' && login[i] >= 'A') || (login[i] <= 'z' && login[i] >= 'a') || (login[i] <= '9' && login[i] >= '0') || login[i] == '.'
			|| login[i] == '_' || login[i] == '@' || login[i] == '-')) {
			continue;
		}

		cout << login[i];
		i++;
	}
	login[i] = '\0';
	log = login;
	delete[] login;
	cout << endl;
	return log;
}
string check_Password() //ф-ция для ввода пароля (возвращает пароль типа string)
{
	char pas[20];//статический массив символов для хранения пароля во время ввода
	int i = 0;
	while (true)
	{
		if (i > 18) {
			do {
				pas[i] = _getch();
			} while (pas[i] != 8 && pas[i] != 13);
		}
		else pas[i] = _getch();

		if (pas[i] == 13 && i > 0) break;
		if (pas[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (!((pas[i] <= 'Z' && pas[i] >= 'A') || (pas[i] <= 'z' && pas[i] >= 'a') || (pas[i] <= '9' && pas[i] >= '0') || pas[i] == '.'
			|| pas[i] == '_' || pas[i] == '(' || pas[i] == ')' || pas[i] == '-')) continue;

		cout << pas[i];
		i++;
	}
	pas[i] = '\0';
	cout << endl;
	string pass = pas;
	return pass;
}
string imagen_Password()// ф-ция для создания пароля (возвращает пароль типа string)
{

	char* pass = new char(20);//статический массив символо для хранения пароля во создания
	int i = 0, number = 0, letter = 0, caplet = 0;// счётчики индекса, цифр,прописных и заглавных букв соответственно
	string password;
	while (true) {
		number = 0, letter = 0, caplet = 0;
		if (i > 15) {
			do {
				pass[i] = _getch();
			} while (pass[i] != 8 && pass[i] != 13);
		}
		else pass[i] = _getch();

		system("cls");
		cout << "Придумайте пароль,содержащий не менее 8-ми символов" << endl;

		for (int j = 0; j < i; j++) { cout << "*"; }//вывод "*" при вводе пароля
		for (int j = 0; j < i; j++) // подсчёт цифр, прописных и заглавных букв
		{
			if (pass[j] <= '9' && pass[j] >= '0') number++;
			if (pass[j] <= 'z' && pass[j] >= 'a')letter++;
			if (pass[j] <= 'Z' && pass[j] >= 'A') caplet++;

		}

		if (pass[i] == 13 && number != 0 && letter != 0 && caplet != 0 && i >= 8) break;
		if (pass[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (!((pass[i] <= 'Z' && pass[i] >= 'A') || (pass[i] <= 'z' && pass[i] >= 'a') || (pass[i] <= '9' && pass[i] >= '0')
			|| pass[i] == '.' || pass[i] == '_' || pass[i] == '-' || pass[i] == '(' || pass[i] == ')')) continue;
		if (pass[i] == ' ') continue;

		cout << "*" << endl;
		// вывод подсказок в соответствии с уже введённым паролем (по содержанию цифр,прописных и заглавных букв)
		if (i < 7) cout << "Ваш пароль небезопасный,он должен содержать БОЛЬШЕ СИМВОЛОВ ";
		else {
			if (number != 0 && (caplet == 0 && letter == 0)) cout << "Ваш пароль небезопасный, используйте БУКВЫ верхнего и нижнего регистра";
			else
				if (letter != 0 && (number == 0 && caplet == 0)) cout << "Ваш пароль небезопасный, используйте ЦИФРЫ и ЗАГЛАВНЫЕ БУКВЫ";
				else
					if (caplet != 0 && (number == 0 && letter == 0)) cout << "Ваш пароль небезопасный, используйте ЦИФРЫ и СТРОЧНЫЕ БУКВЫ";
					else
						if ((number != 0 && letter != 0) && caplet == 0) cout << "Ваш пароль небезопасный, используйте ЗАГЛАВНЫЕ БУКВЫ ";
						else
							if ((number != 0 && caplet != 0) && letter == 0) cout << "Ваш пароль небезопасный, используйте СТРОЧНЫЕ БУКВЫ ";
							else
								if ((letter != 0 && caplet != 0) && number == 0) cout << "Ваш пароль небезопасный, используйте ЦИФРЫ";
								else
									cout << "Вы придумали отличный пароль!";

		}
		i++;
	}
	pass[i] = '\0';
	cout << endl;
	password = pass;
	return password;
}
string check_String()// проверка при вводе ФИО (возвращает string)
{

	int i = 0;
	char name[22];
	while (true) {
		if (i > 20) {
			do {
				name[i] = _getch();
			} while (name[i] != 8 && name[i] != 13);
		}
		else name[i] = _getch();
		if (name[i] == 13 && i > 1) break;
		if (name[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (!(name[0] <= 'Я' && name[0] >= 'А') || name[i] == 'Ё' ) continue;
		if (!((name[i] <= 'я' && name[i] >= 'а') || name[i] == 'ё')&& i > 0) continue;

		cout << name[i];
		i++;
	}
	name[i] = '\0';
	cout << endl;
	string nam = name;
	return nam;
}
string check_line() //проверка ввода русских букв
{
	string nam;
	int i = 0;
	char name[22];
	while (true) {
		if (i > 20) {
			do {
				name[i] = _getch();
			} while (name[i] != 8 && name[i] != 13);
		}
		else name[i] = _getch();
		if (name[i] == 13 && i > 1) break;
		if (name[i] == 8 && i > 0) {
			cout << "\b \b";
			i--;
			continue;
		}
		if (name[i] == ' ' && name[i - 1] == ' ') continue;
		if (!((name[i] <= 'Я' && name[i] >= 'А') || (name[i] <= 'я' && name[i] >= 'а') || name[i] == 'Ё' || name [i] == 'ё')) continue;

		cout << name[i];
		i++;
	}
	name[i] = '\0';
	cout << endl;
	nam = name;
	return nam;
}
