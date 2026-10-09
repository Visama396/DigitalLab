#include "dl_result.h"

const char *dl_status_message(DlStatus status)
{
    switch (status) {
        case DL_OK:
            return "Operacion correcta.";
        case DL_INVALID_ARGUMENT:
            return "Argumento invalido.";
        case DL_OUT_OF_RANGE:
            return "Valor fuera del rango permitido.";
        case DL_BUFFER_TOO_SMALL:
            return "El buffer no tiene espacio suficiente.";
        default:
            return "Error desconocido.";
    }
}
