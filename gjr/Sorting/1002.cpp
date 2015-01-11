/*************************************************************************
	> File Name: 1002.cpp
	> Author: LY
	> Mail: ly.franky@gmail.com
	> Created Time: Sunday, January 11, 2015 PM12:08:00 CST
 ************************************************************************/

#include <bits/stdc++.h>

int a[3000005], b[3000005] ; 
bool visit[1000005]; 

int main () {
    int c, n, k, i; 
    while(scanf("%d %d" , &c , &n) != EOF) {
        for(i = 0; i<n ; i++) scanf("%d", &a[i]);
        k = 0; 
        for(i = n - 1; i >= 0; i--)
            if(!visit[a[i]])
                b[k++] = a[i], visit[a[i]] = 1; 
        printf("%d\n", k);
        printf("%d", b[k - 1]);  
        for(i = k - 2; i >= 0; i--) printf(" %d", b[i]); 
        printf("\n");
        memset(visit , 0, sizeof(visit)) ;  
    }
    return 0 ;
}

