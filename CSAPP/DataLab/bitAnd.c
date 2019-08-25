/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
#include <stdio.h>
int bitAnd(int x, int y){
    int result = ~((~x) | (~y));
    printf("%d\n", result);
    return result;
}

int main(){
    bitAnd(6,5);
}


