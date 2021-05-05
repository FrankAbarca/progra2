#pragma once
#include<iostream>
using namespace std;
using namespace System;
class CChasis
{
private:
	int x, y, l, dx, color;
public:
	CChasis();
	~CChasis();
	void Borrar();
	void Mostrar();
	void Mover(int MAXW, int MAXH);
	void Cambiar_x(int nuevo);
	void Cambiar_y(int nuevo);
	void Cambiar_l(int nuevo);
	void Cambiar_color(int nuevo);
	void Cambiar_dx(int nuevo);
	int getXchasis();
};

