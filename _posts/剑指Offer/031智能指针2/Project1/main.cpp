#include "WeakPtr.h"
#include "Repeater.h"
#include "UniquePtr.h"
//#include "myshared_ptr.h"
using namespace std;
class Parent;
class Child {
private:
	//SharedPtr<Parent> ParentPtr;
	WeakPtr<Parent> ParentPtr;

public:
	void setParent(SharedPtr<Parent> parent) {
		ParentPtr = parent;
	}
};
class Parent {

private:
	SharedPtr<Child> ChildPtr;

public:
	void setChild(SharedPtr<Child> child) {
		ChildPtr = child;
	}
};

int main()
{

	SharedPtr<int> pshared1 = SharedPtr<int>(new int(3));
	SharedPtr<int> pshared2(pshared1);

	cout << "[1]count:" << pshared2.use_count() << "\n"; //2

	WeakPtr<int> pweak(pshared1);
	cout << "[2]count:" << pweak.use_count() << "\n"; //2

	if (!pweak.expired()) { //use_count!=0
		SharedPtr<int> sh_ptr2 = pweak.lock(); //get another shared_ptr
		*pshared1 = 100;
		std::cout << "[3]count:" << pweak.use_count() << std::endl; //3
	}


	//»·ÐÎ
	WeakPtr<Parent> wpp;
	WeakPtr<Child> wpc;

	{
		SharedPtr<Parent> p(new Parent);
		SharedPtr<Child> c(new Child);

		p->setChild(c);
		c->setParent(p);

		wpp = p;
		wpc = c;

		cout <<"[4]"<< wpp.use_count() << "\n";
		cout <<"[4]"<< wpc.use_count() << "\n";
	}

	cout << "[4]"<< wpp.use_count() << "\n";
	cout << "[4]" << wpc.use_count() << "\n";


	UniquePtr<Repeater> punique1 = UniquePtr<Repeater>(new Repeater(2,"xiaohong"));
	Repeater *p=punique1.release();
	cout <<"[5]"<< *p << "\n";

	UniquePtr<Repeater> punique2(new Repeater(3,"xiaoming"));
	cout << "[6]" << *punique2.get() << "\n";

	UniquePtr<Repeater> punique3(new Repeater(4, "xiaolan"));
	cout << "[6]" << *punique3.get() << "\n";

	punique2.swap(punique3);
	cout << "[6]" << *punique2.get() << "\n";
	cout << "[6]" << *punique3.get() << "\n";

	punique2.reset();
	if (punique2.get() == nullptr) {
		cout << "[7]reset success\n";
	}
	else {
		cout << "[7]reset failed!\n";
	}
	Repeater *repeater = new Repeater(3,"lal");
	punique2.reset(repeater);
	if (punique2.get() != nullptr) {
		cout << "[8]reset success\n";
		cout << "[8]" << *punique2.get() << "\n";
	}
	else {
		cout << "[8]reset failed!\n";
	}


	UniquePtr<Repeater> punique4 = my_make_unique<Repeater>(2,"xiaohuang");
	cout <<"[9]"<< *punique4 << "\n";

	system("pause");
	return 0;
}