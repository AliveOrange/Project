#include <iostream> 
#include <string>
#include "point.h"
#include "circle.h"
using namespace std;

//判断点与圆的位置关系
void PositionRelation(Circle &c, Point &p )
{	

	int distance = (c.getm_center().getm_x() - p.getm_x())*(c.getm_center().getm_x() - p.getm_x())
	 + (c.getm_center().getm_y() - p.getm_y())*(c.getm_center().getm_y() - p.getm_y());
	cout<<"2点到圆心的距离的平方:"<<distance<<endl;
	int RR = c.getm_r()*c.getm_r();
	cout<<"半径的平方:"<<RR<<endl;     
	//千万要注意在c++中幂函数不能写成x^2这种，这里卡了一个小时。可以用math.h的库函数pow ；格式：int pow（int a，int b）

	if (distance == RR)
		{
			cout << "点在圆上" << endl;
		}
	if (distance > RR)
		{
			cout << "点在圆外" << endl;
		}
	if (distance < RR)
		{
			cout << "点在圆内" << endl;
		}
}
int main()
{	
	Point p1;
	p1.setm_x(10);
	p1.setm_y(10);
	Point p2;
	p2.setm_x(10);
	p2.setm_y(0);
	Circle c1;
	c1.setm_center(p2);
	c1.setm_r(10);

	PositionRelation(c1,p1);

	return 0;


}