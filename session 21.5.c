#include <stdio.h>

int main() {
    FILE *file = fopen("bt05.txt", "w"); 
    if (!file) {
        printf("Khong the mo file bt05.txt\n");
        return 1;
    }

    int soDong;
    printf("Nhap so dong: ");
    scanf("%d", &soDong);
    getchar(); 

    char noiDung[1000];
    for (int i = 0; i < soDong; i++) {
        printf("Nhap noi dung dong %d: ", i + 1);
        fgets(noiDung, sizeof(noiDung), stdin);
        fprintf(file, "%s", noiDung);
    }

    fclose(file);
    file = fopen("bt05.txt", "r");
    if (!file) {
        printf("Khong the mo file bt05.txt\n");
        return 1;
    }

    printf("\nNoi dung file bt05.txt:\n");
    while (fgets(noiDung, sizeof(noiDung), file)) {
        printf("%s", noiDung);
    }

    fclose(file);
    return 0;
}

