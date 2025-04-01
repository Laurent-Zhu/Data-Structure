#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int date;
    struct node* pre;
    struct node* next;
}node, * pnode;
void insert(pnode list, int date) {
    //β�巨�����������Ԫ�� 
    pnode p = list;
    if (p == NULL) {
        return;
    }
    else {
        while (p->next) {
            p = p->next;
        }
        pnode pnew = (pnode)malloc(sizeof(node));
        pnew->date = date;
        p->next = pnew;
        pnew->pre = p;
        pnew->next = NULL;
    }
}
void tranverselist(pnode list, int n) {
    //�����������ָ��λ����С�� 
    pnode p = list;
    p = p->next;
    printf("%d.", p->date);
    int i;
    p = p->next;
    for (i = 0; i < n; i++) {
        printf("%d", p->date);
        if (p->next) {
            p = p->next;
        }
    }
    printf("\n");
}
int main()
{
    pnode num;//numΪÿ����ӵ� R(n); 
    pnode sum;//sum���յ�ֵԼ���� ����
    num = (pnode)malloc(sizeof(node));
    sum = (pnode)malloc(sizeof(node));
    num->pre = NULL;
    sum->pre = NULL;
    num->next = NULL;
    sum->next = NULL;
    //nΪ��ĿҪ������ĵĦ���С��λ���� 
    int n;
    scanf_s("%d", &n);
    //��������600λ�����м���,��Ϊ�ҵľ���Ҫ�ﵽ500 
    int i;
    for (i = 0; i < 12000; i++) {
        insert(num, 0);
        insert(sum, 0);
    }
    //p1,p2Ϊָ�����������ָ�� 
    pnode p1 = num->next;
    pnode p2 = sum->next;
    //ʹ���������ͷ�ڵ����һ���ڵ������Ϊ2������ֱ�Ӵ�R2��ʼ���㣬���˼��� 
    p1->date = 2;
    p2->date = 2;
    //ָ��num,��sum��β�ڵ�
    while (p1->next) {
        p1 = p1->next;
    }
    pnode numtail = p1;
    while (p2->next) {
        p2 = p2->next;
    }
    pnode sumtail = p2;
    //��ʼ���㣻 
    int temp = 0;//��������в�������ʱ���� 
    int ret = 0; //��������в����Ľ�λor��λ
    int t;//����ʱ�й��ɳ��ֵĳ��� (2n+1)
    for (i = 1, t = 3; i < 10000; i++, t = t + 2) {//������ѧ��֪ʶ����Ĵ���Խ��Խ��ȷ 
        //iͬʱ�е������������������� 
        //�ȼ���˷�������ʽ��R(n)*n�� 
        pnode p3 = numtail;
        ret = 0;
        while (p3) {
            temp = p3->date * i + ret;
            p3->date = temp % 10;
            ret = temp / 10;
            p3 = p3->pre;
        }
        ret = 0;
        p3 = num->next;
        //������� (����ʽ�е�R(n)*n/(2*n+1))
        while (p3) {
            temp = p3->date + ret * 10;
            ret = temp % t;
            p3->date = temp / t;
            p3 = p3->next;
        }
        ret = 0;
        pnode  p4 = sumtail;
        p3 = numtail;
        //���õ���R(n)��ֵ���뵽����� 
        while (p3 && p4) {
            temp = p3->date + p4->date + ret;
            ret = temp / 10;
            p4->date = temp % 10;
            p3 = p3->pre;
            p4 = p4->pre;
        }
    }
    tranverselist(sum, n);
    return 0;
}
