#include <iostream> 
#include <string>
using namespace std;

//点的类
class Point
{
public:
//设置访问x坐标
	void setm_x(int x)
	{
		m_x = x;
	}
	int getm_x()
	{
		return m_x;
	}
//设置访问y坐标
	void setm_y(int y)
	{
		m_y = y;
	}
	int getm_y()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};

//圆的类
class Circle
{
public:
//设置访问圆的半径
	void setm_r(int r)
	{
		m_r = r;
	}
	int getm_r()
	{
		return m_r;
	}
//设置访问圆的圆点
	void setm_center(Point center)
	{
		m_center = center;
	}
	Point getm_center()
	{
		return m_center;
	}
private:
	int m_r;
	Point m_center;
};

//判断点与圆的位置关系
void PositionRelation(Circle c, Point p )
{
	int distance = ((c.getm_center().getm_x() - p.getm_x())^2 + (c.getm_center().getm_y() - p.getm_y())^2);
	int RR = (c.getm_r())^2;
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
