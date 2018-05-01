#include "CGraphe.h"
#include "CSommet.h"

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

//------------------------------------------------ Méthodes ------------------------------------------------

void CGraphe::GRAAjouterSommet(unsigned int uiNumero)
{
	if (uiGRANbSommets == 0)
	{
		vGRAListeSommets.push_back(*(new CSommet(uiNumero)));
	}
	else
	{
		unsigned int uiBoucle = 0;
		while (vGRAListeSommets[uiBoucle].SOMLireNumero() < uiNumero && uiBoucle < vGRAListeSommets.size())
		{
			uiBoucle++;
		}
		vGRAListeSommets.insert(vGRAListeSommets.begin() + uiBoucle, *(new CSommet(uiNumero)));
	}
	uiGRANbSommets++;

}

/*
void CGraphe::GRASupprimerSommet(unsigned int uiNumero)
void CGraphe::GRAAjouterArc(unsigned int uiDepart, unsigned int uiDestination)
void CGraphe::GRAModifierArc(unsigned int uiDepart, unsigned int uiDestination, unsigned int uiNouvelleDestination)
void CGraphe::GRASupprimerArc(unsigned int uiDepart, unsigned int uiDestination)
void CGraphe::GRAAfficherGraphe()
*/