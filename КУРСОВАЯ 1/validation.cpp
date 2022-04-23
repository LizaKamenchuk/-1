#include<string>
#include<iostream>
#include<conio.h>

using namespace std;

int check_Input()//�������� ����� ���� int (���������� ����� ���� int)
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
			cout << "�������� ������ ������ �������� ������ �� ����, ���������: " << endl;
		}
	}
	return num;
}
int check_day()//�������� ����� ������ 
{
	int a;
	cout << " �����: ";
	while (true) {
		a = check_Input();
		if (!(a < 32 && a>0)) cout << "�� �������� � ������,���������� ��� ��� (��� ����� ���� � 1 �� 31)" << endl;
		else
		{
			return a;
		}
	}
}
int check_month()//�������� ������ 
{
	int a;
	cout << " �����: ";
	while (true) {
		a = check_Input();
		if (!(a < 13 && a>0)) cout << "�� �������� � ������� ,���������� ��� ��� (�� ����� ���� �� 1 �� 12)" << endl;
		else
		{
			return a;
		}
	}
}
int check_year()//�������� ����
{
	int a;
	cout << " ���: ";
	while (true) {
		a = check_Input();
		if (!(a<= 2022 && a > 1922)) cout << "�� �������� � ����� ,���������� ��� ��� (�� ����� ���� � 1922 �� 2022)" << endl;
		else
		{
			return a;
		}
	}
}
string imagen_Login() //�-��� ��� �������� ������ (���������� ����� ���� string)
{
	string log;
	int i = 0;
	char*login= new char [20];//������������ ������ �������� ��� �������� ������ �� ����� ��������
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
		//��������, ����������� ���� ��������� ����,���� � ".", "_", "@", "-"
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
	char*login = new char[20];//������������ ������ �������� ��� �������� ������ �� ����� ��������
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
		//��������, ����������� ���� ��������� ����,���� � ".", "_", "@", "-"
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
string check_Password() //�-��� ��� ����� ������ (���������� ������ ���� string)
{
	char pas[20];//����������� ������ �������� ��� �������� ������ �� ����� �����
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
string imagen_Password()// �-��� ��� �������� ������ (���������� ������ ���� string)
{

	char* pass = new char(20);//����������� ������ ������� ��� �������� ������ �� ��������
	int i = 0, number = 0, letter = 0, caplet = 0;// �������� �������, ����,��������� � ��������� ���� ��������������
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
		cout << "���������� ������,���������� �� ����� 8-�� ��������" << endl;

		for (int j = 0; j < i; j++) { cout << "*"; }//����� "*" ��� ����� ������
		for (int j = 0; j < i; j++) // ������� ����, ��������� � ��������� ����
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
		// ����� ��������� � ������������ � ��� �������� ������� (�� ���������� ����,��������� � ��������� ����)
		if (i < 7) cout << "��� ������ ������������,�� ������ ��������� ������ �������� ";
		else {
			if (number != 0 && (caplet == 0 && letter == 0)) cout << "��� ������ ������������, ����������� ����� �������� � ������� ��������";
			else
				if (letter != 0 && (number == 0 && caplet == 0)) cout << "��� ������ ������������, ����������� ����� � ��������� �����";
				else
					if (caplet != 0 && (number == 0 && letter == 0)) cout << "��� ������ ������������, ����������� ����� � �������� �����";
					else
						if ((number != 0 && letter != 0) && caplet == 0) cout << "��� ������ ������������, ����������� ��������� ����� ";
						else
							if ((number != 0 && caplet != 0) && letter == 0) cout << "��� ������ ������������, ����������� �������� ����� ";
							else
								if ((letter != 0 && caplet != 0) && number == 0) cout << "��� ������ ������������, ����������� �����";
								else
									cout << "�� ��������� �������� ������!";

		}
		i++;
	}
	pass[i] = '\0';
	cout << endl;
	password = pass;
	return password;
}
string check_String()// �������� ��� ����� ��� (���������� string)
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
		if (!(name[0] <= '�' && name[0] >= '�') || name[i] == '�' ) continue;
		if (!((name[i] <= '�' && name[i] >= '�') || name[i] == '�')&& i > 0) continue;

		cout << name[i];
		i++;
	}
	name[i] = '\0';
	cout << endl;
	string nam = name;
	return nam;
}
string check_line() //�������� ����� ������� ����
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
		if (!((name[i] <= '�' && name[i] >= '�') || (name[i] <= '�' && name[i] >= '�') || name[i] == '�' || name [i] == '�')) continue;

		cout << name[i];
		i++;
	}
	name[i] = '\0';
	cout << endl;
	nam = name;
	return nam;
}
