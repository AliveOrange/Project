#include <iostream> 
#include <string>
using namespace std;

//对象的初始化和清理
//1、构造函数 进行初始化操作
class Person
{
public:
	Person()
	{
		cout <<"这是一个构造函数"<< endl;
	}
	~Person()
	{
		cout << "这是一个析构函数的调用" << endl;
	}
//构造函数和析构函数都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
};

void test01()
{
	Person p;         //在栈上的数据，test01执行完毕后，释放这个对象
}

int main()
{	
	Person p1;
	// //test01();
	pause();
	return 0;
}
