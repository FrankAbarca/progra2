#include "Monigote.h"

Monigote::Monigote():Base_Movimiento()
{	x = 10;
	y = 10;
	dx = dy = 0;
	factormovimiento = 8;
	direccion = movimiento::ninguno;
	misbalas = vector<Bala*>();
}
Monigote::~Monigote() 
{}
void Monigote::Mover(System::Drawing::Graphics^ g) 
{
	if (x + dx<g->VisibleClipBounds.Left ||
		x + dx + l> g->VisibleClipBounds.Right) 
		dx = 0;
	if (y + dy<g->VisibleClipBounds.Top || 
		y + dy + a> g->VisibleClipBounds.Bottom) 
		dy = 0;
		x += dx;
		y += dy;
}

void Monigote::Disparar() 
{
	Bala* nuevo = new Bala();
	nuevo->Cambiar_x(x + l);
	nuevo->Cambiar_y(y + a/2);
	misbalas.push_back(nuevo);
}
void Monigote::Mover_Balas(Graphics^ g)
{
	for (int i = 0; i < misbalas.size(); i++)
	{
		if (misbalas.at(i)->Retornar_eliminar())
			misbalas.erase(misbalas.begin() + i);
	}
	for (int i = 0; i < misbalas.size(); i++)
	{	misbalas[i]->Mover(g);
		misbalas.at(i)->Mostrar(g, nullptr);
	}
}
int Monigote::Retornar_cantidad_balas()
{
	return  misbalas.size();
}
Bala* Monigote::Retornar_bala_enpos(int pos)
{
	return misbalas.at(pos);
}