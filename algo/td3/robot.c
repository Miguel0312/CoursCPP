#include<stdio.h>

long long paths(int y, int x, int grid[101][101], int n){
  if(x==n-1 && y==n-1){
    return 1;
  }

  long long result = 0;
  if(x<n-1 && grid[y][x+1] == 0)
    result+=paths(y, x+1, grid, n);
  if(y<n-1 && grid[y+1][x] == 0)
    result+=paths(y+1, x, grid, n);
  return result;
}

int main(){
  int n;
  int grid[101][101];

  scanf("%d", &n);

  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%d", &grid[i][j]);
    }
  }
  printf("%lld\r\n", paths(0, 0, grid, n));
  return 0;
}
