/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-11 15:40:40
 * @Author: lydia
 * @Date: 2019-08-11 15:18:13
 */
// #include<iostream>
// #include <vector>
// #include <algorithm>
// #include <random>

// using namespace std;


// int result=1;
// void dfs(vector<bool> &ns,int remain){
//     if(count(ns.begin(),ns.end(),false)==0){
//         int tmp=ns.size();
//         result=max(result,tmp);
//         return;
//     }
//     if(remain==0){
//         int res,tmp=0;
//         for(int i=0;i<ns.size();i++){
//             if(ns[i]){
//                 ++tmp;
//                 res=max(res,tmp);
//             }else{
//                 tmp=0;
//             }
//         }
//         result=max(result,res);
//         return;
//     }

//     for(int j=0;j<ns.size();++j){
//         if(ns[j]==false){
//             ns[j]=true;
//             dfs(ns,remain-1);
//             ns[j]=false;
//         }
//     }
// }

// int process(string input){
//     vector<bool> Ns(input.size(),false);
//     for(int i=0;i<input.size();++i){
//         if(input[i]=='N'){
//             Ns[i]=true;
//         }
//     }
//     dfs(Ns,2);
//     return result;
// }

// int main(){
//     int N;
//     cin>>N;
//     vector<string> inputs(N);

//     for(int i=0;i<N;i++){
//         cin>>inputs[i];
//     }

//     for(int j=0;j<N;j++){
//         cout<<process(inputs[j])<<endl;
//     }

//     return 0;
// }

#include <string>
#include <algorithm>
#include <iostream>
#include<vector>

using namespace std;

int findLen(string &input,int remain,char ch){
    int n=input.size();
    int maxLen=1;
    int count=0;
    int l=0,r=0;

    while(r<n){
        if(input[r]!=ch){
            ++count;
        }

        while (count>remain)
        {
            if(input[l]!=ch){
                --count;
            }
            ++l;
        }
        maxLen=max(maxLen,r-l+1);
        ++r;
    }
    return maxLen;
}

int main(){
    int N;
    cin>>N;
    vector<string> inputs(N);
    for(int j=0;j<N;j++){
        cout<<findLen(inputs[j],2,'N')<<endl;;
    }
    return 1;
}

3
NNTN
NNNNGGNNNN
NGNNNNGNNNNNNNNSNNNN