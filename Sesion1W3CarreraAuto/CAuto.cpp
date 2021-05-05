#include "CAuto.h"

CAuto::CAuto()
{
	dx = 5;
	l = 4;
	x = y = 0;
	color = 1 + rand () % 5;
	obj_chasis = new CChasis();
	obj_chasis->Cambiar_dx(dx);
	obj_chasis->Cambiar_color(color);
	obj_chasis->Cambiar_l(l);
	//Crear las 4 llantas y colocarlas en el arreglo
	arreglo_llantas = new CLlanta * [4];
	for (int i = 0; i < 4; i++)
	{
		arreglo_llantas[i] = new CLlanta();
		arreglo_llantas[i]->Cambiar_dx(dx);
		arreglo_llantas[i]->Cambiar_color(color);
	}
}

CAuto::~CAuto()
{
	delete obj_chasis;
	//Eliminar cada una de las llantas
	for (int i = 0; i < 4; i++)
	{
		delete arreglo_llantas[i];
	}
	delete arreglo_llantas;
}

void CAuto::Borrar()
{
	obj_chasis->Borrar();
	for (int i = 0; i < 4; i++)
	{
		arreglo_llantas[i]->Borrar();
	}
}

void CAuto::Mostrar()
{
	obj_chasis->Mostrar();
	for (int i = 0; i < 4; i++)
	{
		arreglo_llantas[i]->Mostrar();
	}
}

void CAuto::Mover(int MAXW, int MAXH)
{
	obj_chasis->Mover(MAXW, MAXH);
	for (int i = 0; i < 4; i++)
	{
		arreglo_llantas[i]->Mover(MAXW, MAXH);
	}
}

void CAuto::Cambiar_x(int nuevo)
{
	x = nuevo;
	obj_chasis->Cambiar_x(x);
	arreglo_llantas[0]->Cambiar_x(x);
	arreglo_llantas[1]->Cambiar_x(x+2);
	arreglo_llantas[2]->Cambiar_x(x);
	arreglo_llantas[3]->Cambiar_x(x + 2);
}

void CAuto::Cambiar_y(int nuevo)
{
	y = nuevo;
	obj_chasis->Cambiar_y(y + 1);
	arreglo_llantas[0]->Cambiar_y(y);
	arreglo_llantas[1]->Cambiar_y(y);
	arreglo_llantas[2]->Cambiar_y(y+2);
	arreglo_llantas[3]->Cambiar_y(y+2);

}

void CAuto::Cambiar_dx(int nuevo)
{
	obj_chasis->Cambiar_dx(nuevo);
	for (int i = 0; i < 4; i++)
	{
		arreglo_llantas[i]->Cambiar_dx(nuevo);
	}
}

//void CAuto::Detenerse()
//{
//	dx = 0;
//	obj_chasis->Cambiar_dx(dx);
//	for (int i = 0; i < 4; i++)
//	{ 
//		arreglo_llantas[i]->Cambiar_dx(dx);
//	}
//}
int CAuto::retornar_x()
{
	return obj_chasis->getXchasis();
}
