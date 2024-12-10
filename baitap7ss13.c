#include <stdio.h>
#include <stdlib.h>
void taoMaTran(int rows, int cols, int maTran[rows][cols]);
void inMaTran(int rows, int cols, int maTran[rows][cols]);
int main() {
    int rows, cols;
    printf("Nhập số hàng: ");
    scanf("%d", &rows);
    printf("Nhập số cột: ");
    scanf("%d", &cols);
    int maTran[rows][cols];
    taoMaTran(rows, cols, maTran);
    printMatrix(rows, cols, maTran);

    return 0;
}
void taoMaTran(int rows, int cols, int maTran[rows][cols]) {
    printf("Nhập các phần tử của ma trận (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phần tử [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &maTran[i][j]);
        }
    }
}
void inMaTran(int rows, int cols, int maTran[rows][cols]) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", maTran[i][j]);
        }
        printf("\n");
    }
}