#include <stdio.h>
#include <stdlib.h> // สำหรับ malloc และ free
#include <string.h> // สำหรับ strlen

/**
 * @brief สร้างและคืนค่าสตริงใหม่ที่เป็นการกลับลำดับของ str1
 * * @param str1 อาร์เรย์อักขระ (ข้อความต้นฉบับ)
 * @return char* พอยน์เตอร์ไปยังสตริงใหม่ที่กลับลำดับแล้ว (ต้อง free ในภายหลัง)
 */
char* reverse( char str1[] ) {
    int len = strlen(str1);
    int i, j;

    // 1. จัดสรรหน่วยความจำสำหรับสตริงใหม่ (str2)
    // ขนาด len + 1 สำหรับอักขระ len ตัวและ null terminator ('\0')
    char *str2 = (char*)malloc( (len + 1) * sizeof(char) );
    
    // ตรวจสอบว่าจัดสรรหน่วยความจำสำเร็จหรือไม่
    if (str2 == NULL) {
        return NULL; 
    }

    // 2. คัดลอกและกลับลำดับ
    // i วิ่งจาก 0 (สำหรับ str2) และ j วิ่งจาก len - 1 (สำหรับ str1)
    for (i = 0, j = len - 1; i < len; i++, j--) {
        str2[i] = str1[j];
    }
    
    // 3. เพิ่ม null terminator
    str2[len] = '\0';

    // 4. คืนค่าพอยน์เตอร์ไปยังสตริงใหม่
    return str2;
}

int main() {
    // Test Case 1
    char text1[ 50 ] = "I Love You" ;
    char *out1;
    out1 = reverse( text1 ) ;
    printf("Test Case 1:\n");
    printf("Input:  \"%s\"\n", text1);
    printf("Output: \"%s\"\n", out1);
    // สำคัญ: ต้องปล่อยหน่วยความจำที่ถูกจัดสรรโดย malloc
    free(out1); 
    printf("--- \n");

    // Test Case 2
    char text2[ 50 ] = "Hello World" ;
    char *out2;
    out2 = reverse( text2 ) ;
    printf("Test Case 2:\n");
    printf("Input:  \"%s\"\n", text2);
    printf("Output: \"%s\"\n", out2);
    free(out2); 
    printf("--- \n");

    // Example Test (จากโจทย์)
    char str1[ 50 ] = "I love you" ;
    char *str2;
    str2 = reverse( str1 ) ;
    printf("Example Test:\n");
    printf("Input:  \"%s\"\n", str1);
    printf("Output: \"%s\"\n", str2);
    free(str2); 
    printf("--- \n");

    return 0;
}//end function