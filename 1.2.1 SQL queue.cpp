
//实例：
//3 7
//1 2 1 5 4 4 1

//输出：
//5

#include <iostream>
#include <queue>

using namespace std;
int Hash[1003]={0};//哈希检查内存中是否存有单词，若为1则存在
queue <int> mem;//队列模拟内存
int main(){
    int m,n,cnt=0;
    cin>>m>>n;
    while(n--){
        int en;cin>>en;
        if(!Hash[en]){//如果没查到
            ++cnt;//增加查找次数
            mem.push(en);//内存队列中加入en
            Hash[en]=1;//标记内存中存在的en
            while(mem.size()>m){//若超出内存
                Hash[mem.front()]=0;
                mem.pop();//删除内存第一个内容并且去除标记
            }
        }
    }
    cout<<cnt;
    return 0;
}