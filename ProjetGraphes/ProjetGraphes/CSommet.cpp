#include "CSommet.h"
#include <algorithm>
using namespace std;


CSommet::CSommet(void)
{
}

CSommet::CSommet(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
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

unsigned int CSommet::SOMLireNumero()
{
	return uiSOMNumero;
}