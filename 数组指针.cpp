#include<iostream>
#include<string>
using namespace std;

struct Hero
{
	string Name;//����
	int   Age;//����
	int  Pow;//ս��
};

int main()
{

	int arr[5] = { 1,2,3,4,5 };
	int * p = arr;
	cout << p[2]<<endl;
	struct Hero Heros[2] = {
		{"����",25,260},
		{"����", 26,310},
	};
	cout << Heros[1].Name<<endl;
	struct Hero  * Heros2 = Heros;
	Heros2[1].Name = "AAA";//����ͨ����ָ�����޸Ľṹ��������ĳԪ��ĳ����Ա������ֵ
	cout << Heros[1].Name<<endl;
	cout << Heros2[1].Name;//����ͨ��ָ��������ṹ��������ĳ��Ԫ��ĳ����Ա������ֵ
	cout << endl;
	system("pause");
	return 0;
}