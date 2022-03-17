#include<iostream>
#include<string>
using namespace std;

struct Hero
{
	string Name;//姓名
	int   Age;//年龄
	int  Pow;//战力
};

int main()
{

	int arr[5] = { 1,2,3,4,5 };
	int * p = arr;
	cout << p[2]<<endl;
	struct Hero Heros[2] = {
		{"张三",25,260},
		{"李四", 26,310},
	};
	cout << Heros[1].Name<<endl;
	struct Hero  * Heros2 = Heros;
	Heros2[1].Name = "AAA";//可以通过该指针来修改结构体数组中某元素某个成员变量的值
	cout << Heros[1].Name<<endl;
	cout << Heros2[1].Name;//可以通过指针来输出结构体数组中某个元素某个成员变量的值
	cout << endl;
	system("pause");
	return 0;
}