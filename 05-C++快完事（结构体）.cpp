#include<iostream>
#include<string>
using namespace std;

//7.0�ṹ��
//7.1�ṹ��Ĵ���
//ʾ��������һ��ѧ���������ͣ��������ѧ��ѧ�ţ��������Ա𣬰༶��
//7.1.1�ṹ�����������壩
struct  student
{
	//��Ա�б�
	int ID;
	string Name;
	string Sex;
	int Class;
};//������ֱ����}���һ����������}s3���������ʹ�����һ��s3����

//Ƕ�׽ṹ��
struct  teacher
{
	int ID;
	string Name;
	int age;
	struct  student stu;//Ƕ�׽ṹ�壨ʹ����һ���ṹ����Ϊ���ṹ��ĳ�Ա��
		 
};

//��ӡѧ����Ϣ�ĺ���
void Print(struct student s1);

//��ַ���ݸ���ѧ������
void Modify(struct  student * s1,string Name);

int main() 
{
	/*//ͨ��ѧ���������ʹ����������
	struct  student s1;
	{
		s1.ID = 170902316;
		s1.Name = "����";
		s1.Class = 5;
		s1.Sex = "��";

	};//��һ(Ҳ����ʡ��s1.��ֱ�Ӹ���ֵ={170902316,����...})
	  //������������ֵ���ȴ����ýṹ�������struct student s1��֮���ٸ���ֵ��s1.Name=....
	 //ǰ����ʹ�ý϶�
	 //Tips���ṹ���������������ʡ�Թؼ��� struct����student s1���ǿ��Եģ�
			//�ṹ�����ʹ��'.'�����ʳ�Ա����
	cout << "������" << s1.Name << "\n"
		<< "ѧ�ţ�" << s1.ID << "\n"
		<< "�༶:" << s1.Class << "\n"
		<< "�Ա�" << s1.Sex << "\n";*/

	//7.2�ṹ�����鴴����ʽ
	//�﷨��struct �ṹ���� ��������Ԫ�ظ�����={{},{}��{}��{}....}
	//ʾ����
	struct  student Class5[3]=
	{
		{170902317,"����","��",5},
		{170902318,"����","��",5},
		{170902319,"����","Ů",5},
	};
	//��ֵ�����
	Class5[1].Name = "����";
	/*for (int i = 0; i < 3; i++)
	{
		cout << Class5[i].Name <<"\t";
		cout << Class5[i].ID << "\t";
		cout << Class5[i].Sex << "\t";
		cout << Class5[i].Class << "\t" << endl;

	}*/


	//7.3 �ṹ��ָ�루->��
	//ͨ��ָ��ṹ���ָ�������ʽṹ���еĳ�Ա
	student * Pstu = Class5;//�Ⱥ�������������Ӧ����ͬ
	Pstu->Name = "����";
	//cout << Class5[0].Name << endl;

	//7.4 Ƕ�׽ṹ��
	teacher teacher;
	teacher.Name = "��̫��";
	teacher.ID = 10046;
	teacher.age = 41;
	teacher.stu.Class = 5;
	teacher.stu.Name = "������";
	teacher.stu.ID = 10095;
	teacher.stu.Sex = "��";
	//cout << teacher.Name << "��ʦ��ѧ���ǣ�" << teacher.stu.Name << endl;


	//7.4 �ṹ����Ϊ��������
	//�ṹ���ֵ���ݺ͵�ַ����
	//Print(Class5[2]);//ֵ����
	Modify(&Class5[0],"����");//��ַ����
	//cout << Class5[0].Name<<endl;
				//ע�⴫���ʽ����д��ʽ����Ҫ������ϰ��ͬ���ַ����Ҳ���޸�ʵ�ε�ֵ
				//�������е��βθ�Ϊָ����Լ����ڴ�ռ��ռ�ã��Ҳ��Ḵ���µĸ�����ʹ�ü�ͷ���ʳ�Ա������

	//7.5 �ṹ���� const��ʹ�����
	//constʹ�ó���
	student teststu;
	teststu.Name = "·�˼�"; teststu.ID = 00001; teststu.Class = 3; teststu.Sex = "��";
	//�����β��鴫���ַʱ�������ڲ����Զ�ʵ�ε�ֵ�����޸ģ����Ǽ���const֮�����ڲ��Ͳ����Զ���Щֵ�����޸�
	Modify(&teststu,"·����");//const�Ǽ��ں������岿�ֵĵĲ���֮��



	cout << endl;
	system("pause");
	
	return 0;
}

void Print(student s1)
{
	cout << "��ѧ��������Ϊ��" << s1.Name << endl;
	cout << "��ѧ���İ༶Ϊ��" << s1.Class << endl;
	cout << "��ѧ����ѧ��Ϊ��" << s1.ID << endl;
	cout << "��ѧ�����Ա�Ϊ��" << s1.Sex << endl;
}

void Modify( student * p, string Name)
{
	cout << "�޸�ǰѧ������Ϊ��" << p->Name << endl;
	p->Name = Name;
	cout << "�޸ĺ�ѧ������Ϊ��" << p->Name << endl;
}//��ַ���ݴ�����ǵ�ַ�����Է���ʱӦ��ͨ����ͷ��->�����з��ʣ���������ͨ����.��
