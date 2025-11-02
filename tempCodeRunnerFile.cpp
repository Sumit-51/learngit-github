#include<iostream>
using namespace std;

class age{
  protected:
    int year;
    int month;
    int day;
    
  public:
  
    age(){
        year=0;
        month=0;
        day=0;
    }
    
    age(int y,int m,int d){
        year=y;
        month=m;
        day=d;
    }
    
    void normalize(){
        if(day>30){
            month+=day/30;
            day=day%30;
        }
        if(month>12){
            year+=month/12;
            month=month%30;
        }
    }
    age operator +(age period){
        age result;
        result.year=year + period.year;
        result.month=month + period.month;
        result.day= day + period.day;
        normalize();
        return result;
    }
    void display(){
        cout<<year<<" years "<<month<<" month "<<day<<" day "<<endl;
    }
};

int main(){
    age a1(15,5,28);
    a1.display();
    age a2(1,3,23);
    a2.display();
    age a3;
    a3=a1+a2;
    a3.display();
    return 0;
    
}