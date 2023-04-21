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
