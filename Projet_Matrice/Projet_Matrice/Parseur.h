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
	*** Constructeur par défaut                 ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : Parseur initialisé           ***
	**********************************************/
	~CParseur(void);
	/*************************************************
	*** Destructeur par défaut                     ***
	**************************************************
	*** E : néant                                  ***
	*** nécessite : néant                          ***
	*** S : néant                                  ***
	*** entraine : Destruction de l'objet CParseur ***
	*************************************************/
	
	//------------------------------------------------ Méthodes ------------------------------------------------
	CMatrice<double> PARLireFichier(std::string sNomFichier);
	/**********************************************
	*** Interpreteur de fichier                 ***
	***********************************************
	*** E : le nom du fichier à interpréter     ***
	*** nécessite : néant                       ***
	*** S : Un objet CMatrice de type double    ***
	*** entraine : Creation d'un objet CMatrice ***
	**********************************************/
};

#endif