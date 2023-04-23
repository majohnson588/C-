#include <iostream>
#include <vector>
//标准库的东西都放到std
//using namespace std
//1、项目中，尽量不用using namespace std;
//2、日常练习用using namespace std;
//3、项目，指定名空间访问+展开常用

//namespace bit
//{
//	int rand = 0;
//}
//
//using namespace bit;
//
//int main()
//{
//	//不明确是函数rand还是域里面的整形rand
//	printf("%d\n", rand);
//	//printf("%d\n", bit::rand);
//
//	return 0;
//}

using std::cout;
using std::endl;
using std::cin;

//int main()
//{
//	std::vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	cout << "hello bit" << endl;
//	cout << "hello bit" << endl;
//	cout << "hello bit" << endl;
//	cout << "hello bit" << endl;
//
//	return 0;
//}

// IO 流
int main()
{
	//特点：自动识别类型
	int i;
	double d;
	// >> 流提取
	cin >> i >> d;

	// << 流插入
	cout << i << endl;
	//cout << i << "\n";
	cout << d << endl;

	cout << "hello world" << endl;

	return 0;
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 1;
	// int& b;  // 1、引用在定义时必须初始化

	int& b = a; // 2、一个变量可以有多个引用
	int& c = a;
	int& d = c;

	++a;

	return 0;
}

typedef struct SeqList
{
	// ...
}SL;

void SLPushBack(SL& s,int x)
{}

int main()
{
	int a = 0, b = 2;
	Swap(a, b);

	SL sl;
	SLPushBack(sl, 1);
	SLPushBack(sl, 2);
	SLPushBack(sl, 3);

	//SLTNode* list = NULL;
	//SListPushBack(&list, 1);
	//SListPushBack(&list, 2);
	//SListPushBack(&list, 3);

	SLTNode* list = NULL;
	SListPushBack(list, 1);
	SListPushBack(list, 2);
	SListPushBack(list, 3);

	return 0;
}

// 引用使用场景
// 1、作参数 -- a.输出型参数 b.大对象传参、提高效率
// 2、作返回值 -- a.输出型返回对象，调用者可以修改返回对象 b.减少拷贝，提高效率

//传值返回会产生拷贝
//传引用返回别名，栈空间销毁了会返回随机值
int& Count()
{
	static int n = 0;
	n++;

	// ...
	return n;
}

//int main()
//{
//	int& ret = Count();
//	printf("%d\n", ret);
//	cout << ret << endl;
//}

//顺序表调整某个数据
int& SLAt(SL& s, int pos);

int& SLAt(SL& s, int pos)
{
	assert(pos >= 0 && pos <= s.size);

	return s.a[pos];
}

int main()
{
	SL sl;
	SLInit(sl);
	SLPushBack(sl, 1);
	SLPushBack(sl, 2);
	SLPushBack(sl, 3);
	SLPushBack(sl, 4);

	//遍历
	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;

	//修改值
	SLAt(sl, 0)++;
	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;

	//修改值
	SLAt(sl, 0) = 10;

	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;

	return 0;
}

#include <iostream>
#include <map>
#include"t.cpp"
using namespace std;

//ADD两个变量的宏函数
#define ADD(a,b) a+b //容易出现优先级的问题
#define ADD(a,b) ((a)+(b))

int age;  //定义

//预处理--替换

//int main()
//{
//	ADD(1, 2);
//
//	if (ADD(1, 2)) //  if(((a) + (b)))
//	{
//	}
//
//	ADD(1, 2) * 3; // ((1)+(2))*3
//	int a = 1, b = 2;
//	ADD(a | b, a & b);
//
//	return 0;
//}

inline int Add(int a, int b)
{
	int c = a + b;
	printf("Add(%d,%d)->%d\n", a, b, c);
}

//展开太多编译器会选择不展开
inline void func(int a, int b)
{
	cout << a + b << endl;
	cout << a + b << endl;
	cout << a + b << endl;
	cout << a + b << endl;
	cout << a + b << endl;
	cout << a + b << endl;
	cout << a + b << endl;

	int c = a + b;
	c = a * b;
	c = a * b;
	c = a + b;
	c = a / b;
	c = a * b;
	c = a * b;
	c = a * b;
	c = a * b;
}




//int TestAuto()
//{
//	return 10;
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;  //自动推导类型
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}

int main()
{
	int a[] = { 1,2,3,4,5,6 };
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl; 

	// 范围for
	// 自动依次取a的数据，赋值给e
	// 自动迭代，自动判断结束
	for (auto& e : a)
	{
		e--;
	}

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;

	// 类型比较长的时候，auto会自动推导
	std::map<std::string, std::string> dict;
	//std::map<std::string, std::string>::iterator it = dict.begin();
	auto it = dict.begin();


	int x = 10;
	auto a = &x;  // int*
	auto* b = &x; //  int* 强调一定要传指针
	auto& c = x;  //  int 强调c是一个引用

	return 0;
}

void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;
}

int main()
{
	int* p = NULL;
	f(0);
	f(NULL);//NULL 宏在预编译时为整形0，不会被当成指针处理
	f(p);
	
	// C++11 nullptr 关键字 替代NULL
	f(nullptr);
	int* ptr = nullptr;

	return 0;
}

//  兼容c struct 语法
// C++同时将struct 升级成了类
// C++更喜欢使用class

// 成员变量 
// 成员函数

//权限只对外部有作用，对内部没有效果
class Stack
{
public:
	void Init()
	{
		a = 0;
		top = capacity = 0; 
	}

	void Push(int x)
	{
		// ...
	}

	void Pop()
	{
		// ...
	}

	int Top()
	{
		return a[top - 1];
	}
//private:
protected:
	int* a;
	int top;
	int capacity;
};

struct ListNode
{
	struct ListNode;
	int val;
};

void StackInit(struct Stack* ps);
void StackPush(struct Stack* ps, int  x);
void StackPop(struct Stack* ps);

int main()
{
	struct Stack st1;
	Stack st2;
	Stack st;

	st1.Init();
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);

	//st1.a = nullptr;

	Queue q;
	q.Init();
	q.Push(1);
	q.Push(2);
	q.Push(3);

	cout << st.Top() << endl;
	return 0;
}

//class的默认访问权限为private,struct为public(因为struct要兼容)

struct QueueNode
{
	QueueNode* next;
	int val;
};

//
// 类域
class Queue
{
public:
	//inline void Init();
	void Init();
	void Push(int x);
	void Pop();
private:
	QueueNode* head;
	QueueNode* tail;
};

class Person
{
public:
	void PrintPersonInfo();  //声明
private:
	char _name[20];     //声明？定义？
	char _gender[3];
	int _age;
};

// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo()  //定义
{
	cout << _name << " " << _gender << " " << _age << endl;
	cout << "age:" << &age << endl;

	cout << _name << " " << _gender << " " << _age << endl;
}
//生命周期
//存储位置有关系

int main()
{
	cout << "static size:" << &size << endl;

	//cout << sizeof(Person) << endl;

	Person p1;  // 类的实例化
	Person p2;
	Person p3;
	p1.PrintPersonInfo();

	return 0;
}

struct ListNode
{
	struct ListNode* next; //声明
	int val;
};

class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}

	void func()
	{
		cout << "void A::func()" << endl;
	}
private:
	char _a;
	int _i;
};

// 类中仅有成员函数
class A2 {
public:
	void f2(){}
};

// 类中什么都没有--空类
class A3
{};

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;

	A aa1;
	A aa2;
	A aa3;
	aa1._a = 1;
	aa2._a = 2;
	aa1.PrintA();
	aa2.PrintA();

	return 0;
}
