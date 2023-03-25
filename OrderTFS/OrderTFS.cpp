// OrderTFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GetOpt.h"
#include "Brief.h"
#include "LineaProd.h"

using namespace std;


vector<string> split(const string &s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

int main(int argc, char **argv)
{
	// Valido los flags
	char *cvalue;
	double actVal = 0;
	vector<CBrief> vBrief;
	string strArchIn = "";
	string strArchOut = "";
	string line;
	ifstream ifs;
	ofstream ofs;
	int c;
	int nLineasIn = 0;
	while ((c = getopt(argc, argv, "i:o:")) != -1) {
		switch (c) {
		case 'i':
			cvalue = optarg;
			cout << "La entrada es " << cvalue <<endl;
			strArchIn = string(cvalue);
			break;
		case 'o':
			cvalue = optarg;
			cout << "La salida es " << cvalue <<endl;
			strArchOut = string(cvalue);
			break;
		default:
			cout << "No se introdujo el valor"<<endl;
			break;
		}
	}
	cout << "Iniciando proceso de conversion" << endl;

	// Abro los archivos
	try {
		ifs.open(strArchIn.c_str());
		ofs.open(strArchOut.c_str());
	}
	catch (exception &ex) {
		cout << "Error abriendo los archivos de entrada o salida:" << ex.what() << endl;
	}

	// Proceso el archivo de entrada
	try {
		while (getline(ifs, line)) {
			nLineasIn++;
			if (nLineasIn == 1)
				continue;
			vector<string> vtLine = split(line, ';');
			if (line.find("BRIEF") != string::npos) {
				CBrief nBrief;
				nBrief.setDatos(vtLine);
				vBrief.push_back(nBrief);
				actVal++;
			}
			else {
				CBrief nBrief = static_cast<CBrief>(vBrief[(actVal - 1)]);
				CLineaProd lProd;
				lProd.setDatos(vtLine);
				nBrief.agregarLinea(lProd);
				vBrief[(actVal - 1)] = nBrief;
			}
		}
		cout << "Numero de lineas leidas -> " << nLineasIn << endl;
		actVal = 0;
		for (CBrief cb : vBrief) {
			actVal++;
			cout << "[" << actVal << "] -> " << cb.toString() << endl;
			cb.imprimirBrief(ofs);
		}
	}
	catch (exception &ex) {
		cout << "Error procesando los archivos de entrada o salida:" << ex.what() << endl;
	}


	// Cierro los archivos
	if (ifs) {
		ifs.close();
	}
	if (ofs) {
		ofs.close();
	}
    return 0;
}

