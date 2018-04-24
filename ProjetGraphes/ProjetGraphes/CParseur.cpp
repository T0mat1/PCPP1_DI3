#include "CParseur.h"
#include "CExceptions.h"
#include <iostream>
#include <fstream>

CParseur::CParseur(void)
{
}


CParseur::~CParseur(void)
{
}

CGraphe* CParseur::PARLireFichier(std::string sNomFichier)
{
	std::ifstream input(sNomFichier);

	if (input) {
		std::string sLigne;
		unsigned int uiNBSommets, uiNBArcs;

		std::getline(input, sLigne);
		if (sLigne.find("NBSommets=")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		} else {
			uiNBSommets = (unsigned int) std::stoi(sLigne.erase(0, 10));
		}

		std::getline(input, sLigne);
		if (sLigne.find("NBArcs=")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		} else {
			uiNBArcs = (unsigned int) std::stoi(sLigne.erase(0, 7));
		}

		std::getline(input, sLigne);
		if (sLigne.find("Sommets=[")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

		//CMatrice<double> * pmatMatriceTemp = new CMatrice<double>(uiNBLignes, uiNBColonnes);
		CGraphe * tmpGraphe =  new CGraphe();

		for(unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiNBSommets; uiBoucleLigne++) {
			std::getline(input, sLigne);
			tmpGraphe->GRAAjouterSommet(std::stoi(sLigne));
		}

		std::getline(input, sLigne);
		if (sLigne.find("]")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

				std::getline(input, sLigne);
		if (sLigne.find("Sommets=[")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

		CGraphe * tmpGraphe =  new CGraphe();

		for(unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiNBSommets; uiBoucleLigne++) {
			std::getline(input, sLigne);
			tmpGraphe->GRAAjouterArc(std::stoi(sLigne));
		}

		std::getline(input, sLigne);
		if (sLigne.find("]")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

		input.close();

		//return pmatMatriceTemp;
		return nullptr;
	} else {
		throw new CExceptions(OPEN_FILE_EXCEPTION);
	}	
}