#include <iostream>
using namespace std;

class Age {
private:
    int years;
    int months;
    int days;

public:
    Age() {
        years = 0;
        months = 0;
        days = 0;
    }
    
    Age(int y, int m, int d) {
        years = y;
        months = m;
        days = d;
        normalize();
    }
    
    // Normalize age (convert excess days to months, months to years)
    void normalize() {
        if (days >= 30) {
            months += days / 30;
            days = days % 30;
        }
        
        if (months >= 12) {
            years += months / 12;
            months = months % 12;
        }
    }
    
    // Overload + operator to add period to age
    Age operator+(Age period) {
        Age result;
        result.years = years + period.years;
        result.months = months + period.months;
        result.days = days + period.days;
        result.normalize();
        return result;
    }
    
    void display() {
        cout << years << " years, " << months << " months, " << days << " days" << endl;
    }
};

int main() {
    int y1, m1, d1, y2, m2, d2;
    
    cout << "Enter person's current age (years months days): ";
    cin >> y1 >> m1 >> d1;
    
    cout << "Enter period to add (years months days): ";
    cin >> y2 >> m2 >> d2;
    
    Age currentAge(y1, m1, d1);
    Age period(y2, m2, d2);
    
    Age futureAge = currentAge + period;
    
    cout << "\nCurrent Age: ";
    currentAge.display();
    
    cout << "Period: ";
    period.display();
    
    cout << "Age after period: ";
    futureAge.display();
    
    return 0;
}
