/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-11 15:48:10
 * @Author: lydia
 * @Date: 2019-08-11 14:53:10
 */

#include <iostream>

using namespace std;

int main(){
    int T;//测试数据
    for(int i=0;i<T;i++){
        int m,t,m1,t1,m2,t2;
        cin>>m>>t>>m1>>t1>>m2>>t2;
        bool flag1=true;//给水管状态 打开
        bool flag2=true;//排水管状态 打开
        int cur_time=0;
        int round1=t/t1;//给水管round1轮
        int round2=t/t2;//排水管round2轮
        round1=round1/2==0?round1/2:(round1-1)/2;
        round2=round2/2==0?round2/2:(round2-1)/2;

        //一分钟一分钟的走
        int input=0;
        int output=0;

        while(cur_time<=t){
            //判断水管状态
            flag1=cur_time/t1/2==0?false:true;
            flag2=cur_time/t2/2==0?false:true;
            if(flag1){//进水状态
                input+=m1;
            }
            if(flag2){//出水状态
                output+=m2;
            }
            if(input<output){//水量变为负数
                
            }
            cur_time++;
        }
    }
    return 0;
};