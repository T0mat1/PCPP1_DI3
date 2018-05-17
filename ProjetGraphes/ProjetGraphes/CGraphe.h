#ifndef CGRAPHE_H
#define CGRAPHE_H 1

#include <vector>
#include "CArc.h"
#include "CSommet.h"
#include "CExceptions.h"

/***********************************
*** Classe de gestion du graphe  ***
***********************************/
class CGraphe
{
	//------------------------------------------------ Attributs ------------------------------------------------
private:
	unsigned int uiGRANbArc;
	unsigned int uiGRANbSommets;
	std::vector<CSommet> vGRAListeSommets;

public:

	//------------------------------------------------ Constructeurs et destructeur ------------------------------------------------

	CGraphe(void);
	/**********************************************
	*** Constructeur par défaut                 ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : création de l'objet CGraphe  ***
	**********************************************/
	
	~CGraphe(void);
	/**********************************************
	*** Destructeur				                ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : CGraphe détruit		        ***
	**********************************************/

	//------------------------------------------------ Méthodes ------------------------------------------------

	void GRAAjouterSommet(unsigned int uiNumero);
	/********************************************************************************
	*** Methode d'ajout d'un sommet											      ***
	*********************************************************************************
	*** E : uiNumero : unsigned int ; numéro du sommet à créer				      ***
	*** nécessite : néant														  ***
	*** S : néant																  ***
	*** entraine : création d'un nouveau sommet et ajout à la liste de sommets	  ***
	*** Incrémente uiGRANbSommets. Renvoie une exception si le sommet existe déjà ***
	********************************************************************************/
	
	void GRASupprimerSommet(unsigned int uiNumero);
	/******************************************************************************************
	*** Methode de suppression d'un sommet													***
	*******************************************************************************************
	*** E : uiNumero : unsigned int ; numéro du sommet à supprimer							***
	*** nécessite : néant																	***
	*** S : néant																			***
	*** entraine : suppression du sommet de la liste des sommets et supprime				***
	*** l'objet. Décrémente uiGRANbSommets. Renvoie une exception si le sommet n'existe pas	***
	******************************************************************************************/

	void GRAAjouterArc(unsigned int uiDepart, unsigned int uiDestination);
	/*****************************************************************************
	*** Methode d'ajout d'un arc											   ***
	******************************************************************************
	*** E : uiDepart : unsigned int ; numéro du sommet de départ			   ***
	*** uiDestination : unsigned int ; numéro du sommet de destination		   ***
	*** nécessite : néant													   ***
	*** S : néant															   ***
	*** entraine : création d'un nouvel arc	et incrémente uiGRANbArc		   ***
	*** renvoie une exception si l'arc existe déjà							   ***
	*****************************************************************************/

	void GRAModifierArc(unsigned int uiDepart, unsigned int uiDestination, unsigned int uiNouvelleDestination);
	/*****************************************************************************
	*** Methode de modification d'un arc									   ***
	******************************************************************************
	*** E : uiDepart : unsigned int ; numéro du sommet de départ			   ***
	*** uiDestination : unsigned int ; numéro du sommet de destination		   ***
	*** nécessite : néant													   ***
	*** S : néant															   ***
	*** entraine : modification de la destination de l'arc partant de uiDepart ***
	*****************************************************************************/

	void GRASupprimerArc(unsigned int uiDepart, unsigned int uiDestination);
	/*****************************************************************************
	*** Methode de suppression d'un arc										   ***
	******************************************************************************
	*** E : uiDepart : unsigned int ; numéro du sommet de départ			   ***
	*** uiDestination : unsigned int ; numéro du sommet de destination		   ***
	*** nécessite : néant													   ***
	*** S : néant															   ***
	*** entraine : suppression de l'arc de la liste des arcs et décrémente	   ***
	*** uiGRANbArc. Renvoie une exception si l'arc n'existe pas				   ***
	*****************************************************************************/
	
	void GRAAfficherGraphe();
	/*****************************************************************************
	*** Methode d'affichage du graphe										   ***
	******************************************************************************
	*** E : néant															   ***
	*** nécessite : néant													   ***
	*** S : néant															   ***
	*** entraine : affichage du graphe dans la console sous forme de matrice   ***
	*****************************************************************************/

private:
	inline CSommet GRATrouverSommet(unsigned int uiNumero);
	/*****************************************************************************
	*** Méthode retournant l'indice d'un sommet								   ***
	******************************************************************************
	*** E : uiNumero : unsigned int											   ***
	*** nécessite : néant													   ***
	*** S : unsigned int : l'indice du CSommet de numéro uiNumero			   ***
	*** entraine : néant													   ***
	*****************************************************************************/

	inline bool GRAExisteSommet(unsigned int uiNumero);
	/*****************************************************************************
	*** Méthode verifiant l'existance d'un sommet							   ***
	******************************************************************************
	*** E : uiNumero : unsigned int											   ***
	*** nécessite : néant													   ***
	*** S : bool : vrai si le sommet existe, sinon faux						   ***
	*** entraine : néant													   ***
	*****************************************************************************/

	void GRATrierListeSommets();
	/*****************************************************************************
	*** Méthode de trie à bulle pour la liste de sommets					   ***
	******************************************************************************
	*** E : néant															   ***
	*** nécessite : néant													   ***
	*** S : néant															   ***
	*** entraine : les sommets de vGRAListeSommets sont triés dans l'ordre	   ***
	*** croissant en fonction de leurs numéros								   ***
	*****************************************************************************/
};


#endif