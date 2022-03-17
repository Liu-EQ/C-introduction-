#include<iostream>
#include<string>
using namespace std;



#define MAX 1000//���ں���ά�����޸�
				//�����󲻼ӷֺ�***


//����һ����ϵ�˽ṹ��:�����������Ա����䡢��ͥסַ����ϵ��ʽ
struct Friend{
	string Name;
	string Sex;
	int Age;
	string Address;
	long long Tel;
};

//ͨѶ¼�ṹ��
struct AddressBook 
{
	struct Friend Friends [MAX] = {};//����һ����ϵ�����������洢��ϵ����Ϣ
	int length = 0;//�����ʼΪ�����ԣ��������ʼ����Ϊ0
};

void showMenu();//�˵�����

void Print(struct AddressBook * Book);//��ʾģ�麯������

void Add(struct AddressBook * Book, int  length);//����ģ������

int Find1(struct AddressBook Book, string FindName);//�Ӳ��Һ���
void Find(struct AddressBook Book,string FindName);//���Һ�������

void Del(struct AddressBook * Book, string DelName);//ɾ����������

void Modify(struct AddressBook * Book, string ModName);//�޸ĺ�������

int main() 
{
	//����ͨѶ¼����ϵͳ���а˸����ܣ�����д�˸�����ģ������Ӧʵ�֣���ӡ���ʾ��ɾ�������ҡ��޸ġ���ա��˳���
			//���ǰ˸�����ģ�鹲��һ��������Ϣ�������й�������Ϣ�����ģ����Ҫ�����������н���ʵ��
			//��ѯ����ʾ���Է��ļ����б�д
	AddressBook Book1;//����һ��ͨѶ¼����
	Book1.length = 0;

	showMenu();//���ò˵�����
	cout << "��ӭʹ����ľͨѶ¼ϵͳ������������ʹ�õĹ���" << endl;
	//���������Ϊһ����ϵ�����飬���鳤��Ϊһǧ��ͬʱ�������ڲ���Ա����Ϊ�ṹ����������й����ݶ���Ķ���
	//�������ͨ��һ��switch�������й���ѡ���û�ͨ���������ֽ��ж�Ӧ�Ĺ���ѡ��
	int select;//����ѡ��
	while (true)
	{
		cin >> select;
		switch (select)
		{
		case 0://�˳�ģ��
				//��ģ��ɲ�����������0��ֱ��break
			cout << "��ӭ�´�ʹ�ã�����" << endl;
			system("pause");
			return 0;//ע����ѭ����ν���
			break;
		case 1://��ʾģ��
			//��ģ���ʹ������forѭ���������
			//���Է��ļ���д��
			Print(&Book1);//������ʾ����ģ��
			break;
		case 2://����ģ��
			//��ģ��Ӧ�ð���һ����ʾ������䣬һ����Ϣ���룬��lengthֵΪ����λ�ã�ͬʱ������ɺ����length
			Add(&Book1,Book1.length);//���Ӻ�������
			break;
		case 3: 
		{//����ģ��
			//��ģ������ṩ�û�������ϵ������������ϵ��ʽ���ַ�ʽ���в�ѯ
			//���û��������в�ѯ����Ҫһ���ַ����ȽϺ���
			//�ַ����ȽϺ�����Ҫ�ȶ���һ���ַ�������������ʱ�洢�û��������ϵ��������֮����Խ���ǿ������ת��Ȼ������
			//���û���ϵ��ʽ���в�ѯ��Ҫһ���򵥵ıȽϺ���
			string FindName;//��ʱ��������ʱ�洢�û�Ҫ���ҵ���ϵ�˵�����
			cout << "��������Ҫ���ҵ���ϵ��������" << endl;
			cin >> FindName;
			Find(Book1, FindName);//���ò���ģ��
			break; }
		case 4:
		{//�޸�ģ��
			string ModName;
			cout << "��������Ҫ�޸ĵ���ϵ��������";
			cin >> ModName;
			Modify(&Book1,ModName);
			break; }
		case 5:
		{//ɾ��ģ��
			string DelName;//��ɾ������ϵ������
			cout << "������Ҫɾ������ϵ������" << endl;
			cin >> DelName;
			Del(&Book1, DelName);//��Book1��ɾ������ΪDelName����ϵ��
			break; }
		case 6://���ģ��
			//��ģ��ֻ�ý�lengthֵ���и��ļ���
			cout << "��ȷ��ɾ������ϵ����Ϣ��(Y/N)" << endl;
			char answer;
			cin >> answer;
			if (answer == 'Y') Book1.length = 0;//��ʱ��ϵ������Ĭ���Ǵӵ�0����ʼ
			system("pause");
			system("cls");
			break;

		default:
			break;
		}
		showMenu();//���ò˵�����
		cout << "��������Ҫʹ�õĹ���ѡ�" << endl;
	}
	
	cout << endl;
	return 0;
}

//�˵�չʾ
void showMenu()
{
	cout<< "*************************"<<endl
		<< "***** 0-�˳�ͨѶ¼ *****" << endl
		<< "***** 1-��ʾ��ϵ�� *****" << endl
		<< "***** 2-������ϵ�� *****" << endl
		<< "***** 3-������ϵ�� *****" << endl
		<< "***** 4-�޸���ϵ�� *****" << endl
		<< "***** 5-ɾ����ϵ�� *****" << endl
		<< "***** 6-���ͨѶ¼ *****" << endl
		<< "*************************"<<endl;
}

//��ϵ����ʾ
void Print(AddressBook * Book)
{
	if (Book->length == 0)
	{
		cout << "��ͨѶ¼��¼Ϊ�գ�����������ϵ����Ϣ������" << endl;
	}
	else
	{
		for (int i = 0; i < Book->length; i++)//ʹ������forѭ��������Ϣ���
								//���forѭ���Ƕ�������ϵ�˽������
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

//�����ϵ��
void Add(struct AddressBook * Book, int length)
{
	//��������
	if (Book->length==MAX)
	{
		cout << "ͨѶ¼�ռ��������޷����������ϵ�ˣ�����" << endl;
		return;//if...elseҪ���ô��ڣ���������ѭ��
	}
	else
	{
		//����Ҫ�����û�������Ϣ����
		cout << "������������ϵ�˵��������Ա����䡢��ַ����ϵ��ʽ" << endl;
		cin >> Book->Friends[Book->length].Name >> Book->Friends[Book->length].Sex >> Book->Friends[Book->length].Age
			>> Book->Friends[Book->length].Address >> Book->Friends[Book->length].Tel;//ָ��ʹ�ü�ͷ������ָ�����ĳ�Ա����
																					  //�������ʹ��.�����ó�Ա����
		Book->length++;
		cout << "��ϵ����ӳɹ�!" << endl<<endl;
		cout << "ĿǰͨѶ¼����" << Book->length << "λ��ϵ�ˣ�" << endl

			<< "���ɼ������" << 1000 - Book->length << "λ��ϵ��!" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}


}

//������ϵ��,���ڷ�����ϵ���±겢�������ϵ����Ϣ�������ڷ���-1
void  Find(AddressBook Book,string FindName)//���������ң��β���Ӧ������������
{
	//���forѭ�����Ʋ��ҷ�Χ
	//�ڲ�if�����о������
	int i1 = Find1(Book,FindName);
	if (i1!=-1)
	{
		cout << "����ϵ������ͨѶ¼�е�" << i1 + 1 << "λ����" << endl;
		cout << "����ϵ�˵���ϢΪ��" << endl;
		cout << Book.Friends[i1].Name << "\t"
			<< Book.Friends[i1].Sex << "\t"
			<< Book.Friends[i1].Age << "\t"
			<< Book.Friends[i1].Address << "\t"
			<< Book.Friends[i1].Tel << endl;
		system("pause");
		system("cls");

	}
	
}

//ɾ����ϵ�ˣ����õ��Ӳ��Һ���
void Del(AddressBook * Book, string DelName)
{
	int temp = Find1(*Book,DelName);//����ֱ������
	if (temp!=-1)
	{
		cout << "��ȷ��ɾ������ϵ����Ϣ��(Y/N)" << endl;
		char answer;
		cin >> answer;
		if (answer == 'Y')
		{
			for (int j = temp; j < Book->length; j++)//�ø��Ǵ���ɾ��
			{
				/*Book->Friends[j].Name = Book->Friends[j + 1].Name;
				Book->Friends[j].Sex = Book->Friends[j + 1].Sex;
				Book->Friends[j].Age = Book->Friends[j + 1].Age;
				Book->Friends[j].Address = Book->Friends[j + 1].Address;
				Book->Friends[j].Tel = Book->Friends[j + 1].Tel;*/
				Book->Friends[j] = Book->Friends[j + 1];
			}
			cout << "��ϵ��ɾ���ɹ���" << endl;
			system("pause");
			system("cls");	
			Book->length--;
		}
	}
	
}

//�޸���ϵ�ˣ�ͬ��ʹ���Ӳ��Һ���
void Modify(AddressBook * Book, string ModName)
{
	int temp = Find1(*Book, ModName);//�������ҵ�����ϵ��
	if (temp!=-1)
	{
		Friend ModFriend;//��ʱ������ʱ�洢���޸���ϵ�˵���Ϣ
		cout << "���������ϵ�˵�����Ϣ(�������Ա����䡢��ַ���绰)��" << endl;
		cin >> ModFriend.Name >> ModFriend.Sex >> ModFriend.Age >> ModFriend.Address >> ModFriend.Tel;
		cout << endl;
		/*Book->Friends[temp].Name = ModFriend.Name;
		Book->Friends[temp].Sex = ModFriend.Sex;
		Book->Friends[temp].Age = ModFriend.Age;
		Book->Friends[temp].Address = ModFriend.Address;
		Book->Friends[temp].Tel = ModFriend.Tel;*/
		Book->Friends[temp] = ModFriend;//�ṹ�帳ֵ����
		cout << "��ϵ����Ϣ�޸ĳɹ���" << endl;
		system("pause");
		system("cls");
	}
}

//�Ӳ��Һ��������ҵ����ظ���ϵ���±꣬δ���ҵ�����-1
int Find1(struct AddressBook Book, string FindName)
{
	for (int i = 0; i < Book.length; i++)//��ѭ������������ϵ����Ϣ�н��в���
	{
		if (FindName == Book.Friends[i].Name)//�Ƚ�ĳ����ϵ�˺�Ҫ���ҵ���ϵ�������Ƿ�һ�£�����ֱ�ӿ������ַ����ȽϺ����𣿣���
		{
			return i;//���ҵ������±�β���ҵ�����-1
		}
	}
	cout << "�����ϵ���б���û�и���ϵ�˵���Ϣ��������Ӹ���ϵ����Ϣ��" << endl;
	system("pause");
	system("cls");
	return -1;//ע�����forѭ��ִ��˳���Լ�if�������:
					//forѭ��ʱ����ѭ����ʱʲô��ֻҪfor�ж������ϣ��ͻ�һֱִ�У���˲��õ��������ѭ���������ת����һ���ж�
					//����if����ֻ��������������ִ��ѭ������䣬����for+if����ʵ����һ����Χ��Ѱ������ĳһ�����������
										//�Ҹ���Ѱ�ҷ���������forѭ�������õ����Ƿ������������Χ
										//�����ڽ���ķ����ϣ��ҵ�����һ���������Ҳ�������һ�������������Ҫ��if�����ú�������
}//�Ӳ��Һ������޶�����Ϣ����

