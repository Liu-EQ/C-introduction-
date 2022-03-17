#include<iostream>
#include<string>
using namespace std;

//结构体案例：毕业设计：三位老师，每位老师带五位学生
						//老师结构体中：老师姓名；学生结构体数组
						//学生结构体中：姓名、考试成绩、
		//要求：通过函数给每个老师及所带学生赋值，最重打印出老师数据及老师所携带的学生数据
//分析：
//1.有学生、老师，两个结构体，所以需要先进性结构体声明。其中老师结构体是嵌套结构体
struct  student
{
	string Name;//学生姓名
	int Score;//学生成绩
};//学生结构体
struct  teacher
{
	string Name;//教师姓名
	struct  student stu[5];//所带学生数组
};//老师结构体

//3.信息输入函数：因为是输入信息，所以需要更改实参的值，因此应该做地址传递（即函数形参应该为地址）
void Write(struct teacher * p,int length);//传入参数为教师变量地址

//4.信息输出函数，进行值传递即可
void Print(struct teacher * Teachers,int length);//传入数据位数组以及数组长度


int main() 
{
	//2.需要根据要求定义老师和学生变量
	//3位老师
	teacher Teach[3];//定义一个老师数组;[]中为数组长度，不是等于数组下标
	int length = sizeof(Teach) / sizeof(Teach[0]);
	cout << length << endl;
	//设置输入函数对老师变量中的内容进行输入
	Write(Teach,length);//输入函数调用结束
	//4.调用输出函数对录入信息进行输出
	Print(Teach,length);
	cout << endl;
	system ("pause");

	return 0;
}

void Write(struct teacher * p,int length)
{
	for (int i = 0; i < length ; i++)
	{
		cout << "请输入第"<<i+1<<"位老师的姓名：";
		cin >> p[i].Name;//第一位老师的姓名输入完毕之后就要开始输入该老师所带学生的信息
		cout << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t请输入该老师所带的第" << j + 1 << "位同学的姓名：";
			cin >> p[i].stu[j].Name;//第i位老师带的第j位同学
			cout << "\t请输入该老师所带的第" << j + 1 << "位同学的成绩：";
			cin >> p[i].stu[j].Score;
		}//一位老师所携带的学生的信息录入

	}//一位老师的信息录入


}

void Print(teacher * p2, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "第" << i+1 << "位老师的姓名位：" << p2[i].Name << endl
			 <<"该老师所带学生信息为："<<endl;
		for (int j = 0; j < 5; j++)
		{
			cout <<"\t"<< p2[i].Name << "老师所带的第" << j + 1 << "位学生的名字为：" << p2[i].stu[j].Name
				<< "。他对应的毕业设计成绩为：\t" << p2[i].stu[j].Score << endl;//此时传入的是数组地址，即p2参数就是数组名

		}
		
	}
}
//总结：多层循环一定要仔细写i、j、k；一旦i、j、k写错，极易导致循环出问题
//函数形参为指针时，传入的地址就是实参变量的地址，
			//那么在函数中形参名字和实参名字可以视为相等的（即如果实参是数组，那么形参的名字就是该数组在函数中的新名字，除了名字不同外，其余操作均不发生变化）
			//地址传递，传递的是实参的地址，所以在函数中是直接针对于实参进行操作的，形参此时并没有物理存在
				//地址传递书写方式：变量类型 * 变量名（可任意起）。此时，在函数中，该变量就可以等效视为实参，不论实参是何种数据类型，都不会改变

