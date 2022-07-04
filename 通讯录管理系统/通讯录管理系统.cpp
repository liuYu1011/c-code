#include <iostream>
#include<string>
#define MAX 1000
using namespace std;
void showMenu()
{
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
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
	struct Person personArry[MAX];//保存数组
		int m_Size;//人员个数
};
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		//name
		string name;
		cout << "请输入名字" << endl;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name = name;
		//sex
		int sex = 0;
		cout << "请输入您的性别" << endl;
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
		cout << "请输入您的年龄" << endl;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;

		//phone
		string phone = "";
		cout << "请输入你的电话号码" << endl;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;
		
		//add
		string add = "";
		cout << "请输入你的家庭地址" << endl;
		cin >> add;
		abs->personArry[abs->m_Size].m_Addr = add;

		//updata sys user num
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏操作

	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前数据为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArry[i].m_Name << "\t";
			cout << "性别：" << (abs->personArry[i].m_Sex == 1 ? "men" : "women") << "\t";
			cout << "年龄：" << abs->personArry[i].m_Age << "\t";
			cout << "电话：" << abs->personArry[i].m_Phone << "\t";
			cout << "住址：" << abs->personArry[i].m_Addr << endl;

		}
	}
}
//删除联系人功能
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
	cout << "请输您要查找的联系人" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArry[i] = abs->personArry[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;

	}
	else
	{
		cout << "查无此人 " << endl;
	}
	system("pause");
	system("cls");

}
void findPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) 
	{
		cout << "他在第" << ret << "\t";
		cout << "姓名：" << abs->personArry[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArry[ret].m_Sex == 1 ? "men" : "women") << "\t";
		cout << "年龄：" << abs->personArry[ret].m_Age << "\t";
		cout << "电话：" << abs->personArry[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArry[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入你修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//name
		string name;
		cout << "请输入名字" << endl;
		cin >> name;
		abs->personArry[ret].m_Name = name;

		//sex
		cout << "请输入性别" << endl;
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
		cout << "请输入年龄" << endl;
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
		cout << "查无此人" << endl;
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
	//创建通讯录
	Addressbooks abs;
	//通讯录初始化
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
			cout << "欢迎下次使用" << endl;
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