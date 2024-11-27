#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
#include <string>
#include <regex>

using namespace std;

bool isInteger(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool isValidDouble(const string& str) {
    regex doubleRegex("^[+-]?([0-9]*[.])?[0-9]+$");
    return regex_match(str, doubleRegex);
}

double calculate_y(double x, int n) {
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
                if (i != j) { 
                    product *= (1.0 / (2 * x) + (3.0 * i) / (i - j));
                }
            }
            sum += product;
        }
        y = sum;
    }
    return y;
}

double getValidDoubleInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (isValidDouble(input)) {
            return stod(input);  
        }
        else {
            cout << "Invalid input. Please enter a valid number: ";
        }
    }
}

int main() {
    double a, b, step;
    int num;

    while (true) {
        try {
        start:
            cout << "Start (enter 0 to stop or integer to start): ";
            cin >> num;

            if (num == 0) {
                break;
            }

            a = getValidDoubleInput("Enter the range start (a): ");

        sstart:
            b = getValidDoubleInput("Enter the range end (b): ");
            if (a > b) {
                cout << "Error. a must be less than or equal to b" << endl;
                goto sstart;
            }

        ssstart:
            step = getValidDoubleInput("Enter the step value: ");
            if (step <= 0) {
                cout << "Invalid input. Step must be greater than 0: ";
                goto ssstart;
            }

            string n_str;
        nv:
            cout << "Enter the value of n: ";
            cin >> n_str;
            if (!isInteger(n_str) || stoi(n_str) <= 7) {
                cout << "Error: n must be an integer greater than 7." << endl;
                goto nv;
            }

            int n = stoi(n_str);

            ofstream out("resultforequation.txt", ios::app);
            if (!out.is_open()) {
                throw runtime_error("Failed to open the file for writing.");
            }

            int max_iterations = 10000;
            int iteration_count = 0;

            for (double x = a; x <= b; x += step) {
                iteration_count++;
                if (iteration_count > max_iterations) {
                    cout << "Error: Maximum iteration count exceeded." << endl;
                    out << "Error: Maximum iteration count exceeded." << endl;
                    goto start;
                }

                double y = calculate_y(x, n);
                cout << "For x = " << x << ", y = " << y << endl;
                out << "For x = " << x << ", y = " << y << endl;
            }

            out.close();
            cout << "Finished processing. Do you want to continue?" << endl;
            goto start;
        }
        catch (const runtime_error& e) {
            cerr << "Runtime error: " << e.what() << endl;
            cout << "An error occurred. Please try again." << endl;
        }
        catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
            cout << "An unexpected error occurred. Please try again." << endl;
        }
        catch (...) {
            cerr << "An unknown error occurred." << endl;
            cout << "An unknown error occurred. Please try again." << endl;
        }
    }

    return 0;
}


