#include<stdio.h>

#define sq(a) (a*a)
#define cb(a) (a*a*a)

int main(){
  long long a,b;
  scanf("%lld %lld",&a,&b);

  long long x, y;
  int solutions = 0;
  for(x=-250; x<=250; x++){
    for(y =-250; y<=250; y++){
      if(sq(x) + sq(y) == a && cb(x) + cb(y) == b){
        solutions++;
        printf("%lld %lld\r\n", x, y);
      }
    }
  }

  if(solutions == 0){
    printf("-\r\n");
  }
  return 0;
}
