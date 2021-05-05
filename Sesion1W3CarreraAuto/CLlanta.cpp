#include "CLlanta.h"
#include"CChasis.h"
CLlanta::CLlanta() { }
CLlanta::~CLlanta(){}
void CLlanta::Borrar()
{
	Console::SetCursorPosition(x, y);
	cout << " ";
	
}
void CLlanta::Mostrar()
{
	Console::SetCursorPosition(x, y);
	if (color == 1)Console::ForegroundColor = ConsoleColor::Red;
	if (color == 2)Console::ForegroundColor = ConsoleColor::Yellow;
	if (color == 3)Console::ForegroundColor = ConsoleColor::Green;
	if (color == 4)Console::ForegroundColor = ConsoleColor::Magenta;
	if (color == 5)Console::ForegroundColor = ConsoleColor::Cyan;
	cout << char(254);
}
void CLlanta::Mover(int MAXW, int MAXH)
{
	Borrar();
	x += dx;
	Mostrar();

}
void CLlanta::Cambiar_x(int nuevo) { x = nuevo; }
void CLlanta::Cambiar_y(int nuevo) { y = nuevo; }
void CLlanta::Cambiar_dx(int nuevo) { dx = nuevo; }
void CLlanta::Cambiar_color(int nuevo) { color = nuevo; }