#pragma once
#include "WorkItem.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


class CLineaProd :
	public CWorkItem
{
public:
	CLineaProd();
	~CLineaProd();

	// Funciones
	void setSeparador(char val) { separador = val; }
	int setDatos(vector<string> vDatos);
	string toString();

private:
	char separador;
};

