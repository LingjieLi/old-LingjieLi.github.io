/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-11 14:47:13
 * @Author: lydia
 * @Date: 2019-08-11 10:59:48
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

//转为二进制
string toBinary(int val){
    string s="";
    for(int a=val;a;a=a/2){
        s=s+(a%2?'1':'0');
    }
    reverse(s.begin(),s.end());
    return s;
}
int getSize(string str){
    int size=0;
    for(char c:str){
        if(c=='1'){
            size++;
        }
    }
    return size;
};
int main()
{
    //cout << "Hello World\n";
    int T=0;//样例个数
    vector<int> data;
    map<int,int> res;
    cin>>T;
    for(int i=0;i<T;i++){
        int N;
        data.clear();
        res.clear();
        cin>>N;
        for(int j=0;j<N;j++){
            int tmp;
            cin>>tmp;
            string res1=toBinary(tmp);
            int res2=getSize(res1);
            res[res2]++;
        }
        cout<<res.size()<<"\n";
    }
    

    return 1;
}