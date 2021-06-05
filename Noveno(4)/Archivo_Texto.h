#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Archivo_Texto
{

public:
	Archivo_Texto();
	~Archivo_Texto();
	vector<string> LeerdesdeArchivo(string ruta_archivo);
	void GrabarenArchivo(string ruta_archivo, vector<string> datoagrabar);

};

