#include <iostream>
#define N 1003
int Hash[N]={0};
struct myqueue{
    int data[N];//存储每个元素的数据
    int head,rear;//头尾

    bool init(){//初始化
        head=rear=0;
        return true;
    }

    int size(){return (rear-head+N)%N;}//计算长度

    bool empty(){
        if(size()==0)return true;//
        else return false;
    }

    bool push(int e){
        if((rear+1)%N==head) return false;
        data[rear]=e;
        rear=(rear+1)%N;
        return true;
    }

    bool pop(int& e){
        if(head==rear)return false;
        e=data[head];
        head=(head+1)%N;
        return true;
    }
    int front(){return data[head];}
}Q;

int main(){
    Q.init();

    int m,n;
    std::cin>>m>>n;
    int cnt=0;
    while(n--){
        int en;std::cin>>en;
        if(!Hash[en]){
            ++cnt;
            Q.push(en);
            Hash[en]=1;
            while(Q.size()>m){
                int tmp;Q.pop(tmp);//此处很妙，函数内直接把临时地址上的元素修改成删除的元素
                Hash[tmp]=0;
            }
        }
    }
    std::cout<<cnt<<std::endl;
    return 0;
}
