#include <stdio.h>

int main() {
    FILE *file = fopen("bt01.txt", "r"); 
    if (!file) {
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }

    char dongDauTien[1000];
    if (fgets(dongDauTien, sizeof(dongDauTien), file)) {
        printf("Dong dau tien trong file: %s", dongDauTien);
    } else {
        printf("File trong hoac khong co noi dung hop le.\n");
    }

    fclose(file);
    return 0;
}


