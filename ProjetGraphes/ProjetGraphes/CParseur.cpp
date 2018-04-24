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

CMatrice<double>* CParseur::PARLireFichier(std::string sNomFichier)
{
	std::ifstream input(sNomFichier);

	if (input) {
		std::string sLigne;
		unsigned int uiNBLignes, uiNBColonnes;

		std::getline(input, sLigne);
		if (sLigne.find("TypeMatrice=")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		} else {
			if (sLigne.find("TypeMatrice=double")==std::string::npos) {
				throw new CExceptions(NO_DOUBLE_EXCEPTION);
			}
		}

		std::getline(input, sLigne);
		if (sLigne.find("NBLignes=")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		} else {
			//store sNBLignes;
			uiNBLignes = (unsigned int) std::stoi(sLigne.erase(0, 9));
		}

		std::getline(input, sLigne);
		if (sLigne.find("NBColonnes=")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		} else {
			//store sNBColonnes
			uiNBColonnes = (unsigned int) std::stoi(sLigne.erase(0, 11));
		}

		std::getline(input, sLigne);
		if (sLigne.find("Matrice=[")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

		CMatrice<double> * pmatMatriceTemp = new CMatrice<double>(uiNBLignes, uiNBColonnes);

		for(unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiNBLignes; uiBoucleLigne++) {
			std::getline(input, sLigne);
			std::string sTemp;
			unsigned int uiTempLigne = 0,uiTempColonne = 0;
			
			//store components values
			for(unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiNBColonnes; uiBoucleColonne++) {

				sTemp = sLigne.substr(0, sLigne.find(" "));
				pmatMatriceTemp->MATModifierComposante(std::stoi(sTemp), uiBoucleLigne, uiBoucleColonne);
				sLigne.erase(0, sLigne.find(" ")+1); // on efface de 0 jusqu'a la position du delimiteur + sa taille
			}
		}

		std::getline(input, sLigne);
		if (sLigne.find("]")==std::string::npos) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		}

		input.close();

		return pmatMatriceTemp;
	} else {
		throw new CExceptions(OPEN_FILE_EXCEPTION);
	}	
}