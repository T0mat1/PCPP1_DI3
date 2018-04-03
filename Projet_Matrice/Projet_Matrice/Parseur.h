#ifndef CPARSEUR_H
#define CPARSEUR_H 1

#include "CMatrice.h"
#include <iostream>
#include <string>
#include <fstream> 

class CParseur
{
public:
	//------------------------------------------------ Constructeurs et destructeur ------------------------------------------------
	
	CParseur(void);
	/**********************************************
	*** Constructeur par d�faut                 ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : Parseur initialis�           ***
	**********************************************/
	~CParseur(void);
	/*************************************************
	*** Destructeur par d�faut                     ***
	**************************************************
	*** E : n�ant                                  ***
	*** n�cessite : n�ant                          ***
	*** S : n�ant                                  ***
	*** entraine : Destruction de l'objet CParseur ***
	*************************************************/
	
	//------------------------------------------------ M�thodes ------------------------------------------------
	CMatrice<double> PARLireFichier(std::string sNomFichier);
	/**********************************************
	*** Interpreteur de fichier                 ***
	***********************************************
	*** E : le nom du fichier � interpr�ter     ***
	*** n�cessite : n�ant                       ***
	*** S : Un objet CMatrice de type double    ***
	*** entraine : Creation d'un objet CMatrice ***
	**********************************************/
};

#endif