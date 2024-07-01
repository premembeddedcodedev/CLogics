#include<stdio.h>
#include<stdlib.h>

int main(){
    int n = 3, m = 3;
    char ***a;

    // Malloc and store.
    a = (char***)malloc(sizeof(char**) * n);
    for(int i = 0; i <n; ++i){
        a[i] = (char**)malloc(sizeof(char*) * m);
        for(int j = 0; j < m; ++j){
            a[i][j] = "abc"; // <-- you can put your string here in place of "abc".
        }
    }

    // Print or process your array or whatever serves your purpose.
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            printf("%s\n", a[i][j]);
        }
    }

    return 0;
}
