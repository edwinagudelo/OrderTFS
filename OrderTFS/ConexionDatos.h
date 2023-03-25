#pragma once

#include <string>
#include <vector>

using namespace std;

class CConexionDatos
{
public:
	CConexionDatos();
	~CConexionDatos();

	// Funciones
	virtual int conectarse() = 0;
	virtual void desconectarse() = 0;
	virtual int registrarTemporal(vector<string> vVal);
	void setCadenaCon(string val) { cadenacon = val; }
	string getCadenaCon() { return cadenacon; }
private:
	int estado;
	string cadenacon;
};

