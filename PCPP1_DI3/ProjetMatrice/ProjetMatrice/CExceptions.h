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
	*** Constructeur par défaut                 ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : exception initialisée à FAUX ***
	**********************************************/

	CExceptions(unsigned int uiParam);
	/*************************************************
	*** Constructeur avec un paramètre             ***
	**************************************************
	*** E : uiParam : entier naturel               ***
	*** nécessite : néant                          ***
	*** S : néant                                  ***
	*** entraine : exception initialisée à uiParam ***
	*************************************************/

	~CExceptions(void);
	/**********************************************
	*** Destructeur de la classe                ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : exception détruite           ***
	**********************************************/

	void EXCModifierValeur(unsigned int uiParam);
	/**********************************************
	*** Accesseur en écriture de la valeur      ***
	***********************************************
	*** E : nouvelle valeur                     ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : valeur modifiée              ***
	**********************************************/

	unsigned int EXCLireValeur();
	/**********************************************
	*** Accesseur en lecture de la valeur       ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : valeur de l'exception               ***
	*** entraine : on retourne la valeur        ***
	**********************************************/
};

#endif