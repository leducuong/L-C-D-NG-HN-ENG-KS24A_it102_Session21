#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[100];
    int age;
};

int main() {
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    struct Student *students = malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("\nSinh vien %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        getchar();

        printf("Ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        printf("Tuoi: ");
        scanf("%d", &students[i].age);
    }

    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Khong the mo file.\n");
        free(students);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %d\n", students[i].id, students[i].name, students[i].age);
    }

    printf("\nThong tin sinh vien da duoc luu vao file students.txt.\n");

    fclose(file);
    free(students);

    return 0;
}

