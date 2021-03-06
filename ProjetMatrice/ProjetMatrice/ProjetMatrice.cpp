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

			CMatrice<double> * myMatrix = new CMatrice<double>(2, 2);
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
			}

			

			for (int i = 0; i < argc-1; i++)
			{
				//multiplication par C
				std::cout << std::endl << "Multiplication par C de la matrice n*" << i+1 << std::endl;
				CMatrice<double> tmpMatrice1 = (*ppmatTableau[i])*iValeurC;
				tmpMatrice1.MATAfficherMatrice();

				//division par C
				std::cout << std::endl << "Division par C de la matrice n*" << i+1 << std::endl;
				CMatrice<double> tmpMatrice2 = (*ppmatTableau[i])/iValeurC;
				tmpMatrice2.MATAfficherMatrice();
			}
			
			//addition de toutes les matrices entre elles
			std::cout << std::endl << "Addition de toutes les matrices entre elles" << std::endl;
			CMatrice<double> tmpMatrice3 = CMatrice<double>(*ppmatTableau[0]);
			for (int i = 1; i < argc-1; i++)
			{
				CMatrice<double> tmp = tmpMatrice3 + *ppmatTableau[i];
				tmpMatrice3 = *(new CMatrice<double>(tmp));
			}
			tmpMatrice3.MATAfficherMatrice();

			//addition des matrices paires et soustraction des matrices impaires
			std::cout << std::endl << "Addition des matrices paires, soustraction des matrices impaires" << std::endl;
			CMatrice<double> tmpMatrice4 = CMatrice<double>(*ppmatTableau[0]);
			for (int i = 1; i < argc-1; i++)
			{
				if (i%2==0) //pair
				{
					CMatrice<double> tmp = *ppmatTableau[i] + tmpMatrice4;
					tmpMatrice4 = *(new CMatrice<double>(tmp));
				}
				else //impair
				{
					CMatrice<double> tmp = *ppmatTableau[i] - tmpMatrice4;
					tmpMatrice4 = *(new CMatrice<double>(tmp));
				}					
			}
			tmpMatrice4.MATAfficherMatrice();

			//produit de toutes les matrices entre elles
			std::cout << std::endl << "Produit de toutes les matrices entre elles" << std::endl;
			CMatrice<double> tmpMatrice5 = CMatrice<double>(*ppmatTableau[0]);
			for (int i = 1; i < argc-1; i++)
			{
				CMatrice<double> tmp = *ppmatTableau[i] * tmpMatrice5;
				tmpMatrice5 = *(new CMatrice<double>(tmp));
			}
			tmpMatrice5.MATAfficherMatrice();
		}
	} catch(CExceptions e) {
		std::cerr << "Exception levée - ID" << e.EXCLireValeur() << std::endl;
	}
    return 0;
}

