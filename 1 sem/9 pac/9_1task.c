#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int32_t swap_endian(int32_t num) {
    return ((num >> 24) & 0xFF) |  ((num >> 8) & 0xFF00) | ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000); 
}

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
    FILE *input_file = fopen("input.bin", "rb");
    if (!input_file) { 
        perror("ошибка при открытии входного файла"); 
        return 1; 
    }

    int32_t N, M; 
    fread(&N, sizeof(int32_t), 1, input_file); 
    fread(&M, sizeof(int32_t), 1, input_file);

    bool is_big_endian = ((N >> 24) & 0xFF) == 0; 
    if (!is_big_endian) { 
        N = swap_endian(N); 
        M = swap_endian(M); 
    }

    int32_t *a = (int32_t *)malloc(N * sizeof(int32_t));
    int32_t *b = (int32_t *)malloc(M * sizeof(int32_t));
    if (!a || !b) { 
        fprintf(stderr, "ошибка при выделении памяти.\n");
        fclose(input_file); 
        return 1; 
    }

    fread(a, sizeof(int32_t), N, input_file);
    fread(b, sizeof(int32_t), M, input_file);
    fclose(input_file); 

    if (!is_big_endian) {
        for (int i = 0; i < N; i++) {
            a[i] = swap_endian(a[i]);
        }
        for (int i = 0; i < M; i++) {
            b[i] = swap_endian(b[i]);
        }
    }

    int32_t *res = (int32_t *)malloc((N + M) * sizeof(int32_t));
    if (!res) { 
        fprintf(stderr, "ошибка при выделении памяти\n");
        free(a); 
        free(b); 
        return 1;
    }

    int merged_size = merge(a, N, b, M, res);

    if (!is_big_endian) {
        for (int i = 0; i < merged_size; i++) {
            res[i] = swap_endian(res[i]);
        }
    }

    FILE *output_file = fopen("output.bin", "wb");
    if (!output_file) { 
        perror("ошибка открытия файла");
        free(a); 
        free(b); 
        free(res); 
        return 1; 
    }

    fwrite(res, sizeof(int32_t), merged_size, output_file);

    fclose(output_file); 
    free(a);
    free(b);
    free(res);

    return 0; 
}
