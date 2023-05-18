#pragma once
#include <iostream>
#include "point.h"
using namespace std;




//圆的类
class Circle
{
public:
//设置访问圆的半径
	void setm_r(int r);

	int getm_r();

//设置访问圆的圆点
	void setm_center(Point center);

	Point getm_center();

private:
	int m_r;
	Point m_center;
};