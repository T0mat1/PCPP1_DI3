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

void CSommet::SOMAjouterArcArrivant(CArc ARCParam)
{
	vSOMArrivants.push_back(ARCParam);
}

void CSommet::SOMAjouterArcPartant(CArc ARCParam)
{
	vSOMPartants.push_back(ARCParam);
}

void CSommet::SOMSupprimerArcArrivant(CArc ARCParam)
{
	vSOMArrivants.erase(remove(vSOMArrivants.begin(), vSOMArrivants.end(), ARCParam), vSOMArrivants.end());
}

void CSommet::SOMSupprimerArcPartant(CArc ARCParam)
{
	vSOMPartants.erase(remove(vSOMPartants.begin(), vSOMPartants.end(), ARCParam), vSOMPartants.end());
}

inline unsigned int CSommet::SOMLireNumero()
{
	return uiSOMNumero;
}

inline void CSommet::SOMModifierNumero(unsigned int uiParam)
{
	uiSOMNumero = uiParam;
}