//�ʣ�������һ�����ȴ���1�Ĵ�ͷ����ѭ��������A��ĳ������nextָ��ָ���̽�㣬��priorָ�붼��NULL�����һ���㷨�޸���Ӧ����priorָ��ֵ��
// ������������Ϊ��ͨ��ǰ��ָ��prior����ѭ����������ѭ��˫���������˵���ÿ��ܲ��Ǻ���������ղ�ȫ����
//����ʦ�������ҽ�д�����㷨������д�����ĳ����ˡ��������¡�
struct CLinklist
{
	int data;
	CLinklist* next,*prior;
	CLinklist(int x):data(x),next(nullptr),prior(nullptr){}
};
void Repair(CLinklist*& Ahead)//�˴�Ϊ���Ĵ���
{
	CLinklist* prev = Ahead, * curr = Ahead->next;
	curr->prior = prev;
	prev = curr;
	curr = curr->next;
	while (prev != Ahead)
	{
		curr->prior = prev;
		prev = curr;
		curr = curr->next;
	}
}
void CreateList(CLinklist*& Ahead)
{
	//�˴�ʡ��
}
int main()
{
	CLinklist* Ahead;
	CreateList(Ahead);
	Repair(Ahead);
}
