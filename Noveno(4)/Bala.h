#pragma once
#include "Base_Movimiento.h"
class Bala :  public Base_Movimiento
{

public:
	Bala();
	~Bala();
	void Mover(System::Drawing::Graphics^ g);
	void Mostrar(System::Drawing::Graphics^ g, 
			     System::Drawing::Bitmap^ imagen);
};

