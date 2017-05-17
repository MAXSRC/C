#include <stdio.h>

int main(){
    
    int c;
    //c = getchar();
    printf("%d\n", 3 != 4);
    //while (c != EOF){
    //	putchar(c);
    //	c = getchar();
    //}
    while ((c = getchar()) != EOF){
	putchar(c);
    }
}
