#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t read_number(FILE *file) {
    uint32_t number = 0;
    fread(&number, sizeof(uint32_t), 1, file);
    return ntohl(number);
}

void print_result(uint32_t num1, uint32_t num2) {
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, num1 + num2, num1 + num2);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "rb");
    if (file1 == NULL) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }

    FILE *file2 = fopen(argv[2], "rb");
    if (file2 == NULL) {
        printf("Failed to open %s\n", argv[2]);
        return 1;
    }

    uint32_t num1 = read_number(file1);
    uint32_t num2 = read_number(file2);

    fclose(file1);
    fclose(file2);

    print_result(num1, num2);

    return 0;
}

