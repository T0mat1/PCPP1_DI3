/***************************************
*** Classe de gestion des exceptions ***
***************************************/

#include "stdafx.h"
#include "Cexception.h"

/**********************************************
*** Constructeur par d�faut                 ***
***********************************************
*** E : n�ant                               ***
*** n�cessite : n�ant                       ***
*** S : n�ant                               ***
*** entraine : exception initialis�e � FAUX ***
**********************************************/
Cexception::Cexception(void)
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
Cexception::Cexception(unsigned int uiParam)
{
	EXCModifierValeur(uiParam);
}

/**********************************************
*** Destructeur de la classe                ***
***********************************************
*** E : n�ant                               ***
*** n�cessite : n�ant                       ***
*** S : n�ant                               ***
*** entraine : exception d�truite           ***
**********************************************/
Cexception::~Cexception(void)
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
void Cexception::EXCModifierValeur(unsigned int uiParam)
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
unsigned int Cexception::EXCLireValeur()
{
	return uiEXCValeur;
}

