#include <iostream>

int sumOfDigits(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num = 12345;
    std::cout << "Sum of digits of " << num << " is: " << sumOfDigits(num) << std::endl;
    return 0;
}
