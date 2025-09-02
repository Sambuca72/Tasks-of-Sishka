#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t read_int32(FILE *file) {
    uint8_t bytes[4]; 
    if (fread(bytes, sizeof(uint8_t), 4, file) != 4) { 
        fprintf(stderr, "ошибка при чтении\n"); 
        exit(1);
    }
    return (int32_t)((bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | bytes[0]);
}

void write_int32(FILE *file, int32_t value) {
    uint8_t bytes[4]; 
    bytes[0] = (uint8_t)(value & 0xFF); 
    bytes[1] = (uint8_t)((value >> 8) & 0xFF); 
    bytes[2] = (uint8_t)((value >> 16) & 0xFF); 
    bytes[3] = (uint8_t)((value >> 24) & 0xFF); 
    // запись 4 байт в файл
    if (fwrite(bytes, sizeof(uint8_t), 4, file) != 4) { 
        fprintf(stderr, "ошибка при записи\n"); 
        exit(1); 
    }
}

int main() {
    FILE *input_file = fopen("input.bin", "rb");
    if (input_file == NULL) { 
        perror("ошибка при открытии входного файла"); 
        return 1; 
    }

    int32_t A = read_int32(input_file); 
    int32_t B = read_int32(input_file); 

    fclose(input_file);

    int64_t sum = (int64_t)A + (int64_t)B; 
    int32_t half_sum = (int32_t)(sum >> 1); 

    FILE *output_file = fopen("output.bin", "wb");
    if (output_file == NULL) { 
        perror("ошибка при открытии выходного файла"); 
        return 1;
    }

    write_int32(output_file, half_sum);
    fclose(output_file);
    return 0; 
}
