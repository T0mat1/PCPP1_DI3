// Projet_Matrice.cpp : définit le point d'entrée pour l'application console.

//Deadline : Jeudi 19 Avril à 23h55

#include "CExceptions.h"
#include "CParseur.h"
#include "CMatrice.h"

#include <iostream>

int main (int argc, char *argv[])
{
	if(argc==0) {
		std::cout << "You must enter a path to a Parsed Matrix\n";
	} else {
		CParseur * myParseur = new CParseur;
		CMatrice<double> * myMatrix = new CMatrice<double>(2, 2, 0);
		myMatrix->MATModifierComposante(1, 0, 0);
		myMatrix->MATModifierComposante(2, 0, 1);
		myMatrix->MATModifierComposante(-3, 1, 0);
		myMatrix->MATModifierComposante(4, 1, 1);
		myMatrix->MATAfficherMatrice();

		CMatrice<double> * myMatrix2 = new CMatrice<double>(2, 4, 3);
		myMatrix2->MATAfficherMatrice();

		try {

		} catch(CExceptions e) {
			std::cout << e.EXCLireValeur();
		}

		//*myMatrix = myParseur->PARLireFichier(argv[0]);
		//myMatrix->MATAfficherMatrice();

		delete myMatrix, myMatrix2;
	}
    return 0;
}

