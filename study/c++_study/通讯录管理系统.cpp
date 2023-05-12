#include <iostream>
#include <string.h>
#define MAX 1000
using namespace std;

struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_address;
};


struct PhoneBooks
{
	struct Person personarry[MAX];  //这里如果把结构体Person放到后面，会报错，因为编译到这里还没找到结构体Person。
	int m_size;
	//int m_size =0;                如果在创建结构体时就给元素赋值 会报错

};

void AddPerson(PhoneBooks *pbs)
{
	if (pbs->m_size == MAX)
	{
		cout << "储存已达到上限" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入联系人姓名" << endl;
		cin >> name;
		for(int i=0; i<pbs->m_size;i++)
		{
			if (pbs->personarry[i].m_name == name)
			{
				cout << "联系人已存在" << endl;
				return ;                            //这里为啥ruturn 0；会报错
			}
		}
		//pbs->personarry[m_size].name = name;
		pbs->personarry[pbs->m_size].m_name = name;
		
		int sex;
		cout << "请输入联系人性别" << endl;
		cout << "输入数字1为男性 输入数字2为女性" << endl;
		cin >> sex;
		pbs->personarry[pbs->m_size].m_sex = sex;
		
		int age;
		cout << "请输入联系人的年龄" << endl;
		cin >> age;
		pbs->personarry[pbs->m_size].m_age = age;

		string phone;
		cout <<"请输入联系人电话" << endl;
		cin >> phone;
		pbs->personarry[pbs->m_size].m_phone = phone;

		string address;
		cout << "请输入联系人住址" << endl;
		cin >> address;
		pbs->personarry[pbs->m_size].m_address = address;

		pbs->m_size++;
	}
}

void ShowPerson(PhoneBooks* pbs)
{
	for(int i=0;i< (pbs->m_size);i++)
		{
			cout << "姓名:" << pbs->personarry[i].m_name << "\t"; 
			cout << "性别:" << (pbs->personarry[i].m_sex == 1 ? "男":"女") << "\t";
			cout << "年龄:" << pbs->personarry[i].m_age << "\t";
			cout << "电话:" << pbs->personarry[i].m_phone << "\t";
			cout << "住址:" << pbs->personarry[i].m_address << endl;
		}
}

void FindPerson(PhoneBooks *pbs)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	for(int i=0; i<pbs->m_size;i++)
	{
		if(name == pbs->personarry[i].m_name)
		{
			cout << "姓名:" << pbs->personarry[i].m_name << "\t"; 
			cout << "性别:" << (pbs->personarry[i].m_sex == 1 ? "男":"女") << "\t";
			cout << "年龄:" << pbs->personarry[i].m_age << "\t";
			cout << "电话:" << pbs->personarry[i].m_phone << "\t";
			cout << "住址:" << pbs->personarry[i].m_address << endl;

			return;	
		}	
	}
	cout << "查无此人" << endl;
}

void DelPerson(PhoneBooks *pbs)
{
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	for(int i=0; i<pbs->m_size;i++)
	{
		if(name == pbs->personarry[i].m_name)
		{
			cout << "联系人已找到" << endl;
			cout << "姓名:" << pbs->personarry[i].m_name << "\t"; 
			cout << "性别:" << (pbs->personarry[i].m_sex == 1 ? "男":"女") << "\t";
			cout << "年龄:" << pbs->personarry[i].m_age << "\t";
			cout << "电话:" << pbs->personarry[i].m_phone << "\t";
			cout << "住址:" << pbs->personarry[i].m_address << endl;
			
			cout << "是否确认删除联系人:确认（输入:1)/取消（输入其他任意数)" << endl;
			int key = 0;
			cin >> key;

			if(key==1)
			{	
				int j=0;
				for(int i=0; i<(pbs->m_size-1); i++)
				{
					if(j != i)
					{
						pbs->personarry[j].m_name = pbs->personarry[i].m_name;
						pbs->personarry[j].m_sex = pbs->personarry[i].m_sex;
						pbs->personarry[j].m_age = pbs->personarry[i].m_age;
						pbs->personarry[j].m_phone = pbs->personarry[i].m_phone;
						pbs->personarry[j].m_address = pbs->personarry[i].m_address;
						j++;
					}
				}
				cout << "已删除联系人" << endl;

				return;

			}

		}
	}
	cout << "查无此人" << endl;
}
void showMenu()
{
	cout <<"*****  1、添加联系人  *****"<< endl;
	cout <<"*****  2、显示联系人  *****"<< endl;
	cout <<"*****  3、删除联系人  *****"<< endl;
	cout <<"*****  4、查找联系人  *****"<< endl;
	cout <<"*****  5、修改联系人  *****"<< endl;
	cout <<"*****  6、清空联系人  *****"<< endl; 
	cout <<"*****  0、退出通讯录  *****"<< endl; 
}
int main() {

	PhoneBooks pbs;
	pbs.m_size = 0;

	while(true)
	{	
		showMenu();
		cout <<"请输入指令："<< endl;
		int key = 0;
		cin >> key;

		switch(key)
		{
			case 1: 
				AddPerson(&pbs);
				break;
			case 2:
				ShowPerson(&pbs);
				break;
			case 3:
				DelPerson(&pbs);
				break;
			case 4:
				FindPerson(&pbs);
				break;
			case 5:
				break;
			case 6:
				break;
			case 0:
				cout << "退出通讯录"<< endl;
				return 0;
				break;

		}
	}
	system("pause");
	system("cls");         // 》？？？？？？？？？？？

	return 0;
}