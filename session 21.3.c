#include <stdio.h>

int main() {
    FILE *file = fopen("bt01.txt", "a"); 
    if (!file) {
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }

    char chuoi[1000];
    printf("Nhap mot chuoi bat ky de ghi them vao file: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    fprintf(file, "%s", chuoi);
    fclose(file);
    printf("Da ghi them chuoi vao file bt01.txt thanh cong.\n");

    return 0;
}

