#ifndef CPARSEUR_H
#define CPARSEUR_H 1

#define OPEN_FILE_EXCEPTION			25001
#define NO_DOUBLE_EXCEPTION			25002
#define CORRUPTED_FILE_EXCEPTION	25003
/***********************************
*** Classe de gestion du parseur ***
***********************************/

#include <iostream>
#include <fstream>
#include <string>
#include "CGraphe.h"
#include "CExceptions.h"

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
	CGraphe* PARLireFichier(std::string sNomFichier);
	/**********************************************
	*** Interpreteur de fichier                 ***
	***********************************************
	*** E : le nom du fichier à interpréter     ***
	*** nécessite : néant                       ***
	*** S : Un objet CGraphe					***
	*** entraine : Creation d'un objet CGraphe  ***
	**********************************************/
};

#endif