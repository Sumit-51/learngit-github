#include <iostream>
using namespace std;

template <typename T>

void swapValues(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

int main(){
    int x=5, y=10;
    cout<<"The value of x is : "<<x<<" and y is : "<<y<<endl;
    swapValues(x,y);
    cout<<"The swapped value of x is : "<<x<<" and y is : "<<y<<endl;
    return 0;

}