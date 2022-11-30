#include<stdio.h>

int main(){
  int v,s;
  scanf("%d %d",&v, &s);

  int possible[21000] = {0};
  possible[s] = 1;
  int index = 0;
  int end = 1;
  int values_array[21000] = {0};
  int a;
  for(a = 0; a<21000; a++){
    values_array[a] = -1;
  }
  values_array[0] = s;

  while(values_array[index] != -1){
    int current = values_array[index];
    if(2*current<=v && !possible[2*current]){
      possible[2*current] = 1;
      values_array[end] = 2*current;
      end++;
    }
    if(3*current<=v && !possible[3*current]){
      possible[3*current] = 1;
      values_array[end] = 3*current;
      end++;
    }
    if(!possible[current/5]){
      possible[current/5] = 1;
      values_array[end] = current/5;
      end++;
    }
    index ++;
  }

  int i;
  for(i = v; i>=0;i--){
    if(possible[i]){
      printf("%d\r\n", i);
      break;
    }
  }
  return 0;
}
