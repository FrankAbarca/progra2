#pragma once
#include"CAuto.h"
class CArrAuto
{
private:
	int* n_elementos;
	CAuto** arreglo;
public:
	CArrAuto();
	~CArrAuto();
	void Insertar(int MAXW, int MAXH);
	void Mover_todos(int MAXW, int MAXH);
	void Mostrar_todos();
	void Cambiar_x(int indice, int nuevovalor);
	void Cambiar_y(int indice, int nuevovalor);
	void Cambiar_dx(int indice, int nuevovalor);
	int Retornar_x(int indice);
};


