#include <stdio.h>

int main() {
    FILE *file = fopen("bt01.txt", "r");
    if (!file) {
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }

    char kyTuDau;
    if (fscanf(file, "%c", &kyTuDau) == 1) {
        printf("Ky tu dau tien trong file: %c\n", kyTuDau);
    } else {
        printf("File trong hoac khong co noi dung hop le.\n");
    }

    fclose(file);
    return 0;
}

