// learnstocks.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define OK 1
#define NG 0
#define SETSIZE 100//学习数据大小
#define CNO 10//学习数据的位数
#define GENMAX 100000//生成候选解的次数
#define SEED 6666//随机数种子

void readdata(int data[SETSIZE][CNO], int takcher[SETSIZE]);//读入学习数据
int rand012();//返回0\1\2的随机函数
int calcscore(int data[SETSIZE][CNO], int teacher[SETSIZE], int answer[CNO]);//计算候选解的得分
int rand01();

int main()
{
	int i, j;
	int score = 0;
	int answer[CNO];
	int teacher[SETSIZE];
	int data[SETSIZE][CNO];
	int bestscore = 0;
	int bestanswer[CNO];

	srand(SEED);

	readdata(data, teacher);

	for (i = 0; i < GENMAX; ++i) {
		for (j = 0; j < CNO; j++) {
			answer[j] = rand012();
		}
		score = calcscore(data, teacher, answer);

		if (score > bestscore) {
			for (j = 0; j < CNO; ++j)
				bestanswer[j] = answer[j];
			bestscore = score;
			for (j = 0; j < CNO; j++)
				cout << bestanswer[j] << " ";
			cout << ": score=" << bestscore << endl;
		}
	}


	//输出最优解

	cout << "最优解" << endl;
	for (j = 0; j < CNO; j++) {
		cout << bestanswer[j]<<" ";
	}
	cout << ": score=" << bestscore << endl;
	return 0;
}

//候选解模式的得分
int calcscore(int data[SETSIZE][CNO], int teacher[SETSIZE], int answer[CNO])
{
	int score = 0;
	int point;
	int i, j;
	for (i = 0; i < SETSIZE; ++i) 
	{
		point = 0;
		for (j = 0; j < CNO; j++)
		{
			if (answer[j] == 2) ++point;
			else if (answer[j] == data[i][j])  ++point;
		}
		if ((point == CNO) && (teacher[i] == 1))++score;
		else if ((point != CNO) && teacher[i] == 0) ++score;
	}
	return score;
}
//读入学习数据
void readdata(int data[SETSIZE][CNO], int teacher[SETSIZE])
{
	int i, j;
	for (i = 0; i < SETSIZE;++i)
	{
		for (j = 0; j < CNO; j++)
			//cin >> data[i][j];
			data[i][j] = rand01();
	//cin >> teacher[i];
	teacher[i] = rand01();
	}
	for (i = 0; i < SETSIZE; ++i)
	{
		for (j = 0; j < CNO; j++)
			cout << data[i][j] << " ";
		cout << "     "<<teacher[i] << endl;
	}
}

int rand012()
{
	int rnd;
	while((rnd=rand())==RAND_MAX);
	return (double)rnd / RAND_MAX * 3;
}

int rand01()
{
	int rnd;
	while ((rnd = rand()) == RAND_MAX);
	return (double)rnd / RAND_MAX * 2;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
