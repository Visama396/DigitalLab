#include <assert.h>
#include <string.h>
#include <stdint.h>

#include "dl_conversion.h"

int main(void)
{
    char binary[33];

    assert(dl_decimal_to_binary(13, binary, sizeof binary) == DL_OK);
    assert(strcmp(binary, "1101") == 0);

    assert(dl_decimal_to_binary(0, binary, sizeof binary) == DL_OK);
    assert(strcmp(binary, "0") == 0);

    assert(dl_decimal_to_binary(1, binary, sizeof binary) == DL_OK);
    assert(strcmp(binary, "1") == 0);

    assert(dl_decimal_to_binary(13, NULL, 33) == DL_INVALID_ARGUMENT);

    assert(dl_decimal_to_binary(13, binary, 1) == DL_BUFFER_TOO_SMALL);

    uint32_t decimal = 0;

    assert(dl_binary_to_decimal("1101", &decimal) == DL_OK);
    assert(decimal == 13);

    assert(dl_binary_to_decimal("0", &decimal) == DL_OK);
    assert(decimal == 0);

    assert(dl_binary_to_decimal("11111111", &decimal) == DL_OK);
    assert(decimal == 255);

    assert(dl_binary_to_decimal("", &decimal) == DL_INVALID_ARGUMENT);
    assert(dl_binary_to_decimal("102", &decimal) == DL_INVALID_ARGUMENT);
    assert(dl_binary_to_decimal("10a1", &decimal) == DL_INVALID_ARGUMENT);
    assert(dl_binary_to_decimal(NULL, &decimal) == DL_INVALID_ARGUMENT);

    assert(
    dl_binary_to_decimal("100000000000000000000000000000000", &decimal)
    == DL_OUT_OF_RANGE
    );

    return 0;
}
