#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int size=0;
        int j=0;

        vector<int> tmp;
        int cur_length=0;
        for(; j<A.size();) {
            cur_length=sizeOfVector(tmp);
            if(cur_length>K) {
                //删除第一个元素
                tmp.erase(tmp.begin());
                continue;
            }
            else if(cur_length==K) {
                size++;
                tmp.erase(tmp.begin());
                //前窗口再增加
                {
                    vector<int> tmp_tmp=tmp;
                    int tmp_j=j;
                    tmp_tmp.push_back(A[tmp_j]);
                    int tmp_cur_length=sizeOfVector(tmp_tmp);
                    tmp_j++;

                    while(tmp_cur_length==K) {
                        size++;
                        if(tmp_j>=A.size())
                           break;
                        tmp_tmp.push_back(A[tmp_j]);
                        tmp_cur_length=sizeOfVector(tmp_tmp);
                        tmp_j++;
                    }
                }
            } else {
                tmp.push_back(A[j]);
                j++;
            }
        }

        cur_length=sizeOfVector(tmp);
        while(cur_length>=K) {
            if(cur_length==K) {
                size++;
            }
            tmp.erase(tmp.begin());
            cur_length=sizeOfVector(tmp);
        }

        return size;
    }
    int sizeOfVector(const vector<int> &A) {
        set<int> tmp;
        for(int i=0; i<A.size(); i++) {
            tmp.insert(A[i]);

        }
        return tmp.size();

    }
};



int main() {

    Solution sol;
    vector<int> A1= {2,1,2,1,2};
    int K1=2;

    vector<int> A2= {1,2,1,2,3};
    int K2=2;

    int num1=sol.subarraysWithKDistinct(A1,K1);
    int num2=sol.subarraysWithKDistinct(A2,K2);
    //int num3=sol.subarraysWithKDistinct(A3,K3);
    std::cout<<"num1:"<<num1<<"\nnum2:"<<num2<<std::endl;

    return 0;
}
