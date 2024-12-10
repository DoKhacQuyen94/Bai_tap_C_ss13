#include <stdio.h>

int arr[100]; 
int soPhanTu = 0;    
void displayMenu();
void nhapMang();
void inMang();
void themPhanTu();
void suaPhanTu();
void xoaPhanTu();
void sapXepTangDan();
void sapXepGiamDan();
void timKiemTuyenTinh();
void timKiemNhiPhan();

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhapMang();
                break;
            case 2:
                inMang();
                break;
            case 3:
                themPhanTu();
                break;
            case 4:
                suaPhanTu();
                break;
            case 5:
                xoaPhanTu();
                break;
            case 6: {
                int luaChonCon;
                printf("\na. Giảm dần\n");
                printf("b. Tăng dần\n");
                printf("Lựa chọn của bạn (1: Giảm dần, 2: Tăng dần): ");
                scanf("%d", &luaChonCon);
                if (luaChonCon == 1)
                    sapXepGiamDan();
                else
                    sapXepTangDan();
                inMang();
                break;
            }
            case 7: {
                int luaChonCon;
                printf("\na. Tìm kiếm tuyến tính\n");
                printf("b. Tìm kiếm nhị phân\n");
                printf("Lựa chọn của bạn (1: Tuyến tính, 2: Nhị phân): ");
                scanf("%d", &luaChonCon);
                if (luaChonCon == 1)
                    timKiemTuyenTinh();
                else {
                    sapXepTangDan();
                    timKiemNhiPhan();
                }
                break;
            }
            case 8:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 8);

    return 0;
}
void displayMenu(){
    printf("\nMENU\n");
    printf("1. Nhập số phần tử cần nhập và giá trị các phần tử\n");
    printf("2. In ra giá trị các phần tử đang quản lý\n");
    printf("3. Thêm một phần từ vào vị trí chỉ định\n");
    printf("4. Sửa một phần từ ở vị trí chỉ định\n");
    printf("5. Xóa một phần từ ở vị trí chỉ định\n");
    printf("6. Sắp xếp các phần tử\n");
    printf("7. Tìm kiếm phần tử nhập vào\n");
    printf("8. Thoát\n");
    printf("Lựa chọn của bạn: ");
}
void nhapMang() {
    printf("Nhập số phần tử: ");
    scanf("%d", &soPhanTu);
    for (int i = 0; i < soPhanTu; i++) {
        printf("Nhập phần tử [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inMang() {
    printf("Các phần tử trong mảng: ");
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu() {
    int position, giaTri;
    printf("Nhập vị trí muốn thêm (1-%d): ", soPhanTu + 1);
    scanf("%d", &position);
    printf("Nhập giá trị muốn thêm: ");
    scanf("%d", &giaTri);
    for (int i = soPhanTu; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = giaTri;
    soPhanTu++;
    printf("Thêm phần tử thành công.\n");
}

void suaPhanTu() {
    int position, giaTri;
    printf("Nhập vị trí muốn sửa (1-%d): ", soPhanTu);
    scanf("%d", &position);
    if (position < 1 || position > soPhanTu) {
        printf("Vị trí không hợp lệ.\n");
        return;
    }
    printf("Nhập giá trị mới: ");
    scanf("%d", &giaTri);
    arr[position - 1] = giaTri;
    printf("Sửa phần tử thành công.\n");
}

void xoaPhanTu() {
    int position;
    printf("Nhập vị trí muốn xóa (1-%d): ", soPhanTu);
    scanf("%d", &position);
    for (int i = position - 1; i < soPhanTu - 1; i++) {
        arr[i] = arr[i + 1];
    }
    soPhanTu--;
    printf("Xóa phần tử thành công.\n");
}

void sapXepTangDan() {
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sapXepGiamDan() {
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void timKiemTuyenTinh() {
    int x;
    int check=-1;
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &x);
    for (int i = 0; i < soPhanTu; i++) {
        if (arr[i] == x) {
            printf("Phần tử %d tìm thấy ở vị trí %d.\n", x, i + 1);
            check =1;
        }
    }
    if (check==-1){
        printf("Phần tử %d không tồn tại.\n", x);
    }
    
}

void timKiemNhiPhan() {
    int x, start = 0, end = soPhanTu - 1;
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &x);
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == x) {
            printf("Phần tử %d tìm thấy ở vị trí %d.\n", x, mid + 1);
            return;
        }
        if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    printf("Phần tử %d không tồn tại.\n", x);
}
