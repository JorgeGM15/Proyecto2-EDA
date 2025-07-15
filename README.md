# Gestor de Tareas con Pilas y Colas en C

## 📖 Descripción del Proyecto

Este es un **Gestor de Tareas (To-Do List)** desarrollado en C que funciona a través de la línea de comandos. El proyecto es un ejemplo práctico de cómo aplicar estructuras de datos fundamentales para resolver un problema común. Utiliza una **Cola** para gestionar las tareas pendientes y una **Pila** para almacenar las tareas ya completadas.

### Lógica de las Estructuras de Datos
* **Cola (Tareas Pendientes)**: Se basa en el principio **FIFO (First-In, First-Out)**. La primera tarea que agregas es la primera que se te sugiere para completar, simulando una fila de espera ordenada.
* **Pila (Tareas Realizadas)**: Funciona con el principio **LIFO (Last-In, First-Out)**. La tarea completada más recientemente se muestra en la parte superior de la lista, facilitando la revisión de tu progreso inmediato.

---

## ✨ Características

* **Añadir Tareas**: Permite registrar tareas iniciales y agregar nuevas durante la ejecución.
* **Realizar Tareas**: Mueve la tarea más antigua de la lista de "pendientes" a la lista de "realizadas".
* **Estado General**: Muestra en cualquier momento qué tareas han sido completadas y cuáles están pendientes.
* **Eliminar Tareas**: Ofrece la flexibilidad de eliminar una tarea específica de la lista de pendientes.
* **Menú Interactivo**: Toda la interacción se realiza a través de un menú de consola simple y claro.

---

## 🛠️ Tecnologías Utilizadas

* **Lenguaje**: C (Estándar C99)
* **Estructuras de Datos**: Listas Ligadas, Pilas (Stacks) y Colas (Queues).
* **Gestión de Memoria**: Uso de `malloc` y `free` para la asignación dinámica de memoria.

---

## ⚙️ Compilación y Ejecución

Para compilar y correr el proyecto, necesitas un compilador de C como **GCC**.

1.  **Clona o descarga el repositorio.**
2.  **Abre una terminal** en el directorio del proyecto.
3.  **Compila el código** con el siguiente comando:
    ```bash
    gcc nombre_del_archivo.c -o gestor_tareas
    ```
    *(Reemplaza `nombre_del_archivo.c` con el nombre de tu archivo C)*.

4.  **Ejecuta el programa**:
    * En Windows:
        ```bash
        gestor_tareas.exe
        ```
    * En Linux o macOS:
        ```bash
        ./gestor_tareas
        ```
