#include <stdio.h>
#include <stdlib.h>

#define MAX_TAREAS 10
#define TAMANO_TAREA 100

// Definición de la estructura de nodo para la lista ligada
struct Nodo {
    char tarea[TAMANO_TAREA];
    struct Nodo *next;
};

// Definición de la estructura de cola
struct Cola {
    struct Nodo *inicio;
    struct Nodo *fin;
};

// Definición de la estructura de pila
struct Pila {
    struct Nodo *tope;
};

// Función para inicializar una cola vacía
void iniciarCola(struct Cola *cola) {
    cola->inicio = NULL;
    cola->fin = NULL;
}

// Función para inicializar una pila vacía
void iniciarPila(struct Pila *pila) {
    pila->tope = NULL;
}

// Función para agregar una tarea a la lista
void agregarTarea(struct Nodo **lista, char *tarea) {
    // Crear un nuevo nodo para la tarea
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    // Copiar la tarea al nodo
    int i = 0;
    while (tarea[i] != '\0' && i < TAMANO_TAREA - 1) {
        nuevoNodo->tarea[i] = tarea[i];
        i++;
    }
    nuevoNodo->tarea[i] = '\0';
    // Agregar el nuevo nodo al inicio de la lista
    nuevoNodo->next = *lista;
    *lista = nuevoNodo;
}

// Función para mostrar todas las tareas de la lista
void mostrarLista(struct Nodo *lista) {
    // Iterar sobre la lista y mostrar cada tarea
    while (lista != NULL) {
        printf("%s\n", lista->tarea);
        lista = lista->next;
    }
}

// Función para agregar una tarea a la cola de tareas pendientes
void enqueue(struct Cola *cola, char *tarea) {
    // Crear un nuevo nodo para la tarea
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    // Copiar la tarea al nodo
    int i = 0;
    while (tarea[i] != '\0' && i < TAMANO_TAREA - 1) {
        nuevoNodo->tarea[i] = tarea[i];
        i++;
    }
    nuevoNodo->tarea[i] = '\0';
    // Establecer el siguiente del nuevo nodo como NULL
    nuevoNodo->next = NULL;

    // Verificar si la cola está vacía
    if (cola->inicio == NULL) {
        // Si la cola está vacía, el nuevo nodo se convierte tanto en el primero como en el último
        cola->inicio = nuevoNodo;
        cola->fin = nuevoNodo;
    } else {
        // Si la cola no está vacía, se agrega el nuevo nodo al final y se actualiza el puntero al final
        cola->fin->next = nuevoNodo;
        cola->fin = nuevoNodo;
    }
}

// Función para realizar una tarea 
void push(struct Cola *cola, struct Pila *pila) {
    if (cola->inicio == NULL) {
        printf("No hay tareas pendientes.\n");
        return;
    }

    // Sacar la tarea de la cola
    struct Nodo *realizada = cola->inicio;
    cola->inicio = cola->inicio->next;

    // Mostrar la tarea realizada
    printf("Tarea realizada: %s\n", realizada->tarea);

    // Agregar la tarea realizada a la pila de tareas realizadas
    realizada->next = pila->tope;
    pila->tope = realizada;
}

// Función para eliminar una tarea de la cola (Dequeue)
void dequeue(struct Cola *cola) {
    if (cola->inicio == NULL) {
        printf("No hay tareas para eliminar.\n");
        return;
    }

    printf("Tareas pendientes:\n");
    mostrarLista(cola->inicio);

    int numTarea;
    do {
        printf("Seleccione el número de la tarea que desea eliminar: ");
        scanf("%d", &numTarea);
        if (numTarea < 1) {
            printf("Número de tarea inválido. Intente de nuevo.\n");
        }
    } while (numTarea < 1);

    struct Nodo *anterior = NULL;
    struct Nodo *actual = cola->inicio;
    int contador = 1;
    while (contador < numTarea) {
        anterior = actual;
        actual = actual->next;
        contador++;
    }

    if (anterior != NULL) {
        anterior->next = actual->next;
        if (actual == cola->fin) {
            cola->fin = anterior;
        }
    } else {
        cola->inicio = actual->next;
        if (cola->inicio == NULL) {
            cola->fin = NULL;
        }
    }
    free(actual);
    printf("Tarea eliminada correctamente.\n");
}

// Función para mostrar el estado de la lista (tareas realizadas y pendientes)
void mostrarEstado(struct Cola *cola, struct Pila *pila) {
    // Mostrar las tareas realizadas
    printf("Tareas realizadas:\n");
    mostrarLista(pila->tope);
    printf("\n");
    // Mostrar las tareas pendientes
    printf("Tareas pendientes:\n");
    mostrarLista(cola->inicio);
}

int main() {
    // Inicializar la cola y la pila
    struct Cola cola;
    struct Pila pila;
    iniciarCola(&cola);
    iniciarPila(&pila);

    // Solicitar al usuario que ingrese las tareas
    int numTareas;
    do {
        printf("Ingrese el número de tareas que desea realizar (máximo %d): ", MAX_TAREAS);
        scanf("%d", &numTareas);
    } while (numTareas < 0 || numTareas > MAX_TAREAS);

    // Pedir al usuario que ingrese las tareas y agregarlas a la cola de tareas pendientes
    printf("Ingrese las tareas que desea realizar:\n");
    for (int i = 0; i < numTareas; i++) {
        char tarea[TAMANO_TAREA];
        printf("Tarea %d: ", i + 1);
        scanf(" %[^\n]", tarea);
        enqueue(&cola, tarea);
    }

    int opcion;
    do {
        // Mostrar el menú de opciones
        printf("\nOperacion que desea realizar:\n");
        printf("1.- Realizar tarea\n");
        printf("2.- Mostrar estado de la lista\n");
        printf("3.- Registrar tarea\n");
        printf("4.- Eliminar tarea\n");
        printf("5.- Salir\n");
        scanf("%d", &opcion);

        // Ejecutar la opción seleccionada por el usuario
        switch (opcion) {
            case 1:
                push(&cola, &pila);
                break;
            case 2:
                mostrarEstado(&cola, &pila);
                break;
            case 3: {
                // Verificar si la lista de tareas no está llena
                if (cola.fin != NULL && numTareas < MAX_TAREAS) {
                    char tarea[TAMANO_TAREA];
                    printf("Ingrese la tarea que desea registrar: ");
                    scanf(" %[^\n]", tarea);
                    enqueue(&cola, tarea);
                    numTareas++;
                } else {
                    printf("La lista de tareas está llena o se ha alcanzado el límite máximo de tareas.\n");
                }
                break;
            }
            case 4:
                dequeue(&cola);
                numTareas--;
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Por favor, seleccione nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}