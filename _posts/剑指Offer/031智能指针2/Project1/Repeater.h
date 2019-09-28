#include <string>
#include <iostream>

using namespace std;

class Repeater {
public:
	Repeater(int _data, string _name)
		: data(_data)
	{
		ptr = new string(_name);
	}
	void comment() const
	{
		cout <<"data = "<<data<<"  name = "<< *ptr;
	};
	~Repeater()
	{
		delete ptr;
	};

	friend ostream& operator<<(ostream& os, Repeater& repeater);

private:
	int data;
	string* ptr = nullptr;
};

ostream& operator<<(ostream& os, Repeater& repeater)
{
	os << repeater.data << " " << repeater.ptr << " " << *repeater.ptr;

	return os;
}