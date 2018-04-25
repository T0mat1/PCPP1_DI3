#include "CExceptions.h"

/***************************************
*** Classe de gestion des exceptions ***
***************************************/

/************************************************
*** Constructeur par défaut                   ***
*************************************************
*** E : néant                                 ***
*** nécessite : néant                         ***
*** S : néant								  ***
*** entraine : exception initialisée à DEFAUT ***
************************************************/
CExceptions::CExceptions(void)
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
CExceptions::CExceptions(unsigned int uiParam)
{
	EXCModifierValeur(uiParam);
}

/**********************************************
*** Destructeur				                ***
***********************************************
*** E : néant                               ***
*** nécessite : néant                       ***
*** S : néant                               ***
*** entraine : exception détruite           ***
**********************************************/
CExceptions::~CExceptions(void)
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
void CExceptions::EXCModifierValeur(unsigned int uiParam)
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
unsigned int CExceptions::EXCLireValeur()
{
	return uiEXCValeur;
}

