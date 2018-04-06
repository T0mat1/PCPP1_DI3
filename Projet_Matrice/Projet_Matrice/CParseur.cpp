#include "CParseur.h"
#include "stdafx.h"


CParseur::CParseur(void)
{
}


CParseur::~CParseur(void)
{
}

CMatrice<double> CParseur::PARLireFichier(std::string sNomFichier)
{
	std::fstream fsFlux;
	std::string test;
	fsFlux.open (sNomFichier, std::fstream::in | std::fstream::out | std::fstream::app);
	//TODO Do something with the flux
	fsFlux >> test;
	printf("%d",test);
	fsFlux.close();

	return CMatrice<double>();
}