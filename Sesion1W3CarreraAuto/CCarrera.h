#pragma once
#include"CArrAuto.h"
class CCarrera
{
private:
	int indice_ganador;
	int n_participantes;
	int x_meta, y_meta, dmeta;
	CArrAuto* obj_participantes;
	bool ganador;
public:
	CCarrera();
	~CCarrera();
	void dibujar_meta();
	void Inicio(int MAXW, int MAXH);
	void Jugar(int MAXW, int MAXH);
	int Retornar_indice_ganador();
	void Preparar_Carrera();
};

CCarrera::CCarrera()
{
	n_participantes = 0;
	Preparar_Carrera();

}
CCarrera::~CCarrera()
{
	delete obj_participantes;
}
void CCarrera::Preparar_Carrera()
{
	if(n_participantes==0)
		obj_participantes = new CArrAuto();
	else
	{
		delete obj_participantes;
		obj_participantes = new CArrAuto();
	}
	n_participantes = 5+rand() %3;
}
void CCarrera::dibujar_meta()
{
	for (int i =0; i <= dmeta; i++)
	{
		Console::SetCursorPosition(x_meta, i);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << char(220);
	}
}
void CCarrera::Inicio(int MAXW, int MAXH)
{

	indice_ganador = -1;
	x_meta = MAXW-10;
	y_meta = 1;
	dmeta = MAXH;
	int x_inicial = 0;
	int y_inicial = 1;
	for (int i = 0; i < n_participantes; i++)
	{
		obj_participantes->Insertar(MAXW, MAXH);
		obj_participantes->Cambiar_x(i, x_inicial);
		obj_participantes->Cambiar_y(i, y_inicial);
		obj_participantes->Cambiar_dx(i, 1 + rand() % 5);
		y_inicial += 4;
	}
	obj_participantes->Mostrar_todos();
	dibujar_meta();
}
void CCarrera::Jugar(int MAXW, int MAXH)
{
	ganador = false;
	do{
		//corredores se muevan;
		obj_participantes->Mover_todos(MAXW, MAXH);
		for (int i = 0; i < n_participantes; i++)
		{
			obj_participantes->Cambiar_dx(i, 1 + rand() % 5);
		}
		_sleep(100);
		//comprobar si alguien si llega a la meta
		for (int i = 0; i < n_participantes; i++)
		{
			if (obj_participantes->Retornar_x(i) >x_meta)
			{
				indice_ganador = i;
				ganador = true;
			}
		}
	} while (ganador == false);
}
int  CCarrera::Retornar_indice_ganador()
{
	return indice_ganador;
}
