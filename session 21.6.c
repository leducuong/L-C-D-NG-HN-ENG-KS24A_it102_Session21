#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    int id;
    char name[100];
    int age;
};

int main() {
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Khong the mo file students.txt\n");
        return 1;
    }

    int soLuong;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &soLuong);
    getchar();

    struct SinhVien *sinhVien = malloc(soLuong * sizeof(struct SinhVien));

    for (int i = 0; i < soLuong; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &sinhVien[i].id);
        getchar();
        printf("Ten: ");
        fgets(sinhVien[i].name, sizeof(sinhVien[i].name), stdin);
        sinhVien[i].name[strcspn(sinhVien[i].name, "\n")] = '\0';
        printf("Tuoi: ");
        scanf("%d", &sinhVien[i].age);
        getchar();

        fprintf(file, "%d,%s,%d\n", sinhVien[i].id, sinhVien[i].name, sinhVien[i].age);
    }

    printf("\nDa luu thong tin sinh vien vao file students.txt thanh cong.\n");

    fclose(file);
    free(sinhVien);
    return 0;
}

