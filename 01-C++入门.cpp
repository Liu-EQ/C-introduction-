#include<iostream>
#include<string>//字符串头文件
#include<ctime>////系统时间头文件
#include<cstdlib>
using namespace std;

/*main是一个程序入口
  每个程序都应该有这么一个函数
   每个函数只能有这么一个main函数*/

//常量定义(法一)
#define day 7
int main()
{
	cout << "Hello world" << endl;//输出Hello World（注释）
	
								  
//part 1:变量基础知识（物种数据类型，基础输入输出）

/*//变量创建
	int l = 10;
	cout << "l=" << l << endl;
	cout << "一周总共有" << day << "天" << endl;
	
	
	//常量定义（法二）
	const int month = 12;
	cout << "一年总共有" << month << "个月份" << endl;*/


	//关键字
	//int int = 0;//错误命名


	//变量命名，最好能够见名知义
	//数据类型存在意义：给变量分派一个合理的存储空间，避免造成资源浪费
	//数据类型一：short 2B；int 4B; long 4B; longlong 8B
	//1.1整型数据类型
	
	/*//短整型(-32768-32767)
	short num1 = 10;
	//整型
	int num2 = 10;
	//长整型
	long num3 = 10;
	//长长整型*/
   /*long long num4 = 10;
	cout<<"num1="<<num1<<endl
		<<"num2="<<num2<<endl
		<<"num3="<<num3<<endl
		<<"num4="<<num4<<endl;

	//sizeof关键字
	//利用sizeof求出数据类型所占内存大小
	cout <<"num4所占内存空间为："<<sizeof(num4)<<endl ;


	//1.2数据类型二：实型（浮点型）
	//单精度float（4B） 七位有效数字；双精度double（8B）15-16位有效数字
	//单精度
	//小数不论是单精度还是双精度，默认情况下只会输出六位有效数字
	float pi1 = 3.1415926f;
	cout << "pi1="<<pi1<<endl;
	//双精度
	double pi2 = 3.1415926;//输出仍未3.14159（只会输出六位有效数字，若想输出更多，则需要进行专门配置）
	//统计float和double所占内存大小
	cout<<"单精度浮点型所占内存大小为："<<sizeof(float)<<endl
		<<"双精度浮点型所占内存大小为："<<sizeof(double)<<endl;

	//科学计数法标识小数
	float f2 = 3e2;//3e2=3*10`2;
	cout << "f2=" << f2 << endl;
	float f3 = 3e-2f;//3*0.1`2;
	cout << "f3=" << f3 << endl;
	//e后面如果为正数——代表10的n次方
	//e后面如果为负数——代表0.1的n次方*/


	//1.3数据类型三：字符型

	/*char char1 = 'L';//c,c++中字符型变量占用1B
	                 //字符型变量并不是把字符本身存储在内存中，而是把字符对应的ASCII码存储在内存单元中
	cout << "char1=" << char1 << endl;
	cout << "字符型变量所占内存空间大小为：" << sizeof(char) << endl;
	//字符型变量对应的ASCii码值
	cout << (int)char1 << endl;//字符型强制转换为整型	
	                           //a——97；A——65*/


	//1.4转义字符

	/*//常用转义字符：\n:换行； \t:水平制表（跳到下一个Tab位置）；  \\:代表一个\;
	cout << "Hello World\n";
	cout << "\\"<<endl;
	cout << "Thomas\tBenjamin\n";//（\t）+前面的内容总共为八位，前面位数多，\t所输出的空格就少（反之亦然）
	                             //Thomas占六位，所以输出时会有两个空格；\t有对齐的效果，可以整齐的输出后面的数据*/
	 
	//1.5数据类型四：字符串

	/*char str[] = "Hello World";//c风格的字符串*注意中括号和双引号
	cout << "str=" << str << endl;
	string str2 = "Hello Thomas";//c++风格的字符串，使用之前要加载头文件
	cout << "str2=" << str2 << endl;*/

	//1.6数据类型五：布尔型：只有两种值true false；仅占用1B

	/*bool flag = true;
	cout << "flag=" << flag << endl;//1代表真，0代表假
	cout << "flag所占内存空间大小为：" << sizeof(flag) << endl;*/


	//1.7数据输入cin>>

	/*int a = 0;
	float b =0.0f;
	char c = 'm';
	cout << "请输入整形变量a的值\n";
	cin >> a;
	cout << "您所输入的数字为：" << a << endl
		<< "请给浮点型变量b赋值：\n";
	cin >> b;
	cout << "您所输入的浮点型变量值为：\n" << b << endl;
	cout << "请给字符型变量c赋值：\n";
	cin >> c;
	cout << "您所输入的字符型变量的值为：" << c << endl;
	string str9 = "";
	cout << "请给字符串str赋值：\n";
	cin >> str9;
	cout << "您所输入的字符串为：" << str9 << endl;
	bool flag2 = 0;
	cout << "请为布尔类型变量flag2赋值：\n";
	cin >> flag2;                             //bool类型值只要不为0都代表真，输出都为1
	cout << "您所输入的布尔类型变量值为："<<flag2<<endl;  */

	//part2：运算符（四种运算符）

	//2.1:加减乘除

	/*int a1= 26, b1= 7;
	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl
		<< a1 * b1 << endl
		<< a1 / b1 << endl;//两个整数相除，结果依然是整数，小数部分去除
	int a2 = 10, b2 = 20;
	cout << a2 / b2 << endl;
	int a3 = 10, b3 = 0;
	//cout << a3 / b3;//出发运算，分母不可为0
	float c1 = 0.35f, c2 = 0.15f;
	cout << c1 / c2<<endl;//两个小数可以相处，结果仍未小数，仅保留六位有效数字*/

	//2.2：取模运算%

	/*int a4 = 10, b4 = 20;
	cout << 10 % 3 << endl;
	cout << a4 % b4 << endl;//同理，两数相除，除数不能为0
	//两个小数时不可以做取模运算的
	float c4 = 1.5, c5 = 0.3;*/
	//cout << c4 % c5 << endl;

	//2.3:递增递减运算

    /*int a5= 10,b5=20;
	//++a5;
	cout << a5<<endl;
	b5 = a5++ * 20;//++后置，先进行运算，运算结束之后再加一
	cout << b5 << endl;
	int b6 = 20, a6 = 10;
	b6 = ++a6 * 20;//++前置先加一，再进行后续运算
	cout << b6 << endl;*/

    //2.4：赋值运算符

    //=
    /*int a6 = 10;
	cout << "a6为："<<a6 << endl;
    //+=
	a6 += 52;
	cout <<"a6+=52为："<< a6 << endl;
    //-=
	a6 = 72;
	cout <<"a6为："<< a6 << endl;
		a6 -= 10;
	cout<<"a6-=10为："<<a6<<endl;
	//*=
	a6 = 6;
	cout << "a6为：" << a6 << endl;
	a6 *= 5;
	cout << "a6*=5为：" << a6 << endl;
	///=
	a6 = 54;
	cout << "a6为：" << a6 << endl;
	a6 /= 9;
	cout << "a6/=9为：" << a6 << endl;
	//%=
	a6 = 55;
	cout << "a6为：" << a6 << endl;
	a6 %= 9;
	cout << "a6%=9为：" << a6 << endl;*/


	//2.5：比较运算符,运算结果为0或1，即为假或真（0假1真）

    //==相等
    /*int a7 = 10, b7 = 20;
	cout <<"a7与b7是否相等："<< (a7 == b7) << endl;
    //！=不等
	cout <<"a7是否不等于b7："<< (a7 != b7) << endl;
    //大于>
	cout << "a7是否大于b7：" << (a7 > b7) << endl;
    //小于<
	cout << "a7是否小于b7：" << (a7 < b7) << endl;
    //大于等于>=
	cout << "a7是否大于等于b7：" << (a7>=b7) << endl;
    //小于等于<=
	cout << "a7是否小于等于b7：" << (a7 <= b7) << endl;*/


	//2.6：逻辑运算符

    //!非，！a：a假，则！a为真；a真，则！a为假
    /*int a8 = 10;
	cout << !a8<<endl;
	cout << !!a8<<endl;
    //与&&，有一个假，则为假
	int b8 = 0;
	cout <<( a8 && b8) <<endl;
    //或||，有一个着则为真
	cout << (a8 || b8) << endl;*/

    //part 3：程序流程结构（基本语句）

    //c/c++支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构
    //3.1选择结构
    //3.1.1 if语句
    //三种形式：单行；多行；多条件；
    //单行格式
    /*cout << "请输入您的考试成绩：\n";
	int a9;
	cin>>a9;
	if (a9 >= 600) cout << "您已经考上一本大学了\n";//if条件后面不要加分号，分号在表达式之后
	*/

	//多行格式if else

	//int a10 = 0;
	//cout << "请输入您的考试成绩:\n";
	//cin >> a10;
	//if (a10 >= 600) cout << "您已经考上一本大学了\n";
	//else if/*这个if是多余的*/ (a10 < 600)  cout << "非常抱歉，您并未考上一本大学\n";//二选一情况不需要再次添加if，直接else后添加表达式即可
	

	//多条件if
	/*int score = 0;
	cout << "请输入您的考试成绩：\n";
	cin >> score;
	if (score>=600)
	{
		cout << "恭喜你，您已经考上一本大学了\n";
	}
	else if (score>=500)
	{
		cout << "恭喜您，您考上了二本大学\n";
	}
	else if(score>=400)
	{
		cout << "恭喜您，你已经考上了大学\n";
	}
	else
	{
		cout << "很抱歉通知您，您并未考上大学\n";
	}*/


   //嵌套if语句

	/*int score = 0;
	cout << "请输入您的考试成绩：\n";
	cin >> score;
	if (score >= 600)
	{
		cout << "恭喜您，您已经考上了一本大学";
		if (score>=700)
		{
			cout << "恭喜您，您已经考入了北京大学\n";
		}
		else if (score>=650)
		{
			cout << "恭喜您，您已经考入了清华大学了\n";
		}
		else
		cout << "恭喜你，您已经考上中国人民大学了\n";
	}
	else if (score >= 500)
	{
		cout << "恭喜您，您考上了二本大学\n";
	}
	else if (score >= 400)
	{
		cout << "恭喜您，你已经考上了大学\n";
	}
	else
	{
		cout << "很抱歉通知您，您并未考上大学\n";
	}*/

	//练习例题：三只小猪称体重，要求找出其中最重的一只

	/*float weight1 = 0.0f, weight2 = 0.0f, weight3 = 0.0f;
	cout << "请输入第一只小猪的体重：\n";
	cin >> weight1;
	cout << "请输入第二只小猪的体重：\n";
	cin >> weight2;
	cout << "请输入第三只小猪的体重：\n";
	cin >> weight3;
	if (weight1>=weight2)
	{
		if (weight1>=weight3)
		{
			cout << "第一只小猪最重了，可以考虑吃掉它！\n";
		}//A、B比，若A重，则A、C比，若还是A重，则得结果A1
		else
		{
			cout << "第三只小猪最重了，可以考虑吃掉它！\n";
		}//同样如果A重，A、C比，则C重，则得结果C2
	}
	else if (weight2>=weight3)
	{
		cout << "第二只小猪最重了，可以考虑吃掉它！\n";
	}//若A、B比，B重，则B、C比，若B重，则得结果B3
	else
	{
		cout << "第三只小猪最重了，可以考虑吃掉它！\n";
	}*///同样，如果B重，则B、C比，若C重，则得结果C4
	//类似情况，画图查看结构，确定循环：A、B先比，若A重，则比较A、C，得到两个结果（A最重或C最重）；若B重，则B、C比，得到两个结果（B最重或C最重）

	//3.1.2 三目运算符

	//语法：表达式1？表达式2：表达式3（如果表达式1为真，则执行表达式2；否则执行表达式3）
	//三个变量a、b、c，从a、b重找出较大的赋值给c

	/*int a = 0,b = 0,c = 0;
	cout <<"请输入a的值：\n";
	cin >> a;
	cout << "请输入b的值\n";
	cin >> b;
	cout<<"a、b中较大值为："<<(c = (a > b ? a : b))<<endl;//c++中三目运算符返回的是变量，可以继续赋值
	(a > b ? a : b) = 100;
	cout << "将100赋值给a、b中较大值，所得结果为：\n"
		<<"a="<<a<<endl
		<<"b="<<b<<endl;*/

	//3.1.3switch语句

	//执行多条件分支语句
	//案例：电影评分：10-9——经典；7-9——非常好；5-7——一般；5以下——烂片
	//操作步骤：1、提示用户打分；2、用户输入分数；3、根据用户输入分数反应结果；

	/*int score2 = 0;
	cout << "请输入您对本电影的评分：\n";
	cin >> score2;
	switch (score2) 
	{
		case 10:
			cout << "您认为该电影为经典佳作!\n";
			break;//退出当前分支
		case  9:
			cout << "您认为该电影为经典佳作!\n";
			break;//退出当前分支
		case 8:
			cout << "您认为该电影还不错!\n";
			break;//退出当前分支
		case 7:
			cout << "您认为该电影为还不错！\n";
			break;//退出当前分支
		case 6:
			cout << "您认为该电影比较一般！\n";
			break;//退出当前分支
		case 5:
			cout << "您认为该电影比较一般！\n";
			break;//退出当前分支
		default ://注意default的使用方法，以及代表的含义
			cout << "您认为该电影实属烂片！！！\n";
			break;//退出当前分支
	}*/
	//if和switch的区别：switch判断中只能为整形或字符型，不能为区间范围
	//                  switch结构清晰，执行效率较高


	//3.2  循环结构
	//3.2.1 while循环 while（循环条件）{循环语句}（只要循环条件为真，就执行循环语句）
	//案例：打印0-9十个数

	/*int num1 = 0;
	while (num1<10)//合理设置循环条件，避免死循环的出现
	{
		cout << num1<<endl;
		num1++;
	}*/
	//案例练习：猜数字（系统随机生成一个数字，让用户去猜，每次猜错之后系统就会反馈猜大了还是猜小了，直到用户猜对为止）
	/*int random, guess;
	//系统生成随机数
	//random=rand() % 100+1;//rand()%100生成的是0-99的随机数；rand()%100+1生成1-100的随机数
	                      //该随机数为伪随机数，固定为42
	//若想生成真正的随机数，需要添加一个随机数种子（利用系统当前的时间来生成一个随机数，防止伪随机数的现象）
	srand((unsigned int)time(NULL));//time需要一个系统时间的头文件
	                                //属于没抄明白，格式要牢记
	random = rand() % 100 + 1;
	//玩家进行猜测
	//对玩家猜测结果进行判断
	while (1)
	{
		cout << "\n请输入您所猜测的数字：\n";
		cin >> guess;//只有在一些条件随着循环每次执行而改变时，循环才有意义
              		//如果输入语句在外面，就相当于输入了一个值，然后让循环一直判断这个数字和随机数的大小关系，就会陷入死循环
		if (guess>random)
		{
			cout << "非常抱歉，您才的数字太大啦！\n";//猜测结果过大
		}
		else if(guess<random)
		{
			cout << "非常抱歉，您才的数字有点小！\n";//猜测结果过小
		}
		else
		{
			cout << "恭喜您，你已经正确猜到了这个数字了！！！\n";
			break;
		}
	}*/
	
	//3.2.2  do...while循环

	//语句格式：do(循环语句)while(循环条件)；do...while 会先执行一次循环语句，再进行循环判断
	//案例：在屏幕中输出0-9 10个数字
	/*int num3 = 0;
	do
	{
		cout << num3<<endl;
		num3++;

	} while (num3<10);*/

	//案例练习：水仙花数（水仙花数是一个3位数，每个位上的数字的3次幂之和等于它本身）
	//每个位之上的三次幂之和等于这个三位数本身，首先要有判断100-999之间的所有水仙花数
	//所以可以定义一个整型数据，初始值为100
	/*int daffodil1=100;
	//之后在一个大循环中，确保是在100-999之间进行判断
	/*do
	{
		int hundred2 = 0, ten2 = 0,unit2 = 0;

		hundred2 = daffodil1 / 100;//百位
		unit2 = daffodil1 % 10;//个位
		ten2 = daffodil1 / 10 % 10;//十位
		int guess = (hundred2*hundred2*hundred2 + ten2*ten2*ten2 + unit2*unit2*unit2);
		if (guess==daffodil1)
		{
			cout << daffodil1 << endl;
		}
		daffodil1++;
	} while (daffodil1>99&&daffodil1<1000);*/
	//while (daffodil1>99&&daffodil1<1000)
	/*{
		//daffodil1 = 100;
		int daffodil = daffodil1;//保持原数字不变
		//需要分别得到它的百位、十位、个位数
		//用取整可以得到，之后再减去相应的整数就可以进行下一步取整
		int hundred = 0;
		//hundred = daffodil1 / 100;
		hundred = (daffodil / 100);//得到百位上的数字
		daffodil = (daffodil - hundred * 100);//减去对应的百位，为得到十位上的数字做准备
		int ten = 0;
		//ten = daffodil1 / 10 % 10;
		ten = (daffodil / 10);//得到十位上的数字
		daffodil = (daffodil - ten * 10);//减去对应的十位，为得到个位上的数字做准备
		int unit = daffodil;//得到个位上的数字
		//int unit = 0;
		//unit = daffodil1 % 10;
		int guess = ((hundred*hundred*hundred) + (ten*ten*ten) + (unit*unit*unit));
			if (guess==daffodil1)
			{
				cout << daffodil1<<endl;
			}
		daffodil1++;
	}
	/*总结：1.首先是对于函数格式包括一些语句书写一定要正确，这次大问题出在if判断语句的相等判断与赋值判断搞混了‘
	        2.其次是逻辑必须清晰，编写程序要知道第一步、第二步、第三步每一步要干啥，尽量提前缕清思路在进行编写；
			     比如这次的水仙花数，就应该有个框架，首先要确保所有的数是三位数，其次再考虑水仙花数的情况
						而在考虑水仙花数的情况中，要找到方法取到个位、十位、百位的数字（此处对于取整与取模的运算没有理解透彻）
				 在取到水仙花数之后，才能进行判断，使用if条件语句，书写出错没有及时找出*/


	//3.2.3   for循环语句（满足循环条件，执行循环语句）（for(循环语句){循环体}）

	/*for (int i = 0; i < 10; i++)//输出0-9 10个数字，注意判断条件
{
	cout << i << endl;
}//语句执行步骤：0➡1➡2➡3➡1...直到不满足循环条件为止*/
	//示例;敲桌子（过7）
	//首先是要在0-100内进行过7，所以要确定一个大的循环范围
		//可以利用for进行总体上的循环
	//之后是要对所爆出的数字进行查验，如果是与7相关，要输出惩罚措施
			//如果没有讲出7，那么就不用接受该惩罚（讲出与没讲出可以用键盘输入来确定）
	/*for (int i = 1; i <= 100; i++)//注意小于等于号的书写方式
	{
		//可以利用if...else语句对过7中的几种情况进行判断
			//包括：个位有7；十位有7；7的倍数
					//个位有7的情况可以求出个位数字与七比较，（十位同样）Tips：求个位与十位的方法与水仙花数中的方法相同
			//可以先求出一个数字的个位与十位，之后再进行比较
		int unit3 = 0, ten3 = 0;//设置变量存储一个数字个位与十位的值
		unit3 = i % 10;
		ten3 = i / 10 ;//此方法要牢记
		int m = (i % 7);//7的倍数情况
		if (unit3==7|| ten3 == 7||m==0)
		{
			cout << "Konck,konck!" << endl;
		}//注意合并判断条件
		else { cout << i << "\t"; }//注意对情况的分析，路基必须严谨
									//区分情况，选择循环，这种属于符合条件 Knock，不符合条件打印，所以是二选一的情况，应该用if...else
									//使用if是针对一种情况，而此时明显有两个结果，所以不能使用if
	}
	cout << endl;*/

	//3.2.4 嵌套循环（在循环中嵌套一些循环）（使用较广）

	/*for (int i = 0; i <10; i++)
	{
		for (int j = 0; j < 10; j++)//两个循环不使用同一个变量
		{
			cout << "*\t";
		}
		cout << endl;//每十个换一行
				 //书写程序，要对每一个功能进行分析，稍有不慎就容易出现问题
	}
	cout << endl;*/

	//示例：乘法口诀表

	/*//功能分析：乘法口诀表可以看作为单位进行输出
				//按行输出过程中遵循：每一行的表达式数目等于行值，即第一行一个表达式；第二行两个表达式
						//输出每一行的表达式可以用一个for循环
							//Tips：每一行输出完之后要进行换行，每一个表达式输出完之后，要与下一个表达式之间有间隔
	//整体用一个大的for循环进行	
	for (int i = 1; i < 10; i++)//总共从一到九，九个数字，所以i起始值为1，不超过10
								//大循环是以行数为准
	{
		for (int j = 1; j <= i; j++)//小循环是以列数为准
									//每一行的表达式个数为改行行值，行值就是i
									//注意此处的判断条件
									//进行大于小于之类的判断时，一定要谨慎，仔细考虑有没有等号的情况
		{
			cout << j << "*" << i << "=" << (j * i) << "\t";//此时只是输出了一个表达式，所以不能换行
		}
		cout << endl;//换行应该在一行表达式输出完成之后进行
	}
	cout << endl;*///最后加一个换行是为了美观

	//3.3 跳转语句
	//3.3.1 Break语句（用于跳出选择结构或循环结构）
		//Break出现的情况：
	//情况一：出现在switch选择语句中，作用是中止case，跳出switch
	/*//示例：副本难度选择
	cout << "当前副本难度有：1—简单；2—普通；3—困难\n";
	cout << "请输入您选择的副本难度：\n";
	int select;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "您选择的是简单难度！\n";
		break;
	case 2:
		cout << "您选择的是普通难度！！\n";
		break;
	case 3:
		cout << "您选择的是困难难度，请您做好准备！！！\n";
		break;
	default:
		break;
	}*/

    //情况二：出现在循环语句中，跳出当前循环
	/*for (int i = 0; i < 100; i++)
	{
		if (i == 6)
		{
			break;
		}
		cout << i << endl;//单层循环中，break的出现地点就可以随意
						  //break出现在循环语句前，在满足break的条件时不会再执行循环语句
						  //break出现在循环语句后，在满足break的条件时会再执行依次循环语句
	}*/

	//情况三：出现在嵌套中，跳出内层循环
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "*\t";
			if (j==5)
			{
				break;
			}
		} //break前置和后置的区别在于循环多执行一次
		 //该例中，break后置，就会导致在j==5时先执行一次内部循环，再进行打印
		//但是，break的判断是与j相关，所以break只能在循环之后
		cout << endl;
	}*/

	//3.3.2continue语句（再循环语句中，跳过本次循环中尚未执行的其他语句，转而执行下一次循环）
	//continue可以筛选条件
	//案例：
	/*for (int i = 0; i <=100; i++)
	{
		//偶数输出
		if (i%2==0)
		{
			cout << i << endl;
		}
		else
		{
			continue;
		}//注意代码的简洁，二选一情况下，可以使用continue对一种情况进行摘除
		//改进后的代码
		if (i%2!=0)
		{
			continue;
		}
		cout << i<<endl;
		
	}*/

	//3.3.3 go to语句(可以无条件的跳转语句)
	//语法：goto 标记（一般用大写标识）（尽量不使用，避免出错）
	//代码示例：
	/*cout << "1.第一行代码\n";
	goto FLAG;
	cout << "2.第二行代码\n";
	cout << "3.第三行代码\n";
	cout << "4.第四行代码\n";
	FLAG:
	cout << "5.第五行代码\n"; 
	cout << "6.第六行代码\n";*/
	
	system ("pause");/*系统框架，目前尚未解释*/

	return 0;
}