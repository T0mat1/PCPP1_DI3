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
	vGRAListeSommets.push_back(*(new CSommet(uiNumero)));
}