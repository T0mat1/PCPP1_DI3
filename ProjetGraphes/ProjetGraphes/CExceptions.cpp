#include "CExceptions.h"

/***************************************
*** Classe de gestion des exceptions ***
***************************************/

/************************************************
*** Constructeur par d�faut                   ***
*************************************************
*** E : n�ant                                 ***
*** n�cessite : n�ant                         ***
*** S : n�ant								  ***
*** entraine : exception initialis�e � DEFAUT ***
************************************************/
CExceptions::CExceptions(void)
{
	uiEXCValeur = DEFAUT;
}

/*************************************************
*** Constructeur avec un param�tre             ***
**************************************************
*** E : uiParam : entier naturel               ***
*** n�cessite : n�ant                          ***
*** S : n�ant                                  ***
*** entraine : exception initialis�e � uiParam ***
*************************************************/
CExceptions::CExceptions(unsigned int uiParam)
{
	EXCModifierValeur(uiParam);
}

/**********************************************
*** Destructeur				                ***
***********************************************
*** E : n�ant                               ***
*** n�cessite : n�ant                       ***
*** S : n�ant                               ***
*** entraine : exception d�truite           ***
**********************************************/
CExceptions::~CExceptions(void)
{

}

/**********************************************
*** Accesseur en �criture de la valeur      ***
***********************************************
*** E : nouvelle valeur                     ***
*** n�cessite : n�ant                       ***
*** S : n�ant                               ***
*** entraine : valeur modifi�e              ***
**********************************************/
void CExceptions::EXCModifierValeur(unsigned int uiParam)
{
	uiEXCValeur = uiParam;
}

/**********************************************
*** Accesseur en lecture de la valeur       ***
***********************************************
*** E : n�ant                               ***
*** n�cessite : n�ant                       ***
*** S : valeur de l'exception               ***
*** entraine : on retourne la valeur        ***
**********************************************/
unsigned int CExceptions::EXCLireValeur()
{
	return uiEXCValeur;
}

