#include "CGraphe.h"

#define SOMMET_DEJA_EXISTANT 1001
#define SOMMET_INEXISTANT 1002

//------------------------------------------------ Constructeurs et destructeur ------------------------------------------------

CGraphe::CGraphe(void)
{
	uiGRANbArcs = 0;
	uiGRANbSommets = 0;
}


CGraphe::~CGraphe(void)
{
}

//------------------------------------------------ Méthodes ------------------------------------------------

void CGraphe::GRAAjouterSommet(unsigned int uiNumero)
{
	if (!GRAExisteSommet(uiNumero)) {
		vGRAListeSommets.push_back(CSommet(uiNumero));
		uiGRANbSommets++;
	} else {
		throw new CExceptions(SOMMET_DEJA_EXISTANT);
	}
}

void CGraphe::GRASupprimerSommet(unsigned int uiNumero)
{
	try	{
		CSommet SOMTemp = GRATrouverSommet(uiNumero);
		vGRAListeSommets.erase(std::remove(vGRAListeSommets.begin(), vGRAListeSommets.end(), SOMTemp), vGRAListeSommets.end());
		uiGRANbSommets--;
	} catch (CExceptions EXCe) {
		std::cerr << "Exception levée - ID" << EXCe.EXCLireValeur() << std::endl;
	}
}

void CGraphe::GRAAjouterArc(unsigned int uiDepart, unsigned int uiDestination, unsigned int uiPoids)
{
	CArc ARCTemp = CArc(uiDestination, uiPoids);
	GRATrouverSommet(uiDepart).SOMAjouterArcPartant(ARCTemp);
	GRATrouverSommet(uiDestination).SOMAjouterArcArrivant(ARCTemp);
	uiGRANbArcs++;
}

void CGraphe::GRAModifierArc(unsigned int uiDepart, unsigned int uiDestination, unsigned int uiNouvelleDestination)
{
	CArc * pARCTmp = &(GRATrouverSommet(uiDepart).SOMRecupererArcPartant(uiDestination));
	//Suppression de l'arc de la liste d'arcs arrivant vers l'ancienne destination
	GRATrouverSommet(uiDestination).SOMSupprimerArcArrivant(*pARCTmp);
	//Ajout de l'arc à la liste d'arcs arrivant de la nouvelle destination
	GRATrouverSommet(uiNouvelleDestination).SOMAjouterArcArrivant(*pARCTmp);
	//Modification de la destination de l'arc, dans la liste des arcs partant du sommet de depart
	(*pARCTmp).ARCModifierDestination(uiNouvelleDestination);
}

void CGraphe::GRASupprimerArc(unsigned int uiDepart, unsigned int uiDestination)
{
	try {
		CArc * pARCTmp = &(GRATrouverSommet(uiDepart).SOMRecupererArcPartant(uiDestination));
		//Suppression de l'arc de la liste des arcs arrivant au sommet uiDestination
		GRATrouverSommet(uiDestination).SOMSupprimerArcArrivant(*pARCTmp);
		//Suppression de l'arc de la liste des arcs arrivant au sommet uiDepart
		GRATrouverSommet(uiDepart).SOMSupprimerArcPartant(*pARCTmp);
		//On decremente le nombre d'arcs
		uiGRANbArcs--;
	}
	catch (CExceptions EXCe)
	{
		std::cerr << "Exception levée - ID" << EXCe.EXCLireValeur() << std::endl;
	}
}

void CGraphe::GRAAfficherGraphe()
{
	std::cout << "Graphe (" << uiGRANbSommets << "," << uiGRANbArcs << ")" << std::endl;

	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < vGRAListeSommets.size(); uiBoucleSommet++) {
		for (unsigned int uiBoucleArc = 0; uiBoucleArc < vGRAListeSommets[uiBoucleSommet].SOMRecupererArcsPartants().size(); uiBoucleArc++) {
			std::cout << vGRAListeSommets[uiBoucleSommet].SOMLireNumero() << "-->" << vGRAListeSommets[uiBoucleSommet].SOMRecupererArcsPartants()[uiBoucleArc].ARCLireDestination() << " ; Poids = " << vGRAListeSommets[uiBoucleSommet].SOMRecupererArcsPartants()[uiBoucleArc].ARCLirePoids() << std::endl;
		}
	}
}

inline CSommet & CGraphe::GRATrouverSommet(unsigned int uiNumero)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vGRAListeSommets.size(); uiBoucle++) {
		if (vGRAListeSommets[uiBoucle].SOMLireNumero() == uiNumero) {
			return vGRAListeSommets[uiBoucle];
		}
	}
	throw new CExceptions(SOMMET_INEXISTANT);
}

inline bool CGraphe::GRAExisteSommet(unsigned int uiNumero)
{
	for (unsigned int uiBoucle = 0; uiBoucle < vGRAListeSommets.size(); uiBoucle++) {
		if (vGRAListeSommets[uiBoucle].SOMLireNumero() == uiNumero) {
			return true;
		}
	}
	return false;
}

void CGraphe::GRATrierListeSommets()
{
	bool bEstTrie = false;
	int iTaille = vGRAListeSommets.size();
	while (!bEstTrie)
	{
		bEstTrie = true;
		for (int iBoucle = 0; iBoucle < iTaille - 1; iBoucle++)
		{
			if (vGRAListeSommets[iBoucle].SOMLireNumero() > vGRAListeSommets[iBoucle + 1].SOMLireNumero())
			{
				std::swap(vGRAListeSommets[iBoucle], vGRAListeSommets[iBoucle + 1]);
				bEstTrie = false;
			}
		}
		iTaille--;
	}
}

CSommet * CGraphe::GRARecupererSommetAtIndex(unsigned int uiIndex)
{
	return &vGRAListeSommets[uiIndex];
}

CGraphe * CGraphe::GRAInverserArcs()
{
	CGraphe * graTmp = new CGraphe();
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < vGRAListeSommets.size(); uiBoucleSommet++) {
		graTmp->GRAAjouterSommet(GRARecupererSommetAtIndex(uiBoucleSommet)->SOMLireNumero());
	}
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < vGRAListeSommets.size(); uiBoucleSommet++) {
		for (unsigned int uiBoucleArc = 0; uiBoucleArc < GRARecupererSommetAtIndex(uiBoucleSommet)->SOMRecupererArcsPartants().size(); uiBoucleArc++) {
			graTmp->GRAAjouterArc(GRARecupererSommetAtIndex(uiBoucleSommet)->SOMRecupererArcPartantAtIndex(uiBoucleArc)->ARCLireDestination(), GRARecupererSommetAtIndex(uiBoucleSommet)->SOMLireNumero(), GRARecupererSommetAtIndex(uiBoucleSommet)->SOMRecupererArcPartantAtIndex(uiBoucleArc)->ARCLirePoids());
		}
	}

	return graTmp;
}

CGraphe * CGraphe::GRAExtraireArbreCouvrant()
{

	CGraphe	* pGRAArbre = new CGraphe();
	pGRAArbre->GRAAjouterSommet(vGRAListeSommets[0].SOMLireNumero());
	for (unsigned int uiBoucleSommetCourant = 0; uiBoucleSommetCourant < GRALireNbSommets(); uiBoucleSommetCourant++)
	{
		if (pGRAArbre->GRALireNbSommets() == GRALireNbSommets()) {
			break;
		}

		unsigned int uiTmpBestDepart = GRARecupererSommetAtIndex(uiBoucleSommetCourant)->SOMLireNumero();
		CArc * pARCBest = nullptr;

		for (unsigned int uiBoucleSommetTmp = 0; uiBoucleSommetTmp < pGRAArbre->GRALireNbSommets(); uiBoucleSommetTmp++)
		{
			for (unsigned int uiBoucleArcs = 0;
				uiBoucleArcs < GRATrouverSommet(pGRAArbre->GRARecupererSommetAtIndex(uiBoucleSommetTmp)->SOMLireNumero()).SOMRecupererArcsPartants().size();
				uiBoucleArcs++)
			{
				CArc * pArcTemp = GRATrouverSommet(pGRAArbre->GRARecupererSommetAtIndex(uiBoucleSommetTmp)->SOMLireNumero()).SOMRecupererArcPartantAtIndex(uiBoucleArcs);
				if (!(pGRAArbre->GRAExisteSommet(pArcTemp->ARCLireDestination()))) {
					if (pARCBest == nullptr) {
						pARCBest = pArcTemp;
					} else if(pARCBest->ARCLirePoids() > pArcTemp->ARCLirePoids()) {
						pARCBest = pArcTemp;
						uiTmpBestDepart = pGRAArbre->GRARecupererSommetAtIndex(uiBoucleSommetTmp)->SOMLireNumero();
					}
				}
			}
		}

		pGRAArbre->GRAAjouterSommet(pARCBest->ARCLireDestination());
		pGRAArbre->GRAAjouterArc(uiTmpBestDepart, pARCBest->ARCLireDestination(), pARCBest->ARCLirePoids());
		pGRAArbre->GRAAjouterArc(pARCBest->ARCLireDestination(), uiTmpBestDepart, pARCBest->ARCLirePoids());

	}

	return pGRAArbre;
}

unsigned int CGraphe::GRALireNbSommets()
{
	return uiGRANbSommets;
}

unsigned int CGraphe::GRALireNbArcs()
{
	return uiGRANbArcs;
}