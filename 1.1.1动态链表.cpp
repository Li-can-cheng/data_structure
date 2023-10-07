#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};//单链表节点

int main(){
    int n,m;
    scanf("%d %d",&n,&m);//n个人，数到m出列
    node *head;//头指针
    node *p;//新节点
    node *now;//当前节点
    node *prev;//前一个

    head=new node;head->data=1;head->next=NULL;//分配第一个节点，数据是1，初始化

    now=head;
    for (int i = 2; i <=n; ++i){
        p=new node;p->data=i;p->next=NULL;//新节点，赋值i
        now->next=p;//当前指针指向新节点
        now=p;
    }
    now->next=head;
    //后续不断创建新节点并连上去

    now=head;//从第一个开始数
    while((n--)>1){
        for (int i = 1; i < m; ++i) {
            prev=now;
            now=now->next;
        }
        printf("%d  ",now->data);
        prev->next=now->next;
        delete now;
        now=prev->next;

    }
    printf("%d",now->data);
    delete now;
    //每次出列一个人，所以出列n次。最后一个人单独处理，因此while中条件为(n--)-1>0
    return 0;
}
