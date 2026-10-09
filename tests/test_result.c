#include <assert.h>
#include <string.h>

#include "dl_result.h"

int main(void)
{
    assert(strcmp(
        dl_status_message(DL_OK),
        "Operacion correcta."
    ) == 0);

    assert(strcmp(
        dl_status_message(DL_INVALID_ARGUMENT),
        "Argumento invalido."
    ) == 0);

    assert(strcmp(
        dl_status_message(DL_OUT_OF_RANGE),
        "Valor fuera del rango permitido."
    ) == 0);

    assert(strcmp(
        dl_status_message(DL_BUFFER_TOO_SMALL),
        "El buffer no tiene espacio suficiente."
    ) == 0);

    return 0;
}
