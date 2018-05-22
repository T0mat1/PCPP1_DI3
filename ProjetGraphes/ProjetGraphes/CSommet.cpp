#include "CSommet.h"
#include "CExceptions.h"
#include <algorithm>
using namespace std;

#define ARC_DEJA_EXISTANT 2001
#define ARC_INEXISTANT 2002


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

inline unsigned int CSommet::SOMLireNumero()
{
	return uiSOMNumero;
}

CArc CSommet::SOMRecupererArcPartant(unsigned int uiDestination)
{
	std::for_each(vSOMPartants.begin(), vSOMPartants.end(),
		[](CArc * partant, unsigned int uiDestination)
	{
		if (partant->ARCLireDestination() == uiDestination)
		{
			return partant;
		}
	}
	);
	throw new CExceptions(ARC_INEXISTANT);
}

inline std::vector<CArc> CSommet::SOMRecupererArcsPartants()
{
	return vSOMPartants;
}

inline std::vector<CArc> CSommet::SOMRecupererArcsArrivants()
{
	return vSOMArrivants;
}