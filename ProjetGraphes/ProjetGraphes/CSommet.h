#ifndef CSOMMET_H
#define CSOMMET_H 1

#include <vector>
#include <algorithm>
#include "CArc.h"
#include "CExceptions.h"

/***********************************
*** Classe de gestion d'un sommet***
***********************************/
class CSommet
{
	// ----------------------------------------------- Attributs ----------------------------------------------- 
private:
	unsigned int uiSOMNumero;
	std::vector<CArc> vSOMArrivants;
	std::vector<CArc> vSOMPartants;

	// ----------------------------------------------- Constructeurs et destructeur ----------------------------------------------- 
private:
	CSommet(void);
	/*************************************************************************************************
	*** Constructeur par défaut																	   ***
	**************************************************************************************************
	*** E : néant																				   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : Sommet non initialisée 														   ***
	*************************************************************************************************/
public:
	CSommet(unsigned int uiNumero);
	/*************************************************************************************************
	*** Constructeur																			   ***
	**************************************************************************************************
	*** E : uiNumero ; le futur numero du sommet												   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : Sommet initialisée avec uiNumero												   ***
	*************************************************************************************************/
	~CSommet(void);
	/*************************************************************************************************
	*** Destructeur																				   ***
	**************************************************************************************************
	*** E : néant																				   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : Detruit un sommet	 														   ***
	*************************************************************************************************/

	// ----------------------------------------------- Méthodes ----------------------------------------------- 
	void SOMAjouterArcArrivant(CArc ARCParam);
	/*************************************************************************************************
	*** Methode d'ajout d'un arc arrivant														   ***
	**************************************************************************************************
	*** E : ARCParam ; un arc arrivant															   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : ajout de l'arc ARCParam au vecteur d'arc arrivants							   ***
	*************************************************************************************************/
	void SOMAjouterArcPartant(CArc ARCParam);
	/*************************************************************************************************
	*** Methode d'ajout d'un arc partant														   ***
	**************************************************************************************************
	*** E : pARCParam ; un arc partant															   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : ajout de l'arc ARCParam au vecteur d'arc partants							   ***
	*************************************************************************************************/
	void SOMSupprimerArcArrivant(CArc ARCParam);
	/*************************************************************************************************
	*** Methode de suppression d'un arc arrivant												   ***
	**************************************************************************************************
	*** E : pARCParam ; un arc arrivant															   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : suppression de l'arc ARCParam du vecteur d'arc arrivants						   ***
	*************************************************************************************************/
	void SOMSupprimerArcPartant(CArc ARCParam);
	/*************************************************************************************************
	*** Methode de suppression d'un arc partant													   ***
	**************************************************************************************************
	*** E : pARCParam ; un arc partant															   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : suppression de l'arc ARCParam du vecteur d'arc partants						   ***
	*************************************************************************************************/
	
	inline unsigned int SOMLireNumero() const;
	/*************************************************************************************************
	*** Accesseur en lecture de uiNumero														   ***
	**************************************************************************************************
	*** E : néant																				   ***
	*** nécessite : néant																		   ***
	*** S : uiSOMNumero																			   ***
	*** entraine : Renvoie uiSOMNumero		 													   ***
	*************************************************************************************************/
	CArc & SOMRecupererArcPartant(unsigned int uiDestination);
	/*************************************************************************************************
	*** Accesseur en lecture d'un arc partant en particulier									   ***
	**************************************************************************************************
	*** E : uiDestination ; la destination de l'arc	partant voulu								   ***
	*** nécessite : néant																		   ***
	*** S : CArc ; l'arc partant voulu															   ***
	*** entraine : Renvoie l'arc partant voulu 													   ***
	*************************************************************************************************/
	
	inline std::vector<CArc> SOMRecupererArcsPartants() const;
	/*************************************************************************************************
	*** Accesseur en lecture de la liste d'arcs partants										   ***
	**************************************************************************************************
	*** E : neant																				   ***
	*** nécessite : néant																		   ***
	*** S : un vecteur d'arcs																	   ***
	*** entraine : neant					 													   ***
	*************************************************************************************************/
	
	inline std::vector<CArc> SOMRecupererArcsArrivants() const;
	/*************************************************************************************************
	*** Accesseur en lecture de la liste d'arcs arrivants										   ***
	**************************************************************************************************
	*** E : neant																				   ***
	*** nécessite : néant																		   ***
	*** S : un vecteur d'arcs																	   ***
	*** entraine : neant					 													   ***
	*************************************************************************************************/

	bool operator==(const CSommet & SOMsommet) const;
	/*************************************************************************************************
	*** Surcharge de l'operateur de comparaison													   ***
	**************************************************************************************************
	*** E : deux CSommets a comparer															   ***
	*** nécessite : néant																		   ***
	*** S : un boolean ; vrai si les CSommets sont identiques, faux sinon						   ***
	*** entraine : neant					 													   ***
	*************************************************************************************************/
};

#endif