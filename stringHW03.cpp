//����һ��˳��s�����ַ��������ֺ�Сд��ĸ��ɡ����һ���㷨����s�е����������ַ�����ǰ�벿�֣�������Сд��ĸ�ַ����ں�벿�֣��������㷨��ʱ��Ϳռ临�Ӷȡ�
#include<iostream>
#define MAXLEN 40
using namespace std;
struct sstring {
	int len;
	char str[MAXLEN];
};

void strlength(sstring& s)
{
	int i;
	for (i = 0; s.str[i] != '\0'; i++)
	{
	}
	s.len = i;
}

bool process(sstring& s)//ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
{
	int i, j;
	char temp;
	for (i = 0, j = s.len - 1; i < j;)//����ָ��ֱ���ַ���ͷ��β������ǰ��
	{
		if (s.str[i] >= 97 && s.str[i] <= 122 && s.str[j] >= 48 && s.str[j] <= 57)//ǰΪ��ĸ����Ϊ���֣�������ǰ��ָ��������ǰ��һλ
		{
			temp = s.str[i];
			s.str[i] = s.str[j];
			s.str[j] = temp;
			i++;
			j--;
		}
		else if (s.str[i] >= 48 && s.str[i] <= 57 && s.str[j] >= 97 && s.str[j] <= 122)//ǰΪ���֣���Ϊ��ĸ����������ǰ��ָ��������ǰ��һλ
		{
			i++;
			j--;
		}
		else if (s.str[i] >= 48 && s.str[i] <= 57 && s.str[j] >= 48 && s.str[j] <= 57)//ǰ���Ϊ���֣���������ǰָ��������һλ
		{
			i++;
		}
		else if (s.str[i] >= 97 && s.str[i] <= 122 && s.str[j] >= 97 && s.str[j] <= 122)//ǰ���Ϊ��ĸ������������ָ����ǰ��һλ
		{
			j--;
		}
		else//���������ʾ��������
		{
			return false;
		}
	}
	return true;
}

int main()
{
	sstring s;
	s.len = 0;
	cout << "����һ���ַ�����ֻ��Сд��ĸ�����֣���";
	cin >> s.str;
	strlength(s);
	bool x = process(s);
	if (x == 0)
	{
		cout << "�ַ���δ��Ҫ�����룡" << endl;
		return 0;
	}
	cout << "�����е����ַŵ�Сд��ĸǰ�����ַ���Ϊ��" << s.str << endl;

	return 0;
}