#include "CChasis.h"
CChasis::CChasis()
{
	l = 4;
	color = rand() % 5 + 1;
	x = y = 0;
}
CChasis::~CChasis(){}
void CChasis::Borrar()
{
	for (int c = x; c <= x + l; c++)
	{
		Console::SetCursorPosition(c, y);
		cout << " ";
    }
}
void CChasis::Mostrar()
{
	for (int c = x; c < x + l; c++)
	{
		Console::SetCursorPosition(c, y);
		if (color == 1)Console::ForegroundColor = ConsoleColor::Red;
		if (color == 2)Console::ForegroundColor = ConsoleColor::Yellow;
		if (color == 3)Console::ForegroundColor = ConsoleColor::Green;
		if (color == 4)Console::ForegroundColor = ConsoleColor::Magenta;
		if (color == 5)Console::ForegroundColor = ConsoleColor::Cyan;
		cout << char(254);
	}
}
void CChasis::Mover(int MAXW, int MAXH)
{
	Borrar();
	x += dx;
	Mostrar();
}
void CChasis::Cambiar_x(int nuevo) { x = nuevo; }
void CChasis::Cambiar_y(int nuevo) { y = nuevo; }
void CChasis::Cambiar_l(int nuevo) { l = nuevo; }
void CChasis::Cambiar_color(int nuevo) { color = nuevo; }
void CChasis::Cambiar_dx(int nuevo) { dx = nuevo; }
int CChasis::getXchasis() { return x + l; }