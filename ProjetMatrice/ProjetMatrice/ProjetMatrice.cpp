// ProjetMatrice.cpp : définit le point d'entrée pour l'application console.

//Deadline : Samedi 21 Avril à 23h55

#include "CExceptions.h"
#include "CParseur.h"
#include "CMatrice.h"

#include <iostream>

int main (int argc, char *argv[])
{
	try {
		if(argc==1) { //no argument
			std::cout << "You must enter a path to a Parsed Matrix\n";

			CMatrice<double> * myMatrix = new CMatrice<double>(2, 2, 0);
			myMatrix->MATModifierComposante(1, 0, 0);
			myMatrix->MATModifierComposante(2, 0, 1);
			myMatrix->MATModifierComposante(-3, 1, 0);
			myMatrix->MATModifierComposante(4, 1, 1);
			myMatrix->MATAfficherMatrice();

			CMatrice<double> * myMatrix2 = new CMatrice<double>(2, 4, 3);
			myMatrix2->MATAfficherMatrice();

			delete myMatrix, myMatrix2;
		} else { //some argument
			CParseur * myParseur = new CParseur;
			CMatrice<double> ** ppmatTableau = new CMatrice<double>*[argc-1];
			int iValeurC;
			std::cout << "Veuillez saisir une valeur C" << std::endl;
			std::cin >> iValeurC;

			for(int i = 1; i < argc; i++) {
				CMatrice<double> * myMatrix;
				myMatrix = myParseur->PARLireFichier(argv[i]);
				ppmatTableau[i-1] = myMatrix;
				//delete myMatrix;
			}

			for (int i = 0; i < argc-1; i++)
			{
				//multiplication par C
				CMatrice<double> tmpMatrice = (*ppmatTableau[i])*iValeurC;
				tmpMatrice.MATAfficherMatrice();
				//division par C
				CMatrice<double> tmpMatrice = (*ppmatTableau[i])/iValeurC;
				tmpMatrice.MATAfficherMatrice();
			}
		}
	} catch(CExceptions e) {
		std::cout << e.EXCLireValeur();
	}
    return 0;
}

