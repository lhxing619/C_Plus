面向对象程序设计有4个主要特点：
 抽象、封装、继承和多态性
类和对象 面向对象技术强调软件的可重用性，主要通过继承来实现。

 C++的继承就是在一个已经存在的类的基础上建立一个新的类。
派生类是基类的具体化，而基类则是派生类的抽象。

基类
 class Student
{ public:
void display( )
{cout <<“num:”<<num<<endl;
cout <<“name:”<<name<<endl;
cout <<“sex:”<<sex<<endl;}
private:
int num;
string name;
char sex;
};

派生类
class Student1：public Student
{ public:
void display_1( )
{cout <<“age:”<<age<<endl;
cout <<“address:”<<addr<<endl;}
private:
int age;
string addr;
};

public:公用的
private: 私有的
protected: 受保护的

class Student
{ public:               //类外可以访问
void display();    
protected:              //类外不能访问，但派生类成员函数可以引用
int age;
private:                //类外不能访问
int num;
string name;
char sex;
};

当派生类的继承方式为public（公用）属性时，在派生类中，基类的公用成员和保护成员在派生类中的访问
属性没有变化，即分别作为派生类的公用成员和保护成员，派生类的成员可以直接访问它们。但是，派生
类的成员无法直接访问基类的私有成员。保护私有成员是一条重要的原则。

在派生类中，基类的公用成员和保护成员作为派生类的私有成员，派生类的成员可以直接访问它
们，而派生类的成员无法直接访问基类的私有成员。
私有继承之后，全部基类成员在派生类中都成为了私有成员或不可访问的成员，无法进一步派生。

• 在派生类的构造函数里调用基类的构造函数。
• 调用基类的构造函数，基类里的参数是实参而非形参。
