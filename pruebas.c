#include "src/abb.h"
#include <stdio.h>
#include "pa2mm.h"
#include "string.h"

int comparador(void* _a, void* _b){
  int num1 = *(int*)_a;
  int num2 = *(int*)_b;

  return num1 - num2;
}

int* crear_entero(int entero){
  int* _entero = (int*)malloc(sizeof(int));
  *_entero = entero;

  return _entero;
}

bool imprimir_enteros(void* num, void* nada){
  if (num){
    printf("%i ", *(int*)num);
  }
  return true;
}

bool imprimir_enteros_hasta_10(void* num, void* nada){
  if (num){
    printf("%i ", *(int*)num);
  }
  return (*(int*)num < 10);
}

void imprimir_vector_enteros(int** vector_enteros, size_t tamanio_vector){
  printf("Vector enteros: ");
  for (size_t i = 0; i < tamanio_vector; i++){
    if (vector_enteros[i]){
      printf("%i ", *(vector_enteros[i]));
    }
  }
  printf("\n");
}

void destructor(void* elemento){
  if (elemento){
    printf("Elemento destruido: %i\n", *(int*)elemento);
    free(elemento);
  }
}

void crear_y_destruir_arbol(){
  abb_t* arbol = abb_crear(&comparador);

  pa2m_afirmar(arbol, "El arbol se crea correctamente");
  pa2m_afirmar((abb_vacio(arbol)) || (abb_tamanio(arbol) == 0), "El arbol esta vacio");

  abb_destruir(arbol);
}

void operaciones_para_arbol_nulo(){
  abb_t* arbol = NULL;
  int* num1 = crear_entero(1);

  pa2m_afirmar((abb_vacio(arbol)) || (abb_tamanio(arbol) == 0), "El arbol nulo esta vacio");
  pa2m_afirmar(!abb_insertar(arbol, (void*)num1), "No puedo insertar en un arbol nulo");
  pa2m_afirmar(!abb_quitar(arbol, (void*)num1), "No puedo quitar del arbol nulo");
  pa2m_afirmar(!abb_buscar(arbol, (void*)num1), "No puedo buscar un elemento en el arbol nulo");

  int contador = 0;
  pa2m_afirmar((abb_con_cada_elemento(arbol, INORDEN, &imprimir_enteros_hasta_10, &contador) == 0), "Se aplica 0 veces la funcion a cada elemento");

  int* vector_ints[15];
  pa2m_afirmar((abb_recorrer(arbol, INORDEN, (void**)&vector_ints, 15) == 0), "Se insertaron 0 elementos en el vector");

  destructor((void*)num1);
  abb_destruir(arbol);
}

void operaciones_para_arbol_vacio(){
  abb_t* arbol = abb_crear(&comparador);
  int* num1 = crear_entero(1);

  pa2m_afirmar((abb_vacio(arbol)) || (abb_tamanio(arbol) == 0), "El arbol vacio esta vacio");
  pa2m_afirmar(!abb_quitar(arbol, (void*)num1), "No puedo quitar del arbol vacio");
  pa2m_afirmar(!abb_buscar(arbol, (void*)num1), "No puedo buscar un elemento en el arbol vacio");

  int contador = 0;
  pa2m_afirmar((abb_con_cada_elemento(arbol, INORDEN, &imprimir_enteros_hasta_10, &contador) == 0), "Se aplica 0 veces la funcion a cada elemento");

  int* vector_ints[15];
  pa2m_afirmar((abb_recorrer(arbol, INORDEN, (void**)&vector_ints, 15) == 0), "Se insertaron 0 elementos en el vector");

  pa2m_afirmar(abb_insertar(arbol, (void*)num1), "Puedo insertar en un arbol nulo");
  
  abb_destruir_todo(arbol, &destructor);
}

void operaciones_para_arbol_normal(){   
  abb_t* arbol = abb_crear(&comparador);

  int* num1 = crear_entero(1);
  int* num2 = crear_entero(2);
  int* num3 = crear_entero(3);
  int* num4 = crear_entero(4);
  int* num5 = crear_entero(5);
  int* num6 = crear_entero(6);
  int* num7 = crear_entero(7);
  int* num8 = crear_entero(8);
  int* num9 = crear_entero(9);
  int* num10 = crear_entero(10);
  int* num11 = crear_entero(11);
  int* num12 = crear_entero(12);
  int* num13 = crear_entero(13);
  int* num14 = crear_entero(14);
  int* num15 = crear_entero(15);
  int* num16 = crear_entero(16);

  pa2m_afirmar(abb_vacio(arbol), "El arbol se encuentra inicialmente vacio");
  pa2m_afirmar(abb_insertar(arbol, (void*)num8), "Se pudo insertar un entero 8");
  pa2m_afirmar(abb_insertar(arbol, (void*)num12), "Se pudo insertar un entero 12");
  pa2m_afirmar(abb_insertar(arbol, (void*)num14), "Se pudo insertar un entero 14");
  pa2m_afirmar(abb_insertar(arbol, (void*)num15), "Se pudo insertar un entero 15");
  pa2m_afirmar(abb_insertar(arbol, (void*)num13), "Se pudo insertar un entero 13");  
  pa2m_afirmar(abb_insertar(arbol, (void*)num10), "Se pudo insertar un entero 10");
  pa2m_afirmar(abb_insertar(arbol, (void*)num11), "Se pudo insertar un entero 11");
  pa2m_afirmar(abb_insertar(arbol, (void*)num9), "Se pudo insertar un entero 9");  
  pa2m_afirmar(abb_insertar(arbol, (void*)num4), "Se pudo insertar un entero 4"); 
  pa2m_afirmar(abb_insertar(arbol, (void*)num6), "Se pudo insertar un entero 6");
  pa2m_afirmar(abb_insertar(arbol, (void*)num7), "Se pudo insertar un entero 7");   
  pa2m_afirmar(abb_insertar(arbol, (void*)num5), "Se pudo insertar un entero 5"); 
  pa2m_afirmar(abb_insertar(arbol, (void*)num2), "Se pudo insertar un entero 2");
  pa2m_afirmar(abb_insertar(arbol, (void*)num3), "Se pudo insertar un entero 3");
  pa2m_afirmar(abb_insertar(arbol, (void*)num1), "Se pudo insertar un entero 1");
  pa2m_afirmar(!abb_buscar(arbol, (void*)num16), "El entero 16 no esta en la lista");
  pa2m_afirmar((!abb_vacio(arbol)) && (abb_tamanio(arbol) == 15), "El arbol no esta vacio y tiene 15 elementos");


  printf("\n");
  printf("ABB in-order : ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, INORDEN, &imprimir_enteros, NULL) == 15, "Se pudieron imprimir 15 objetos (INORDER)");
  printf("ABB pre-order: ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, PREORDEN, &imprimir_enteros, NULL) == 15, "Se pudieron imprimir 15 objetos (PREORDEN)");
  printf("ABB post-order: ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, POSTORDEN, &imprimir_enteros, NULL) == 15, "Se pudieron imprimir 15 objetos (POSTORDER)");


  printf("\n");
  printf("ABB in-order hasta >=10: ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, INORDEN, &imprimir_enteros_hasta_10, NULL) == 10, "Se pudieron imprimir 10 objetos, hasta el 10(INORDER)");
  printf("ABB pre-order hasta >=10: ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, PREORDEN, &imprimir_enteros_hasta_10, NULL) == 9, "Se pudieron imprimir 9 objetos, hasta el 12(PREORDER)");
  printf("ABB post-order hasta >=10: ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, POSTORDEN, &imprimir_enteros_hasta_10, NULL) == 9, "Se pudieron imprimir 8 objetos, hasta el 11 (POSTORDER)");


  printf("\n");
  int* vector_enteros[20] = {NULL};
  int* vector_enteros2[12] = {NULL};
  size_t contador = 0;

  contador = abb_recorrer(arbol, INORDEN, (void**)vector_enteros, 20);
  pa2m_afirmar(contador == 15, "Puedo depositar todos los elementos del arbol en el vector (INORDER)");
  printf ("Insertados: %lu\n", contador);
  imprimir_vector_enteros(vector_enteros, 20);
  
  contador = abb_recorrer(arbol, PREORDEN, (void**)vector_enteros, 20);
  pa2m_afirmar(contador == 15, "Puedo depositar todos los elementos del arbol en el vector (PREORDER)");
  printf ("Insertados: %lu\n", contador);
  imprimir_vector_enteros(vector_enteros, 20);

  contador = abb_recorrer(arbol, POSTORDEN, (void**)vector_enteros, 20);
  pa2m_afirmar(contador == 15, "Puedo depositar todos los elementos del arbol en el vector (POSTORDER)");
  printf ("Insertados: %lu\n", contador);
  imprimir_vector_enteros(vector_enteros, 20);

  contador = abb_recorrer(arbol, INORDEN, (void**)vector_enteros2, 12);
  pa2m_afirmar(contador == 12, "Puedo depositar 12 elementos en el vector (INORDER)");
  printf ("Insertados: %lu\n", contador);
  imprimir_vector_enteros(vector_enteros2, 12);

  contador = abb_recorrer(arbol, INORDEN, (void**)vector_enteros2, 6);
  pa2m_afirmar(contador == 6, "Puedo depositar 6 elementos en el vector (INORDER)");
  printf ("Insertados: %lu\n", contador);
  imprimir_vector_enteros(vector_enteros2, 6);

  contador = abb_recorrer(arbol, INORDEN, (void**)vector_enteros2, 24);
  pa2m_afirmar(contador ==15, "Puedo depositar 15 elementos en el vector (INORDER)");
  printf ("Insertados: %lu\n", contador);
  imprimir_vector_enteros(vector_enteros2, 24);


  printf("\n");
  pa2m_afirmar(abb_buscar(arbol, (void*)num7) == num7, "El entero 7 esta en el arbol");
  pa2m_afirmar(abb_buscar(arbol, (void*)num11) == num11, "El entero 11 esta en el arbol");
  pa2m_afirmar(abb_quitar(arbol, (void*)num7) == num7, "Puedo quitar el nodo hoja con entero 7");
  pa2m_afirmar(abb_quitar(arbol, (void*)num11) == num11, "Puedo quitar el nodo hoja con entero 11");
  pa2m_afirmar(!abb_buscar(arbol, (void*)num7), "El entero 7 no esta en el arbol");
  pa2m_afirmar(!abb_buscar(arbol, (void*)num11), "El entero 11 no esta en el arbol");
  pa2m_afirmar(abb_tamanio(arbol) == 13, "Luego de quitar 2 enteros, mi tamanio es 13");
  printf("ABB in-order : ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, INORDEN, &imprimir_enteros, NULL) == 13, "Se pudieron imprimir 13 objetos (INORDER)");
  free(num7);
  free(num11);


  printf("\n");
  pa2m_afirmar(abb_buscar(arbol, (void*)num12) == num12, "El entero 12 esta en el arbol");
  pa2m_afirmar(abb_quitar(arbol, (void*)num12) == num12, "Pude sacar el entero 12");
  pa2m_afirmar(!abb_buscar(arbol, (void*)num12), "El entero 12 no esta en el arbol");
  pa2m_afirmar(abb_tamanio(arbol) == 12, "Luego de quitar 1 entero, mi tamanio es 12");
  printf("ABB in-order : ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, INORDEN, &imprimir_enteros, NULL) == 12, "Se pudieron imprimir 12 objetos (INORDER)");
  free(num12);

  printf("\n");
  pa2m_afirmar(abb_buscar(arbol, (void*)num8) == num8, "El entero 8 esta en el arbol");
  pa2m_afirmar(abb_quitar(arbol, (void*)num8) == num8, "Pude sacar la raiz del arbol (entero 8)");
  pa2m_afirmar(!abb_buscar(arbol, (void*)num8), "El entero 8 no esta en el arbol");
  pa2m_afirmar(abb_tamanio(arbol) == 11, "Luego de quitar 1 entero, mi tamanio es 11");
  printf("ABB in-order : ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, INORDEN, &imprimir_enteros, NULL) == 11, "Se pudieron imprimir 11 objetos (INORDER)");
  free(num8);

  printf("\n");
  pa2m_afirmar(abb_buscar(arbol, (void*)num4) == num4, "El entero 4 esta en el arbol");
  pa2m_afirmar(abb_quitar(arbol, (void*)num4) == num4, "Pude sacar el entero 4");
  pa2m_afirmar(!abb_buscar(arbol, (void*)num4), "El entero 4 no esta en el arbol");
  pa2m_afirmar(abb_tamanio(arbol) == 10, "Luego de quitar 1 entero, mi tamanio es 10");
  printf("ABB in-order : ");
  pa2m_afirmar(abb_con_cada_elemento(arbol, INORDEN, &imprimir_enteros, NULL) == 10, "Se pudieron imprimir 10 objetos (INORDER)");
  free(num4);


  printf("\n");
  destructor((void*)num16);
  abb_destruir_todo(arbol, &destructor);
}

void operaciones_para_romper_arbol(){
  abb_t* arbol = abb_crear(&comparador);

  pa2m_afirmar(abb_insertar(arbol, NULL), "Puedo insertar un elemento NULL");

  abb_destruir_todo(arbol, &destructor);


  abb_t* arbol2 = abb_crear(&comparador);

  int* num1 = crear_entero(1);
  int* num2 = crear_entero(2);
  int* num3 = crear_entero(3);
  int* num4 = crear_entero(4);
  int* num5 = crear_entero(5); 

  pa2m_afirmar(abb_insertar(arbol2, (void*)num1), "Puedo insertar el 1");
  pa2m_afirmar(abb_insertar(arbol2, (void*)num2), "Puedo insertar el 2");
  pa2m_afirmar(abb_insertar(arbol2, (void*)num3), "Puedo insertar el 3");
  pa2m_afirmar(abb_insertar(arbol2, (void*)num4), "Puedo insertar el 4");
  pa2m_afirmar(abb_con_cada_elemento(arbol2, INORDEN, &imprimir_enteros, NULL) == 4, "Se pudieron imprimir 4 objetos (INORDER)");

  pa2m_afirmar(abb_quitar(arbol2, (void*)num1) == num1, "Puedo quitar el 1");
  pa2m_afirmar(abb_quitar(arbol2, (void*)num2) == num2, "Puedo quitar el 2");
  pa2m_afirmar(abb_quitar(arbol2, (void*)num3) == num3, "Puedo quitar el 3");
  pa2m_afirmar(abb_quitar(arbol2, (void*)num4) == num4, "Puedo quitar el 4");
  pa2m_afirmar(abb_vacio(arbol2), "El arbol esta vacio");

  pa2m_afirmar(abb_insertar(arbol2, (void*)num5), "Puedo insertar el 5");
  pa2m_afirmar(abb_tamanio(arbol2) == 1, "El arbol tiene un entero");
  pa2m_afirmar(abb_con_cada_elemento(arbol2, INORDEN, &imprimir_enteros, NULL) == 1, "Se imprimio 1 objeto");
  pa2m_afirmar(abb_quitar(arbol2, (void*)num5) == num5, "Puedo quitar el 5");
  pa2m_afirmar((abb_tamanio(arbol2) == 0) && (abb_vacio(arbol2)), "El arbol ta vacio");

  free(num1);
  free(num2);
  free(num3);
  free(num4);
  free(num5);
  abb_destruir_todo(arbol2, &destructor);
}

int main(){
  pa2m_nuevo_grupo("Pruebas de ABB");

  pa2m_nuevo_grupo("Crear y destruir arbol");
  crear_y_destruir_arbol();

  pa2m_nuevo_grupo("Operar un arbol nulo");
  operaciones_para_arbol_nulo();

  pa2m_nuevo_grupo("Operar un arbol vacio");
  operaciones_para_arbol_vacio();

  pa2m_nuevo_grupo("Usar un arbol normalmente");
  operaciones_para_arbol_normal();

  pa2m_nuevo_grupo("Crear muchos errores");
  operaciones_para_romper_arbol();

  return pa2m_mostrar_reporte();
}
