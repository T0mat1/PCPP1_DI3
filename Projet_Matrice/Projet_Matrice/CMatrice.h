#pragma once
template <class MType> class CMatrice
{
private:
	MType ** pptMatrice;
	unsigned int uiNombreLignes;
	unsigned int uiNombreColonnes;

public:
	// ----------------------------------------------- Constructeurs et destructeur ----------------------------------------------- 

	CMatrice();
	/**********************************************
	*** Constructeur par défaut                 ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : Matrice 1x1 initialisée à 1  ***
	**********************************************/

	CMatrice(CMatrice & MATParam);
	/*************************************************************
	*** Constructeur de recopie                                ***
	**************************************************************
	*** E : MATParam ; la matrice à recopier					   ***
	*** nécessite : néant									   ***
	*** S : néant											   ***
	*** entraine : Matrice initialisée par recopie de MATParam ***
	*************************************************************/
	
	CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes);
	/**************************************************************************
	*** Constructeur par défaut												***
	***************************************************************************
	*** E : uiNombreLignes, uiNombreColonnes ; les dimensions de la matrice ***
	*** nécessite : néant													***
	*** S : néant															***
	*** entraine : Matrice 1x1 initialisée à 1								***
	**************************************************************************/

	~CMatrice();
	/**************************************************************************
	*** Destructeur         												***
	***************************************************************************
	*** E : néant															***
	*** nécessite : néant													***
	*** S : néant															***
	*** entraine : Destruction de l'objet CMatrice							***
	**************************************************************************/


	//----------------------------------------------- Accesseurs ----------------------------------------------- 

	inline unsigned int MATLireNombreLignes();
	/************************************************************************************
	*** Accesseur en lecture   														  ***
	*************************************************************************************
	*** E : néant																	  ***
	*** nécessite : néant															  ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreLignes) ; entier naturel ***
	*** entraine : retour de la valeur de uiNombreLignes							  ***
	************************************************************************************/

	inline unsigned int MATLireNombreColonnes();
	/****************************************************************************************
	*** Accesseur en lecture   															  ***
	*****************************************************************************************
	*** E : néant																		  ***
	*** nécessite : néant																  ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreColonnes) ; entier naturel	  ***
	*** entraine : retour de la valeur de uiNombreColonnes    							  ***
	****************************************************************************************/

	inline void MATModifierComposante(MType tParam, unsigned int uiLigne, unsigned int uiColonne);
	/*************************************************************************************************
	*** Accesseur en ecriture 																	   ***
	**************************************************************************************************
	*** E : - tParam un parametre de type MType qui contient la nouvelle valeur de la composante   ***
	***		- uiLigne la coordonnee de la ligne de la composante à modifier ; entier naturel	   ***
	***		- uiColonne la coordonnee de la colonne de la composante à modifier ; entier naturel   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : modification d'une composante de la matrice aux coordonnées (uiColonne,uiLigne) ***
	*************************************************************************************************/


	//----------------------------------------------- Surcharges d'operateurs ----------------------------------------------- 


	CMatrice operator*(int iParam);
	CMatrice operator*(CMatrice MATParam);
	CMatrice operator+(CMatrice MATParam);
	CMatrice operator-(CMatrice MATParam);
	CMatrice operator/(int iParam);

	//----------------------------------------------- Methodes ----------------------------------------------- 
	void MATAfficherMatrice();
	CMatrice MATCalculerTransposee();
};

