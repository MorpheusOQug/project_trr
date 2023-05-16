#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c, d;
    char q;
    do {
    cout<<"Xin hay nhap thong tin du lieu: "<<endl;

    do{
        cout<<"Nhap a: "; cin>>a;
    } while(a==0);
    cout<<"Nhap b: "; cin>>b;
    cout<<"Nhap c: "; cin>>c;
    cout<<"Nhap d: "; cin>>d;

    double delta = pow(b,2) - 3*a*c;
    double k = (9*a*b*c - 2*pow(b,3) - 27*pow(a,2)*d)/(2*sqrt(pow(abs(delta),3)));
    double pi = 2*acos(0.0);

    cout<<"Delta = "<<delta<<endl;
    cout<<"k = "<<fixed<<setprecision(10)<<k<<endl;

    if (delta>0) {
        if (abs(k)<=1) {
        //PT có 3 no pb
        double x1 = (2*sqrt(delta)*cos(acos(k)/3)-b)/3*a;
        double x2 = (2*sqrt(delta)*cos((acos(k)/3)-(2*pi/3))-b)/3*a;
        double x3 = (2*sqrt(delta)*cos((acos(k)/3)+(2*pi/3))-b)/3*a;
        cout<<"Phuong trinh có 3 nghiem phan biet:"<<endl;
        cout<<"x1 = "<<fixed<<setprecision(10)<<x1<<endl;
        cout<<"x2 = "<<fixed<<setprecision(10)<<x2<<endl;
        cout<<"x3 = "<<fixed<<setprecision(10)<<x3<<endl;
        } else if (abs(k)>1) {
            //PT có 1 no duy nhat
            double x = (sqrt(delta)*abs(k)/3*a*k)*(cbrt(abs(k) + sqrt(pow(k,2) - 1)) + cbrt(abs(k) - sqrt(pow(k,2) - 1))) - b/3*a;
            cout<<"Phuong trinh co 1 nghiem duy nhat vs delta (>0):"<<endl;
            cout<<"x = "<<fixed<<setprecision(10)<<x<<endl;
        }
    }
    else if (delta==0) {
        //PT co 1 no boi
        double y = ((sqrt(delta)*abs(k))/3*a*k)*(cbrt(abs(k) + sqrt(pow(k,2)-1)) + cbrt(abs(k) - sqrt(pow(k,2)-1))) - b/3*a;
        cout<<"Phuong trinh co 1 nghiem boi:"<<endl;
        cout<<"x = "<<fixed<<setprecision(10)<<y<<endl;
    }
    else {
        //PT co 1 no duy nhat
        double z = (sqrt(abs(delta))/3*a)*(cbrt(k + sqrt(pow(k,2) + 1)) + cbrt(k - sqrt(pow(k,2) + 1))) - b/3*a;
        cout<<"Phuong trinh co 1 nghiem duy nhat vs delta (<0):"<<endl;
        cout<<"x = "<<fixed<<setprecision(10)<<z<<endl;
    }

    cout<<"Continue (Y/N) ?"; cin>>q;
    }while (q=='y'||q=='Y');
    return 0;
}

