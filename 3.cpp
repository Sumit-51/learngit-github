#include <iostream>
using namespace std;

class Base{
private:
    int x;
public:
    Base(int a){
        x=a;
    }
    int getx(){
        return x;
    }
    void showx(){
        cout<<"The value of x is: "<<x<<endl;
    }
};

class Derived : public Base{
    int y;
public:
    Derived (int x,int b):Base(x){
        y=b;
    }

    void showBoth(){
        cout<<"The value of x is: "<<getx()<<" and value of y is"<<y<<endl;
    }

};
int main(){
    Derived v1(5,6);
    v1.showx();
    v1.showBoth();
    return 0;
}