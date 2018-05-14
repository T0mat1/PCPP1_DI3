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

	void GRAAjouterArc(unsigned int uiDepart, unsigned int uiDestination);
	/*****************************************************************************
	*** Methode d'ajout d'un arc											   ***
	******************************************************************************
	*** E : uiDepart : unsigned int ; num�ro du sommet de d�part			   ***
	*** uiDestination : unsigned int ; num�ro du sommet de destination		   ***
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

private:
	inline unsigned int GRATrouverIndiceSommet(unsigned int uiNumero);
	/*****************************************************************************
	*** M�thode retournant l'indice d'un sommet								   ***
	******************************************************************************
	*** E : uiIndice : unsigned int											   ***
	*** n�cessite : n�ant													   ***
	*** S : uhnisgned int : l'indice du CSommet	de num�ro uiNumero			   ***
	*** entraine : n�ant													   ***
	*****************************************************************************/

};


#endif