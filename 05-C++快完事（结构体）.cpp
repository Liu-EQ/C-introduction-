#include<iostream>
#include<string>
using namespace std;

//7.0结构体
//7.1结构体的创建
//示例：创建一个学生数据类型（具体包括学生学号，姓名，性别，班级）
//7.1.1结构体声明（定义）
struct  student
{
	//成员列表
	int ID;
	string Name;
	string Sex;
	int Class;
};//法三：直接再}后加一个变量名：}s3；，这样就创建了一个s3变量

//嵌套结构体
struct  teacher
{
	int ID;
	string Name;
	int age;
	struct  student stu;//嵌套结构体（使用另一个结构体作为本结构体的成员）
		 
};

//打印学生信息的函数
void Print(struct student s1);

//地址传递更改学生姓名
void Modify(struct  student * s1,string Name);

int main() 
{
	/*//通过学生数据类型创建具体变量
	struct  student s1;
	{
		s1.ID = 170902316;
		s1.Name = "张三";
		s1.Class = 5;
		s1.Sex = "男";

	};//法一(也可以省略s1.，直接赋初值={170902316,张三...})
	  //法二：单独赋值，先创建该结构体变量：struct student s1；之后再赋初值：s1.Name=....
	 //前两种使用较多
	 //Tips：结构体变量创建：可以省略关键字 struct：（student s1这是可以的）
			//结构体变量使用'.'来访问成员变量
	cout << "姓名：" << s1.Name << "\n"
		<< "学号：" << s1.ID << "\n"
		<< "班级:" << s1.Class << "\n"
		<< "性别：" << s1.Sex << "\n";*/

	//7.2结构体数组创建方式
	//语法：struct 结构体名 数组名【元素个数】={{},{}，{}，{}....}
	//示例：
	struct  student Class5[3]=
	{
		{170902317,"张三","男",5},
		{170902318,"李四","男",5},
		{170902319,"雁六","女",5},
	};
	//赋值或更改
	Class5[1].Name = "李毅";
	/*for (int i = 0; i < 3; i++)
	{
		cout << Class5[i].Name <<"\t";
		cout << Class5[i].ID << "\t";
		cout << Class5[i].Sex << "\t";
		cout << Class5[i].Class << "\t" << endl;

	}*/


	//7.3 结构体指针（->）
	//通过指向结构体的指针来访问结构体中的成员
	student * Pstu = Class5;//等号两侧数据类型应该相同
	Pstu->Name = "张宪";
	//cout << Class5[0].Name << endl;

	//7.4 嵌套结构体
	teacher teacher;
	teacher.Name = "章太炎";
	teacher.ID = 10046;
	teacher.age = 41;
	teacher.stu.Class = 5;
	teacher.stu.Name = "周作人";
	teacher.stu.ID = 10095;
	teacher.stu.Sex = "男";
	//cout << teacher.Name << "老师的学生是：" << teacher.stu.Name << endl;


	//7.4 结构体作为函数参数
	//结构体的值传递和地址传递
	//Print(Class5[2]);//值传递
	Modify(&Class5[0],"张毅");//地址传递
	//cout << Class5[0].Name<<endl;
				//注意传入格式的书写方式，需要大量练习，同理地址传递也会修改实参的值
				//将函数中的形参改为指针可以减少内存空间的占用，且不会复制新的副本（使用箭头访问成员变量）

	//7.5 结构体中 const的使用情况
	//const使用场景
	student teststu;
	teststu.Name = "路人甲"; teststu.ID = 00001; teststu.Class = 3; teststu.Sex = "男";
	//函数形参书传入地址时，函数内部可以对实参的值进行修改，但是加入const之后函数内部就不可以对这些值进行修改
	Modify(&teststu,"路人乙");//const是加在函数定义部分的的参数之中



	cout << endl;
	system("pause");
	
	return 0;
}

void Print(student s1)
{
	cout << "该学生的姓名为：" << s1.Name << endl;
	cout << "该学生的班级为：" << s1.Class << endl;
	cout << "该学生的学号为：" << s1.ID << endl;
	cout << "该学生的性别为：" << s1.Sex << endl;
}

void Modify( student * p, string Name)
{
	cout << "修改前学生姓名为：" << p->Name << endl;
	p->Name = Name;
	cout << "修改后学生姓名为：" << p->Name << endl;
}//地址传递传入的是地址，所以访问时应该通过箭头（->）进行访问，而不能再通过（.）
