/***************************************
*** Classe de gestion des exceptions ***
***************************************/

#include "stdafx.h"
#include "Cexception.h"

/**********************************************
*** Constructeur par défaut                 ***
***********************************************
*** E : néant                               ***
*** nécessite : néant                       ***
*** S : néant                               ***
*** entraine : exception initialisée à FAUX ***
**********************************************/
Cexception::Cexception(void)
{
	uiEXCValeur = DEFAUT;
}

/*************************************************
*** Constructeur avec un paramètre             ***
**************************************************
*** E : uiParam : entier naturel               ***
*** nécessite : néant                          ***
*** S : néant                                  ***
*** entraine : exception initialisée à uiParam ***
*************************************************/
Cexception::Cexception(unsigned int uiParam)
{
	EXCModifierValeur(uiParam);
}

/**********************************************
*** Destructeur de la classe                ***
***********************************************
*** E : néant                               ***
*** nécessite : néant                       ***
*** S : néant                               ***
*** entraine : exception détruite           ***
**********************************************/
Cexception::~Cexception(void)
{

}

/**********************************************
*** Accesseur en écriture de la valeur      ***
***********************************************
*** E : nouvelle valeur                     ***
*** nécessite : néant                       ***
*** S : néant                               ***
*** entraine : valeur modifiée              ***
**********************************************/
void Cexception::EXCModifierValeur(unsigned int uiParam)
{
	uiEXCValeur = uiParam;
}

/**********************************************
*** Accesseur en lecture de la valeur       ***
***********************************************
*** E : néant                               ***
*** nécessite : néant                       ***
*** S : valeur de l'exception               ***
*** entraine : on retourne la valeur        ***
**********************************************/
unsigned int Cexception::EXCLireValeur()
{
	return uiEXCValeur;
}

