#include<stdio.h>

int main(){
  long long result =1;
  int n;
  scanf("%d", &n);

  while(n--){
    result*=(n+1);
  }
  printf("%lld\r\n", result);
  return 0;
}
