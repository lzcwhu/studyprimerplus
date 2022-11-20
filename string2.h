#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using std::ostream;
using std::istream;

class String{
    private:
        char *str;
        int len;
        static const int CINLIM = 80;
        static int num_strings;
    public:
        String(const char*);
        String();
        String(const String &c);
        ~String();
        int length() const {return len;}
        String & operator=(const String &c);
        String & operator=(const char*);
        char & operator[](int i);
        const char & operator[](int i) const;
        void stringlow(); 
        void stringup(); 
        int has(const char s);
        String operator+(const char *s);
        friend String operator+(const char *s, const String &st);
        friend bool operator<(const String &st, const String &st2);
        friend bool operator>(const String &st1, const String &st2);
        friend bool operator==(const String &st, const String &st2);
        friend ostream & operator<<(ostream &os, const String &st );
        friend istream & operator>>(istream &is, String &st );
        friend String  operator+(const String &st1, const String &st2);
        static int Howmany();
};

#endif
