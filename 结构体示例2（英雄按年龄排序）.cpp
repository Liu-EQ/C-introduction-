#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//Ӣ�۰���������
//1.����һ��Ӣ�۽ṹ�壬Ȼ������һ��Ӣ������
struct Hero
{
	string Name;//����
	int   Age;//����
	int  Pow;//ս��
};

void BubbleSort(struct Hero * Heros,int length);//��ð�������Ѿ��������
			//������������ܼ򵥵Ķ��������˳����ģ�Ӧ�ö���һ����ʱ��Ӣ�۽ṹ�����

int   main() 
{
	Hero Heros[5];//����Ӣ������
	int length = sizeof(Heros) / sizeof(Heros[0]);
	cout << length << endl;
	//2.����Ӣ����Ϣ
	//�������÷���ѭ���������Ӣ����Ϣ���������루�����ֶ������ˣ�
	string nameSeed = "ABCDE";//��������
	srand((unsigned int)time(NULL));//���������
	for (int i = 0; i < length; i++)
	{
		Heros[i].Name = "Hero";
		Heros[i].Name += nameSeed[i];//ע��nameSeed��д������ʱ������Ϣ�������
		//��ʼ����������Ϣ,�������������������
		int random1 = rand() % 20+20;//��ʱӢ����������Ϊ20-39
		Heros[i].Age = random1;
		//��ʼ����ս����Ϣ��ͬ��������������ɷ�
		int random2 = rand() % 50000 + 1000;//��ʱӢ��ս������Ϊ��1000-59999
		Heros[i].Pow = random2;//��ʱΪα�����������Ҫ��һ����������ӹ����������
	}//��ʱ�ѽ�Ӣ����Ϣ�������
	cout << "����ǰ��Ӣ����ϢΪ��\n";
	for (int i = 0; i < length; i++)
	{
		cout << Heros[i].Name << "\t" << Heros[i].Age << "\t" << Heros[i].Pow << "\t" << endl;
	}//���δ����֮ǰ��Ӣ����Ϣ
	//3.����ð�������㷨����Ӣ������Ϊ��׼��������
	//�������ȹ���һ��ð�������㷨
	BubbleSort(Heros,length);//����ð��������
	//ʹ��for�������������Ӣ����Ϣ
	cout << "������Ӣ����ϢΪ��\n";
	for (int i = 0; i < length; i++)
	{
		cout << Heros[i].Name << "\t" << Heros[i].Age << "\t" << Heros[i].Pow << "\t" << endl;
	}//�������֮���Ӣ����Ϣ�����Ƚ�





	cout << endl;
	system("pause");
	return 0;
}

void BubbleSort(struct Hero  * Heros , int length)//�������������Ӣ��������׵�ַ
{
	for (int i = 1; i < length; i++)//��ıȽ��ִε�ѭ��
									//�Ƚ��ִ�=��������-1
	{
		for (int j = 1; j <= length-i; j++)//һ���ִ��бȽϴ�����ѭ��
										  //ÿһ�˱Ƚϴ���=��������-��ǰ�Ƚ��ִ�
		{
			if (Heros[j-1].Age>Heros[j].Age)//�Ƚϱ�׼������Ӣ������
			{
				Hero temp;
				//����ϴ��Ӣ�۱�����ֵ������ʱ����
				temp.Name = Heros[j - 1].Name;
				temp.Age = Heros[j-1].Age;
				temp.Pow = Heros[j - 1].Pow;
				//�����С�ߵ�Ӣ�۱���ֵ��������ϴ��ߵ�Ӣ�۱���
				Heros[j-1].Name = Heros[j].Name;
				Heros[j - 1].Age = Heros[j].Age;
				Heros[j - 1].Pow = Heros[j].Pow;
				//temp����ֵ���������С�ߵ�Ӣ�۱���
				Heros[j].Name = temp.Name;
				Heros[j].Age = temp.Age;
				Heros[j].Pow = temp.Pow;
				//˳��������
			}//����ʱ��Ӣ�۱�������������

		}
	}
}
				//ð��ѭ���ڲ����Ƚϴ���Ҫ�μǣ�������⣺
									//���Ƚ��ִ�ѭ������=��������-1��һ��ѭ���ó�һ�����������ôn-1��ѭ���͵ó�ǰn-1���������ʣ�����ȻΪ��Сֵ��
									//�ڲ�Ƚ�ѭ������=��������-��ǰ�Ƚ��ִΣ�ÿһ�˵ó�һ�����������һ�˾ͻ���һ�����ֲ���Ƚϣ�n������n-1�αȽϵó��������
				//ͬ������ַ������Ҫ�ú���⣬ָ������Ķ��巽ʽ���������� * �������������𣩣�����ָͨ�붨�岢������
