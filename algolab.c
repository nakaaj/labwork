#include <stdio.h>
float add(float x, float y){
    return x + y;
}
float sub(float x, float y){
    return x - y;
}
float mul(float x, float y){
    return x * y;
}
float div(float x, float y){
    if (y == 0){
        return x;
    }
    else {
    return x / y;
}}

int main(){
    int x;
    float y,z;
    float (*math[4])(float,float);
    math[0] = add;
    math[1] = sub;
    math[2] = mul;
    math[3] = div;
    scanf("%d %f %f",&x,&y,&z);
    printf("%d %f %f %f\n",x,y,z,math[x](y,z));
    return 0;
}