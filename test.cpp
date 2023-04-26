//基本兼容C语言
#include <iostream>
#include <stdio.h>

//int main()
//{
//	cout << "hello world" << endl;
//}

//命名空间

//命名冲突 eg.rand。与库中关键词冲突

//命名空间域
//可以嵌套
namespace sql
{
	int a = 0;

	namespace ma
	{
		int rand = 0;
		void func()
		{
			printf("func()\n");
		}

		struct TreeNode
		{
			struct TreeNode* left;
			struct TreeNode* right;
			int val;
		};
	}
}

//int main()
//{
//	int rand = 0;
//	printf("%p\n", rand);
//	printf("%P\n", sql::ma::rand);
//
//	sql::ma::func();
//
//	struct sql::ma::TreeNode node;
//
//	return 0;
//}

//int a = 0;
//int main()
//{
//	int a = 1;
//	printf("%d\n", a);
//
//	//::域作用限定符
//	//空白表示全局域
//	printf("%d\n", ::a);
//
//	return 0;
//}

#include "Stack.h"
#include "Queue.h"

namespace ch
{
	typedef int STDataType;

	typedef struct Stack
	{
		STDataType* a;
		int top;        //栈顶的位置
		int capacity;   //容量
	}ST;
}

//int main()
//{
//	bit::ST st;
//	bit::StackInit(&st);
//
//	bit::Queue q;
//	bit::QueueInit(&q);
//}

using namespace ch;

//std是c++标准库的命名空间
using namespace std;

//int main()
//{
//	//先在全局域去找，如果没有还会带展开的ch域中去找
//	ST st；
//	StackInit(&st);
//
//	Queue q;
//	QueueInit(&q);
//
//	return 0;
//}

using std::cout;
using std::cin;

int main()
{
	// << 是流插入运算符
	std::cout << "hello world" << std:: endl;
	std::cout << "hello world" <<  "\n";

	//自动识别类型
	int i = 11;
	double d = 11.11;

	// >>流提取
	scanf("%d,%f", &i, &d);
	std::cin >> i >> d;

	printf("%d,%f\n", i, d);
	std::cout << i << "," << d << std::endl;
	
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
	//Time(int hour = 0)
	Time(int hour)
	{
		_hour = hour;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int year, int hour, int& x)
		: _year(year)
		, _t(hour)
	    , _N(10)
		, _ref(x)
	{ 
		// 函数体内初始化 
		_year = year;
		_ref++;
	}
private:
	// 声明
	int _year = 0;  // C++11 缺省值 -- 初始化列表时没有显示给值就会用这个缺省值
	Time _t;
	const int _N;
	int& _ref;
};

// 结论：自定义类型成员，推荐用初始化列表初始化
// 初始化列表可以认为是成员变量定义的地方

//内置类型也推荐使用初始化列表，当然内置类型在函数体内初始化也没有什么明显的问题
//能使用初始化列表就使用，使用初始化列表基本没什么毛病

//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//	const int N; // const必须在定义的地方初始化，只有一次机会
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	// 有些初始化工作还是必须在函数体内完成
//    A(int N)
//		:_N(N)
//	{
//		 _a = ((int*)malloc(sizeof(int)*N))
//		, _N(N)
//		if (_a == NULL)
//		{
//			perror("malloc fail\n");
//		}
//		memset(_a, 0, sizeof(int) * N);
//	}
//private:
//	// 声明
//	int* _a;
//	int _N;
//};

class A
{
public:
	// 初始化按声明顺序初始化
	A(int a)
	// 成员变量定义
		:_a1(a)
		, _a2(_a1)
	{}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	// 成员变量声明
	int _a2;
	int _a1;
};

//A.输出1  1
//B.程序崩溃
//C、编译不通过
//D、输出1  随机值

//int main()
//{
//	// D
//	// 对象定义
//	A aa1(1);
//	aa1.Print();
//
//	A aa2(2);
//
//	return 0;
//} 

/////////////////////////////////////////////////////////////
//explicit关键字 + 匿名对象
class Date
{
public:
	explicit Date(int year)
		:_year(year)
	{
		cout << "Date(int year)" << endl;
	}

	Date(const Date& d)
	{
		cout << "Date (const Date& d)" << endl;
	}

	~Date()
	{
		cout << "Date(const Date& d)" << endl;
	}
private:
	int _year;
};

void func(const string& s)
{}

class Solution {
public:
	int Sum_Solution(int n) {
		// ...
		return 0;
	}
};

//int main()
//{
//	Date d1(2022);  // 直接调用构造
//	Date d2 = 2022; // 隐式类型转换：构造 + 拷贝构造 + 优化 -> 直接调用构造
//	const Date& d3 = 2022;
//
//	int i = 10;
//	const double& d = i;
//
//	string s1("hello");
//	string s2 = "hello";
//
//	string str("insert");
//	func(str);
//	func("insert");
//
//	Date d4(2000);
//
//	//匿名对象，一些使用场景
//	Solution slt;
//	slt.Sum_Solution(10);
//	Solution().Sum_Solution(10);
//
//	// 匿名对象 - 生命周期只有这一行
//	Date(2000);
//
//	return 0;
//}

//设计一个只能在栈上定义对象的类
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		StackOnly so;
	    return so;
	}
private:
	StackOnly(int x = 0,int y = 0)
		:_x(x)
		, _y(0)
	{}
private:
	int _x = 0;
	int _y = 0;
};

//int main()
//{
//	//StackOnly so1; // 栈
//	//static StackOnly so2;  // 静态区
//	StackOnly so3 = StackOnly::CreateObj();
//
//	return 0;
//}

class A
{
private:
	int _h;
public:
    // B定义在A的里面
	// 1、受A的类域限制，访问限定符
	// 2、B天生是A的友元
	class B 
	{
	public:
		void foo(const B& a)
		{
			cout << k << endl; // OK
			cout << a._b << endl; // OK -- 友元
		}
	private:
		int _b;
	};
};
int A::k = 1;

class ListNode
{
private:
	ListNode* _next;
	int _val;
};

class List
{
	class ListNode
	{
	private:
		ListNode* _next;
		int _val;
	};
public:
	void PushBack()
	{
		ListNode node;
		node->_val;
	}
private:
	ListNode* _head;
};
int main()
{
	cout << sizeof(A) << endl; // 4
	A a;
	A::B b;

	return 0;
}
