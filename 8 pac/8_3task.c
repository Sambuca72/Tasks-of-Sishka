#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Функция для чтения int32 из буфера
int32_t read_int32(const unsigned char *buffer, int *offset) {
    int32_t value = (buffer[*offset + 3] << 24) | (buffer[*offset + 2] << 16) |
                    (buffer[*offset + 1] << 8) | buffer[*offset];
    *offset += 4;
    return value;
}

// Функция для записи int32 в буфер
void write_int32(unsigned char *buffer, int *offset, int32_t value) {
    buffer[*offset] = value & 0xFF;
    buffer[*offset + 1] = (value >> 8) & 0xFF;
    buffer[*offset + 2] = (value >> 16) & 0xFF;
    buffer[*offset + 3] = (value >> 24) & 0xFF;
    *offset += 4;
}

// Функция для слияния двух отсортированных последовательностей
int merge(const int *a, int ak, const int *b, int bk, int *res) {
    int i = 0, j = 0, k = 0;
    while (i < ak && j < bk) {
        if (a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }
    while (i < ak) {
        res[k++] = a[i++];
    }
    while (j < bk) {
        res[k++] = b[j++];
    }
    return k;
}

int main() {
    FILE *input_file = fopen("input.txt", "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *buffer = (unsigned char *)malloc(file_size);
    fread(buffer, 1, file_size, input_file);
    fclose(input_file);

    int offset = 0;
    int N = read_int32(buffer, &offset);
    int M = read_int32(buffer, &offset);

    int *a = (int *)malloc(N * sizeof(int));
    int *b = (int *)malloc(M * sizeof(int));
    int *res = (int *)malloc((N + M) * sizeof(int));

    for (int i = 0; i < N; i++) {
        a[i] = read_int32(buffer, &offset);
    }
    for (int i = 0; i < M; i++) {
        b[i] = read_int32(buffer, &offset);
    }

    int rk = merge(a, N, b, M, res);

    FILE *output_file = fopen("output.txt", "wb");
    if (!output_file) {
        perror("Failed to open output file");
        free(a);
        free(b);
        free(res);
        free(buffer);
        return 1;
    }

    offset = 0;
    for (int i = 0; i < rk; i++) {
        write_int32(buffer, &offset, res[i]);
    }

    fwrite(buffer, 1, offset, output_file);
    fclose(output_file);

    free(a);
    free(b);
    free(res);
    free(buffer);
    return 0;
}
