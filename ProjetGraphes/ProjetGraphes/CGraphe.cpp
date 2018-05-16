#include "CGraphe.h"
#include "CSommet.h"
#include <iostream>

#define SOMMET_DEJA_EXISTANT 1001
#define SOMMET_INEXISTANT 1002
#define ARC_DEJA_EXISTANT 2001
#define ARC_INEXISTANT 2002

//------------------------------------------------ Constructeurs et destructeur ------------------------------------------------

CGraphe::CGraphe(void)
{
	uiGRANbArc = 0;
	uiGRANbSommets = 0;
}


CGraphe::~CGraphe(void)
{
}

//------------------------------------------------ M�thodes ------------------------------------------------

void CGraphe::GRAAjouterSommet(unsigned int uiNumero)
{
	vGRAListeSommets.push_back(CSommet(uiNumero));
	uiGRANbSommets++;

}

void CGraphe::GRASupprimerSommet(unsigned int uiNumero)
{
	try	{
		CSommet SOMTemp = GRATrouverSommet(uiNumero);
		vGRAListeSommets.erase(remove(vGRAListeSommets.begin(), vGRAListeSommets.end(), SOMTemp), vGRAListeSommets.end());
		uiGRANbSommets--;
	}
	catch (CExceptions e)
	{
		std::cerr << "Exception lev�e - ID" << e.EXCLireValeur() << std::endl;
	}
}

void CGraphe::GRAAjouterArc(unsigned int uiDepart, unsigned int uiDestination)
{
	//TODO
}
/*
void CGraphe::GRAModifierArc(unsigned int uiDepart, unsigned int uiDestination, unsigned int uiNouvelleDestination)
/*
void CGraphe::GRASupprimerArc(unsigned int uiDepart, unsigned int uiDestination)
/*
void CGraphe::GRAAfficherGraphe()
*/

inline CSommet CGraphe::GRATrouverSommet(unsigned int uiNumero)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vGRAListeSommets.size(); uiBoucle++) {
		if (vGRAListeSommets[uiBoucle].SOMLireNumero == uiNumero) {
			return vGRAListeSommets[uiBoucle];
		}
	}
	throw new CExceptions(1002);
}
