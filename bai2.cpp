#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class Da_thuc
{
public:
    int heso[100] = {0};
    int somu;
    //void khoitaodathucrong(Da_thuc &a);
    void setSomu(int x)
    {
        this->somu = x;
    }
    int getSomu()
    {
        return this->somu;
    }
    void Nhap(Da_thuc &dt);
    void xuat(Da_thuc dt);
    friend Da_thuc operator+(Da_thuc a, Da_thuc b);
    friend Da_thuc operator*(Da_thuc a, Da_thuc b);
    long double Tinh_x(Da_thuc a, double x);
    friend istream &operator >> (istream &in, Da_thuc &sm)
    {
        in >> sm.somu;
        return in;
    }

    friend ostream& operator << (ostream &os, const Da_thuc &x)
    {
        os << x.heso << x.somu << endl;
        return os;
    }
    int operator [](int x)
    {
        if (x >= somu) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return heso[somu];
    }
};

/*void Da_thuc ::khoitaodathucrong(Da_thuc &a)
{
    a.somu = 0;
    for(int i = 0; i <100; i++)
    {
        a.heso[i] = 0;
    }
}*/

void Da_thuc ::Nhap(Da_thuc &a)
{
    cin >> a.somu;
    a.setSomu(a.somu);
    for(int i = a.somu; i >= 0; i--)
    {
        double temp;
        cin >> temp;
        a.heso[i] = temp;
    }
}

void Da_thuc :: xuat(Da_thuc a)
{
    for(int i = a.somu; i >= 1; i--)
    {
        if(a.somu != 0)
        {
            if(a.heso[i] == 0)
                continue;
            else if(a.heso[i] > 0)
                cout << "+" << a.heso[i] << "x^" << i << " ";
            else if(a.heso[i] < 0)
                cout << a.heso[i] << "x^" << i << " " ;
        }
    }
    cout << a.heso[0] << "x^0";
}

Da_thuc operator+(Da_thuc a, Da_thuc b)
{
    Da_thuc kq1;
    kq1.somu = max(a.somu, b.somu);
    for(int i=kq1.somu; i >= 0; i--)
    {
        kq1.heso[i] = a.heso[i] + b.heso[i];
    }
    return kq1;
}

Da_thuc operator*(Da_thuc a, Da_thuc b)
{
    Da_thuc k;
    k.somu = a.somu+b.somu;
    for(int i=a.somu; i >= 0; i--)
    {
        for(int j=b.somu; j >= 0; j--)
        {
            k.heso[i+j] += a.heso[i]*b.heso[j];
        }
    }
    return k;
}

long double Da_thuc ::Tinh_x(Da_thuc a, double x)
{
    long double sum = 0;
    for(int i = a.somu; i >= 0; i--)
    {
        sum += a.heso[i] * pow(x,i);
    }
    return sum;
}

int main()
{
    Da_thuc a;
    Da_thuc b;
    a.Nhap(a);
    b.Nhap(b);
    cout << "Da thuc thu nhat: ";
    a.xuat(a);
    cout << endl;
    cout << "Da thuc thu hai: ";
    b.xuat(b);
    cout << endl;
    Da_thuc kq, kq1;
    kq = a + b;
    kq1 = a * b;
    cout << "Tong: ";
    kq.xuat(kq);
    cout << endl;
    cout << "Tich: ";
    kq1.xuat(kq1);
    cout << endl;
    double x;
    cout << "Nhap x: ";
    cin >> x;
    long double sum = 0, sum1 = 0;
    sum = a.Tinh_x(a,x);
    sum1 = b.Tinh_x(b, x);
    cout << "Gia tri cau a: " << sum << "\tGia tri cau b: " << sum1 << endl;
    cout << endl << a.heso[a.getSomu()] << " " << b.heso[b.getSomu()] << endl;
    return 0;
}

/*5 1 1 1 1 1 1
5 -4 2 4 -3 2 1*/
