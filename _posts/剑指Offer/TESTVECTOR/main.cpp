#include <vector>
#include <iostream>

using namespace std;

//test  vector
int main() {
	vector<int> data(2, 9);
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << &data << "\t";//变量的存储地址
	cout << data.begin()._Ptr << "\n";//第一个元素的地址

	data.insert(data.begin(), 3);
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << &data << "\t";
	cout << data.begin()._Ptr<<"\n";

	data.push_back(2);
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << &data << "\t";
	cout << data.begin()._Ptr << "\n";

	data.insert(data.begin(), 3);
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << &data << "\t";
	cout << data.begin()._Ptr << "\n";

	data.insert(data.begin(), 3);
	cout << "size: " << data.size() << "\t";
	cout << "capicity: " << data.capacity() << "\t";
	cout << &data << "\t";
	cout << data.begin()._Ptr << "\n";

	system("pause");
}