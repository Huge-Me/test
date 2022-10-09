#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a, b, c;
    cout<<"请选择要兑换的方式：1.人民币换美元  2.美元换人民币" << endl;
    cin >> a；
    switch(a) {
    case 0:
        cout<<"你选择的是人民币换美元" << endl;
        cin >> b;
        cout << b<<"RMB"<<"="<<b * 6 << "$" << endl;
    }
     case 1:
         cout << "你选择的是美元换人民币" << endl;
         cin >> c;
         cout << c << "$" << "=" << c / 6 << "RMB" << endl;
}
       
    return 0;
}