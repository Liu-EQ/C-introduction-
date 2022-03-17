#include<iostream>
#include<ctime>
using  namespace std;

//函数的地址传递
void swap02(int *p1,int *p2);//函数声明，此时形参就是指针，在进行传入参数的时候就是传入的地址了
								//即为两个指针指向同一个变量，因此，可以直接解引用对变量本身进行操作


void arrBubble(int *arr,int length);//添加对数组进行冒泡排序的函数的声明

int main() 
{
	//6.0 指针（占用4B）
	//6.1 指针定义与使用

	//用途：记录地址（保存变量地址）（指针可以视为一个专门存储16进制地址的变量）
	//6.1.1定义指针:数据类型 * 指针变量名
	/*int a = 10;
	int * p = &a;//数据类型（空格）*（空格）指针名=&（取地址符）变量名
	cout <<(int) &a << endl;
	cout << (int)p << endl;*/
	//6.1.2使用指针：可以通过解引用的方式来找到指针指向的内存
		//指针前加星号，代表指针指向的变量（即该地址指向的内存）
	//*p = 100;//通过*p找到所指向的变量（内存），可以对它进行修改和读取
	//指针所占内存空间
	/*cout<<"sizeof(int *)="<<sizeof(p)<<endl;
	cout << "sizeof(float *)=" << sizeof(float *) << endl;
	cout << "sizeof(double *)=" << sizeof(double *) << endl;
	cout << "sizeof(char *)=" << sizeof(char *) << endl;//指针也是一种变量，它不因为指向不同类型的变量，大小就会有所差别
	cout << a << endl;*/

	//6.2空指针和野指针

	//6.2.1空指针：指向内存编号为0的空间；用途：初始化指针变量；Tips：空指针指向的内存是不可以访问的（（0-255之间的内存是系统占用的）
	//int *p = NULL;//(指针初始化)
	//野指针：指针变量指向非法的内存空间
	//int *p2 = (int *)0x1100;//这是一种错误，没有申请该空间但是就直接指向了该空间

	//6.3 const修饰指针

	//const修饰指针有三种情况：
	//1.const修饰指针——常量指针
	/*int num1 = 10;
	int *p = &num1;//常量指针书写方式：const int *p=&num1
	const int *p = &num1;//此时，p指针就成为了一个常量指针
			//常量指针特点：指针指向可以改，但是指针不论指向哪一个变量，值都是一开始指针所指变量的值
			//因此，在p变为常量指针后：*p=20（错误语法，值不能改）；p=&num2；（正确语法，指针指向可以改）
	//2.const修饰常量——指针常量
		//指针常量书写方式：int * const p=&a；
	int * const p = &num1;//此时p就是一个指针常量
			//指针常量特点：指针指向不可以改，但是指针指向的变量值可以改
			//因此，在指针常量中：*p=20（正确，指针指向的变量值可以改）；p=&num2（错误，指针指向不可以改）
	//3.const及修饰指针，又修饰常量
		//书写方式 const int * const p =&num1
	const int * const p = &num1;//此时const既修饰指针，又修饰常量
			//此时，指针指向与指针所指变量的值都不可以改
			//*p=20；p=&num2（都是错误）
	//记忆方法：*——指针；const——常量。因此int * const p就是指针常量；const int * p就是常量指针
						//能修改指向还是所指变量值：谁在前不能修改谁（即：指针常量不能修改指针，常量指针不能修改常量）（而指针对应指向，常量对应所指变量值）
						*/

	//6.4 指针和数组（利用指针访问数组）
	
	/*int arr[10] = {1,2,3,4,5,6,7,8,9,10,};
	int *p = arr;//数组名就是数组首地址
	cout << *p << endl;
	//利用指针访问第二个元素
	p++;//默认加一个单位（即4B）
	cout << *p << endl;
	//利用指针遍历整个数组
	cout << "数组内部值为：" << endl;
	p = arr;//初始化指针
	for (int i = 1; i <=10; i++)
	{
		

		cout << *p <<" ";
		p++;
	}*/

	//6.5 指针和函数（利用指针作为函数参数（形参），可以修改实参的值）
	//因为指针是指向实参的地址，即为实参的内存空间，因此用指针作为形参可以改变实参的值

	//1.值传递
	//2.地址传递
		//类似：void swap（int *p1,int *p2）
			//在此函数中再进行操作就是针对实参的操作了
				//*p解引用就是针对于该指针所指向的变量进行的操作，可以视为*p就是所指向的变量本身
	/*int num1 = 10, num2 = 20;
	cout << "num1=" << num1 << endl
		<< "num2=" << num2 << endl;
	swap02(&num1, &num2);
	cout << "进行地址传递之后：" << endl;
	cout << "num1=" << num1 << endl
		<< "num2=" << num2 << endl;*/


	//6.6  指针、函数和数组
	//案例：封装一个函数，利用冒泡排序。实现对整型数组的升序排序
	//分析：是一个现成的函数，可以理解为使用冒泡排序算法对数组进行排列，且函数形参为指针
	//1.需要创建一个数组
	int testarr[5] = {5,4,3,2,1};//会议随机数生成法，利用随机数输入数组元素的值
	int length = sizeof(testarr)/sizeof(testarr[0]);
	/*for (int i = 0; i < 50; i++)//使用for循环来随机输入数组元素的值
	{
		srand((unsigned int)time(NULL));
		testarr[i] = rand() % 100 + 1;
		cout << testarr[i] << " ";
	}*///完成了数组元素输入
	//2.之后要使用冒泡排序对数组元素进行排序
		//2.1需要对应创建一个冒泡排序算法
	for (int i = 0; i <length; i++)//使用for循环来输出数组元素的值
	{
		//srand((unsigned int)time(NULL));
		//testarr[i] = rand() % 100 + 1;
		cout << testarr[i] << " ";
	}
	cout << endl;
	arrBubble(testarr,5);//数组不需要取地址符
	for (int i = 0; i <length; i++)//3.使用for循环来输出数组元素的值
	{
		//srand((unsigned int)time(NULL));
		//testarr[i] = rand() % 100 + 1;
		cout << testarr[i] << " ";
	}
	cout << endl;
	int * p=testarr;
	cout << "*p1=" << *p << endl;


	cout << endl;

	system("pause");

	return 0;
}

void swap02(int * p1, int * p2)
{
	int temp = *p1;
	*p1 = *p2;//此时是针对实参的操作，*p可以视为是所指变量本身
	*p2 = temp;//同理
}

void arrBubble(int * arr,int length)//此时传递的是地址，所以会对实参的值进行更改
									//而在函数内部叫什么名字完全随意，不一定非要和主函数中的名字保持一致
{
	//首先要明确传入的是数组首地址，而冒泡排序是两两比较
	for (int j = 1; j <length; j++)//大的循环，总共进行的排序轮次
	{
		for (int i = 1; i <= (length-j); i++)//每一趟的循环，i初始值为1即为指向第二个元素，每趟比较的次数=元素总数-当前轮次
		{
			//应该定义一个临时变量用来暂时存储变量值
			if (arr[i-1]>arr[i]) //Tips：函数内部使用的变量名应该和函数形参的变量名保持相同（即函数形参中为arr，最内层比较函数也应该为arr）
								 //此时arr就是testarr，因为再形参中传入的是testarr的地址，只不过再函数内部给它换了个名字
			{
				int temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
			}//出现该情况，进行交换，如果没有出现则不做处理
			 //目前所学并不会用指针进行最内层的比较
		}//由此完成了一趟循环
	}
}

