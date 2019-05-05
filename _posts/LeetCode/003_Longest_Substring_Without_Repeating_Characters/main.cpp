#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<string> store;
        string substr;
        for(int i=0; i<s.length(); i++) {
            string::size_type pos=substr.find(s.at(i));
            if(pos==string::npos) {
                substr.append(1,s.at(i));
            } else {
                store.push_back(substr);
                if(pos+1>=substr.length()) {
                    substr.clear();
                    substr.append(1,s.at(i));
                } else {
                    substr=substr.substr(pos+1);
                    substr.append(1,s.at(i));
                }
            }
        }
        store.push_back(substr);
        int max_length=0;
        for(int i=0; i<store.size(); i++) {
            max_length=store[i].length()>max_length?store[i].length():max_length;
        }
        return max_length;
    }
};

int main(int argc, char** argv) {
    if(argc<2) {
        std::cout<<"please enter a string"<<std::endl;
        return 1;
    }
    Solution sol;
    string value(argv[1]);
    int length=sol.lengthOfLongestSubstring(value);
    std::cout<<length<<std::endl;
    return 0;


}
