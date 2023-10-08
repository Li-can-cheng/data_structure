//静态链表的特点在于它的内存是固定的


#include <iostream>

const int N=105;
struct node {
    int id, nextid;
}nodes[N];
int main(){
    int n,m;
    std::cin>>n>>m;
    nodes[0].nextid=1;
    for (int i = 1; i <=n; ++i) {
        nodes[i].id=i;
        nodes[i].nextid=i+1;
    }
    nodes[n].nextid=1;
    int now=1,prev=0;
    while((n--)>1){
        for(int i=1;i<m;i++){
            prev=now;
            now=nodes[now].nextid;
        }
        std::cout<<nodes[now].id<<" ";
        nodes[prev].nextid=nodes[now].nextid;
        now=nodes[prev].nextid;

    }
    std::cout<<nodes[now].id;
    //原著std::cout<<nodes[now].nextid;
    //原因是最后只有一个数据形成了自我闭环，因此id=nextid，但事实上id理解起来直观一点。

    return 0;
}

