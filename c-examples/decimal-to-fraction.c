#include <stdio.h>

// Function to find the Greatest Common Divisor (GCD)
int getGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGCD(b, a % b);
}

void decimalToFraction(double decimal) {
    // Scale the decimal to handle more precision
    int numerator = (int)(decimal * 1000000);
    int denominator = 1000000;

    // Find the greatest common divisor
    int gcd = getGCD(numerator, denominator);

    // Simplify the fraction
    numerator /= gcd;
    denominator /= gcd;

    printf("Decimal: %.6lf\n", decimal);
    printf("Fraction: %d / %d\n", numerator, denominator);

    // Simplify the fraction further
	int wholePart = numerator / denominator;
	int remainderNumerator = numerator % denominator;
    printf("Simplified Fraction: %d and %d/%d\n", wholePart, remainderNumerator, denominator);
}

int main() {
    double inputDecimal;

    printf("Enter a decimal number: ");
    scanf("%lf", &inputDecimal);

    decimalToFraction(inputDecimal);

    return 0;
}
