#include "ArrBase_Movimiento.h"

ArrBase_Movimiento::ArrBase_Movimiento() {
	n_elementos = new int;
	*n_elementos = 0;
}
ArrBase_Movimiento::~ArrBase_Movimiento() {
	for (int i = 0; i < *n_elementos; i++)
		delete arreglo[i];
	delete[] arreglo;
	delete n_elementos;
}
void ArrBase_Movimiento::Insertar(Base_Movimiento* objeto) 
{
	Base_Movimiento** auxiliar= new Base_Movimiento*[*n_elementos];
	for (int i = 0; i < *n_elementos; i++)
		auxiliar[i] = arreglo[i];
	arreglo = new Base_Movimiento * [*n_elementos+1];
	for (int i = 0; i < *n_elementos; i++)
		arreglo[i] = auxiliar[i];
	arreglo[*n_elementos] = objeto;
	*n_elementos = *n_elementos + 1;
}

void ArrBase_Movimiento::Mover_todos(Graphics^ g)
{	for (int i = 0; i < *n_elementos; i++)
		arreglo[i]->Mover(g);
}
void ArrBase_Movimiento::Mostrar_todos(Graphics^ g, Bitmap^ imagen)
{
	Eliminar();
	for (int i = 0; i < *n_elementos; i++)
		arreglo[i]->Mostrar(g,imagen);
}
void ArrBase_Movimiento::Cambiar_x(int indice, int nuevo)
{	arreglo[indice]->Cambiar_x(nuevo); }
void ArrBase_Movimiento::Cambiar_y(int indice, int nuevo)
{	arreglo[indice]->Cambiar_y(nuevo); }
void ArrBase_Movimiento::Cambiar_dx(int indice, int nuevo) 
{	arreglo[indice]->Cambiar_dx(nuevo); }
void ArrBase_Movimiento::Cambiar_dy(int indice, int nuevo)
{	arreglo[indice]->Cambiar_dy(nuevo);}
void ArrBase_Movimiento::Cambiar_a(int indice, int nuevo)
{	arreglo[indice]->Cambiar_a(nuevo);}
void ArrBase_Movimiento::Cambiar_l(int indice, int nuevo)
{	arreglo[indice]->Cambiar_l(nuevo);}
void ArrBase_Movimiento::Cambiar_color(int indice, int nuevo) 
{	arreglo[indice]->Cambiar_color(nuevo);}
int ArrBase_Movimiento::Retornar_x(int indice) { return arreglo[indice]->Retornar_x(); }
int ArrBase_Movimiento::Retornar_y(int indice) { return arreglo[indice]->Retornar_y(); }
int ArrBase_Movimiento::Retornar_dx(int indice){return arreglo[indice]->Retornar_dx();}
int ArrBase_Movimiento::Retornar_dy(int indice){return arreglo[indice]->Retornar_dy();}
int ArrBase_Movimiento::Retornar_a(int indice){return arreglo[indice]->Retornar_a();}
int ArrBase_Movimiento::Retornar_l(int indice){return arreglo[indice]->Retornar_l();}
int ArrBase_Movimiento::Retornar_color(int indice) {return arreglo[indice]->Retornar_color();}

int ArrBase_Movimiento::Retornar_nelementos()
{	return *n_elementos; }

Base_Movimiento* 
ArrBase_Movimiento::Retornar_elemento(int indice)
{
	return arreglo[indice];
}

void ArrBase_Movimiento::Eliminar()
{
	int contador = 0;
	for (int i = 0; i < *n_elementos; i++)
		if (arreglo[i]->Retornar_eliminar())
			contador++;
	Base_Movimiento** aux = new Base_Movimiento*[*n_elementos - contador];
	int j = 0;
	for (int i = 0; i < *n_elementos; i++)
		if (arreglo[i]->Retornar_eliminar() == false)
		{
			aux[j] = arreglo[i];
			j++;
		}
	arreglo = aux;
	*n_elementos = *n_elementos - contador;

}