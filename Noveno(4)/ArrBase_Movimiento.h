#pragma once
#include "Base_Movimiento.h"
class ArrBase_Movimiento
{
private:
	int* n_elementos;
	Base_Movimiento** arreglo;
public:
	ArrBase_Movimiento();
	~ArrBase_Movimiento();
	void Insertar(Base_Movimiento *objeto);
	void Mover_todos(Graphics ^g);
	void Mostrar_todos(Graphics^ g, Bitmap ^imagen);
	void Cambiar_x(int indice, int nuevo);
	void Cambiar_y(int indice, int nuevo);
	void Cambiar_dx(int indice, int nuevo);
	void Cambiar_dy(int indice, int nuevo);
	void Cambiar_a(int indice, int nuevo);
	void Cambiar_l(int indice, int nuevo);
	void Cambiar_color(int indice, int nuevo);
	int Retornar_x(int indice);
	int Retornar_y(int indice);
	int Retornar_dx(int indice);
	int Retornar_dy(int indice);
	int Retornar_a(int indice);
	int Retornar_l(int indice);
	int Retornar_color(int indice);
	int Retornar_nelementos();
	Base_Movimiento* Retornar_elemento(int indice);
	void Eliminar();

};

