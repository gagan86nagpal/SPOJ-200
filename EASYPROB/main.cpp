#include <iostream>

using namespace std;

int main()
{
    string _1 = "2(0)";
    string _2 = "2";
    string _4 = "2(2)";
    string _8 = "2(2+2(0))";
    string _16= "2(2(2))";
    string _32 = "2(2(2)+2(0))";
    string _64 = "2(2(2)+2)";
    string _128 ="2(2(2)+2+2(0))";
    string _256="2(2(2+2(0)))";
    string _1024 = "2(2(2+2(0))+2)";
    string _16384="2(2(2+2(0))+2(2)+2)";
    cout<<"137="<<_128+"+"+_8+"+"+_1<<"\n";
    cout<<"1315="<<_1024+"+"+_256+"+"+_32+"+"+_2+"+"+_1<<"\n";
    cout<<"73="<<_64+"+"+_8+"+"+_1<<"\n";
    cout<<"136="<<_128+"+"+_8<<"\n";
    cout<<"255="<<_128+"+"+_64+"+"+_32+"+"+_16+"+"+_8+"+"+_4+"+"+_2+"+"+_1<<"\n";
    cout<<"1384="<<_1024+"+"+_256+"+"+_64+"+"+_32+"+"+_8<<"\n";
    cout<<"16385="<<_16384+"+"+_1<<"\n";
    return 0;
}