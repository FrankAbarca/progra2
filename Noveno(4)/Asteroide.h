#pragma once
#include "Base_Movimiento.h"
class Asteroide :    public Base_Movimiento
{
public:
	Asteroide();
	~Asteroide();
	void Borrar(System::Drawing::Graphics^ g);
	void Mover(System::Drawing::Graphics^ g);
};
	

