#include <iostream>
#include <set>
using namespace std;

/*Student结构体*/
struct Student {
    string name;
    int age;
    string sex;
};

/*“仿函数"。为Student set指定排序准则*/
class studentSortCriterion {
public:
    bool operator()(const Student& a, const Student& b) const
    {
        /*先比较名字；若名字相同，则比较年龄。小的返回true*/
        if (a.name < b.name) {
            std::cout << a.name << "<" << b.name << "\n";
            return true;
        } else if (a.name == b.name) {
            std::cout << a.name << "==" << b.name << "\n";
            if (a.age < b.age)
                return true;
            else
                return false;
        } else {
            std::cout << a.name << ">" << b.name << "\n";
            return false;
        }
    }
};

int main()
{
    set<Student, studentSortCriterion> stuSet;

    Student stu1, stu2;
    stu1.name = "张三";
    stu1.age = 13;
    stu1.sex = "male";

    stu2.name = "李四";
    stu2.age = 23;
    stu2.sex = "female";

    stuSet.insert(stu1);
    stuSet.insert(stu2);

    /*构造一个测试的Student，可以看到，即使stuTemp与stu1实际上并不是同一个对象，
     *但当在set中查找时，仍会查找成功。这是因为已定义的studentSortCriterion的缘故。
     */

    for (auto s : stuSet) {
        std::cout << s.name << "\t" << s.age << "\t" << s.sex << "\n";
    }
    Student stuTemp;
    stuTemp.name = "张三";
    stuTemp.age = 13;
    stuTemp.sex = "female";

    set<Student, studentSortCriterion>::iterator iter;
    iter = stuSet.find(stuTemp);
    if (iter != stuSet.end()) {
        cout << (*iter).name << endl;
    } else {
        cout << "Cannot fine the student!" << endl;
    }

    return 0;
}