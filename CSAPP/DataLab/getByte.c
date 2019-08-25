/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
#include <stdio.h>
int getByte(int x, int n) {
    int result = (x >> (n << 3)) & 0xff;
    printf("%x\n", result);
    return result;
}

int main(){
    
    getByte(0x12345678,1);
}