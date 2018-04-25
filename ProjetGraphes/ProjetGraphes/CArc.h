#ifndef CARC_H
#define CARC_H 1

/***********************************
*** Classe de gestion d'un arc   ***
***********************************/
class CArc
{
	// ----------------------------------------------- Attributs -----------------------------------------------

private:
	unsigned int uiARCDestination;

	// ----------------------------------------------- Constructeurs et destructeur ----------------------------------------------- 

	CArc(void);
	/**********************************************
	*** Constructeur par défaut                 ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : néant						***
	**********************************************/

public:
	CArc(unsigned int uiNouvelleDestination);
	/*****************************************************************************************************
	*** Constructeur																				   ***
	******************************************************************************************************
	*** E : uiNouvelleDestination : unsigned int ; la nouvelle destination vers laquelle pointe l'arc. ***
	*** nécessite : néant																			   ***
	*** S : néant																					   ***
	*** entraine : néant																			   ***
	*****************************************************************************************************/

	~CArc(void);
	/**********************************************
	*** Destructeur			                    ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : destruction de l'objet		***
	**********************************************/

	// ----------------------------------------------- Méthodes -----------------------------------------------

	inline void ARCModifierDestination(unsigned int uiNouvelleDestination);
	/*****************************************************************************************************
	*** Accesseur en écriture de uiARCDestination													   ***
	******************************************************************************************************
	*** E : uiNouvelleDestination : unsigned int ; la nouvelle destination vers laquelle pointe l'arc. ***
	*** nécessite : néant																			   ***
	*** S : néant																					   ***
	*** entraine : modification de l'attribut uiARCDestination										   ***
	*****************************************************************************************************/

	inline unsigned int ARCLireDestination();
	/*****************************************************************************************************
	*** Accesseur en lecture de uiARCDestination													   ***
	******************************************************************************************************
	*** E : néant																					   ***
	*** nécessite : néant																			   ***
	*** S : la valeur de l'attribut uiARCDestination												   ***
	*** entraine : néant																			   ***
	*****************************************************************************************************/

};

#endif