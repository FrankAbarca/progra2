#pragma once
#include <iostream>
#include <string>
using namespace std;
using namespace System::Drawing;

public enum movimiento {arriba,abajo, izquierda, derecha, ninguno};
class Base_Movimiento
{
protected:
	int x, y, dx, dy, a, l, color;
	string ruta;
	bool eliminar;
	int col, fil,maxcol,maxfil;
	movimiento direccion;
	int factormovimiento;
public:
	Base_Movimiento();
	~Base_Movimiento();
	virtual void Borrar(System::Drawing::Graphics ^g );
	virtual void Mover(System::Drawing::Graphics  ^g);
	virtual void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^imagen);
	void Cambiar_x(int nuevo);
	void Cambiar_y(int nuevo);
	void Cambiar_dx(int nuevo);
	void Cambiar_dy(int nuevo);
	void Cambiar_a(int nuevo);
	void Cambiar_l(int nuevo);
	void Cambiar_color(int nuevo);
	void Cambiar_ruta(string nuevo);
	int Retornar_x();
	int Retornar_y();
	int Retornar_dx();
	int Retornar_dy();
	int Retornar_a();
	int Retornar_l();
	int Retornar_color();
	void Cambiar_eliminar(bool nuevo);
	bool Retornar_eliminar();
	string Retornar_ruta();
	void Cambiar_columna(int nuevo);
	void Cambiar_fila(int nuevo);
	int Retornar_fila();
	int Retornar_columna();
	void Cambiar_maxcolumna(int nuevo);
	void Cambiar_maxfila(int nuevo);
	int Retornar_maxfila();
	int Retornar_maxcolumna();

	void Init(Bitmap^ imagen, int maxcolumna, int maxfila);

	void Cambiar_direccion(movimiento nuevo);
	movimiento Retornar_direccion();

	void Cambiar_factormovimiento(int nuevo);
	int Retornar_factormovimiento();
};

