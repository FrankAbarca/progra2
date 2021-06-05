#include "Bala.h"

Bala::Bala():Base_Movimiento()
{
	a = l = 8;
	factormovimiento = 2;
	Cambiar_direccion(movimiento::derecha);
}
Bala::~Bala()
{}
void Bala::Mover(System::Drawing::Graphics^ g)
{
	if (x + dx + l > g->VisibleClipBounds.Right) 
		eliminar = true;

	if (!eliminar)
		x += dx;
}
void Bala::Mostrar(System::Drawing::Graphics^ g,
	System::Drawing::Bitmap^ imagen)
{
	SolidBrush^ b = gcnew SolidBrush(Color::Yellow);
	g->FillEllipse(b, x, y, l, a);
}