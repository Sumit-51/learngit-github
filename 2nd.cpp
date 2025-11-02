#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    try {
        // Check for invalid array size
        if (n <= 0)
            throw "Array size must be positive!";
        if (n > 100)
            throw "Array size out of bound! Maximum allowed is 100.";

        int arr[100]; // fixed-size array

        cout << "Enter " << n << " positive numbers:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < 0)
                throw "Array contains negative values! Only positive numbers are allowed.";
        }

        // Find greatest element
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max)
                max = arr[i];
        }

        cout << "The greatest value in the array is: " << max << endl;
    }

    // Exception handling
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    cout << "Program terminated safely." << endl;
    return 0;
}
