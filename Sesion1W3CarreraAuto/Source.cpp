#include"CCarrera.h"
#include<conio.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	const int MAXW = 150;
	const int MAXH = 50;
	Console::SetWindowSize(MAXW, MAXH);
	Console::CursorVisible = false;
	CCarrera* obj_carrera=new CCarrera();
	char opt;
	do{
		obj_carrera->Inicio(MAXW, MAXH);
		obj_carrera->Jugar(MAXW, MAXH);
		cout << "\n\n\n\nEl ganador es el carro: " << obj_carrera->Retornar_indice_ganador() + 1 << endl;
		_getch();
		Console::Clear();
		Console::SetCursorPosition(5, 10);
		cout << "Otra carrera[S: Si; N: No]: ";
		cin >> opt;
		if (toupper(opt) == 'S')
		{
			obj_carrera->Preparar_Carrera();
			Console::Clear();
		}
	} while (toupper(opt)!='N');
	delete obj_carrera;
	system("pause>0");
	return 0;
}

/*

#include"CArrAuto.h"
int main()
{
	CArrAuto* obj_arr = new CArrAuto();
	obj_arr->Insertar(70, 20);
	obj_arr->Mostrar_todos();
	while (true)
	{
		obj_arr->Mover_todos(50,10);
		_sleep(1000);
	}
	cout << endl;
	Console::SetCursorPosition(1, 20);
	system("pause>0");
	delete obj_arr;
	return 0;
}*/