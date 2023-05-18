#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
//设置访问x坐标
	void setm_x(int x);

	int getm_x();

//设置访问y坐标
	void setm_y(int y);

	int getm_y();

private:
	int m_x;
	int m_y;
};

