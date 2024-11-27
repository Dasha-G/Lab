#include <iostream>
#include <cmath>

double calculate_y(double x, int n) {
    double y;
    if (x < 7) {
        double product = 1.0;
        for (int i = 3; i <= n - 4; i++) {
            product *= x / (5.0 + i);
        }
        y = product;
    }
    else { // x >= 7
        double sum = 0.0;
        for (int j = 0; j <= n; j++) {
            double product = 1.0;
            for (int i = 1; i <= n + 1; i++) {
                if (i != j) { // Prevent division by zero
                    product *= (1.0 / (2 * x) + (3.0 * i) / (i - j));
                }
            }
            sum += product;
        }
        y = sum;
    }
    return y;
}

int main() {
    double x;
    int n;

    // Input values
    std::cout << "Enter value of x: ";
    std::cin >> x;
    std::cout << "Enter value of n: ";
    std::cin >> n;

    // Calculate and output the result
    double result = calculate_y(x, n);
    std::cout << "Result: " << result << std::endl;

    return 0;
}