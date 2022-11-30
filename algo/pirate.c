#include<stdio.h>

 

 int table[10010][10010];

 int max(int a, int b, int c, int d){
    int result =a;
    if(b>a)
        result = b;
    if(c>result)
    result = c;
    if(d>result)
    result = d;
    return result;
 }

 int solve(int obj[], int size, int n, int m){
    int i,j,k;
    for(i=0;i<size;i++){
        for(j=n;j>=0;j--){
            for(k=m;k>=0;k--){
                if(table[j][k]==1){
                    if(j+obj[i]<=n)
                        table[j+obj[i]][k] = 1;
                    if(k+obj[i]<=m)
                        table[j][k+obj[i]] = 1;
                }
            }
        }
    }
    int result = 0;
    for(j=n;j>=0;j--){
        for(k=m;k>=0;k--){
            if(table[j][k]==1 && j+k>result)
                result = j+k;
        }
    }
    return result;
 }

 void resettable(int jmax, int kmax){
    int j,k;
    for(j=0;j<=jmax;j++){
        for(k=0;k<=kmax;k++){
            if(j==0 && k ==0)
                table[j][k]=1;
            else
                table[j][k]=0;
        }
    }
 }

int main(){
   int m,n;
    int pa, po;
    
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &pa);
    scanf("%d", &po);
    int gold[100], silver[100];
    int i,j,k;
    for(i = 0;i<pa;i++){
        scanf("%d", &silver[i]);
    }
    for(i = 0;i<po;i++){
        scanf("%d", &gold[i]);
    }

    //only silver
    resettable(n,m);
    int a = solve(silver, pa, n,m);
    //only gold
    resettable(n,m);
    int b = solve(silver, po, n,m);
    //gold 1 silver 2
    resettable(n, 0);
    int c = solve(gold, po, n, 0);
    resettable(0,m);
    c+=solve(silver, pa, 0, m);

    //gold 2 silver 1
    resettable(0, m);
    int d = solve(gold, po, 0, m);
    resettable(n,0);
    d+=solve(silver, pa, n, 0);

    /*for(j=0;j<=n;j++){
        for(k=0;k<=m;k++){
            printf("%d ", table[j][k]);
        }
        printf("\n");
    }*/

    printf("%d\r\n", max(a,b,c, d));
    return 0;
}