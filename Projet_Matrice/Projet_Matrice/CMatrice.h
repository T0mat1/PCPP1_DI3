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
	*** Constructeur par d�faut                 ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : Matrice 1x1 initialis�e � 1  ***
	**********************************************/

	CMatrice(CMatrice & MATParam);
	/*************************************************************
	*** Constructeur de recopie                                ***
	**************************************************************
	*** E : MATParam ; la matrice � recopier					   ***
	*** n�cessite : n�ant									   ***
	*** S : n�ant											   ***
	*** entraine : Matrice initialis�e par recopie de MATParam ***
	*************************************************************/
	
	CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes);
	/**************************************************************************
	*** Constructeur par d�faut												***
	***************************************************************************
	*** E : uiNombreLignes, uiNombreColonnes ; les dimensions de la matrice ***
	*** n�cessite : n�ant													***
	*** S : n�ant															***
	*** entraine : Matrice 1x1 initialis�e � 1								***
	**************************************************************************/

	~CMatrice();
	/**************************************************************************
	*** Destructeur         												***
	***************************************************************************
	*** E : n�ant															***
	*** n�cessite : n�ant													***
	*** S : n�ant															***
	*** entraine : Destruction de l'objet CMatrice							***
	**************************************************************************/


	//----------------------------------------------- Accesseurs ----------------------------------------------- 

	inline unsigned int MATLireNombreLignes();
	/************************************************************************************
	*** Accesseur en lecture   														  ***
	*************************************************************************************
	*** E : n�ant																	  ***
	*** n�cessite : n�ant															  ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreLignes) ; entier naturel ***
	*** entraine : retour de la valeur de uiNombreLignes							  ***
	************************************************************************************/

	inline unsigned int MATLireNombreColonnes();
	/****************************************************************************************
	*** Accesseur en lecture   															  ***
	*****************************************************************************************
	*** E : n�ant																		  ***
	*** n�cessite : n�ant																  ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreColonnes) ; entier naturel	  ***
	*** entraine : retour de la valeur de uiNombreColonnes    							  ***
	****************************************************************************************/

	inline void MATModifierComposante(MType tParam, unsigned int uiLigne, unsigned int uiColonne);
	/*************************************************************************************************
	*** Accesseur en ecriture 																	   ***
	**************************************************************************************************
	*** E : - tParam un parametre de type MType qui contient la nouvelle valeur de la composante   ***
	***		- uiLigne la coordonnee de la ligne de la composante � modifier ; entier naturel	   ***
	***		- uiColonne la coordonnee de la colonne de la composante � modifier ; entier naturel   ***
	*** n�cessite : n�ant																		   ***
	*** S : n�ant																				   ***
	*** entraine : modification d'une composante de la matrice aux coordonn�es (uiColonne,uiLigne) ***
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

