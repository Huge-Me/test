#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a, b, c;
    cout<<"��ѡ��Ҫ�һ��ķ�ʽ��1.����һ���Ԫ  2.��Ԫ�������" << endl;
    cin >> a��
    switch(a) {
    case 0:
        cout<<"��ѡ���������һ���Ԫ" << endl;
        cin >> b;
        cout << b<<"RMB"<<"="<<b * 6 << "$" << endl;
    }
     case 1:
         cout << "��ѡ�������Ԫ�������" << endl;
         cin >> c;
         cout << c << "$" << "=" << c / 6 << "RMB" << endl;
}
       
    return 0;
}