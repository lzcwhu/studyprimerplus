#ifndef DMA_H_
#define DMA_H_
#include <iostream>
class DMA
{
private:
    char *classname; //基类成员设为一个char指针方便分配内存空间保存派生类的类名;

protected:
    const char *show_classname() const { return classname; } //抽象基类DMA的View方法不进行定义因此使用protected让派生类可以访问基类数据;

public:
    DMA(const char *cn = "null");  //声明基类DMA的默认构造函数;
    DMA(const DMA &rs);            //声明基类DMA的复制构造函数;
    DMA &operator=(const DMA &rs); //声明为基类DMA重载赋值运算符;
    virtual ~DMA();                //声明基类DMA的虚析构函数;
    virtual void View() const = 0; //声明基类DMA的纯虚函数;
};
class baseDMA:public DMA{
    private:
        char * label;
        int rating;
    public:
        baseDMA(const char * l = "null", int r = 0, const char *cn = "null");
        baseDMA(const char *l, int r, const DMA & rs);
        baseDMA(const baseDMA &rs);
        ~baseDMA();
        baseDMA & operator=(const baseDMA &rs);
        virtual void View() const;
};

class lacksDMA:public DMA{
    private:
        enum {COL_LEN = 40};
        char color[COL_LEN];
    public:
        lacksDMA(const char *c = "blank", const char *cn = "null");
        lacksDMA(const char *c, const DMA & rs);
        lacksDMA(const lacksDMA &rs);
        lacksDMA &operator=(const lacksDMA &rs);
        virtual void View() const;
        ~lacksDMA();

};

class hasDMA:public DMA{
    private:
        char * style;
    public:
        hasDMA(const char *s = "none", const char *l = "null");
        hasDMA(const char *s, const DMA &rs);
        hasDMA(const hasDMA &rs);
        ~hasDMA();
        hasDMA & operator=(const hasDMA & rs);
        virtual void View() const;
};




#endif
