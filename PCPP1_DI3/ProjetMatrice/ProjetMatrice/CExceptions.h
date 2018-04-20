#ifndef CEXCEPTIONS_H
#define CEXCEPTIONS_H 1
/***************************************
*** Classe de gestion des exceptions ***
***************************************/
//Def valeur initiale pour une exception
#define DEFAUT 0

class CExceptions
{

//Attributs
private:
	unsigned int uiEXCValeur;
	
//Methodes
public:
	CExceptions(void);
	/**********************************************
	*** Constructeur par d�faut                 ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : exception initialis�e � FAUX ***
	**********************************************/

	CExceptions(unsigned int uiParam);
	/*************************************************
	*** Constructeur avec un param�tre             ***
	**************************************************
	*** E : uiParam : entier naturel               ***
	*** n�cessite : n�ant                          ***
	*** S : n�ant                                  ***
	*** entraine : exception initialis�e � uiParam ***
	*************************************************/

	~CExceptions(void);
	/**********************************************
	*** Destructeur de la classe                ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : exception d�truite           ***
	**********************************************/

	void EXCModifierValeur(unsigned int uiParam);
	/**********************************************
	*** Accesseur en �criture de la valeur      ***
	***********************************************
	*** E : nouvelle valeur                     ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : valeur modifi�e              ***
	**********************************************/

	unsigned int EXCLireValeur();
	/**********************************************
	*** Accesseur en lecture de la valeur       ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : valeur de l'exception               ***
	*** entraine : on retourne la valeur        ***
	**********************************************/
};

#endif