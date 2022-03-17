#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//英雄按年龄排序
//1.定义一个英雄结构体，然后生成一个英雄数组
struct Hero
{
	string Name;//姓名
	int   Age;//年龄
	int  Pow;//战力
};

void BubbleSort(struct Hero * Heros,int length);//简单冒泡排序已经定义完毕
			//需求分析：不能简单的对年龄进行顺序更改，应该定义一个临时的英雄结构体变量

int   main() 
{
	Hero Heros[5];//构建英雄数组
	int length = sizeof(Heros) / sizeof(Heros[0]);
	cout << length << endl;
	//2.输入英雄信息
	//可以利用佛如循环随机生成英雄信息，进行输入（懒得手动输入了）
	string nameSeed = "ABCDE";//姓名种子
	srand((unsigned int)time(NULL));//随机数种子
	for (int i = 0; i < length; i++)
	{
		Heros[i].Name = "Hero";
		Heros[i].Name += nameSeed[i];//注意nameSeed的写法，此时姓名信息输入完毕
		//开始输入年龄信息,利用随机数法进行输入
		int random1 = rand() % 20+20;//此时英雄年龄区间为20-39
		Heros[i].Age = random1;
		//开始输入战力信息，同样利用随机数生成法
		int random2 = rand() % 50000 + 1000;//此时英雄战力区间为：1000-59999
		Heros[i].Pow = random2;//此时为伪随机数，还需要加一个随机数种子构成真随机数
	}//此时已将英雄信息输入完毕
	cout << "排序前的英雄信息为：\n";
	for (int i = 0; i < length; i++)
	{
		cout << Heros[i].Name << "\t" << Heros[i].Age << "\t" << Heros[i].Pow << "\t" << endl;
	}//输出未排序之前的英雄信息
	//3.构建冒泡排序算法，以英雄年龄为标准进行排序
	//可以首先构建一个冒泡排序算法
	BubbleSort(Heros,length);//调用冒泡排序函数
	//使用for函数输出排序后的英雄信息
	cout << "排序后的英雄信息为：\n";
	for (int i = 0; i < length; i++)
	{
		cout << Heros[i].Name << "\t" << Heros[i].Age << "\t" << Heros[i].Pow << "\t" << endl;
	}//输出排序之后的英雄信息以作比较





	cout << endl;
	system("pause");
	return 0;
}

void BubbleSort(struct Hero  * Heros , int length)//传入参数可以是英雄数组的首地址
{
	for (int i = 1; i < length; i++)//大的比较轮次的循环
									//比较轮次=参数总数-1
	{
		for (int j = 1; j <= length-i; j++)//一趟轮次中比较次数的循环
										  //每一趟比较次数=参数总数-当前比较轮次
		{
			if (Heros[j-1].Age>Heros[j].Age)//比较标准可以是英雄年龄
			{
				Hero temp;
				//年龄较大的英雄变量的值赋给临时变量
				temp.Name = Heros[j - 1].Name;
				temp.Age = Heros[j-1].Age;
				temp.Pow = Heros[j - 1].Pow;
				//年龄较小者的英雄变量值赋给年龄较大者的英雄变量
				Heros[j-1].Name = Heros[j].Name;
				Heros[j - 1].Age = Heros[j].Age;
				Heros[j - 1].Pow = Heros[j].Pow;
				//temp变量值赋给年龄较小者的英雄变量
				Heros[j].Name = temp.Name;
				Heros[j].Age = temp.Age;
				Heros[j].Pow = temp.Pow;
				//顺序更换完毕
			}//用临时的英雄变量来进行排序

		}
	}
}
				//冒泡循环内层外层比较次数要牢记，并且理解：
									//外层比较轮次循环次数=参数总数-1（一趟循环得出一个最大数，那么n-1趟循环就得出前n-1个最大数，剩余的自然为最小值）
									//内层比较循环次数=参数总数-当前比较轮次（每一趟得出一个最大数，下一趟就会少一个数字参与比较，n个数组n-1次比较得出最大数）
				//同样，地址传递需要好好理解，指针数组的定义方式：数据类型 * 变量名（任意起），与普通指针定义并无区别
