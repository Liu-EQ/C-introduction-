#include<iostream>
#include<string>
using namespace std;



#define MAX 1000//便于后期维护与修改
				//声明后不加分号***


//定义一个联系人结构体:包括姓名、性别、年龄、家庭住址、联系方式
struct Friend{
	string Name;
	string Sex;
	int Age;
	string Address;
	long long Tel;
};

//通讯录结构体
struct AddressBook 
{
	struct Friend Friends [MAX] = {};//定义一个联系人数组用来存储联系人信息
	int length = 0;//数组初始为空所以，该数组初始长度为0
};

void showMenu();//菜单函数

void Print(struct AddressBook * Book);//显示模块函数声明

void Add(struct AddressBook * Book, int  length);//增加模块声明

int Find1(struct AddressBook Book, string FindName);//子查找函数
void Find(struct AddressBook Book,string FindName);//查找函数声明

void Del(struct AddressBook * Book, string DelName);//删除函数声明

void Modify(struct AddressBook * Book, string ModName);//修改函数声明

int main() 
{
	//整个通讯录管理系统共有八个功能，可以写八个函数模块来对应实现（添加、显示、删除、查找、修改、清空、退出）
			//但是八个函数模块共享一套数据信息，所以有关数据信息的相关模块需要放在主函数中进行实现
			//查询，显示可以份文件进行编写
	AddressBook Book1;//定义一个通讯录数组
	Book1.length = 0;

	showMenu();//调用菜单函数
	cout << "欢迎使用青木通讯录系统，请输入您想使用的功能" << endl;
	//整体可以视为一个联系人数组，数组长度为一千，同时，数组内部成员变量为结构体变量——有关数据对象的定义
	//整体可以通过一个switch函数进行功能选择，用户通过键入数字进行对应的功能选择
	int select;//功能选择
	while (true)
	{
		cin >> select;
		switch (select)
		{
		case 0://退出模块
				//该模块可不做处理，输入0，直接break
			cout << "欢迎下次使用！！！" << endl;
			system("pause");
			return 0;//注意死循环如何结束
			break;
		case 1://显示模块
			//该模块可使用两层for循环进行输出
			//可以份文件编写，
			Print(&Book1);//调用显示函数模块
			break;
		case 2://增加模块
			//该模块应该包括一个提示输入语句，一个信息输入，以length值为输入位置，同时输入完成后更改length
			Add(&Book1,Book1.length);//增加函数调用
			break;
		case 3: 
		{//查找模块
			//该模块可以提供用户按照联系人姓名或者联系方式两种方式进行查询
			//按用户姓名进行查询，需要一个字符串比较函数
			//字符串比较函数需要先定义一个字符串常量用于暂时存储用户输入的联系人姓名，之后可以进行强制类型转换然后来进
			//按用户联系方式进行查询需要一个简单的比较函数
			string FindName;//临时变量，暂时存储用户要查找的联系人的姓名
			cout << "请输入您要查找的联系人姓名：" << endl;
			cin >> FindName;
			Find(Book1, FindName);//调用查找模块
			break; }
		case 4:
		{//修改模块
			string ModName;
			cout << "请输入您要修改的联系人姓名：";
			cin >> ModName;
			Modify(&Book1,ModName);
			break; }
		case 5:
		{//删除模块
			string DelName;//待删除的联系人姓名
			cout << "请输入要删除的联系人姓名" << endl;
			cin >> DelName;
			Del(&Book1, DelName);//从Book1中删除姓名为DelName的联系人
			break; }
		case 6://清空模块
			//该模块只用将length值进行更改即可
			cout << "您确定删除该联系人信息吗？(Y/N)" << endl;
			char answer;
			cin >> answer;
			if (answer == 'Y') Book1.length = 0;//此时联系人数组默认是从第0个开始
			system("pause");
			system("cls");
			break;

		default:
			break;
		}
		showMenu();//调用菜单函数
		cout << "请输入您要使用的功能选项：" << endl;
	}
	
	cout << endl;
	return 0;
}

//菜单展示
void showMenu()
{
	cout<< "*************************"<<endl
		<< "***** 0-退出通讯录 *****" << endl
		<< "***** 1-显示联系人 *****" << endl
		<< "***** 2-增加联系人 *****" << endl
		<< "***** 3-查找联系人 *****" << endl
		<< "***** 4-修改联系人 *****" << endl
		<< "***** 5-删除联系人 *****" << endl
		<< "***** 6-清空通讯录 *****" << endl
		<< "*************************"<<endl;
}

//联系人显示
void Print(AddressBook * Book)
{
	if (Book->length == 0)
	{
		cout << "该通讯录记录为空，请先输入联系人信息！！！" << endl;
	}
	else
	{
		for (int i = 0; i < Book->length; i++)//使用两层for循环进行信息输出
								//外层for循环是对所有联系人进行输出
		{

			cout << Book->Friends[i].Name << "\t"
				<< Book->Friends[i].Sex << "\t"
				<< Book->Friends[i].Age << "\t"
				<< Book->Friends[i].Address << "\t"
				<< Book->Friends[i].Tel << "\t"
				<< endl;
		}
	}

	system("pause");
	system("cls");
}

//添加联系人
void Add(struct AddressBook * Book, int length)
{
	//判满操作
	if (Book->length==MAX)
	{
		cout << "通讯录空间已满，无法继续添加联系人！！！" << endl;
		return;//if...else要设置窗口，不能无限循环
	}
	else
	{
		//首先要提醒用户进行信息输入
		cout << "请依次输入联系人的姓名、性别、年龄、地址、联系方式" << endl;
		cin >> Book->Friends[Book->length].Name >> Book->Friends[Book->length].Sex >> Book->Friends[Book->length].Age
			>> Book->Friends[Book->length].Address >> Book->Friends[Book->length].Tel;//指针使用箭头调用所指变量的成员变量
																					  //其余情况使用.来调用成员变量
		Book->length++;
		cout << "联系人添加成功!" << endl<<endl;
		cout << "目前通讯录中有" << Book->length << "位联系人！" << endl

			<< "还可继续存放" << 1000 - Book->length << "位联系人!" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}


}

//查找联系人,存在返回联系人下标并且输出联系人信息，不存在返回-1
void  Find(AddressBook Book,string FindName)//按姓名查找，形参中应该有姓名参数
{
	//外层for循环控制查找范围
	//内层if语句进行具体查找
	int i1 = Find1(Book,FindName);
	if (i1!=-1)
	{
		cout << "该联系人是您通讯录中第" << i1 + 1 << "位好友" << endl;
		cout << "该联系人的信息为：" << endl;
		cout << Book.Friends[i1].Name << "\t"
			<< Book.Friends[i1].Sex << "\t"
			<< Book.Friends[i1].Age << "\t"
			<< Book.Friends[i1].Address << "\t"
			<< Book.Friends[i1].Tel << endl;
		system("pause");
		system("cls");

	}
	
}

//删除联系人，利用到子查找函数
void Del(AddressBook * Book, string DelName)
{
	int temp = Find1(*Book,DelName);//不能直接套用
	if (temp!=-1)
	{
		cout << "您确定删除该联系人信息吗？(Y/N)" << endl;
		char answer;
		cin >> answer;
		if (answer == 'Y')
		{
			for (int j = temp; j < Book->length; j++)//用覆盖代替删除
			{
				/*Book->Friends[j].Name = Book->Friends[j + 1].Name;
				Book->Friends[j].Sex = Book->Friends[j + 1].Sex;
				Book->Friends[j].Age = Book->Friends[j + 1].Age;
				Book->Friends[j].Address = Book->Friends[j + 1].Address;
				Book->Friends[j].Tel = Book->Friends[j + 1].Tel;*/
				Book->Friends[j] = Book->Friends[j + 1];
			}
			cout << "联系人删除成功！" << endl;
			system("pause");
			system("cls");	
			Book->length--;
		}
	}
	
}

//修改联系人，同样使用子查找函数
void Modify(AddressBook * Book, string ModName)
{
	int temp = Find1(*Book, ModName);//首先先找到该联系人
	if (temp!=-1)
	{
		Friend ModFriend;//临时变量暂时存储待修改联系人的信息
		cout << "请输入该联系人的新信息(姓名、性别、年龄、地址、电话)：" << endl;
		cin >> ModFriend.Name >> ModFriend.Sex >> ModFriend.Age >> ModFriend.Address >> ModFriend.Tel;
		cout << endl;
		/*Book->Friends[temp].Name = ModFriend.Name;
		Book->Friends[temp].Sex = ModFriend.Sex;
		Book->Friends[temp].Age = ModFriend.Age;
		Book->Friends[temp].Address = ModFriend.Address;
		Book->Friends[temp].Tel = ModFriend.Tel;*/
		Book->Friends[temp] = ModFriend;//结构体赋值方法
		cout << "联系人信息修改成功！" << endl;
		system("pause");
		system("cls");
	}
}

//子查找函数，查找到返回该联系人下标，未查找到返回-1
int Find1(struct AddressBook Book, string FindName)
{
	for (int i = 0; i < Book.length; i++)//大循环，在所有联系人信息中进行查找
	{
		if (FindName == Book.Friends[i].Name)//比较某个联系人和要查找的联系人姓名是否一致？？：直接可以用字符串比较函数吗？？？
		{
			return i;//查找到返回下标尾差找到返回-1
		}
	}
	cout << "你的联系人列表中没有该联系人的信息，请先添加该联系人信息！" << endl;
	system("pause");
	system("cls");
	return -1;//注意对于for循环执行顺序以及if语句的理解:
					//for循环时不管循环体时什么，只要for判断语句符合，就会一直执行，因此不用担心如何由循环体继续跳转到下一次判断
					//对于if而言只有在满足条件才执行循环体语句，所以for+if可以实现在一个大范围内寻找满足某一个条件的情况
										//且该类寻找方法由于是for循环，不用担心是否会找完整个范围
										//而对于结果的反馈上，找到了是一个反馈，找不到是另一个反馈，因此需要在if中设置函数出口
}//子查找函数，无多余信息返回

