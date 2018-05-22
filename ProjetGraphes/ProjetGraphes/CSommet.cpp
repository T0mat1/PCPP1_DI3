#include "CSommet.h"
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
	vSOMArrivants.erase(std::remove(vSOMArrivants.begin(), vSOMArrivants.end(), ARCParam), vSOMArrivants.end());
}

void CSommet::SOMSupprimerArcPartant(CArc ARCParam)
{
	vSOMPartants.erase(std::remove(vSOMPartants.begin(), vSOMPartants.end(), ARCParam), vSOMPartants.end());
}

inline unsigned int CSommet::SOMLireNumero() const
{
	return uiSOMNumero;
}

CArc CSommet::SOMRecupererArcPartant(unsigned int uiDestination)
{
	for (unsigned int uiBoucle = 0; uiBoucle < SOMRecupererArcsArrivants().size(); uiBoucle++) {
		if (SOMRecupererArcsArrivants()[uiBoucle].ARCLireDestination() == uiDestination) {
			return SOMRecupererArcsArrivants()[uiBoucle];
		}
	}
	throw new CExceptions(ARC_INEXISTANT);
}

inline std::vector<CArc> CSommet::SOMRecupererArcsPartants() const
{
	return vSOMPartants;
}

inline std::vector<CArc> CSommet::SOMRecupererArcsArrivants() const
{
	return vSOMArrivants;
}

bool CSommet::operator==(const CSommet & SOMsommet) const
{
	if (SOMsommet.SOMLireNumero() != SOMLireNumero() || SOMsommet.SOMRecupererArcsArrivants().size() != SOMRecupererArcsArrivants().size() || SOMsommet.SOMRecupererArcsPartants().size() != SOMRecupererArcsPartants().size()) {
		return false;
	}

	for (unsigned int uiBoucle = 0; uiBoucle < SOMRecupererArcsArrivants().size(); uiBoucle++) {
		if (SOMsommet.SOMRecupererArcsArrivants()[uiBoucle].ARCLireDestination() != SOMRecupererArcsArrivants()[uiBoucle].ARCLireDestination()) {
			return false;
		}
	}

	for (unsigned int uiBoucle = 0; uiBoucle < SOMRecupererArcsPartants().size(); uiBoucle++) {
		if (SOMsommet.SOMRecupererArcsPartants()[uiBoucle].ARCLireDestination() != SOMRecupererArcsPartants()[uiBoucle].ARCLireDestination()) {
			return false;
		}
	}

	return true;
}