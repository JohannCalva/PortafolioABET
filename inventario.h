#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <stdio.h>
#include <string.h>

void listaProdu(char produ[][20], float precio[], int canti[], int numproducto) {
    printf("\n-----------LISTA DE PRODUCTOS----------\n");
    printf("\n\tPRODUCTOS|\tPRECIO\t|\tCANTIDAD\n");

    for (int i = 0; i < numproducto; i++) {
        if (strlen(produ[i]) > 0 && canti[i] >= 0) {
            printf("\n%s\t\t|\t\t$%.2f\t|\t\t%d", produ[i], precio[i], canti[i]);
        }
    }
}

void editarProdu(char produ[][20], float precio[], int canti[], int numproducto) {
    int nProducto;
    printf("Ingrese el número de producto que desea editar: ");
    scanf("%d", &nProducto);

    if (nProducto >= 1 && nProducto <= numproducto) {
        int opcionEdicion;
        printf("\nSeleccione la opción de edición:\n");
        printf("1. Editar nombre del producto\n");
        printf("2. Editar precio del producto\n");
        printf("3. Editar cantidad del producto\n");
        printf("4. Editar todo\n");
        printf("Seleccione: ");
        scanf("%d", &opcionEdicion);

        switch (opcionEdicion) {
            case 1:
                printf("Ingrese el nuevo nombre del producto: ");
                scanf("%s", produ[nProducto - 1]);
                break;
            case 2:
                printf("Ingrese el nuevo precio del producto: $");
                scanf("%f", &precio[nProducto - 1]);
                break;
            case 3:
                printf("Ingrese la nueva cantidad del producto: ");
                scanf("%d", &canti[nProducto - 1]);
                break;
            case 4:
                printf("Ingrese el nuevo nombre del producto: ");
                scanf("%s", produ[nProducto - 1]);
                printf("Ingrese el nuevo precio del producto: $");
                scanf("%f", &precio[nProducto - 1]);
                printf("Ingrese la nueva cantidad del producto: ");
                scanf("%d", &canti[nProducto - 1]);
                break;
            default:
                printf("Intente nuevamente:\n");
        }
    } else {
        printf("El número de producto no es válido. Intente nuevamente.\n");
    }
}

void eliminarProdu(char produ[][20], float precio[], int canti[], int *np, char elim[][20], int *cont_elim, float p_elim[], int c_elim[]){
    int nProducto;
    printf("Ingrese el número de producto que desea eliminar: ");
    scanf("%d", &nProducto);

    if (nProducto >= 1 && nProducto <= *np) {
        for (int i = nProducto - 1; i < *np - 1; i++){
            strcpy(elim[*cont_elim], produ[i]);
            p_elim[*cont_elim] = precio[i];
            c_elim[*cont_elim] = canti[i];
            strcpy(produ[i], produ[i + 1]);
            precio[i] = precio[i + 1];
            canti[i] = canti[i + 1];
        }
        (*np)--;
        (*cont_elim)++;
    } else {
        printf("El número de producto no es válido. Intente nuevamente.\n");
    }
}

void imprimirEliminados(char elim[][20], float precio[], int canti[], int np) {
    printf("Productos eliminados:\n");
    printf("\n\tPRODUCTOS|\tPRECIO\t|\tCANTIDAD\n");

    for (int i = 0; i < np; i++) {
        printf("\n%s\t\t|\t\t$%.2f\t|\t\t%d", elim[i], precio[i], canti[i]);
    }
}

#endif