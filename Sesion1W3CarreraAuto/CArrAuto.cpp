#include "CArrAuto.h"
CArrAuto::CArrAuto()
{
	n_elementos = new int;
	*n_elementos = 0;
	arreglo = NULL;
}
CArrAuto::~CArrAuto()
{
	for (int i = 0; i < *n_elementos; i++)
	{
		delete arreglo[i];
    }
	delete[]arreglo;
	delete n_elementos;
}
void CArrAuto::Insertar(int MAXW, int MAXH)
{
	CAuto** auxiliar = new CAuto * [*n_elementos+1];
	for (int i = 0; i < *n_elementos; i++)
		auxiliar[i] = arreglo[i];
	arreglo = new CAuto * [*n_elementos + 1];
	for (int i = 0; i < *n_elementos; i++)
		arreglo[i]=auxiliar[i];
	arreglo[*n_elementos] = new CAuto;
	arreglo[*n_elementos]->Cambiar_x(1);
	arreglo[*n_elementos]->Cambiar_y(5);
	*n_elementos = *n_elementos + 1;
}
void CArrAuto::Mover_todos(int MAXW, int MAXH)
{
	for (int i = 0; i < *n_elementos; i++)
	{
		arreglo[i]->Mover(MAXW, MAXH);
	}

}
void CArrAuto::Mostrar_todos()
{
	for (int i = 0; i < *n_elementos; i++)
		arreglo[i]->Mostrar();

}
void CArrAuto::Cambiar_x(int indice, int nuevovalor)
{
	arreglo[indice]->Cambiar_x(nuevovalor);
}
void CArrAuto::Cambiar_y(int indice, int nuevovalor)
{
	arreglo[indice]->Cambiar_y(nuevovalor);
}
void CArrAuto::Cambiar_dx(int indice, int nuevovalor)
{
	arreglo[indice]->Cambiar_dx(nuevovalor);
}

int CArrAuto::Retornar_x(int indice)
{
	return arreglo[indice]->retornar_x();
}
