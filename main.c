
#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int i;
    struct nodo *enlace;
};

struct nodo *cab;
int atencion = 1;

struct nodo * ingresar_persona(struct nodo *ptr) {

    struct nodo *cabeza, *persona;

    persona = (struct nodo *) malloc(sizeof (struct nodo));
    persona->i = atencion;
    persona->enlace = NULL;

    if (ptr == NULL) {
        ptr = persona;
        cabeza = ptr;
    } else {
        cabeza = ptr;
        while (ptr->enlace != NULL) {
            ptr = ptr->enlace;
        }
        ptr -> enlace = persona;
    }
    printf("Se le asigno el número %d", atencion);
    atencion++;
    return cabeza;

}

struct nodo * atencion_persona(struct nodo *ptr) {

    struct nodo *cabeza;

    if (ptr == NULL) {
        printf("No existe persona en la fila");
        cabeza = ptr;
    } else {
        cabeza = ptr;
        cabeza = cabeza->enlace;
        printf("Pase el número ---> %d", ptr->i);
        ptr->enlace = NULL;
        free(ptr);
    }

    return cabeza;

}

void mostrar_fila(struct nodo *ptr) {
    if (ptr == NULL) {
        printf("No hay número en espera...");
    } else {
        printf("Los números en espera son: \n");
        while (ptr != NULL) {
            printf("%d\n", ptr->i);
            ptr = ptr->enlace;
        }
        printf("\n");
    }
}

int main() {
    int opc_menu;
    cab = NULL;

    do {
        printf("\n\n                  MENU ATENCION CLIENTES\n");
        printf("-------------------------------------------------------------\n");
        printf("Opción = 1 ---> Tomar número \n");
        printf("Opción = 2 ---> Atender persona \n");
        printf("Opción = 3 ---> Mostrar la lista de personas en la fila \n");
        printf("Opción = 0 ---> Salir de la atención clientes \n");
        printf("Ingrese opción: ");
        scanf("%d", &opc_menu);
        if (opc_menu == 1) {
            cab = ingresar_persona(cab);
            fflush(stdin);
            getchar();
        } else if (opc_menu == 2) {
            cab = atencion_persona(cab);
            fflush(stdin);
            getchar();
        } else if (opc_menu == 3) {
            mostrar_fila(cab);
            fflush(stdin);
            getchar();
        } else {
            printf("Programa Finalizado\n");
        }
    } while (opc_menu != 0);

    return (EXIT_SUCCESS);
}

