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
    char romanNumerals[] = "IVXLCDM";
    int values[] = {1, 5, 10, 50, 100, 500, 1000};
    int i, j, div, mod;

    printf("%d = ", num);

    for (i = 6; i >= 0; i--) {
        div = num / values[i];
        num %= values[i];

        // ตรวจสอบว่าตัวเลขโรมันนี้ให้ใช้กี่ตัว
        if (div <= 3) {
            for (j = 0; j < div; j++) {
                printf("%c", romanNumerals[i]);
            }
        } else {
            // ในกรณีที่ตัวเลขโรมันนี้ให้ใช้ตัวที่มากกว่า 3 ตัว
            // ให้ใช้ตัวเลขโรมันที่ต่อมาคือ 1 หรือ 10 หรือ 100 ขึ้นอยู่กับค่าที่เหลือ
            mod = i % 2; // ค่า mod จะเป็น 0 หรือ 1
            printf("%c%c", romanNumerals[i - mod * 2], romanNumerals[i + mod]);
        }
    }
}

int main() {
    int num;
    printf(":");
    scanf("%d", &num);

    convertToRoman(num);

    return 0;
}
