#include <iostream>
#include <vector>

std::vector<int> generatePrimes(int n) {

    std::vector<bool> isPrime(n + 1, true);

    for (int p = 2; p * p <= n; ++p) {

        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int limit;
    std::cout << "Enter the limit to generate prime numbers up to: ";
    std::cin >> limit;

    std::vector<int> primes = generatePrimes(limit);

    std::cout << "Prime numbers up to " << limit << ": ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }

    return 0;
}

