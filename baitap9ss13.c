#include <stdio.h>
#include <stdbool.h>

bool laSoNguyenTo(int num);
void nhapMaTran(int maTran[][100], int n, int m);
void inMaTran(int maTran[][100], int n, int m);
void inGocMaTran(int maTran[][100], int n, int m);
void inDuongBien(int maTran[][100], int n, int m);
void inDuongCheo(int maTran[][100], int n, int m);
void inSoNguyenTo(int maTran[][100], int n, int m);
void displayMenu();
int main() {
    int n, m;
    int maTran[100][100];
    int luaChon;
    printf("Nhập số hàng của ma trận: ");
    scanf("%d", &n);
    printf("Nhập số cột của ma trận: ");
    scanf("%d", &m);

    do {
        displayMenu();
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                nhapMaTran(maTran, n, m);
                break;
            case 2:
                inMaTran(maTran, n, m);
                break;
            case 3:
                inGocMaTran(maTran, n, m);
                break;
            case 4:
                inDuongBien(maTran, n, m);
                break;
            case 5:
                inDuongCheo(maTran, n, m);
                break;
            case 6:
                inSoNguyenTo(maTran, n, m);
                break;
            case 7:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ\n");
        }
    } while (luaChon != 7);

    return 0;
}

void displayMenu(){
    printf("\nMENU\n");
    printf("1. Nhập giá trị các phần tử của ma trận\n");
    printf("2. In giá trị các phần tử của ma trận theo ma trận\n");
    printf("3. In ra các phần tử ở góc theo ma trận\n");
    printf("4. In ra các phần tử nằm trên đường biên theo ma trận\n");
    printf("5. In ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận\n");
    printf("6. In ra các phần tử là số nguyên tố theo ma trận\n");
    printf("7. Thoát\n");
    printf("Lựa chọn của bạn: ");
}

void nhapMaTran(int maTran[][100], int n, int m) {
    printf("Nhập giá trị các phần tử của ma trận:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("maTran[%d][%d] = ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
}


void inMaTran(int maTran[][100], int n, int m) {
    printf("Ma trận hiện tại:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", maTran[i][j]);
        }
        printf("\n");
    }
}


void inGocMaTran(int maTran[][100], int n, int m) {
    printf("Các phần tử ở góc của ma trận:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == m - 1) ||
                (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                printf("%3d ", maTran[i][j]);
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}


void inDuongBien(int maTran[][100], int n, int m) {
    printf("Các phần tử nằm trên đường biên của ma trận:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%3d ", maTran[i][j]);
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}


void inDuongCheo(int maTran[][100], int n, int m) {
    printf("Các phần tử nằm trên đường chéo chính và chéo phụ:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j || i + j == n - 1) {
                printf("%3d ", maTran[i][j]);
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}


void inSoNguyenTo(int maTran[][100], int n, int m) {
    printf("Các phần tử là số nguyên tố trong ma trận:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num = maTran[i][j];
            int laSoNguyenTo = 1; 

            if (num < 2) {
                laSoNguyenTo = 0; 
            } else {
                for (int k = 2; k * k <= num; k++) {
                    if (num % k == 0) {
                        laSoNguyenTo = 0; 
                        break;
                    }
                }
            }

            if (laSoNguyenTo) {
                printf("%3d ", num); 
            } else {
                printf("  0 "); 
            }
        }
        printf("\n");
    }
}
