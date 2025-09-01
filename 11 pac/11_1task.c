#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t read_int32(FILE *file) {
    uint8_t bytes[4];
    fread(bytes, sizeof(uint8_t), 4, file);
    return (int32_t)((bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | bytes[0]);
}

void write_int32(FILE *file, int32_t value) {
    uint8_t bytes[4];
    bytes[0] = (uint8_t)(value & 0xFF);
    bytes[1] = (uint8_t)((value >> 8) & 0xFF);
    bytes[2] = (uint8_t)((value >> 16) & 0xFF);
    bytes[3] = (uint8_t)((value >> 24) & 0xFF);
    fwrite(bytes, sizeof(uint8_t), 4, file);
}

int main() {
    FILE *input_file = fopen("input.bin", "rb");
    if (input_file == NULL) {
        perror("Ошибка открытия входного файла");
        return 1;
    }

    int32_t n = read_int32(input_file);

    int32_t *array = (int32_t *)malloc(n * sizeof(int32_t));
    if (array == NULL) {
        perror("Ошибка выделения памяти для массива");
        fclose(input_file);
        return 1;
    }

    for (int32_t i = 0; i < n; i++) {
        array[i] = read_int32(input_file);
    }

    // Close the input file
    fclose(input_file);

    int32_t *hash_table = (int32_t *)calloc(200000000, sizeof(int32_t));
    if (hash_table == NULL) {
        perror("Ошибка выделения памяти для хеш-таблицы");
        free(array);
        return 1;
    }

    int32_t unique_count = 0;
    for (int32_t i = 0; i < n; i++) {
        int32_t value = array[i];
        if (hash_table[value + 1000000000] == 0) {
            hash_table[value + 1000000000] = 1;
            array[unique_count++] = value;
        }
    }

    free(hash_table);

    FILE *output_file = fopen("output.bin", "wb");
    if (output_file == NULL) {
        perror("Ошибка открытия выходного файла");
        free(array);
        return 1;
    }

    write_int32(output_file, unique_count);

    for (int32_t i = 0; i < unique_count; i++) {
        write_int32(output_file, array[i]);
    }

    fclose(output_file);

    free(array);

    return 0;
}
