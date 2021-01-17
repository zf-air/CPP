#include <iostream>

using namespace std;

class Animal
{
public:
    int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Tuo, public Sheep {};

void test01()
{
    SheepTuo st;

    //答案和这两条语句的赋值顺序有关
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 200;

    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;

//    st.Sheep::m_Age = 200
//    st.Tuo::m_Age = 200
//    st.m_Age = 200
}


int main() {

    test01();

    system("pause");

    return 0;
}
