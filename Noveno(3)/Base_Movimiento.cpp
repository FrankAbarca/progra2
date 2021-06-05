#include<iostream>
#include "Base_Movimiento.h"
using namespace System;
using namespace std;

Base_Movimiento::Base_Movimiento() { eliminar = false;  }
Base_Movimiento::~Base_Movimiento() {}

void Base_Movimiento::Borrar(System::Drawing::Graphics^ g) {}
void Base_Movimiento::Mover(System::Drawing::Graphics^ g) {}
void Base_Movimiento::Mostrar(System::Drawing::Graphics^ g, System::Drawing::Bitmap^ imagen) 
{
	Rectangle porcion = Rectangle(col * l, fil * a, l, a);
	imagen->MakeTransparent(imagen->GetPixel(1, 1)); // COLOR TRANSPARENTE
	g->DrawImage(imagen, x, y, porcion, GraphicsUnit::Pixel);
	col++;
	if (col >= maxcol)
	{
		fil++;
		if (fil >= maxfil)
			fil = 0;
		col = 0;
	}

}
void Base_Movimiento::Cambiar_x(int nuevo) { x = nuevo; }
void Base_Movimiento::Cambiar_y(int nuevo) { y = nuevo; }
void Base_Movimiento::Cambiar_dx(int nuevo) { dx = nuevo; }
void Base_Movimiento::Cambiar_dy(int nuevo) { dy = nuevo; }
void Base_Movimiento::Cambiar_a(int nuevo) { a = nuevo; }
void Base_Movimiento::Cambiar_l(int nuevo) { l = nuevo; }
void Base_Movimiento::Cambiar_color(int nuevo) { color = nuevo; }
int Base_Movimiento::Retornar_x() { return x; }
int Base_Movimiento::Retornar_y() { return y; }
int Base_Movimiento::Retornar_dx() { return dx; }
int Base_Movimiento::Retornar_dy() { return dy; }
int Base_Movimiento::Retornar_a() { return a; }
int Base_Movimiento::Retornar_l() { return l; }
int Base_Movimiento::Retornar_color() { return color; }
void Base_Movimiento::Cambiar_eliminar(bool nuevo)
{	eliminar = nuevo;  }
bool Base_Movimiento::Retornar_eliminar()
{	return eliminar; }

void Base_Movimiento::Cambiar_ruta(string nuevo)
{
	ruta = nuevo;
}
string Base_Movimiento::Retornar_ruta()
{
	return ruta;
}

void Base_Movimiento::Cambiar_columna(int nuevo)
{
	col = nuevo;
}
void Base_Movimiento::Cambiar_fila(int nuevo)
{
	fil = nuevo;
}
int Base_Movimiento::Retornar_fila()
{
	return fil;
}
int Base_Movimiento::Retornar_columna()
{
	return col;
}

void Base_Movimiento::Cambiar_maxcolumna(int nuevo)
{
	maxcol = nuevo;
}
void Base_Movimiento::Cambiar_maxfila(int nuevo) 
{
	maxfil = nuevo;
}
int Base_Movimiento::Retornar_maxfila() { return maxfil; }
int Base_Movimiento::Retornar_maxcolumna() { return maxcol; }

void Base_Movimiento::Init(Bitmap^ imagen, int maxcolumna, int maxfila)
{
	maxcol = maxcolumna;
	maxfil = maxfila;
	a = imagen->Height / maxfil;
	l = imagen->Width / maxcol;
	col = fil = 0;
}

void Base_Movimiento::Cambiar_direccion(movimiento nuevo)
{
	direccion = nuevo;
	dx = dy = 0;
	if (direccion == movimiento::arriba) { dy = - (a/factormovimiento) ; }
	if (direccion == movimiento::abajo) { dy = (a/ factormovimiento); }
	if (direccion == movimiento::izquierda) { dx = - (l/ factormovimiento); }
	if (direccion == movimiento::derecha) { dx = (l/ factormovimiento); }
}

movimiento Base_Movimiento::Retornar_direccion()
{
	return direccion;
}

void Base_Movimiento::Cambiar_factormovimiento(int nuevo)
{
	factormovimiento = nuevo;
}

int Base_Movimiento::Retornar_factormovimiento()
{
	return factormovimiento;
}