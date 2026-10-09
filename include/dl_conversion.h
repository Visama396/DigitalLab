#ifndef DL_CONVERSION_H
#define DL_CONVERSION_H

#include <stddef.h>
#include <stdint.h>
#include "dl_result.h"

DlStatus dl_decimal_to_binary(
uint32_t value,
char *output,
size_t output_size
);

DlStatus dl_binary_to_decimal(
const char *binary,
uint32_t *output
);

#endif
