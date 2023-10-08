//题解形式，最简单最快，但是工作中动态和规范为主.

#include <iostream>
int nodes[105];
int main(){
    int n,m;
    std::cin>>n>>m;
    //1到n赋值一个next值
    for(int i=1;i<n;i++){
        nodes[i]=i+1;
    }
    nodes[n]=1;
    int now=1,prev;
    while((n--)>1){
        for(int i=1;i<m;i++){
            prev=now;
            now=nodes[now];
        }
        std::cout<<now<<" ";
        nodes[prev]=nodes[now];
        now=nodes[now];
        //原著now=nodes[prev];
    }
    std::cout<<prev;
    //原著printf("%d",now);
    return 0;
}