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
		CMatrice<double> * myMatrix;
		myMatrix = myParseur->PARLireFichier(argv[0]);
		delete myMatrix;
	}
    return 0;
}

