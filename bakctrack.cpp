//���ݷ�
//�б��ʽΪ1��2��3��4�����С�Ϊ�����߸��ţ����û��ݷ�����ñ��ʽ����ֵΪ4�����б��ʽ��
#include<iostream>
using namespace std;

int a[] = {1,2,3,4};
char x[4];

void solution(int i, int sum)
{
	if (i == 3)
	{
		if (abs(sum) == 4)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%d", a[j]);
				printf("%c", x[j]);
			}
			printf("=%d\n", sum);
		}
		return;
	}
	x[i] = '+';
	sum += a[i + 1];
	solution(i + 1, sum);
	sum -= a[i + 1];
	x[i] = '-';
	sum -= a[i + 1];
	solution(i + 1, sum);
	sum += a[i + 1];
}

int main()
{
	int sum = 1;
	cout << "����ֵΪ4�ı��ʽ�У�" << endl;
	solution(0, sum);

	return 0;
}