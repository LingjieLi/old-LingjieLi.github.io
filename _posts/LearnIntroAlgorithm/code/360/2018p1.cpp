/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-14 21:04:22
 * @Author: lydia
 * @Date: 2019-08-14 20:47:25
 */
#include <iostream>
#include <deque>

using namespace std;

int main(){
    int T=0;
    cin>>T;
    deque<int> data;
    for(int i=1;i<=T;i++){
        int length=0;
        int tmp=0;
        cin>>length;
        for(int j=0;j<length;j++){
            cin>>tmp;
            data.push_back(tmp);
        }
        int sum1=0;
        int sum2=0;
        bool isFirtRound=true;
        while (!data.empty())
        {
            if(data.front()>data.back()){
                if(isFirtRound){
                    sum1+=data.front();
                    data.pop_front();
                }else{
                    sum2+=data.front();
                    data.pop_front();
                }
            }else if(data.front()<data.back()){
                if(isFirtRound){
                    sum1+=data.back();
                    data.pop_back();
                }else{
                    sum2+=data.back();
                    data.pop_back();
                }
            }else{
                if(isFirtRound){
                    sum1+=data.front();
                    data.pop_front();
                }else{
                    sum2+=data.front();
                    data.pop_front();
                }
            }
            isFirtRound=!isFirtRound;
        }

        cout<<"Case #"<<i<<": "<<sum1<<" "<<sum2<<"\n";
        
    }
    return 0;
}