#include <stdio.h>
#include <malloc.h>
#include <limits.h>

typedef int ElemType;

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkList;

//头插法创建空链表
void headCreatLinkList(LinkList &L, ElemType enterArray[], int enterArrayLength)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < enterArrayLength; i++)
    {
        LinkNode *pNode = (LinkNode *)malloc(sizeof(LinkNode));
        pNode->data = enterArray[i];
        pNode->next = L->next;
        L->next = pNode;
    }
}

//尾插法创建空链表
void tailCreatLinkList(LinkList &L, ElemType enterArray[], int enterArrayLength)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    LinkNode *pTail = L;
    for (int i = 0; i < enterArrayLength; i++)
    {
        LinkNode *pNode = (LinkNode *)malloc(sizeof(LinkNode));
        pNode->data = enterArray[i];
        pNode->next = NULL;
        pTail->next = pNode;
        pTail = pNode;
    }
}

//输出链表
void printfLinkList(LinkList L)
{
    LinkNode *pNode = L->next;  //有头结点输出
    // LinkNode *pNode = L;     //无头结点输出
    while (pNode != NULL)
    {
        printf("%d ", pNode->data);
        pNode = pNode->next;
    }
    printf("%\n");
}

//递归求链表中最大整数
ElemType maxElem(LinkNode *p)
{
    if (p == NULL)
    {
        return INT_MIN;
    }
    return p->data > maxElem(p->next) ? p->data : maxElem(p->next);
}

//递归求链表中的结点数
int nodeNum(LinkNode *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return 1 + nodeNum(p->next);
}

//递归求链表所有元素的平均值  1.求和
ElemType sum(LinkNode *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return p->data + sum(p->next);
}
//递归求链表所有元素的平均值  2.求平均值
double average(LinkNode *p)
{
    return sum(p) / (double)nodeNum(p);
}

//单链表访问第i个结点   1.我的
ElemType getIthElem(LinkList L, int i)
{
    LinkNode *p = L->next;
    while (--i&&p!=NULL)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        return INT_MIN; //不存在i结点
    }
    return p->data;
}
//单链表访问第i个结点   2.书上的
void getIthElement(LinkList L,int ith,ElemType &e){
    LinkNode *p=L;
    int cnt=0;
    while(p->next!=NULL){
        cnt++;
        if(cnt==ith){
            e=p->next->data;
            break;
        }
        p=p->next;
    }
}

//在第i个数据结点前插入元素e    1.我的
bool insertElemFrontIth(LinkList L,int i,ElemType e){
    LinkNode *p = L;
    while (--i>0&&p->next!=NULL)
    {
        p = p->next;
    }
    if(i<1||p->next==NULL){
        return false;
    }
    LinkNode *t=(LinkNode *)malloc(sizeof(LinkNode));
    t->data=e;
    t->next=p->next;
    p->next=t;
    return true;
}
//在第i个数据结点前插入元素e    2.书上的
void insertElement(LinkList L,int ith,ElemType e){
    LinkNode *p=L;
    int cnt=0;
    while(p->next!=NULL){
        cnt++;
        if(cnt==ith){
            LinkNode *t=(LinkNode *)malloc(sizeof(LinkNode));
            t->data=e;
            t->next=p->next;
            p->next=t;
            break;
        }
        p=p->next;
    }
}

//设计算法高效查找链表倒数第m个位置（m个正整数）的结点并输出该节点值
void getElem(LinkList L,int m){
    LinkNode *p=L;
    LinkNode *e=L->next;
    int cnt=0;
    while(p->next!=NULL){
        cnt++;
        if(cnt==m){
            p=p->next;
            break;
        }
        p=p->next;
    }
    if(cnt!=m){
        printf("error");     //不存在该结点
    }
    while(p->next!=NULL){
        e=e->next;
        p=p->next;
    }
    printf("%d",e->data);
}

//已知指针La和Lb分别指向两个无头结点的单链表，编写函数完成从La中删除第j个元素开始的共len个元素，并将这len个元素插入到表Lb中第j个元素之前
void removeLenFromLaToLb(LinkList &La,LinkList &Lb,int j,int len){
    LinkNode *pa=La;
    LinkNode *pb=Lb;
    LinkNode *pal,*par;
    LinkNode *pbl,*pbr;
    if(j==1){
        pbl=pa;
        int cnt=1;
        while(pa!=NULL){
            if(cnt==len){
                La=pa->next;
                pa->next=pb;
            }
            cnt++;
            pa=pa->next;
        }
        Lb=pbl;
    }
    int cnt=1;
    while(pa!=NULL){
        cnt++;
        if(cnt==j){
            pal=pa;
            pbr=pb->next;
            pb->next=pal->next;
            break;
        }
        pa=pa->next;
        pb=pb->next;
    }
    cnt=0;
    while(pa!=NULL){
        if(cnt==len){
            pal->next=pa->next;
            pa->next=pbr;
            break;
        }
        cnt++;
        pa=pa->next;
    }
}
int main(){
    ElemType a[10]={5,4,6,7,8,9,1,2,3,0};
    LinkList La,Lb;
    tailCreatLinkList(La,a,10);
    headCreatLinkList(Lb,a,10);
    // La=La->next;
    // Lb=Lb->next;
    printfLinkList(La);
    printfLinkList(Lb);
    // printf("max:%d average:%.2lf  1th:%d",maxElem(L->next),average(L->next),getIthElem(L,11));
    // bool b=insertElemFrontIth(L,0,10);
    // if(b){
    //     printfLinkList(L);
    // }
    // removeLenFromLaToLb(La,Lb,1,3);
    // printfLinkList(La);
    // printfLinkList(Lb);
    
    return 0;
}