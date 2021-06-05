#pragma once
#include <ctime>
#include "Monigote.h"
#include "Asteroide.h"
#include "ArrBase_Movimiento.h"
using namespace std;
class Controladora
{
private:
	Monigote* obj_monigote;
	ArrBase_Movimiento* obj_asteroides;
	time_t tiempo_inicial;
	bool termino;
public:
	Controladora();
	~Controladora();
	void Crear_Asteroides(Graphics^ g,Bitmap^ imagenasteroide);
	void Mover_Monigote(movimiento nuevo_movimiento);
	void Init(Bitmap^ imagenmonigote, Bitmap^ imagenasteroide);
	void Run(Graphics^ g, 
		 Bitmap^ imagenmonigote, Bitmap^ imagenasteroide);
	bool Colision(Base_Movimiento* m,
		Base_Movimiento* a);
	bool Retornar_termino();
	void Resumen_final(Graphics^ g);

	void Disparar();

};

