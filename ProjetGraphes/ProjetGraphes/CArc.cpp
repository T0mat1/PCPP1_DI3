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

inline void CArc::ARCModifierDestination(unsigned int uiNouvelleDestination) {
	uiARCDestination = uiARCDestination;
}

inline unsigned int CArc::ARCLireDestination() {
	return uiARCDestination;
}