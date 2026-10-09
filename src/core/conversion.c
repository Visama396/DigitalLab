#include "dl_conversion.h"

DlStatus dl_decimal_to_binary(uint32_t value, char *output, size_t output_size)
{
    if (output == NULL)
    {
        return DL_INVALID_ARGUMENT;
    }

    if (output_size == 0)
    {
        return DL_BUFFER_TOO_SMALL;
    }

    char temp[32];
    size_t length = 0;

    do
    {
        temp[length] = (char)('0'+(value%2));
        length++;
        value /= 2;
    } while (value > 0);

    if (output_size <= length)
    {
        return DL_BUFFER_TOO_SMALL;
    }

    for (size_t i = 0; i < length; i++)
    {
        output[i] = temp[length - 1 - i];
    }

    output[length] = '\0';

    return DL_OK;
}

DlStatus dl_binary_to_decimal(const char *binary, uint32_t *output)
{
    if (binary == NULL || output == NULL)
    {
        return DL_INVALID_ARGUMENT;
    }

    if (binary[0] == '\0')
    {
        return DL_INVALID_ARGUMENT;
    }

    uint32_t result = 0;

    for (size_t i = 0; binary[i] != '\0'; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            return DL_INVALID_ARGUMENT;
        }

        uint32_t bit = (uint32_t)(binary[i] - '0');

        if (result > (UINT32_MAX - bit) / 2)
        {
            return DL_OUT_OF_RANGE;
        }

        result = result * 2 + bit;
    }

    *output = result;

    return DL_OK;
}
