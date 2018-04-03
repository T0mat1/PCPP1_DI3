#include "stdafx.h"
#include "Parseur.h"


CParseur::CParseur(void)
{
}


CParseur::~CParseur(void)
{
}

CMatrice<double> CParseur::PARLireFichier(std::string sNomFichier)
{
	std::fstream fsFlux;
	fsFlux.open (sNomFichier, std::fstream::in | std::fstream::out | std::fstream::app);
	//TODO Do something with the flux
	fsFlux.close();

	return CMatrice<double>();
}