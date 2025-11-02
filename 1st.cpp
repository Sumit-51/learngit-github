//here we allocate memory dynamically
#include <iostream>
using namespace std;

class allocateMemory{
    int *arr;
    int size;

    public:
    allocateMemory(int s){
        size=s;
        arr= new int[size];
        cout<<"Memory allocated for size "<<size<<" integers\n";
    }

    void input(){
        for(int i=0; i<size; i++){
            cin>>arr[i];
        }
    }
    void display(){
         for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~allocateMemory(){
        delete[] arr;
        cout<<"Memory deallocated\n";
     }
};

int main(){
    allocateMemory a1(3);
    a1.input();
    a1.display();
    return 0;
}