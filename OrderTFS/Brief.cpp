#include "stdafx.h"
#include "Brief.h"


CBrief::CBrief()
{
	vLineas.clear();
	separador = ';';
}


CBrief::~CBrief()
{

}

int CBrief::imprimirBrief(ofstream &salida)
{
	int retorno = 0;
	for (CLineaProd p : vLineas) {
		salida << this->toString() << separador << p.toString() << endl;
		retorno++;
	}
	return retorno;
}

void CBrief::agregarLinea(CLineaProd &lprod)
{
	vLineas.push_back(lprod);
}

string CBrief::toString()
{
	ostringstream osstr;
	osstr << this->getId() << this->separador << this->getTipo() << this->separador << this->getTitulo() << this->separador << this->getfCreacion() << this->separador << this->getfActualizacion() << this->separador << this->getEstado() << this->separador << this->getEtiquetas() << this->separador << this->getBloqueado();
	return osstr.str();
}

int CBrief::setDatos(vector<string> vDatos) {
	int retorno = 0;
	try {
		this->setId(stod(vDatos[0]));
		this->setTipo(vDatos[1]);
		this->setTitulo(vDatos[2]);
		this->setfCreacion(vDatos[3]);
		this->setfActualizacion(vDatos[4]);
		this->setEstado(vDatos[5]);
		this->setEtiquetas(vDatos[6]);
		this->setBloqueado(vDatos[7]);
	}
	catch (exception &ex) {
		retorno = -1;
	}
	return retorno;
}
