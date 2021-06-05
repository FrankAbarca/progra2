#pragma once
#include <vector>
#include "Base_Movimiento.h"
#include "Bala.h"
using namespace std;
class Monigote : public Base_Movimiento
{
private:
	vector<Bala*> misbalas;
public:
	Monigote();
	~Monigote();
	void Mover(System::Drawing::Graphics^ g);
	void Disparar();
	void Mover_Balas(Graphics^ g);
	int Retornar_cantidad_balas();
	Bala* Retornar_bala_enpos(int pos);
};

