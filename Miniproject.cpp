#include <iostream>
#include <cmath>
using namespace std;

class TaylorSeries {
private:
    double x;
    int n;

    
    double factorial(int num) {
        if (num == 0 || num == 1)
            return 1;
        else
            return num * factorial(num - 1);
    }

public:
    TaylorSeries(double val, int terms) {
        x = val;
        n = terms;
    }

    double computeExp() {
        double result = 0;
        for (int i = 0; i < n; i++)
            result += pow(x, i) / factorial(i);
        return result;
    }

    double computeSin() {
        double result = 0;
        for (int i = 0; i < n; i++) {
            double sign = (i % 2 == 0) ? 1 : -1;
            result += sign * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        }
        return result;
    }

    double computeCos() {
        double result = 0;
        for (int i = 0; i < n; i++) {
            double sign = (i % 2 == 0) ? 1 : -1;
            result += sign * pow(x, 2 * i) / factorial(2 * i);
        }
        return result;
    }
};

int main() {
    double x;
    int n, choice;

    cout << "=== Taylor Series Approximation ===\n";
    cout << "1. e^x\n2. sin(x)\n3. cos(x)\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    cout << "Enter value of x (in radians for sin/cos): ";
    cin >> x;
    cout << "Enter number of terms (n): ";
    cin >> n;

    TaylorSeries t(x, n);

    switch (choice) {
        case 1:
            cout << "Approximation of e^" << x << " = " << t.computeExp() << endl;
            break;
        case 2:
            cout << "Approximation of sin(" << x << ") = " << t.computeSin() << endl;
            break;
        case 3:
            cout << "Approximation of cos(" << x << ") = " << t.computeCos() << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

