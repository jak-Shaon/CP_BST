#include <iostream>
#include <vector>

std::vector<int> primeFactors(int n) {
    std::vector<int> factors;

    // Divide the number by 2 until it is odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Try dividing by odd numbers starting from 3
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If the remaining number is a prime greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::vector<int> factors = primeFactors(number);

    std::cout << "Prime factors of " << number << ": ";
    for (int factor : factors) {
        std::cout << factor << " ";
    }

    return 0;
}

