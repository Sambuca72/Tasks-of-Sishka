#include <stdint.h>
#include <stdio.h>

void swap_endian(int32_t *value)
{
    *value = ((*value >> 24) & 0xff) | ((*value << 8) & 0xff0000) | ((*value >> 8) & 0xff00) | ((*value << 24) & 0xff000000);
}

int main(){
    FILE *input_f = fopen("input.txt", "rb");
    FILE *output_f = fopen("output.txt", "wb");
    int32_t N, temp, sum = 0;
   
    fread(&N, sizeof(int32_t), 1, input_f);

    int is_big_endian = ((N >> 24) & 0xFF) == 0;

    if (!is_big_endian)
    {
        swap_endian(&N);
    }

    for (int i = 0; i < N; i++)
    {
        fread(&temp, sizeof(int32_t), 1, input_f);
        if (!is_big_endian)
        {
            swap_endian(&temp);
        }

        sum += temp;
    }

    if (!is_big_endian)
    {
        swap_endian(&sum);
    }

    fwrite(&sum, sizeof(int32_t), 1, output_f);

    fclose(input_f);
    fclose(output_f);
    return 0;
}
