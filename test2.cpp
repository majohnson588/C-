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
