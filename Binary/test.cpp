#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class A{
    private:
    int x = 10;

    public:
    int y = 20;

    friend void display(A a);
    friend class B;
};

class B{
    public:
    void display(A a){
        cout<<"From friend class"<<endl;
        cout<<"X :"<<a.x<<endl;
        cout<<"X :"<<a.y<<endl;
    }
};

void display(A a){
    cout<<"From friend function"<<endl;
    cout<<"X :"<<a.x<<endl;
    cout<<"X :"<<a.y<<endl;
}

class Box{
    public:
    int *a;

    Box(int x){
        cout<<"Box Constructor"<<endl;
        a = new int(x);
    }

    ~Box(){
        cout<<"Box Destructor"<<endl;
        delete a;
    }

    void setData(int x){
        *a = x;
    }
};

int main(){
    // Box b1(20);

    // Box b2 = b1;
    // b2.setData(10);

    // cout<<*b1.a<<endl;

    int b = 20;
    int &z = b;
    int *y = &b;

    cout<<b<<endl;
    cout<<*y<<endl;

    return 0;
}