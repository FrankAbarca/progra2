#pragma once
class CLlanta
{
private:
	int x, y, dx, color;
public:
	CLlanta();
	~CLlanta();
	void Borrar();
	void Mostrar();
	void Mover(int MAXW, int MAXH);
	void Cambiar_x(int nuevo);
	void Cambiar_y(int nuevo);
	void Cambiar_dx(int nuevo);
	void Cambiar_color(int nuevo);
};

