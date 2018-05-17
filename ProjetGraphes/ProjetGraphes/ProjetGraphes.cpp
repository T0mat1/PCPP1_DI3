// ProjetMatrice.cpp : définit le point d'entrée pour l'application console.

//Deadline : Dimanche 27 mai 2018, 23:55

#include "CExceptions.h"
#include "CParseur.h"
#include "CGraphe.h"

#include <iostream>

int main (int argc, char *argv[])
{
	try {
		if(argc==1) { //no argument
			
		} else { //some argument

		}
	} catch(CExceptions EXCe) {
		std::cerr << "Exception levée - ID" << EXCe.EXCLireValeur() << std::endl;
	}
    return 0;
}

