#include <stdio.h>
int main(){
    int a = 123;
    int *b = &a;
    printf("a = %d||pointer of the a : %p\n", a,b);
    return 0;
}