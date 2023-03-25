#pragma once
#include "ConexionDatos.h"
#include "sqlite3.h"


class CDatosSQLite :
	public CConexionDatos
{
public:
	CDatosSQLite();
	~CDatosSQLite();
	//
	int conectarse();
	void desconectarse();
	int registrarTemporal(vector<string> vVal);

private:
	sqlite3 *db;


};

