#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

int32_t change_endian(int32_t num) {
    return ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) | ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000); 
}

int main() {
    FILE *input_file = fopen("input.txt", "rb");   
    FILE *output_file = fopen("output.txt", "wb"); 

    if (!input_file || !output_file) {
        fprintf(stderr, "Ошибка.\n");  
        return 1;                     
    }

    int32_t count, total = 0, number; 

    fread(&count, sizeof(int32_t), 1, input_file);

    bool big_endian_input = ((count >> 24) & 0xFF) == 0;
    if (!big_endian_input) {
        count = change_endian(count); 
    }

    for (int i = 0; i < count; i++) {
        fread(&number, sizeof(int32_t), 1, input_file); 
        if (!big_endian_input) {
            number = change_endian(number); 
        }
        total += number; 
    }

    if (!big_endian_input) {
        total = change_endian(total);
    }

    fwrite(&total, sizeof(int32_t), 1, output_file);

    fclose(input_file);
    fclose(output_file);
    return 0; 
}

