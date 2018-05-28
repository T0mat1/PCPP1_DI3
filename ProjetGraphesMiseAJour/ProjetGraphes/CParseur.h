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
	CGraphe* PARLireFichier(std::string sNomFichier);
	/**********************************************
	*** Interpreteur de fichier                 ***
	***********************************************
	*** E : le nom du fichier � interpr�ter     ***
	*** n�cessite : n�ant                       ***
	*** S : Un objet CGraphe					***
	*** entraine : Creation d'un objet CGraphe  ***
	**********************************************/
};

#endif