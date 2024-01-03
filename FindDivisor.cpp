#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findDivisors(int n) {
    std::vector<int> divisors;

    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    return divisors;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::vector<int> divisors = findDivisors(number);

    std::cout << "Divisors of " << number << ": ";
    for (int divisor : divisors) {
        std::cout << divisor << " ";
    }

    return 0;
}

