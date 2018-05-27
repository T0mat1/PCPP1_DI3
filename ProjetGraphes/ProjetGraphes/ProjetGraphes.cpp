// ProjetMatrice.cpp : définit le point d'entrée pour l'application console.

//Deadline : Dimanche 27 mai 2018, 23:55

#include "vld.h"
#include "CExceptions.h"
#include "CParseur.h"
#include "CGraphe.h"

#include <iostream>

int main (int argc, char *argv[])
{
	try {
		if(argc==1) { //no argument
			
		} else { //some argument
			CParseur * pPARmonParseur = new CParseur;
			CGraphe * pGRAmonGraphe = pPARmonParseur->PARLireFichier(argv[1]);
			pGRAmonGraphe->GRAAfficherGraphe();
			CGraphe * pGRAmonGrapheInverse = pGRAmonGraphe->GRAInverserArcs();
			pGRAmonGrapheInverse->GRAAfficherGraphe();
			system("PAUSE");
			delete pGRAmonGrapheInverse;
			delete pPARmonParseur;
			delete pGRAmonGraphe;
		}
	} catch(CExceptions EXCe) {
		std::cerr << "Exception levée - ID" << EXCe.EXCLireValeur() << std::endl;
	}
    return 0;
}

