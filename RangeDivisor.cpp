#include <iostream>
#include <vector>

std::vector<int> countDivisorsInRange(int n) {
    std::vector<int> divisorsCount(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divisorsCount[j]++;
        }
    }

    return divisorsCount;
}

int main() {
    int limit;
    std::cout << "Enter the limit (n): ";
    std::cin >> limit;

    std::vector<int> divisorsCount = countDivisorsInRange(limit);

    std::cout << "Number of divisors for each number in the range [1, " << limit << "]:\n";
    for (int i = 1; i <= limit; ++i) {
        std::cout << "Number " << i << ": " << divisorsCount[i] << " divisors\n";
    }

    return 0;
}

