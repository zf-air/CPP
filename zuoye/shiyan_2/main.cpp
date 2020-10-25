#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    Student(string id,string name,int score[]);
    void print();
    static int getTotal();
    static double getAverage();
    static int getCount();

private:
    string id;
    string name;
    int score[3];
    static int total;
    static int count;
};

int Student::total=0;
int Student::count=0;

//所有学生成绩总和
int Student::getTotal(){
    return total;
}

//所有学生平均成绩
double Student::getAverage(){
    double average=0;
    average=total*1.0/count;
    return average;
}

//所有学生个数
int Student::getCount(){
    return count;
}

//带参构造函数
Student::Student(string id,string name,int score[]){
    this->id=id;
    this->name=name;
    for(int i=0;i<3;i++){
        this->score[i]=score[i];
        total+=score[i];
    }
    count++;
}

//打印单个学生学号，姓名和个人平均成绩
void Student::print(){
    cout<<"学号:"<<id<<endl;
    cout<<"姓名:"<<name<<endl;
    int sum=0;
    for(int i=0;i<3;i++){
        sum+=score[i];
    }
    double average=0;
    average=sum*1.0/3;
    cout<<"平均成绩为:"<<average<<endl;
}

int main()
{
    int n;
    cout<<"请您输入学生个数:";
    cin>>n;
    for(int i=0;i<n;i++){
        string id;
        cout<<"请您输入学号:";
        cin>>id;

        string name;
        cout<<"请您输入姓名:";
        cin>>name;

        int score[3];
        for(int j=0;j<3;j++){
            cout<<"请您输入第"<<j+1<<"科成绩:";
            cin>>score[j];
        }

        Student s(id,name,score);

        int total;
        total=s.getTotal();
        int count;
        count=s.getCount();
        double average;
        average=s.getAverage();
        cout<<"所有学生总分:"<<total<<endl;
        cout<<"所有学生个数:"<<count<<endl;
        cout<<"所有学生平均成绩:"<<average<<endl;
    }

    return 0;
}
