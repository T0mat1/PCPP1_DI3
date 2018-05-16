#include "CSommet.h"
#include <algorithm>
using namespace std;


CSommet::CSommet(void)
{
}

CSommet::CSommet(unsigned int uiNumero)
{
	SOMModifierNumero(uiNumero);
}

CSommet::~CSommet(void)
{
}

void CSommet::SOMAjouterArcArrivant(CArc * pARCParam)
{
	vSOMArrivants.push_back(pARCParam);
}

void CSommet::SOMAjouterArcPartant(CArc * pARCParam)
{
	vSOMPartants.push_back(pARCParam);
}

void CSommet::SOMSupprimerArcArrivant(CArc * pARCParam)
{
	vSOMArrivants.erase(remove(vSOMArrivants.begin(), vSOMArrivants.end(), pARCParam), vSOMArrivants.end());
}

void CSommet::SOMSupprimerArcPartant(CArc * pARCParam)
{
	vSOMPartants.erase(remove(vSOMPartants.begin(), vSOMPartants.end(), pARCParam), vSOMPartants.end());
}

inline unsigned int CSommet::SOMLireNumero()
{
	return uiSOMNumero;
}

inline void CSommet::SOMModifierNumero(unsigned int uiParam)
{
	uiSOMNumero = uiParam;
}