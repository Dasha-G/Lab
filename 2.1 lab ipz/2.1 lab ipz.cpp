#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    double a, b, step;
    int n;

    cout << "Enter the range start (a): ";
    cin >> a;
    cout << "Enter the range end (b): ";
    cin >> b;
    cout << "Enter the step value: ";
    cin >> step;
    cout << "Enter the value of n: ";
    cin >> n;

    ofstream out("resultforequation.txt", ios::app);
    if (out.is_open()) {
        if (n <= 7) {
            cout << "Error. n value is less or equal than 7 " << endl;
            out << "Error: n value is less or equal than 7 " << endl;
            return 1;
        }
        else if (cin.fail()) {
            cout << "Error. The entered data is not a number " << endl;
            out << "Error: The entered data is not a number " << endl;
            return 1;
        }
        else if (step <= 0) {
            cout << "Error: step must be more than 0" << endl;
            out << "Error: step must be more than 0" << endl;
            return 1;
        }
        else {
            int max_iterations = 1000;  
            int iteration_count = 0;
            for (double x = a; x <= b; x += step) {
                iteration_count++;
                if (iteration_count > max_iterations) {
                    cout << "Error: Maximum iteration count exceeded." << endl;
                    out << "Error: Maximum iteration count exceeded." << endl;
                    break;  
                }
                double y;
                if (x < 7) {
                    double product = 1.0;
                    for (int i = 3; i <= n - 4; i++) {
                        product *= x / (5 + i);
                    }
                    y = product;
                }
                else {
                    double sum = 0.0;
                    for (int j = 0; j <= n; j++) {
                        double product = 1.0;
                        for (int i = 1; i <= n + 1; i++) {
                            product *= (1.0 / (2 * x) + (3 * i) / (i - j + 1));  
                        }
                        sum += product;
                    }
                    y = sum;
                }
                cout << "For x = " << x << ", y = " << y << endl;
                out << "For x = " << x << ", y = " << y << endl;
            }
        }

        out.close();
        cout << "File has been written" << endl;
    }
    return 0;
}



