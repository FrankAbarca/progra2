#include "Archivo_Texto.h"

Archivo_Texto::Archivo_Texto()
{}
Archivo_Texto::~Archivo_Texto()
{}
vector<string> Archivo_Texto::LeerdesdeArchivo(string ruta_archivo)
{
	string linea;
	vector<string> resultado;
	ifstream miarchivo(ruta_archivo);
	if (miarchivo.fail())
		cout << "Archivo no existe"; 
	else
	{	while (!miarchivo.eof())
		{
			getline(miarchivo, linea); // lee hasta \n
			resultado.push_back(linea);
		}
		miarchivo.close();
	}
	return resultado;
	/*
	//CONVERTIR A STRING
	int x = 10;
	string auxiliar = std::to_string(x);
	//DE STRING A INT
	System::String^ aux = gcnew System::String(auxiliar.c_str());
	int y = System::Convert::ToInt32(aux);
	*/
}
void Archivo_Texto::GrabarenArchivo(string ruta_archivo, vector<string> datoagrabar)
{
	//ofstream miarchivo(ruta_archivo); // BORRAR EL CONTENIDO DEL ARCHIVO ANTES DE ESCRIBIR LO NUEVO
	ofstream miarchivo(ruta_archivo,std::ofstream::app); // LOS DATOS NUEVOS LOS COLOCA AL FINAL. MANTIENE LO ANTERIOR
	if (miarchivo.fail())
		cout << "Archivo no existe";
	else
	{	for (int i = 0; i < datoagrabar.size(); i++)
			miarchivo << datoagrabar.at(i);
		miarchivo.flush();
		miarchivo.close();
	}
}