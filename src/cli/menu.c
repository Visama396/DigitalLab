#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dl_conversion.h"
#include "dl_menu.h"
#include "dl_result.h"

void dl_show_menu(void)
{
    printf("\n=== DigitalLab ===\n");
    printf("1. Decimal a binario\n");
    printf("2. Binario a decimal\n");
    printf("0. Salir\n");
    printf("Selecciona una opcion: ");
}

static void run_decimal_to_binary(void)
{
    uint32_t value;
    char binary[33];

    printf("Introduce un numero decimal (0 a %" PRIu32 "): ", UINT32_MAX);

    if (scanf("%" SCNu32, &value) != 1)
    {
        printf("Entrada no valida.\n");
        return;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch != ' ' && ch != '\t' && ch != '\r')
        {
            printf("Entrada no valida.\n");
            return;
        }
    }

    DlStatus status = dl_decimal_to_binary(value, binary, sizeof binary);

    if (status == DL_OK)
    {
        printf("Resultado binario: %s\n", binary);
    } else
    {
        printf("Error: %s\n", dl_status_message(status));
    }
}

static void run_binary_to_decimal(void)
{
    char binary[34];
    uint32_t decimal;

    printf("Introduce un numero binario: ");

    if (scanf("%33s", binary) != 1)
    {
        printf("No se pudo leer la entrada.\n");
        return;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch != ' ' && ch != '\t' && ch != '\r')
        {
            printf("Entrada demasiado larga o no valida.\n");
            return;
        }
    }

    DlStatus status = dl_binary_to_decimal(binary, &decimal);

    if (status == DL_OK) {
        printf("Resultado decimal: %" PRIu32 "\n", decimal);
    } else
    {
        printf("Error: %s\n", dl_status_message(status));
    }
}

void dl_run(void)
{
    char line[32];

    for (;;)
    {
        dl_show_menu();

        if (fgets(line, sizeof line, stdin) == NULL)
        {
            printf("\nHasta pronto.\n");
            return;
        }

        char *end;
        long option = strtol(line, &end, 10);

        if (end == line)
        {
            printf("Opcion no valida.\n");
            continue;
        }

        while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n')
        {
            end++;
        }

        if (*end != '\0')
        {
            printf("Opcion no valida.\n");
            continue;
        }

        switch (option)
        {
            case 1:
                run_decimal_to_binary();
                break;
            case 2:
                run_binary_to_decimal();
                break;
            case 0:
                printf("Hasta pronto.\n");
                return;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    }
}
