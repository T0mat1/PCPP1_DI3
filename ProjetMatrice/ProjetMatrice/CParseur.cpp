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
		std::string sNBLignes, sNBColonnes;

		std::getline(input, sLigne);
		if (!sLigne.find("TypeMatrice=")) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		} else {
			if (!sLigne.find("TypeMatrice=double")) {
				throw new CExceptions(NO_DOUBLE_EXCEPTION);
			}
		}

		std::getline(input, sLigne);
		if (!sLigne.find("NBLignes=")) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		} else {
			//TODO store sNBLignes
		}

		std::getline(input, sLigne);
		if (!sLigne.find("NBColonnes=")) {
			throw new CExceptions(CORRUPTED_FILE_EXCEPTION);
		} else {
			//TODO store sNBColonnes
		}

		CMatrice<double> * pmatMatriceTemp = new CMatrice<double>(1, 1);
		while (std::getline(input, sLigne)) {
			std::cout << sLigne << std::endl;
			//TODO store components values
		}


		input.close();

		return pmatMatriceTemp;
	} else {
		throw new CExceptions(OPEN_FILE_EXCEPTION);
	}	
}