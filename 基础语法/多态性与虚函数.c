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
  m=max(a,b,c);
  cout << “max_i =” <<m<<endl;
  float n;
  n=max(d,e,f);
  cout << “max_f =” <<n<<endl;
  long int p;
  p=max(g,h,i);
  cout << “max_l =” <<p<<endl;
  return 0;
}










