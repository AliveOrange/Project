#include "circle.h"


//设置访问圆的半径
void Circle::setm_r(int r)
{
    m_r = r;
}
int Circle::getm_r()
{
    return m_r;
}
//设置访问圆的圆点
void Circle::setm_center(Point center)
{
    m_center = center;
}
Point Circle::getm_center()
{
    return m_center;
}

