#include <iostream>
using namespace std;

class animal{
public:
    virtual void sound(){
        cout<<"Animals make sound"<<endl;
    }
};
class Dog:public animal{
    void sound(){
        cout<<"Dog barks"<<endl;
    }
};
class cat:public animal{
    void sound(){
        cout<<"cat mews"<<endl;
    }
};

int main(){
    animal *a;
    Dog d;
    cat c;

    a=&d;
    a->sound();
    
    a=&c;
    a->sound();

    return 0;

}