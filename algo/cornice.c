#include<stdlib.h>

int main(){
    int* x = (int*)malloc(1000000000*sizeof(int));
    x[1000] = 3;
    free(x);
}