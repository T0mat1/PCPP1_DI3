#include "CParseur.h"

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

		CGraphe * tmpGraphe =  new CGraphe();

		for(unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiNBSommets; uiBoucleLigne++) {
			std::getline(input, sLigne);
			try {
				tmpGraphe->GRAAjouterSommet(std::stoi(sLigne));
			} catch (CExceptions EXCe) {
				std::cerr << "Exception levée - ID" << EXCe.EXCLireValeur() << std::endl;
			}
		}

		std::getline(input, sLigne);
		if (sLigne.find("]")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

		std::getline(input, sLigne);
		if (sLigne.find("Arcs=[")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

		for(unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiNBArcs; uiBoucleLigne++) {
			std::getline(input, sLigne);
			std::string sTemp;
			unsigned int uiTempSommet1 = 0, uiTempSommet2 = 0;

			//store components values
			uiTempSommet1 = std::stoi(sLigne.substr(0, sLigne.find(" ")));
			sLigne.erase(0, sLigne.find(" ") + 1); // on efface de 0 jusqu'a la position du delimiteur + sa taille
			uiTempSommet2 = std::stoi(sLigne.substr(0, sLigne.find(" ")));

			tmpGraphe->GRAAjouterArc(uiTempSommet1, uiTempSommet2);
		}


		std::getline(input, sLigne);
		if (sLigne.find("]")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

		input.close();

		return tmpGraphe;
	} else {
		throw new CExceptions(OPEN_FILE_EXCEPTION);
	}	
}