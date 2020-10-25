#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    Student(string id,string name,int score[]);
    void print();
private:
    string id;
    string name;
    int score[3];
};

Student::Student(string id,string name,int score[]){
    this->id=id;
    this->name=name;
    this->score[0]=score[0];
    this->score[1]=score[1];
    this->score[2]=score[2];
}

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
    cout<<"请输入姓名:";
    string name;
    cin>>name;

    cout<<"请输入学号:";
    string id;
    cin>>id;

    int score[3]={0};
    for(int i=0;i<3;i++){
        cout<<"请输入第"<<i+1<<"科成绩:";
        cin>>score[i];
    }

    Student s(id,name,score);
    s.print();

    return 0;
}
