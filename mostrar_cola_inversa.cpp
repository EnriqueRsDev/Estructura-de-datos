#include <iostream>
using namespace std;

/*                Estructura de los nodos de la cola
------------------------------------------------------------------------*/
struct nodo
{
     int nro;
     struct nodo *sig;
};

/*                      Estructura para la cola
------------------------------------------------------------------------*/
struct cola
{
     nodo *delante;
     nodo *atras;
};

/*                        Encolar un elemento a la cola
------------------------------------------------------------------------*/
void encolar(struct cola &q, int valor)
{
     struct nodo *aux = new (struct nodo);

     aux->nro = valor;
     aux->sig = NULL;

     if (q.delante == NULL)
          q.delante = aux; // encolamos el primero elemento
     else
          (q.atras)->sig = aux;

     q.atras = aux; // este puntero siempre apunta al ultimo elemento en la cola
}

/*                        Desencolar un elemento
------------------------------------------------------------------------*/
int desencolar(struct cola &q)
{
     int num;
     struct nodo *aux;

     aux = q.delante; // usamos "aux" para apuntar al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sig;
     delete (aux); // permite liberar la memoria a la cual apuntaba aux

     return num;
}

/*                        Mostrar la cola
------------------------------------------------------------------------*/
void mostrar_cola(struct cola q)
{

     struct nodo *aux;

     aux = q.delante;

     while (aux != NULL)
     {
          cout << "   " << aux->nro;
          aux = aux->sig;
     }
}
/*                        Mostrar cola inversa
------------------------------------------------------------------------*/

void mostrar_cola_inversa(struct cola q)
{
     struct nodo *anterior = NULL;     
     struct nodo *actual = q.delante; 

     // recorriendo la lista
     while (actual != NULL)
     {
          // complicado: observe el siguiente nodo
          struct nodo *next = actual->sig;

          actual->sig = anterior;

          // avanzando los punteros
          anterior = actual;
          actual = next;
     }

     // Apuntando al nuevo frente
     q.delante = anterior;

     // imprimiendo
     struct nodo *aux;
     aux = q.delante;

     while (aux != NULL)
     {
          cout << "   " << aux->nro;
          aux = aux->sig;
     }
}

/*              Vaciando la cola
------------------------------------------------------------------------*/
void vaciaCola(struct cola &q)
{
     struct nodo *aux;

     while (q.delante != NULL)
     {
          aux = q.delante;
          q.delante = aux->sig;
          delete (aux);
     }
     q.delante = NULL;
     q.atras = NULL;
}

/*                        Generando el Men�
------------------------------------------------------------------------*/
void menu()
{
     cout << "\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
     cout << " 1. ENCOLAR                               " << endl;
     cout << " 2. DESENCOLAR                            " << endl;
     cout << " 3. MOSTRAR COLA                          " << endl;
     cout << " 4. MOSTRAR COLA INVERSA                  " << endl;
     cout << " 5. VACIAR COLA                           " << endl;
     cout << " 6. SALIR                                 " << endl;

     cout << "\n INGRESE OPCION: ";
}

/*                        Funcion Principal
------------------------------------------------------------------------*/
int main()
{
     struct cola q;

     q.delante = NULL;
     q.atras = NULL;

     // declarando variables
     int dato; // valor a encolar
     int op;   // opcion del menu
     int x;    // numero que devuelve la funcon pop

     system("color 0e");

     do
     {
          menu();
          cin >> op;

          switch (op)
          {
          case 1:

               cout << "\n VALOR A ENCOLAR: ";
               cin >> dato;
               encolar(q, dato); // llamamos el m�tod para agregar un elemento a la cola
               cout << "\n\n\t\tNumero " << dato << " encolado...\n\n";
               break;

          case 2:

               x = desencolar(q); // accionamos el m�todo para remover un elemento de la cola
               cout << "\n\n\t\tNumero " << x << " desencolado...\n\n";
               break;

          case 3:
               cout << "\n\n MOSTRANDO COLA\n\n";
               if (q.delante != NULL)
                    mostrar_cola(q); // aqui llamamos al m�todo para imprimir en pantalla la cola
               else
                    cout << "\n\n\tCola vacia...!" << endl;
               break;

          case 4:
               cout << "\n\n MOSTRANDO COLA INVERSA\n\n";
               if (q.delante != NULL)
                    mostrar_cola_inversa(q); // aqui llamamos al m�todo para imprimir en pantalla la cola
               else
                    cout << "\n\n\tCola vacia...!" << endl;
               break;

          case 5:

               vaciaCola(q); // llamamos el m�todo para vaciar todos los elementos encolados
               cout << "\n\n\t\tHecho...\n\n";
               break;
          }

          cout << endl
               << endl;
          system("pause");
          system("cls");

     } while (op != 6);

     return 0;
}
