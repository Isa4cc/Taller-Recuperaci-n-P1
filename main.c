#include <stdio.h>
#include <string.h>

void getnames(char luchadores[6][30]);

int main(int argc, char *argv[])
{
    char luchadores[6][30], finalistas[3][30];
    char finalista1[30], finalista2[30];
    int val, scores[3];
    int cont_finalistas = 0;

    printf("======================================\n");
    printf("SISTEMA DE GESTION DE LLAVES DE BOX\n");
    printf("======================================\n");
    getnames(luchadores);
    printf("\n======================================\n");
    printf("-----------------COMBATES--------------\n");
    printf("======================================\n");

    // Peleas
    for (int i = 0; i < 6; i += 2)
    {
        printf("Pelea: %s vs %s\n", luchadores[i], luchadores[i + 1]);

        do
        {
            printf("Ingrese el nombre del ganador:\n");
            fflush(stdin);
            fgets(finalistas[cont_finalistas], 30, stdin);
            int len = strlen(finalistas[cont_finalistas]) - 1;
            if (finalistas[cont_finalistas][len] == '\n')
            {
                finalistas[cont_finalistas][len] = '\0';
            }

            if (strcmp(finalistas[cont_finalistas], luchadores[i]) != 0 && strcmp(finalistas[cont_finalistas], luchadores[i + 1]) != 0)
            {
                printf("Nombre inválido. Debe ingresar exactamente el nombre de uno de los luchadores de la pelea.\n");
            }

        } while (strcmp(finalistas[cont_finalistas], luchadores[i]) != 0 && strcmp(finalistas[cont_finalistas], luchadores[i + 1]) != 0);

        printf("Ingrese la cantidad de puntos obtenidos por el ganador:\n");
        do
        {
            fflush(stdin);
            val = scanf("%d", &scores[cont_finalistas]);
            fflush(stdin);
            if (val != 1 || scores[cont_finalistas] < 0)
            {
                printf("Por favor ingrese un número válido mayor o igual a 0.\n");
            }
        } while (val != 1 || scores[cont_finalistas] < 0);

        cont_finalistas++;
    }

    // Lógica para determinar los finalistas
    if (scores[0] > scores[1] && scores[0] > scores[2])
    {
        strcpy(finalista1, finalistas[0]);
        strcpy(finalista2, (scores[1] > scores[2]) ? finalistas[1] : finalistas[2]);
    }
    else if (scores[1] > scores[0] && scores[1] > scores[2])
    {
        strcpy(finalista1, finalistas[1]);
        strcpy(finalista2, (scores[0] > scores[2]) ? finalistas[0] : finalistas[2]);
    }
    else
    {
        strcpy(finalista1, finalistas[2]);
        strcpy(finalista2, (scores[0] > scores[1]) ? finalistas[0] : finalistas[1]);
    }

    // Mostrar finalistas
    printf("\n==================\n");
    printf("FINALISTAS DEL TORNEO\n");
    printf("=====================\n");
    printf("Primer finalista: %s\n", finalista1);
    printf("Segundo finalista: %s\n", finalista2);

    // Final
    char campeon[30];
    int opci;

    do
    {
        printf("Por favor indique qué finalista ganó:\n");
        fflush(stdin);
        fgets(campeon, 30, stdin);
        int len = strlen(campeon) - 1;
        if (campeon[len] == '\n')
        {
            campeon[len] = '\0';
        }

        // Validación para que el nombre del campeón sea uno de los finalistas
        if (strcmp(campeon, finalista1) != 0 && strcmp(campeon, finalista2) != 0)
        {
            printf("Nombre inválido. Debe ingresar exactamente el nombre de uno de los finalistas: %s o %s\n", finalista1, finalista2);
        }

    } while (strcmp(campeon, finalista1) != 0 && strcmp(campeon, finalista2) != 0);

    printf("Ingrese la cantidad de puntos obtenidos por el campeón:\n");
    do
    {
        fflush(stdin);
        val = scanf("%d", &opci);
        fflush(stdin);
        if (val != 1 || opci < 0)
        {
            printf("El valor no es correcto. Ingrese un número mayor o igual a 0.\n");
        }
    } while (val != 1 || opci < 0);

    printf("Felicidades!! %s es campeón con %d puntos!\n", campeon, opci);

    return 0;
}

void getnames(char luchadores[6][30])
{
    int len, repetido;
    for (int i = 0; i < 6; i++)
    {
        do
        {
            repetido = 0;
            printf("Ingrese por favor el nombre del luchador %d\n", i + 1);
            fflush(stdin);
            fgets(luchadores[i], 30, stdin);
            len = strlen(luchadores[i]) - 1;
            if (luchadores[i][len] == '\n')
            {
                luchadores[i][len] = '\0';
            }

            // Validar que el nombre no esté vacío
            if (len < 1)
            {
                printf("El nombre no puede estar vacío. Inténtelo de nuevo.\n");
                continue;
            }

            // Validar que el nombre no esté repetido
            for (int j = 0; j < i; j++)
            {
                if (strcmp(luchadores[i], luchadores[j]) == 0)
                {
                    repetido = 1;
                    printf("El nombre ya fue ingresado. Introduzca un nombre distinto.\n");
                    break;
                }
            }
        } while (len < 1 || repetido);
    }
}
