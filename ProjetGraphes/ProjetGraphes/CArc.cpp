#include "CArc.h"

CArc::CArc(void)
{
}

// ----------------------------------------------- Constructeurs et destructeur ----------------------------------------------- 

CArc::CArc(unsigned int uiNouvelleDestination)
{
	uiARCDestination = uiNouvelleDestination;
	uiARCPoids = 1;
}

CArc::CArc(unsigned int uiNouvelleDestination, unsigned int uiPoids)
{
	uiARCDestination = uiNouvelleDestination;
	uiARCPoids = uiPoids;
}

CArc::~CArc(void)
{
}

// ----------------------------------------------- Méthodes -----------------------------------------------

void CArc::ARCModifierDestination(unsigned int uiNouvelleDestination)
{
	uiARCDestination = uiNouvelleDestination;
}

inline unsigned int CArc::ARCLireDestination() const 
{
	return uiARCDestination;
}

bool CArc::operator==(const CArc & ARCParam) const
{
	return (uiARCDestination == ARCParam.ARCLireDestination() && uiARCPoids == ARCParam.ARCLirePoids());
}

void CArc::ARCModifierPoids(unsigned int uiNouveauPoids)
{
	uiARCPoids = uiNouveauPoids;
}

inline unsigned int CArc::ARCLirePoids() const
{
	return uiARCPoids;
}