#ifndef CGRAPHE_H
#define CGRAPHE_H 1

#include <vector>
#include <iostream>
#include <algorithm>
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
	unsigned int uiGRANbArcs;
	unsigned int uiGRANbSommets;
	std::vector<CSommet> vGRAListeSommets;

public:

	//------------------------------------------------ Constructeurs et destructeur ------------------------------------------------

	CGraphe(void);
	/**********************************************
	*** Constructeur par d�faut                 ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : cr�ation de l'objet CGraphe  ***
	**********************************************/
	
	~CGraphe(void);
	/**********************************************
	*** Destructeur				                ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : CGraphe d�truit		        ***
	**********************************************/

	//------------------------------------------------ M�thodes ------------------------------------------------

	void GRAAjouterSommet(unsigned int uiNumero);
	/********************************************************************************
	*** Methode d'ajout d'un sommet											      ***
	*********************************************************************************
	*** E : uiNumero : unsigned int ; num�ro du sommet � cr�er				      ***
	*** n�cessite : n�ant														  ***
	*** S : n�ant																  ***
	*** entraine : cr�ation d'un nouveau sommet et ajout � la liste de sommets	  ***
	*** Incr�mente uiGRANbSommets. Renvoie une exception si le sommet existe d�j� ***
	********************************************************************************/
	
	void GRASupprimerSommet(unsigned int uiNumero);
	/******************************************************************************************
	*** Methode de suppression d'un sommet													***
	*******************************************************************************************
	*** E : uiNumero : unsigned int ; num�ro du sommet � supprimer							***
	*** n�cessite : n�ant																	***
	*** S : n�ant																			***
	*** entraine : suppression du sommet de la liste des sommets et supprime				***
	*** l'objet. D�cr�mente uiGRANbSommets. Renvoie une exception si le sommet n'existe pas	***
	******************************************************************************************/

	void GRAAjouterArc(unsigned int uiDepart, unsigned int uiDestination, unsigned int uiPoids);
	/*****************************************************************************
	*** Methode d'ajout d'un arc											   ***
	******************************************************************************
	*** E : uiDepart : unsigned int ; num�ro du sommet de d�part			   ***
	*** uiDestination : unsigned int ; num�ro du sommet de destination		   ***
	*** uiPoids : unsigned int ; poids de l'arc								   ***
	*** n�cessite : n�ant													   ***
	*** S : n�ant															   ***
	*** entraine : cr�ation d'un nouvel arc	et incr�mente uiGRANbArc		   ***
	*** renvoie une exception si l'arc existe d�j�							   ***
	*****************************************************************************/

	void GRAModifierArc(unsigned int uiDepart, unsigned int uiDestination, unsigned int uiNouvelleDestination);
	/*****************************************************************************
	*** Methode de modification d'un arc									   ***
	******************************************************************************
	*** E : uiDepart : unsigned int ; num�ro du sommet de d�part			   ***
	*** uiDestination : unsigned int ; num�ro du sommet de destination		   ***
	*** n�cessite : n�ant													   ***
	*** S : n�ant															   ***
	*** entraine : modification de la destination de l'arc partant de uiDepart ***
	*****************************************************************************/

	void GRASupprimerArc(unsigned int uiDepart, unsigned int uiDestination);
	/*****************************************************************************
	*** Methode de suppression d'un arc										   ***
	******************************************************************************
	*** E : uiDepart : unsigned int ; num�ro du sommet de d�part			   ***
	*** uiDestination : unsigned int ; num�ro du sommet de destination		   ***
	*** n�cessite : n�ant													   ***
	*** S : n�ant															   ***
	*** entraine : suppression de l'arc de la liste des arcs et d�cr�mente	   ***
	*** uiGRANbArc. Renvoie une exception si l'arc n'existe pas				   ***
	*****************************************************************************/
	
	void GRAAfficherGraphe();
	/*****************************************************************************
	*** Methode d'affichage du graphe										   ***
	******************************************************************************
	*** E : n�ant															   ***
	*** n�cessite : n�ant													   ***
	*** S : n�ant															   ***
	*** entraine : affichage du graphe dans la console sous forme de matrice   ***
	*****************************************************************************/

	CGraphe * GRAInverserArcs();
	/*****************************************************************************
	*** M�thode qui inverse le sens de tous les arcs						   ***
	******************************************************************************
	*** E : n�ant															   ***
	*** n�cessite : n�ant													   ***
	*** S : un graphe inverse												   ***
	*** entraine : les arcs partants deviennent les arcs arrivants			   ***
	*** pour tous les sommets												   ***
	*****************************************************************************/

	CGraphe * GRAExtraireArbreCouvrant();
	/*****************************************************************************
	*** M�thode extrayant l'arbre couvrant du graphe						   ***
	*** � l'aide de l'algorithme de Prim									   ***
	******************************************************************************
	*** E : n�ant															   ***
	*** n�cessite : n�ant													   ***
	*** S : Un graphe repr�sentant l'arbre couvrant							   ***
	*** entraine : n�ant													   ***
	*****************************************************************************/

	unsigned int GRALireNbSommets();
	/*****************************************************************************************************
	*** Accesseur en lecture de uiGRANbSommets														   ***
	******************************************************************************************************
	*** E : n�ant																					   ***
	*** n�cessite : n�ant																			   ***
	*** S : la valeur de l'attribut uiGRANbSommets													   ***
	*** entraine : n�ant																			   ***
	*****************************************************************************************************/
	unsigned int GRALireNbArcs();
	/*****************************************************************************************************
	*** Accesseur en lecture de uiGRANbArc															   ***
	******************************************************************************************************
	*** E : n�ant																					   ***
	*** n�cessite : n�ant																			   ***
	*** S : la valeur de l'attribut uiGRANbArc														   ***
	*** entraine : n�ant																			   ***
	*****************************************************************************************************/

private:
	inline CSommet & GRATrouverSommet(unsigned int uiNumero);
	/*****************************************************************************
	*** M�thode retournant l'indice d'un sommet								   ***
	******************************************************************************
	*** E : uiNumero : unsigned int											   ***
	*** n�cessite : n�ant													   ***
	*** S : unsigned int : l'indice du CSommet de num�ro uiNumero			   ***
	*** entraine : n�ant													   ***
	*****************************************************************************/

	inline bool GRAExisteSommet(unsigned int uiNumero);
	/*****************************************************************************
	*** M�thode verifiant l'existance d'un sommet							   ***
	******************************************************************************
	*** E : uiNumero : unsigned int											   ***
	*** n�cessite : n�ant													   ***
	*** S : bool : vrai si le sommet existe, sinon faux						   ***
	*** entraine : n�ant													   ***
	*****************************************************************************/

	void GRATrierListeSommets();
	/*****************************************************************************
	*** M�thode de trie � bulle pour la liste de sommets					   ***
	******************************************************************************
	*** E : n�ant															   ***
	*** n�cessite : n�ant													   ***
	*** S : n�ant															   ***
	*** entraine : les sommets de vGRAListeSommets sont tri�s dans l'ordre	   ***
	*** croissant en fonction de leurs num�ros								   ***
	*****************************************************************************/

	CSommet * GRARecupererSommetAtIndex(unsigned int uiIndex);
	/*****************************************************************************
	*** Modificateur d'un sommet											   ***
	/*****************************************************************************
	*** E : uiIndex, l'emplacement de mon sommet dans la liste				   ***
	*** n�cessite : n�ant													   ***
	*** S : un pointeur vers un sommet										   ***
	*** entraine : neant					 								   ***
	/****************************************************************************/
};


#endif