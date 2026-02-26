#include <stdio.h>
#include <string.h>

// Prototypes
void explode( char str1[], char splitter, char str2[][10], int *count );

void explode( char str1[], char splitter, char str2[][10], int *count ) {
    int i = 0; // ดัชนีสำหรับ str1
    int k = 0; // ดัชนีสำหรับสตริงย่อยใน str2 (แถว)
    int j = 0; // ดัชนีสำหรับอักขระในสตริงย่อยปัจจุบัน (คอลัมน์)

    *count = 0;

    // วนซ้ำจนกว่าจะถึงจุดสิ้นสุดของ str1
    while (str1[i] != '\0') {
        
        // ถ้าอักขระปัจจุบันไม่ใช่ตัวแบ่ง
        if (str1[i] != splitter) {
            
            // คัดลอกอักขระไปยัง str2
            // ตรวจสอบเพื่อป้องกัน Buffer Overflow ใน str2[k] (จำกัดที่ 9 อักขระ + \0)
            if (j < 9) { 
                str2[k][j] = str1[i];
                j++;
            }
        } else {
            // ถ้าเจอตัวแบ่ง
            
            // 1. ปิดสตริงย่อยปัจจุบันด้วย Null Terminator
            str2[k][j] = '\0';
            
            // 2. เคลื่อนไปยังช่องเก็บสตริงย่อยถัดไป (แถวถัดไป)
            k++;
            
            // 3. รีเซ็ตดัชนีอักขระภายในสตริงย่อย
            j = 0;
        }
        
        i++;
    }

    // ปิดสตริงย่อยตัวสุดท้าย (ในกรณีที่ไม่มี splitter ปิดท้าย)
    str2[k][j] = '\0'; 

    // เก็บจำนวนสตริงที่แบ่งได้ (k + 1 เพราะ k เริ่มจาก 0)
    *count = k + 1;
}

int main() {
    char out[ 20 ][ 10 ] ;
    int num ;
    int i;
    
    // Test Case 1
    char str1_test1[50] = "I/Love/You";
    char splitter_test1 = '/';
    
    explode( str1_test1, splitter_test1, out, &num ) ;
    
    printf("Test Case 1 (Input: I/Love/You):\n");
    printf("count = %d\n", num);
    
    for (i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("--- \n");
    
    // Test Case 2
    char str1_test2[50] = "Hello World:Welcome:To:C";
    char splitter_test2 = ':';
    
    explode( str1_test2, splitter_test2, out, &num ) ;
    
    printf("Test Case 2 (Input: Hello World:Welcome:To:C):\n");
    printf("count = %d\n", num);
    
    for (i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("--- \n");
    
    return 0 ;
}//end function