#include "Archivo_Texto.h"
#include "Controladora.h"


Controladora::Controladora()
{
	obj_monigote = new Monigote();
	obj_asteroides = new ArrBase_Movimiento();
}
Controladora::~Controladora()
{}
void Controladora::Crear_Asteroides(Graphics^ g,Bitmap^ imagenasteroide)
{
	Archivo_Texto* miarchivo = new Archivo_Texto();
	vector<string> datosleidos = miarchivo->LeerdesdeArchivo("datosmonigote.txt");
	int col = System::Convert::ToInt32(gcnew System::String(datosleidos[4].c_str()));
	int fil = System::Convert::ToInt32(gcnew System::String(datosleidos[5].c_str()));
	delete miarchivo;
	Asteroide* nuevo_asteroide = new Asteroide();
	nuevo_asteroide->Init(imagenasteroide, col, fil);
	int x = (gcnew System::Random())->Next(g->VisibleClipBounds.Width - nuevo_asteroide->Retornar_l() - 5);
	int y = (gcnew System::Random())->Next(g->VisibleClipBounds.Height - nuevo_asteroide->Retornar_a() - 5);
	nuevo_asteroide->Cambiar_x(x);
	nuevo_asteroide->Cambiar_y(y);
	nuevo_asteroide->Cambiar_dy((gcnew System::Random())->Next(1,5));
	obj_asteroides->Insertar(nuevo_asteroide);
}
void Controladora::Init(Bitmap^ imagenmonigote, Bitmap^ imagenasteroide)
{
	obj_monigote->Cambiar_y(500);
	Archivo_Texto* miarchivo = new Archivo_Texto();
	vector<string> datosleidos = miarchivo->LeerdesdeArchivo("datosmonigote.txt");
	int col = System::Convert::ToInt32(gcnew System::String(datosleidos[2].c_str()));
	int fil = System::Convert::ToInt32(gcnew System::String(datosleidos[3].c_str()));
	delete miarchivo;
	obj_monigote->Init(imagenmonigote, col, fil);
	tiempo_inicial = time(0);
	termino = false;
}
void Controladora::Run(Graphics^ g,Bitmap ^ imagenmonigote, Bitmap^ imagenasteroide)
{	time_t tiempo_actual= time(0);
	if (difftime(tiempo_actual, tiempo_inicial) > 4)
	{
		Crear_Asteroides(g, imagenasteroide);
		tiempo_inicial = time(0);
	}
	obj_monigote->Mover(g);
	obj_monigote->Mostrar(g, imagenmonigote);
	obj_monigote->Mover_Balas(g);
	obj_asteroides->Mover_todos(g);
	obj_asteroides->Mostrar_todos(g, imagenasteroide);
	for (int i = 0; !termino && i < obj_asteroides->Retornar_nelementos(); i++)
	{
		termino = Colision(obj_monigote, obj_asteroides->Retornar_elemento(i));
	}
	for (int i = 0; i < obj_asteroides->Retornar_nelementos(); i++)
	{
		for (int j = 0; j < obj_monigote->Retornar_cantidad_balas(); j++)
		{
			if (Colision(obj_asteroides->Retornar_elemento(i), obj_monigote->Retornar_bala_enpos(j)))
				obj_asteroides->Retornar_elemento(i)->Cambiar_eliminar(true);
		}
	}
	if (termino)
		Resumen_final(g);
}
void Controladora::Disparar() { 	obj_monigote->Disparar();  }



bool Controladora::Retornar_termino()
{
	return termino;
}
void Controladora::Resumen_final(Graphics^ g)
{
	g->Clear(Color::Black);
	Font^ f = gcnew Font("Arial", 18);
	SolidBrush^ b = gcnew SolidBrush(Color::Red);
	g->DrawString("FIN", f, b, 50, 50);
}
bool Controladora::Colision(Base_Movimiento* m, Base_Movimiento* a)
{
	Rectangle r1 = Rectangle(m->Retornar_x(), m->Retornar_y(),
							 m->Retornar_l(), m->Retornar_a());
	Rectangle r2 = Rectangle(a->Retornar_x(), a->Retornar_y(),
		                     a->Retornar_l(), a->Retornar_a());
	return r1.IntersectsWith(r2);
}
void Controladora::Mover_Monigote(movimiento nuevo_movimiento)
{
	obj_monigote->Cambiar_direccion(nuevo_movimiento);


}