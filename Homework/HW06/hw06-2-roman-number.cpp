/*
    ผู้ใช้กรอกตัวเลขเข้ามาในระบบ และให้คุณแปลงตัวเลขดังกล่าวให้เป็นตัวเลขโรมัน
    (โจทย์ข้อนี้ให้ใช้ For Loop เท่านั้น)

    Test case:
        8
    Output:
        8 = VIII

    Test case:
        4
    Output:
        4 = IV

    Test case:
        514
    Output:
        514 = DXIV

    Test case:
        929
    Output:
        929 = CMXXIX

*/
#include <stdio.h>

void convertToRoman(int num) {
    // กำหนดตัวเลขโรมันและค่าของแต่ละตัวเลขโรมัน
    char* romanNumerals[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int i;

    printf("%d = ", num);

    for (i = 12; i >= 0; i--) {
        while (num >= values[i]) {
            printf("%s", romanNumerals[i]);
            num -= values[i];
        }
    }
}

int main() {
    int num;
    printf("กรอกตัวเลขที่ต้องการแปลงเป็นตัวเลขโรมัน: ");
    scanf("%d", &num);

    convertToRoman(num);

    return 0;
}
