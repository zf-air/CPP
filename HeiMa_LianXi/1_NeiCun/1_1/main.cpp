#include <iostream>
using namespace std;

//ȫ�ֱ���
int g_a = 10;
int g_b = 10;

//ȫ�ֳ���
const int c_g_a = 10;
const int c_g_b = 10;

int main() {

    //�ֲ�����
    int a = 10;
    int b = 10;

    //��ӡ��ַ
    cout << "�ֲ�����a��ַΪ�� " << &a << endl;
    cout << "�ֲ�����b��ַΪ�� " << &b << endl;

    cout << "ȫ�ֱ���g_a��ַΪ�� " <<  &g_a << endl;
    cout << "ȫ�ֱ���g_b��ַΪ�� " <<  &g_b << endl;

    //��̬����
    static int s_a = 10;
    static int s_b = 10;

    cout << "��̬����s_a��ַΪ�� " << &s_a << endl;
    cout << "��̬����s_b��ַΪ�� " << &s_b << endl;

    cout << "�ַ���������ַΪ�� " << &"hello world" << endl;
    cout << "�ַ���������ַΪ�� " << &"hello world1" << endl;

    cout << "ȫ�ֳ���c_g_a��ַΪ�� " << &c_g_a << endl;
    cout << "ȫ�ֳ���c_g_b��ַΪ�� " << &c_g_b << endl;

    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "�ֲ�����c_l_a��ַΪ�� " << &c_l_a << endl;
    cout << "�ֲ�����c_l_b��ַΪ�� " << &c_l_b << endl;

    system("pause");

    return 0;
}