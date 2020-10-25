#include <iostream>
#include <string>
using namespace std;

//CPerson类
class CPerson{
public:
    CPerson(string name,string sex,int age);
    void print();

protected:
    string name;
    string sex;
    int age;
};
CPerson::CPerson(string name,string sex,int age){
    this->name=name;
    this->sex=sex;
    this->age=age;
}
void CPerson::print(){
    cout<<"姓名:"<<name<<endl;
    cout<<"性别:"<<sex<<endl;
    cout<<"年龄:"<<age<<endl;
}

//CStudent类
class CStudent:public CPerson{
public:
    CStudent(string name,string sex,int age,int score):CPerson(name,sex,age),score(score){}
    void print();
private:
    int score;
};
//学生类打印方法
void CStudent::print(){
    this->CPerson::print();
    cout<<"学生成绩:"<<score<<endl;
}

class CTeacher:public CPerson{
public:
    CTeacher(string name,string sex,int age,int t_age):CPerson(name,sex,age),t_age(t_age){}
    void print();
private:
    int t_age;
};

//教师类打印方法
void CTeacher::print(){
    this->CPerson::print();
    cout<<"教师教龄:"<<t_age<<endl;
}

int main()
{
    string name;
    string sex;
    int age;
    int score;
    int t_age;

    cout<<"请输入学生姓名:";
    cin>>name;
    cout<<"请输入学生性别:";
    cin>>sex;
    cout<<"请输入学生年龄:";
    cin>>age;
    cout<<"请输入学生成绩:";
    cin>>score;
    CStudent s(name,sex,age,score);
    s.print();

    cout<<"请输入教师姓名:";
    cin>>name;
    cout<<"请输入教师性别:";
    cin>>sex;
    cout<<"请输入教师年龄:";
    cin>>age;
    cout<<"请输入教师教龄:";
    cin>>t_age;
    CTeacher t(name,sex,age,t_age);
    t.print();

    return 0;
}
