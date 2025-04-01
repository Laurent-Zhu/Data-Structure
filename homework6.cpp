//问：假设有一个长度大于1的带头结点的循环单链表A，某个结点的next指针指向后继结点，但prior指针都是NULL，设计一个算法修复适应结点的prior指针值。
// 第六题可以理解为，通过前向指针prior，把循环单链表补成循环双链表，这道题说明得可能不是很清楚，按照补全来做
//答：老师，本题我仅写核心算法，不再写完整的程序了。代码如下。
struct CLinklist
{
	int data;
	CLinklist* next,*prior;
	CLinklist(int x):data(x),next(nullptr),prior(nullptr){}
};
void Repair(CLinklist*& Ahead)//此处为核心代码
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
	//此处省略
}
int main()
{
	CLinklist* Ahead;
	CreateList(Ahead);
	Repair(Ahead);
}
