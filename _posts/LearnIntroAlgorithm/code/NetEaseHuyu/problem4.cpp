/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-11 16:50:55
 * @Author: lydia
 * @Date: 2019-08-11 15:07:00
 */
#include <iostream>
#include <vector>
#include <map>
#include <limits>
using std::cin;
using std::cout;
using std::endl;

int split(std::vector<int> & a,int height);

int main(){
    int length_n=0;
    int length_q=0;
    std::map<int,int> result;
    
    cin>>length_n;
    std::vector<int> a(length_n);

    int maxheight=0;
    int minheight=std::numeric_limits<int>::max();

    for(int i=0;i<length_n;i++){
        cin>>a[i];
        if(a[i]<minheight){
            minheight=a[i];
        }
        if(a[i]>maxheight){
            maxheight=a[i];
        }
    }
    cin>>length_q;
     std::vector<int> y(length_q);
    for(int i=0;i<length_q;i++){
        cin>>y[i];
    }
    for(auto height:y){
       // map<int,int>::iterator it=
       if(height>maxheight){
           cout<<0<<"\n";
       }
      else  if(height<minheight){
           cout<<1<<"\n";
       }
        else if(result.find(height)!=result.end()){
            cout<<result.at(height)<<"\n";
        }else{
            int res=split(a,height);
            cout<<res<<endl;
            result[height]=res;
        }
    }
}
int split(std::vector<int> & a,int height){
        bool flag=a[0]>height;
        bool t_flag;
        int count=flag?1:0;
        
        for(int i=1;i<a.size();i++){
             t_flag=a[i]>height;
            if(!flag&&t_flag){
                count++;
            }
            flag=t_flag;
        }
        return count;
    }
