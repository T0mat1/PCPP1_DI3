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
	*** Constructeur par d�faut                 ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : n�ant						***
	**********************************************/

public:
	CArc(unsigned int uiNouvelleDestination);
	/*****************************************************************************************************
	*** Constructeur																				   ***
	******************************************************************************************************
	*** E : uiNouvelleDestination : unsigned int ; la nouvelle destination vers laquelle pointe l'arc. ***
	*** n�cessite : n�ant																			   ***
	*** S : n�ant																					   ***
	*** entraine : n�ant																			   ***
	*****************************************************************************************************/

	~CArc(void);
	/**********************************************
	*** Destructeur			                    ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : destruction de l'objet		***
	**********************************************/

	// ----------------------------------------------- M�thodes -----------------------------------------------

	inline void ARCModifierDestination(unsigned int uiNouvelleDestination);
	/*****************************************************************************************************
	*** Accesseur en �criture de uiARCDestination													   ***
	******************************************************************************************************
	*** E : uiNouvelleDestination : unsigned int ; la nouvelle destination vers laquelle pointe l'arc. ***
	*** n�cessite : n�ant																			   ***
	*** S : n�ant																					   ***
	*** entraine : modification de l'attribut uiARCDestination										   ***
	*****************************************************************************************************/

	inline unsigned int ARCLireDestination();
	/*****************************************************************************************************
	*** Accesseur en lecture de uiARCDestination													   ***
	******************************************************************************************************
	*** E : n�ant																					   ***
	*** n�cessite : n�ant																			   ***
	*** S : la valeur de l'attribut uiARCDestination												   ***
	*** entraine : n�ant																			   ***
	*****************************************************************************************************/

};

#endif