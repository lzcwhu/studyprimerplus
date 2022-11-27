#include "dma.h"
#include <iostream>
#include <cstring>

DMA::DMA(const char *cn) //定义基类DMA的默认构造函数;
{
    classname = new char[std::strlen(cn) + 1];
    std::strcpy(classname, cn);
}

DMA::DMA(const DMA &rs) //定义基类DMA的复制构造函数;
{
    classname = new char[std::strlen(rs.classname) + 1];
    std::strcpy(classname, rs.classname);
}

DMA &DMA::operator=(const DMA &rs) //为基类DMA重载赋值运算符;
{
    if (this == &rs)
    {
        return *this;
    }
    delete[] classname; //先释放后分配;
    classname = new char[std::strlen(rs.classname) + 1];
    std::strcpy(classname, rs.classname);
    return *this;
}

DMA::~DMA() //定义基类DMA的析构函数;
{
    delete[] classname;
}

baseDMA::baseDMA(const char *l, int r, const char *cn):DMA(cn){
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const char *l, int r, const DMA &rs):DMA(rs){
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs) : DMA(rs) //定义派生类baseDMA的复制构造函数;
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA(){
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA &rs){
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

void baseDMA::View() const //为派生类baseDMA定义基类虚函数;
{
    std::cout << "Classname: " << show_classname() << std::endl; //调用基类protected中的show_classname方法显示基类数据成员;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
    return;
}
//lackDMA method
lacksDMA::lacksDMA(const char *c, const char *cn):DMA(cn){
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA &rs):DMA(rs){
    std::strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::~lacksDMA()
{
}

lacksDMA &lacksDMA::operator=(const lacksDMA &rs) //为派生类lacksDMA重载赋值运算符;
{
    if (this == &rs)
    {
        return *this;
    }
    DMA::operator=(rs); //调用基类DMA的赋值运算符方法初始化派生类lacksDMA的基类数据成员;
    std::strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
    return *this;
}

void lacksDMA::View() const //为派生类lacksDMA定义基类虚函数;
{
    std::cout << "Classname: " << show_classname() << std::endl; //调用基类protected中的show_classname方法显示基类数据成员;
    std::cout << "Color: " << color << std::endl;
    return;
}
//hasDMA method
hasDMA::hasDMA(const char *s, const char *cn):DMA(cn){
    style = new char[std::strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const DMA & rs):DMA(rs){
    style = new char[std::strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs):DMA(hs){
    style = new char[std::strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA(){
    delete []style;
}

hasDMA & hasDMA::operator=(const hasDMA &hs){
    if (this == &hs)
        return *this;
    DMA::operator=(hs);
    style = new char[std::strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}

void hasDMA::View() const //为派生类hasDMA定义基类虚函数;
{
    std::cout << "Classname: " << show_classname() << std::endl; //调用基类protected中的show_classname方法显示基类数据成员;
    std::cout << "Style: " << style << std::endl;
    return;
}