#include <iostream>
#include <string>

using namespace std;

///基类
class Quota { //按照原价销售的书籍
private:
    string bookNo = ""; //书籍的isbn编号

protected:
    double price = 0.0; //代表普通状态下不打折的价格

public:
    Quota() = default; //希望其行为等同于默认的合成构造函数，并且在类内部声明，所以是内联的
    virtual ~Quota() = default;
    Quota(string _no)
        : bookNo(_no){};

    //返回书籍的isbn编号
    string isbn() const
    {
        return bookNo;
    };
    //返回书籍的实际价格 派生类负责改写并使用不同的折扣计算方法
    virtual double net_price(size_t n) const
    {
        return n * price; //不打折
    }

    friend ostream& operator<<(ostream& os, const Quota& quota);
};

ostream& operator<<(ostream& os, const Quota& quota)
{
    os << "print quota: " << quota.bookNo << "\t" << quota.price;
};

///继承类
class Bulk_quota : public Quota {
public:
    Bulk_quota() = default;
    Bulk_quota(string _no)
        : Quota(_no){};
    //重写基类的函数版本以实现大量购买的折扣
    double net_price(size_t n) const override //[1]
    {
    }

    friend ostream& operator<<(ostream& os, const Bulk_quota& quota);

private:
    size_t min_qty = 0; //适用折扣的最低购买数量
    double discount = 0.0; //折扣额
};

ostream& operator<<(ostream& os, const Bulk_quota& quota)
{
    os << "print bulk_quota: " << dynamic_cast<const Quota&>(quota) << "\t" << quota.min_qty;
}

int main()
{
    Quota* quota = new Quota("quota");
    Quota* bulk = new Bulk_quota("bulkquota");
    Bulk_quota* bulk2 = new Bulk_quota("bulkquota2");

    cout << "没有类型转换\n";
    cout << *quota << "\n";
    cout << *bulk << "\n";
    cout << *bulk2 << "\n";

    cout << "显式类型转换\n";
    cout << dynamic_cast<Bulk_quota*>(quota) << "\n"; //发生错误，返回空指针
    cout << *dynamic_cast<Bulk_quota*>(bulk) << "\n";
    cout << *dynamic_cast<Bulk_quota*>(bulk2) << "\n";
    cout << *static_cast<Bulk_quota*>(bulk) << "\n";
    return 0;
}