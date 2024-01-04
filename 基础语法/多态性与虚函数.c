面向对象程序设计有4个主要特点：
抽象     封装        继承                                    多态性
 类      对象     提高了软件的可重用性。       提高了软件的可重用性可扩充性，使编程变得更加简捷、便利

 • 什么是多态性?
多态性是指，向不同的对象发送同一个消息，不同的对象在接受时会产生不同的行为。也
就是说，每个对象可以用自己的方式去响应共同的消息，“一个接口，多种方法”。

 C语言的方法：
三角形(边长为整数)    area1()
三角形(边长为实数)    area2()
正方形(边长为整数)    area3()
正方形(边长为实数)    area4()
圆形(半径为整数)      area5()
圆形(半径为实数)      area6() 

程序员:对象不同则调用语句不同。

 C++的函数重载：
 三角形(边长为整数)
三角形(边长为实数)    area_t()
正方形(边长为整数)
正方形(边长为实数)    area_s()
圆形(半径为整数)
圆形(半径为实数)      area_c()

程序员:调用语句减少，但依然是不同对象调用语句不同
C++的多态性：
三角形(边长为整数)     area(){}
三角形(边长为实数)     area(){}
正方形(边长为整数)     area(){}
正方形(边长为实数)     area(){}
圆形(半径为整数)       area(){}
圆形(半径为实数)       area(){}

p->area()
程序员：不论对象如何千变万化，调用语句都一样。

从系统实现的角度看，多态性分为：静态多态性和动态多态性。
 
静态多态性    
 • 程序编译时系统就能知道调用的是哪个函数。
 • 通过函数重载实现。
动态多态性
• 编译时不确定调用哪个函数，运行时才动态地确定对象及其函数。
• 通过虚函数实现。

 静态多态性
 #include <iostream>
using namespace std;
int max(int a, int b, int c)
{ if (b>a) a=b;
  if (c>a) a=c;
  return a;
}
float max(float a, float b, float c)
{ if (b>a) a=b;
  if (c>a) a=c;
  return a;
}
long max(long a, long b, long c)
{ if (b>a) a=b;
  if (c>a) a=c;
  return a;
}
int main ( )
{ 
  int a, b, c;
  float d, e, f;
  long g, h, i;
  cin >> a >> b >> c;
  cin >> d >> e >> f;
  cin >> g >> h >> i;
  int m;
  m=max(a,b,c);       //运行之前就知道要调用哪个函数。
  cout << “max_i =” <<m<<endl;
  float n;
  n=max(d,e,f);
  cout << “max_f =” <<n<<endl;
  long int p;
  p=max(g,h,i);
  cout << “max_l =” <<p<<endl;
  return 0;
}

动态多态性
程序运行中，才知道p指向的对象，从而确定要调用的是哪个area()。

area()        area()           area()
t.area()      s.area()       c.area()
并没有达到要求：没有实现一个相同的调用语句，可以调用不同对象的area()。

1.使这三个类来自于同一个基类
2.在基类中也定义同名函数area()。

利用虚函数实现动态多态性
基类与派生类中有同名函数。

 基类Student    派生类Graduate
class Student
{ public:
  Student(int, string, float);
  void display();
  protected:
  int num;
  string name;
  float score;
};

class Graduate:public Student
{ public:
  Graduate(int, string, float, float);
  void display();
  private:
  float wage;
};

int main()
{ Student stud1(1001,“Li”  , 87.5);
  Graduate grad1(2001,  “Wang”  , 98.5, 1200);
  Student *pt=&stud1;
  pt->display();  //pt调用的是基类对象的display
  pt = &grad1;
  pt->display();  //希望pt调用的是派生类对象的display，但实际上并没有输出派生类新增成员的值
  return 0;
};

int main()
{ Student stud1(1001, “Li”, 87.5);
  Graduate grad1(2001, “Wang”, 98.5, 1200);
  Student *pt=&stud1;
  pt->display();
  Graduate *pt1 = &grad1;
  pt1->display();
  return 0;
};


p->area() 虚函数

 
class Student
{ public:
  Student(int, string, float);
  virtual void display();
  protected:
  int num;
  string name;
  float score;
};
class Graduate:public Student
{ public:
  Graduate(int, string, float, float);
  void display();
  private:
  float wage;
};

int main()
{ Student stud1(11,“Li”, 87.5);
  Graduate grad1(21,“Liu”, 98.5, 12);
  Student *pt=&stud1;
  pt->display();
  pt = &grad1;
  pt->display();
  return 0;
};

• 在基类中用virtual声明成员函数为虚函数。在类外定义时，不必再加virtual。
• 在派生类中重新定义虚函数，函数名、函数类型、函数参数个数及类型都必须与基类的虚函数相同。
• 只能用virtual声明类的成员函数，作为虚函数，不能将类外的普通函数声明为虚函数。
• 定义一个指向基类对象的指针。
• 通过虚函数与指向基类对象的指针变量的配合使用，就能实现动态的多态性。

1. 声明基类中的area()为虚函数
2. 定义基类类型的指针p

 p->area()
 virtual area()

使用虚函数实现动态多态性的优点
int main()
{ Shape *pt;
  Circle circle;
  pt=&circle;                        //• 只改对象部分的代码，其他调用部分不用改。
  pt->shapeName();
  pt->area();
  pt->volume();
  return 0;
}

• 对象千变万化，调用方式不变。
• 不必考虑对象的特殊性等细节，也可以完成代码的写作。
• 提高代码的可重用性。

纯虚函数与抽象类
把它定义为纯虚函数：virtual void area( ) = 0;
在基类中预留函数名，具体功能留给派生类根据需要去定义。

纯虚函数只有函数名，没有函数体，不具备函数功能，不能被调用。
定义纯虚函数的格式：
virtual 函数类型 函数名(参数表)=0；
virtual void area( ) = 0;

抽象类
• 定义对象
• 作为基类去建立派生类
这种不用来定义对象，而只作为一种基本类型用作继承的类，成为抽象类。

凡是包含纯虚函数的类都是抽象类。因为纯虚函数不能被调用，包含纯虚函数的类是无法建立对象的。
抽象类的作用是为一个类族提供一个公共接口。

• 一个类层次结构中当然也可以不包含任何抽象类，每一层都是实际可用的。
• 也可以顶层为抽象类。
• 也可以顶部好几层都为抽象类。

          A                            抽象类：有多个纯虚函数。
      A1    A2                         如果在派生类中对基类的所有纯虚函数都进行了定义，那么这个派生类就不是抽象类，而变为具体的类。
A11   A12    A21   A22

抽象类虽然不能定义对象，但是可以定义指向抽象类数据的指针变量，当派生类成为具体的类时，可以用这种指针指向派生类对象，
然后通过该指针调用虚函数，实现多态性的操作。
