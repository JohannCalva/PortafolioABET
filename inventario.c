#include "inventario.h"

int main(void) {
    char produ[20][20];
    char eliminados[20][20];
    float precio[20];
    float p_eliminados[20];
    int canti[20];
    int c_eliminados[20];
    int contador = 0;
    int contador_eliminados = 0;
    int np = 0;
    int op;

    do {
        printf("\n");
        printf("\n-------SISTEMA DE INVENTARIOS-------\n");
        printf("1.Registrar productos\n");
        printf("2.Ver inventario\n");
        printf("3.Editar productos\n");
        printf("4.Eliminar productos\n");
        printf("5.Ver productos eliminados\n");
        printf("6.Salir del programa\n");
        printf("\nSeleccione:");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Cuantos productos desea ingresar: ");
                scanf("%d", &np);

                for (int i = 0; i < np; i++) {
                    printf("\nRegistre el producto %d: ", contador + 1);
                    scanf("%s", produ[contador]);
                    printf("Ingrese el precio de %s: $", produ[contador]);
                    scanf("%f", &precio[contador]);
                    printf("Ingrese las Unidades de %s: ", produ[contador]);
                    scanf("%d", &canti[contador]);
                    contador++;
                }
                break;
            case 2:
                listaProdu(produ, precio, canti, contador);
                break;
            case 3:
                editarProdu(produ, precio, canti, contador);
                break;
            case 4:
                eliminarProdu(produ, precio, canti, &contador, eliminados, &contador_eliminados, p_eliminados, c_eliminados);
                break;
            case 5:
                imprimirEliminados(eliminados, p_eliminados, c_eliminados, contador_eliminados);
                break;
            case 6:
                break;
            default:
                printf("Intente nuevamente.\n");
        }
    } while (op != 6);
    
    return 0;
}