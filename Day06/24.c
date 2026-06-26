#include <stdio.h>
double power(double base, int exp) {
    double result = 1.0;
    long long abs_exp = exp;

    
    if (abs_exp < 0) {
        abs_exp = -abs_exp;
        base = 1.0 / base;
    }

  
    while (abs_exp > 0) {
        
        if (abs_exp % 2 == 1) {
            result *= base;
        }
    
        base *= base;
        
        abs_exp /= 2;
    }

    return result;
}

int main() {
    double x;
    int n;

    printf("Enter base (x): ");
    scanf("%lf", &x);
    printf("Enter exponent (n): ");
    scanf("%d", &n);

    double ans = power(x, n);

    printf("%.4f raised to the power of %d is: %.4f\n", x, n, ans);

    return 0;
}

