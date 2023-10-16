//格式化快捷键 ctrl+alt+L

#include<iostream>

#define N 1003
int Hash[N] = {0};


//一个myqueue队列的对象
struct myqueue {
    int *data;//一个指向data的指针

    int head, rear;

//初始化内存
    bool init() {
        this->data = (int *) malloc(N * sizeof(int));
        //在《堆》上动态分配内存，int是4个字节，N * sizeof(int))即分配的总内存，(int *)强制转化

        if (!this->data) return false;//校验错误
    }

//队列大小为《尾-头》，但为了防止出现负数，+N模N
    int size() { return (rear - head + N) % N; }


    bool empty() {
        if (size() == 0) { return 1; }
        else return false;
    }

    bool push(int e) {
        if ((rear + 1) % N == head) { return 0; }
        data[rear] = e;
        rear = (rear + 1) % N;
        return 1;
    }

    //弹出，但是把弹出队列第一个元素元素存在e中，这里采用引用的手法
    bool pop(int &e) {
        if (head == rear)return 0;
        e = data[head];
        head++;
        return 1;

    }

    int front() {
        return data[head];
    }
} Q;
int main(){
    Q.init();//队列初始化
    int m,n;
    std::cin>>m>>n;
    int cnt=0;
    while(n--){
        int en;
        std::cin>>en;
        if(!Hash[en]){
            cnt++;
            Q.push(en);
            Hash[en]=1;
            while(Q.size()>m){
                int tmp;
                Q.pop(tmp);
                Hash[tmp]=0;
            }
        }
    }
    std::cout<<cnt;
    return 0;
}