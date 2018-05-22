#include "CArc.h"

CArc::CArc(void)
{
}

// ----------------------------------------------- Constructeurs et destructeur ----------------------------------------------- 

CArc::CArc(unsigned int uiNouvelleDestination)
{
	uiARCDestination = uiNouvelleDestination;
}

CArc::~CArc(void)
{
}

// ----------------------------------------------- M�thodes -----------------------------------------------

inline void CArc::ARCModifierDestination(unsigned int uiNouvelleDestination)
{
	uiARCDestination = uiNouvelleDestination;
}

inline unsigned int CArc::ARCLireDestination() const 
{
	return uiARCDestination;
}

bool CArc::operator==(const CArc & ARCParam) const
{
	return uiARCDestination == ARCParam.ARCLireDestination();
}