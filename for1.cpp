#include <stdio.h>

int main() {
    int n, a, b, c;

    for (n = 0; n < 1000; n++) {
        a = n / 100;         
        b = (n-100*a)/10;  
        c = n-100*a-10*b;       

        if (a + c == b && n % 3 == 0) {
            printf("n=%d a=%d b=%d c=%d\n", n,a,b,c);

            if (n % 10 == 0) {
                printf("\n");
            }
        }
    }

    return 0;
}