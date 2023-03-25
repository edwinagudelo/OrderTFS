#pragma once
#include "WorkItem.h"
#include "LineaProd.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class CBrief :
	public CWorkItem
{
public:
	CBrief();
	~CBrief();

	// Funciones
	string toString();
	void setSeparador(char val) { separador = val; }
	int imprimirBrief(ofstream &salida);
	void agregarLinea(CLineaProd &lprod);
	int setDatos(vector<string> vDatos);
private:
	vector<CLineaProd> vLineas;
	char separador;
};

