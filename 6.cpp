#include <iostream>
using namespace std;

class counter{
private:
    static int totalObjects;
public:

    counter(){
        totalObjects++;
    }

    static void displayCount(){
        cout<<"The total no of objects created is: "<<totalObjects<<endl;
    }

};

int counter::totalObjects=0;
int main(){
    counter c1;
    counter c2;
    counter c3;

    counter::displayCount();
    return 0;
}