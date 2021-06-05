#include "Asteroide.h"
Asteroide::Asteroide() { dx = 0; dy = 1; x = 30; y = 1; }
Asteroide::~Asteroide() {}
void Asteroide::Borrar(System::Drawing::Graphics^ g) {

	g->Clear(Color::Black);
}
void Asteroide::Mover(System::Drawing::Graphics^ g) {


	if (y + dy + a > g->VisibleClipBounds.Bottom)
		eliminar = true;

	if (!eliminar)
		y += dy;

}