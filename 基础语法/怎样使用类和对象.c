利用构造函数对类对象进行初始化

对象的初始化
程序中常常需要对变量初始化：int a =10;
不能在类声明中对数据成员进行初始化。因为类是一种抽象类型，不是一个实体，不占内存空间，无处容纳数据。
定义一个对象也需要对对象进行初始化。

如果一个类的所有数据成员都是公用的，可以在定义对象时对数据成员进行初始化。
• C++提供了构造函数来处理对象的初始化。
• 构造函数是一种特殊的成员函数，与其他成员函数不同，不需要用户来调用它，而是在建立对象时自动执行。
• 构造函数的名字必须与类名同名。
• 构造函数不具有任何类型，不返回任何值。

建立类对象时会自动调用构造函数。用户不必操心初始化的事。
• 不是声明类时赋值，而是调用构造函数时才执行这些赋值语句。
• 构造函数不能被用户调用。t1.Time(); //错误
• 可以用一个类对象初始化另一个类对象。
#include <iostream>
using namespace std;
class Time
{ public:
Time( );
void show_time();
private:
int hour;
int minute;
int sec;
};

Time :: Time( )
{hour=0;
minute=0;
sec=0;
}

int main()
{ Time t1;
Time t2=t1;
t2.show_time();
return 0;
}

• 在函数体中赋初值: 每个对象的数据成员初值相同。
• 带参数的构造函数: 可以给不同对象不同的初值。
class Box
{ public:
Box(int, int, int);
int volume();
private:
int length;
int width;
int height;
};
Box :: Box( int h, int w, int len)
{height=h;
width=w;
length=len;
}
构造函数是不能被调用的，如何把实参传递给构造函数？
在定义对象时给出实参：
类名 对象名( 实参1，实参2， …)
int main()
{
Box box1(12, 25, 30);
Box box2(15, 30, 21); …
}
先把实参传递给对象，对象调用构造函数时再传递实参给构造函数。
用参数初始化表对数据成员初始化
Box :: Box( int h, int w, int len)
{height=h;
width=w;
length=len;
}
Time:: Time(int h, int m, int s): hour(h), minute(m), sec(s){ }

构造函数的重载
一个类中可以定义多个构造函数，为对象提供不同的初始化方法，供用户选择。
#include <iostream>
using namespace std;
class Rectangle
{ public:
Rectangle ( );
Rectangle (int len, int wid);
int area()
{return (length*width);}
private:
int length, width;
};
Rectangle::Rectangle( )
{length =10; width =10;}
Rectangle::Rectangle(int len, int wid)
{length =len; width =wid;}
int main( )
{Rectangle rec1;
cout<<“The area of Rectangle 1 is ”;
cout<<rec1.area()<<endl;
Rectangle rec2(15,20);
cout<<“The area of Rectangle 2 is ”;
cout<<rec2.area()<<endl;
return 0;
}
The area of Rectangle 1 is 100
The area of Rectangle 1 is 300

析构函数: 与构造函数作用相反。对象生命周期结束时，会自动执行析构函数。
析构函数: 不返回任何值，没有函数类型，也没有函数参数。一个类可以有多个构造函数，但是只能有一个析构函数。

#include <string>
#include <iostream>
using namespace std;
class Student
{ public:
Student (int n, string nam, char s)
{ num =n;
  name = nam;
  sex = s;
cout<< “constructor called.”<<endl;
}
~Student()
{cout<< “ Destructor called.”<<endl;}
void display()
{cout<<“num:”<<num<<endl;
cout<<“name:”<<name<<endl;
cout<<“sex:”<<sex<<endl;}
private:
int num;
char name[10];
char sex;
};
int main( )
{ Student stud1(10010,
“Wang_Li”
,
‘f’);
stud1.display();
Student stud2(10011,
“Zhang_fan”
,
‘m’);
stud2.display();
return 0;
}
先构造的后析构
后构造的先析构

对象数组
计算和输出3个立方体的体积。
#include <iostream>
using namespace std;
class Box
{ public:
Box (int h =10, int w=12, int len =15): height(h), width(w), length(len) {}
int volume();
private:
int height;
int width;
int length;
};
int Box::volume()
{ return (height*width*length);
}
int main( )
{ Box a[3] = {
Box(10, 12, 15),
Box(15, 18, 20),
Box(16, 20, 26)
};
cout <<“volume of a[0] is ” << a[0].volume()<<endl;
cout <<“volume of a[1] is ” << a[1].volume()<<endl;
cout <<“volume of a[2] is ” << a[2].volume()<<endl;
return 0;
}

指向对象的指针
class Time
{ public:
int hour;
int minute;
int sec;
void get_time();
};
void Time::get_time()
{cout<< hour <<“:” << minute
<<“:”<<sec<<endl;}
Time *pt;
Time t1;
pt = &t1;

t1.hour
t1.get_time()
pt ->hour
pt->get_time()
(*pt).hour
(*pt).get_time()

用对象指针方法输出时、分、秒。
#include <iostream>
using namespace std;
class Time
{ public:
Time(int, int, int);
int hour;
int minute;
int sec;
void get_time();
};
Time::Time(int h, int m, int s)
{ hour=h;
minute=m;
sec=s;
}
void Time::get_time( )
{ cout << hour << “:” << minute << “:” << sec << endl;}
int main()
{ Time t1(10, 13, 56);
int *p1=&t1.hour;
cout << *p1<< endl;
t1.get_time( );
Time *p2 =&t1;
p2->get_time( );
void(Time::*p3)();
p3=&Time::get_time;
(t1.*p3)( );
return 0;
};

对象指针
• 指向对象                         Time *p2 =&t1;
• 指向对象的数据成员                int *p1=&t1.hour;
• 指向对象的成员函数                 void(Time::*p3)();  p3=&Time::get_time;
• 指向当前对象的this指针

对象的复制
• 调用三种类型的构造函数：
Box box2;                  调用无参数的构造函数Box( )
Box box2(10,15,20);        调用有参数的构造函数Box(int, int, int)
Box box2(box1);            调用复制构造函数Box( const Box&)

静态数据成员的存储空间与对象的空间是互相独立的。
静态数据成员
class Box
{ public:
int volume();
private:
static int length;
int width;
int height;
};
int Box:: length =10;
• 只能在类体外初始化此时不加static
• 不属于某一对象，用类名访问静态数据成员

静态数据成员可以通过对象名引用，也可以通过类名引用。
#include <iostream>
using namespace std;
class Box
{ public:
Box(int, int);
int volume();
static int height;
int length;
int width;
};
Box::Box(int w, int len)
{width =w; length=len;}
int Box::volume( )
{return (width*length*height);}
int Box::height = 10;
int main( )
{Box a(15,20), b(20,30);
cout <<a.height<<endl;
cout <<b.height<<endl;
cout <<Box:: height<<endl; …
}

静态成员函数
class Box
{ public:
static int volume( );
private:
static int length;
int width;
int height;
};
int main( )
{Box a(15,20); …
cout <<Box:: volume( )<<endl;
cout <<a.volume( )<<endl; …
}

静态成员函数与普通的成员函数有什么区别?
普通成员函数自带this指针,静态成员函数没有this指针
只用静态成员函数引用静态数据成员，而不引用非静态数据成员。

统计学生平均成绩，使用静态成员函数。
class Student
{ public:
void total( );
static float average( );
private:
static int count;
static float sum;
int num;
int age;
float score;
};
void Student::total( )
{sum+=score;
count++;
}
只访问静态数据成员
float Student::average( )
{return (sum/count);
}
静态成员函数是为了处理本类所有对象的共性问题的。
使用静态成员函数的好处：它跟类的实例无关，只跟类有关，不需要this指针。因此，调用方便，不需要生成对象就能调用。
例如：数学函数(sin, cos, tan...)，这些函数本就没必要属于任何一个对象，所以从类上调用感觉更好。
为了一个无状态存储可言的数学函数，还要引入一次对象的构造与一次对象的析构...对纯算法来说是不合适的。

将普通函数声明为友元函数
友元成员函数
#include <iostream>
using namespace std;
class Date; //提前引用声明
class Time
{ public:
Time(int, int, int);
void display(Date &);
private:
int hour;
int minute;
int sec;
};
class Date
{ public:
Date (int, int, int);
friend void Time::display(Date &);
private:
int month;
int day;
int year;
};
Time::Time(int h, int m, int s)
{ hour =h;
minute = m;
sec = s;
}
void Time::display(Date& d)
{cout<<d.month<<“/”<<d.day<<“/”<<d.year<<endl;
cout<<hour<<“:”<<minute<<“:”<<sec<<endl;
}
Date::Date(int m, int d, int y)
{ month =m;
day = d;
year = y;
}
int main()
{ Time t1(10, 13, 56);
Date d1(12, 25, 2004);
t1.display(d1);
return 0;
};

12/25/2004
10:13:56

• 友元的关系是单向的：类B是类A的友元，不等于类A是类B的友元。
• 友元的关系不能传递：类B是类A的友元，类C是类B的友元，不等于类C是类A的友元。
