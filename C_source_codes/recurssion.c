#include <stdio.h>

void countdown(int n)
{
    if(n < 0) {
        return;
    }
    //printf("%d ", n);
    countdown(n - 1);
}

void factorial(int n)
{
    static int result = 1;
    if (n < 1) {
        printf("Factorial : %d\r\n", result);
        return;
    }
    result = result * (n);
    factorial(n - 1);
}


int fibo(int n)
{
    /*
    n = 3;
    0 + 1 + 1 + 2 + 3
    */
   if (n == 1) {
    return 1;
   }
   if (n == 0) {
    return 0;
   }
    
   return fibo(n - 1) + fibo(n -2);
}

int main(void)
{
    int n = 6;
    countdown(n);
    factorial(n);
    int result = fibo(n);
    printf("Result : %d \r\n", result);
    return 0;
}