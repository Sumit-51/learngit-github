#include <iostream>
using namespace std;


class Complex {
private:
    int real;
    int imag;


public:
    // Constructors
    Complex() {
        real = 0;
        imag = 0;
    }
    
    Complex(int real, int imag) {
        this->real = real;
        this->imag = imag;
    }
    
    // Minus unary operator (-) - Returns void
    void operator-() {
        real = -real;
        imag = -imag;
    }
    
    // Scalar multiplication (friend function) - Returns Complex
    friend Complex operator*(Complex c, int scalar) {
        Complex temp;
        temp.real = c.real * scalar;
        temp.imag = c.imag * scalar;
        return temp;
    }
    
    // Plus binary operator (+) - Returns Complex
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    
    // Minus binary operator (-) - Returns Complex
    Complex operator-(Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    
    // += Shorthand operator - Returns void
    void operator+=(Complex c) {
        real += c.real;
        imag += c.imag;
    }
    
    // == Equals to operator - Returns TRUE or FALSE
    bool operator==(Complex c) {
        return (real == c.real && imag == c.imag);
    }
    
    // Greater than operator - Returns TRUE or FALSE
    bool operator>(Complex c) {
        // Comparing magnitude (real^2 + imag^2)
        return ((real*real + imag*imag) > (c.real*c.real + c.imag*c.imag));
    }
    
    // != Not equals to operator - Returns TRUE or FALSE
    bool operator!=(Complex c) {
        return (real != c.real || imag != c.imag);
    }
    
    // Pre Increment operator (++c) - Returns Complex
    Complex operator++() {
        ++real;
        ++imag;
        return *this;
    }
    
    // Post Increment operator (c++) - Returns Complex
    Complex operator++(int) {
        Complex temp = *this;
        real++;
        imag++;
        return temp;
    }
    
    // Stream Insertion operator (friend function) - Returns ostream&
    friend ostream& operator<<(ostream& out, Complex c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};


int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3;
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    // Testing Plus operator
    c3 = c1 + c2;
    cout << "\nc1 + c2 = " << c3 << endl;
    
    // Testing Minus operator
    c3 = c1 - c2;
    cout << "c1 - c2 = " << c3 << endl;
    
    // Testing Scalar multiplication
    c3 = c1 * 3;
    cout << "c1 * 3 = " << c3 << endl;
    
    // Testing += operator
    cout << "\nBefore +=: c1 = " << c1 << endl;
    c1 += c2;
    cout << "After c1 += c2: c1 = " << c1 << endl;
    
    // Testing == operator
    cout << "\nc1 == c2: " << (c1 == c2 ? "TRUE" : "FALSE") << endl;
    
    // Testing != operator
    cout << "c1 != c2: " << (c1 != c2 ? "TRUE" : "FALSE") << endl;
    
    // Testing > operator
    cout << "c1 > c2: " << (c1 > c2 ? "TRUE" : "FALSE") << endl;
    
    // Testing Pre-increment
    cout << "\nBefore pre-increment: c2 = " << c2 << endl;
    ++c2;
    cout << "After ++c2: c2 = " << c2 << endl;
    
    // Testing Post-increment
    Complex c4(5, 6);
    cout << "\nBefore post-increment: c4 = " << c4 << endl;
    Complex c5 = c4++;
    cout << "After c4++: c4 = " << c4 << endl;
    cout << "Returned value c5 = " << c5 << endl;
    
    // Testing Unary minus
    Complex c6(7, 8);
    cout << "\nBefore unary minus: c6 = " << c6 << endl;
    -c6;
    cout << "After -c6: c6 = " << c6 << endl;
    
    return 0;
}
