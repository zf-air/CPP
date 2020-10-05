/*
 * 多态案例 p142
 * 电脑接口
 * Cpu* cpu=new IntelCpu;
 */

#include <iostream>

using namespace std;
class Cpu{
public:
    virtual void cpuwork()=0;
};

class Memory{
public:
    virtual void memorywork()=0;
};

class VideoCard{
public:
    virtual void videocardwork()=0;
};

class Computer{
public:
    Computer(Cpu* cpu,Memory* memory,VideoCard* videocard){
        this->cpu=cpu;
        this->memory=memory;
        this->videocard=videocard;
        cout<<"computer构造函数"<<endl;
    }

    ~Computer(){
        delete cpu;
        delete memory;
        delete videocard;
        cout<<"computer析构函数"<<endl;
    }

    void dowork(){
        cpu->cpuwork();
        memory->memorywork();
        videocard->videocardwork();
    }
private:
    Cpu* cpu;
    Memory* memory;
    VideoCard* videocard;
};

class IntelCpu:public Cpu{
public:
    void cpuwork(){
        cout<<"intel cpu work"<<endl;
    }
};

class IntelMemory:public Memory{
public:
    void memorywork(){
        cout<<"intel memory work"<<endl;
    }
};

class IntelVideoCard:public VideoCard{
public:
    void videocardwork(){
        cout<<"intel videocard work"<<endl;
    }
};

void test(){
    Cpu* cpu=new IntelCpu;
    Memory* memory=new IntelMemory;
    VideoCard* videocard=new IntelVideoCard;

    Computer* computer=new Computer(cpu,memory,videocard);
    computer->dowork();
    delete computer;
}
int main()
{
    test();
    return 0;
}
