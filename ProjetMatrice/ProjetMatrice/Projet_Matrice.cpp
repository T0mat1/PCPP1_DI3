// Projet_Matrice.cpp : définit le point d'entrée pour l'application console.

#include "CExceptions.h"
#include "CParseur.h"
#include "CMatrice.h"

int main (int argc, char *argv[])
{
	if(argc==0) {
		printf("You must enter a path to a Parsed Matrix\n");
	} else {
		CParseur * myParseur = new CParseur;
		CMatrice<double> * myMatrix = new CMatrice<double>(2, 2);
		myMatrix->MATModifierComposante(1, 0, 0);
		myMatrix->MATModifierComposante(2, 0, 1);
		myMatrix->MATModifierComposante(-3, 1, 0);
		myMatrix->MATModifierComposante(4, 1, 1);
		myMatrix->MATAfficherMatrice();

		//myMatrix = myParseur->PARLireFichier(argv[0]);
		delete myMatrix;
	}
    return 0;
}

