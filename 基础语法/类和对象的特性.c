// C语言分配内存
int *p = (int*)malloc (sizeof(int))
// C++分配内存
int *p = new int;

new int(100).
//开辟一个存放整数的空间，初值为100
new char [10];
//开辟一个存放字符数组的空间
new int[5]I4]:
//开辟一个存放二维整型数组的空间
float *p=new float(3.14159),
//开辟一个存放实数的空间,并指定初值为3.14159

类代表了一批对象的共性和特征。类是对象的抽象,而对象是类的具体实例。

类由结构体发展而来,把数据和函数封装起来

在类体中，只对成员函数进行声明，而在类的外面进行函数定义。类的函数必须先在类中声明，然后再在类外定义。其中::是作用域运算符或作用域限定符，指明函数是哪个类的。

找出一个整型数组中的元素的最大值。(用类和对象来处理)

第一步：分析类由哪些数据和函数组成。数据是什么？函数是什么？
第二步：声明类，将与之有关的数据和函数封装进来。
第三步：定义类的成员函数。
第四步：在主函数中完成对类的对象的调用。

#include <iostream>
using namespace std;
class Array_max
{ public:
  void set_value();
  void max_value();
  void show_value();
  private:
  int array[10];
  int max;
};

void Array_max::set_value()
{ 
  int i;
  for(i=0; i<10;i++)
  cin>>array[i];
}

void Array_max::max_value()
{ 
  int i;
  max=array[0];
  for(i=0; i<10;i++)
  if(array[i]>max)max=array[i];
}
void Array_max::show_value()
{ 
  cout<<“max = ”<<max;}
  int main( )
  {Array_max arrmax; //定义对象
  arrmax.set_value(); //调用对象的公用成员函数
  arrmax.max_value(); //调用对象的公用成员函数
  arrmax.show_value(); //调用对象的公用成员函数
  return 0;
}
