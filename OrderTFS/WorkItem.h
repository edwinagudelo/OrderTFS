#pragma once

#include <string>

using namespace std;

class CWorkItem
{
public:
	CWorkItem();
	~CWorkItem();

	// funciones publicas
	double getId() { return id; }
	void setId(double vid) { id = vid; }
	string getTipo() { return tipo;  }
	void setTipo(string val) { tipo = val; }
	string getTitulo() { return titulo; }
	void setTitulo(string val) { titulo = val; }
	string getfCreacion() { return fCreacion; }
	void setfCreacion(string val) { fCreacion = val; }
	string getfActualizacion() { return fActualizacion; }
	void setfActualizacion(string val) { fActualizacion = val; }
	string getEstado() { return estado; }
	void setEstado(string val) { estado = val; }
	string getEtiquetas() { return etiquetas; }
	void setEtiquetas(string val) { etiquetas = val; }
	string getBloqueado() { return bloqueado; }
	void setBloqueado(string val) { bloqueado = val; }
	virtual string toString() { return string(); };

private:
	double id;
	string tipo;
	string titulo;
	string fCreacion;
	string fActualizacion;
	string estado;
	string etiquetas;
	string bloqueado;

};

