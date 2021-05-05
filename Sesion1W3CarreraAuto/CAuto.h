#pragma once
#include"CLlanta.h"
#include"CChasis.h"
#include<iostream>
class CAuto
{
private:
	int dx, color;
	int x, y, a, l;
	CChasis* obj_chasis;
	CLlanta** arreglo_llantas;
public:
	CAuto();
	~CAuto();
	void Borrar();
	void Mostrar();
	void Mover(int MAXW, int MAXH);
	void Cambiar_x(int nuevo);
	void Cambiar_y(int nuevo);
	void Cambiar_dx(int nuevo);
	int retornar_x();
	//void Detenerse();
};

