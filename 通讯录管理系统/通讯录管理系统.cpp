#include <iostream>
#include<string>
#define MAX 1000
using namespace std;
void showMenu()
{
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}
struct Person
{
	string m_Name;
	int m_Sex; //0,1
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks
{
	struct Person personArry[MAX];//��������
		int m_Size;//��Ա����
};
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		//name
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name = name;
		//sex
		int sex = 0;
		cout << "�����������Ա�" << endl;
		cout << "1-man 2-women" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 2 || sex == 1)
			{
				abs->personArry[abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "warring input again" << endl; 

		}
		//age
		int age = 0;
		cout << "��������������" << endl;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;

		//phone
		string phone = "";
		cout << "��������ĵ绰����" << endl;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;
		
		//add
		string add = "";
		cout << "��������ļ�ͥ��ַ" << endl;
		cin >> add;
		abs->personArry[abs->m_Size].m_Addr = add;

		//updata sys user num
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//��������

	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ����Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArry[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArry[i].m_Sex == 1 ? "men" : "women") << "\t";
			cout << "���䣺" << abs->personArry[i].m_Age << "\t";
			cout << "�绰��" << abs->personArry[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArry[i].m_Addr << endl;

		}
	}
}
//ɾ����ϵ�˹���
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArry[i].m_Name == name)
		{
			return i;
		}
		return -1;
	}
}
void deletePerson (Addressbooks * abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArry[i] = abs->personArry[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;

	}
	else
	{
		cout << "���޴��� " << endl;
	}
	system("pause");
	system("cls");

}
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) 
	{
		cout << "���ڵ�" << ret << "\t";
		cout << "������" << abs->personArry[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArry[ret].m_Sex == 1 ? "men" : "women") << "\t";
		cout << "���䣺" << abs->personArry[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArry[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArry[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs)
{
	cout << "���������޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//name
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArry[ret].m_Name = name;

		//sex
		cout << "�������Ա�" << endl;
		cout << "1-men" << endl;
		cout << "2-women" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArry[ret].m_Sex = sex;
				break;
			}
			cout << "warring again" << endl;
		}
		//age
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArry[ret].m_Age = age;
		//phonr
		cout << "input your phonr" << endl;
		string phone;
		cin >> phone;
		abs->personArry[ret].m_Phone = phone;

		//add
		cout << "input your add" << endl;
		string add;
		cin >> add;
		abs->personArry[ret].m_Addr = add;

		cout << "successful" << endl;


	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "successful" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//����ͨѶ¼
	Addressbooks abs;
	//ͨѶ¼��ʼ��
	abs.m_Size = 0;

	
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://add unser
			addPerson(&abs);
			break;
		case 2://show user
			showPerson(&abs);
			break;
		case 3://del user
			deletePerson(&abs);
			break;
		case 4://find user
			findPerson(&abs);
			break;
		case 5://fix user
			modifyPerson(&abs);
			break;
		case 6://dclear user
			cleanPerson(&abs);
			break;
		case 0://back system
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}