

#include <iostream>
const int N=105;
struct node{
    int id;
    int preid;
    int nextid;

}nodes[N];

int main(){
    int n,m;
    std::cin>>n>>m;
    nodes[0].nextid=1;
    for (int i = 1; i <=n ; ++i) {
        nodes[i].id=i;
        nodes[i].nextid=i+1;
        nodes[i].preid=i-1;
    }
    nodes[n].nextid=1;
    nodes[1].preid=n;

    int now=1;
    while((n--)>1){
        for (int i = 1; i <m ; ++i) {
            now=nodes[now].nextid;
        }
        std::cout<<nodes[now].id<<" ";
        nodes[nodes[now].preid].nextid=nodes[now].nextid;
        nodes[nodes[now].nextid].preid=nodes[now].preid;
        now=nodes[now].nextid;
    }
    std::cout<<nodes[now].id;

    return 0;

}

