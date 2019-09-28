#include <vector>
#include <iostream>

using namespace std;

//test  vector
int main() {
	vector<int> data{1,2,3,4};
	cout << "vector<int> data{1,2,3,4};" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	//cout << &data << "\t";//变量的存储地址
	cout << data.begin()._Ptr << "\t";//第一个元素的地址
	cout << data.end()._Ptr << "\n";

	data.insert(data.begin(), 3);
	cout << "data.insert(data.begin(), 3);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.push_back(2);
	cout << "data.push_back(2);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.insert(data.begin(), 3);
	cout << "data.insert(data.begin(), 3);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.insert(data.begin(), 3);
	cout << "data.insert(data.begin(), 3);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	//for (int val : data) {
	//	cout << val << "\t";
	//}
	//cout << "\n";

	data.shrink_to_fit();
	cout << "data.shrink_to_fit();" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.shrink_to_fit();
	cout << "data.shrink_to_fit();" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.assign(data.size()-1,2);
	cout << "data.assign(data.size()-1,2);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.assign(data.size(), 2);
	cout << "data.assign(data.size(), 2);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.assign(data.capacity(), 2);
	cout << "data.assign(data.capacity(), 2);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.assign(data.capacity()+2, 2);
	cout << "data.assign(data.capacity()+2, 2);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";


	data.resize(data.size());
	cout << "data.resize(data.size());" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.resize(data.size()-1);
	cout << "data.resize(data.size()-1);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.resize(data.size() + 1);
	cout << "data.resize(data.size()+1);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.resize(data.capacity());
	cout << "data.resize(data.capacity());" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.resize(data.capacity() + 1);
	cout << "data.resize(data.capacity()+1);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.resize(data.capacity() - 1);
	cout << "data.resize(data.capacity()-1);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.reserve(data.capacity());
	cout << "data.reserve(data.capacity());" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.reserve(data.capacity()+1);
	cout << "data.reserve(data.capacity()+1);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.reserve(data.capacity() - 1);
	cout << "data.reserve(data.capacity()-1);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";
	
	data = vector<int>(data.size() - 1, 9);
	cout << "data = vector<int>(data.size()-1, 9);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data = vector<int>(data.size() , 9);
	cout << "data = vector<int>(data.size(), 9);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data = vector<int>(data.size() + 1, 9);
	cout << "data = vector<int>(data.size()+1, 9);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data = vector<int>(data.capacity()-1, 9);
	cout << "data = vector<int>(data.capacity()-1, 9);" << ":\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data = vector<int>(data.capacity(),9);
	cout << "data = vector<int>(data.capacity(),9);" << "\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";


	data = vector<int>(data.capacity()+1, 19);
	cout << "data = vector<int>(data.capacity()+1, 19);" << "\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";
	
	vector<int> tmp(data.capacity(), 1);
	data.swap(tmp);
	cout << "data.swap(tmp);//tmp.capixity()=data.capacity()" << "\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	tmp= vector<int>(data.capacity()-1, 1);
	data.swap(tmp);
	cout << "data.swap(tmp);//tmp.capixity()=data.capacity()-1" << "\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	tmp= vector<int>(data.capacity()+1, 1);
	data.swap(tmp);
	cout << "data.swap(tmp);//tmp.capixity()=data.capacity()+1" << "\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	data.clear();
	cout << "data.clear();" << "\n";
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << data.begin()._Ptr << "\t";
	cout << data.end()._Ptr << "\n";

	system("pause");
}