#include "stdafx.h"
#include "CMatrice.h"


template <typename MType> CMatrice<typename MType>::CMatrice()
{
	uiMATNombreLignes = 1;
	uiMATNombreColonnes = 1;
	pptMATMatrice = new MType*[uiMATNombreLignes];
	pptMATMatrice[0] = new MType[uiMATNombreColonnes];
}

template <typename MType> CMatrice<typename MType>::CMatrice(CMatrice & MATParam)
{
	unsigned int uiBoucleLignes, uiBoucleColonnes;
	uiMATNombreLignes = MATParam.uiMATNombreLignes;
	uiMATNombreColonnes = MATParam.uiMATNombreColonnes;
	pptMATMatrice = new MType*[uiMATNombreLignes];

	for (uiBoucleLignes = 0; uiBoucleLignes < uiMATNombreLignes; uiBoucleLignes++)
	{
		pptMATMatrice[uiBoucleLignes] = new MType[uiMATNombreColonnes];
		for (uiBoucleColonnes = 0; uiBoucleColonnes < uiMATNombreColonnes; uiBoucleColonnes++)
			pptMATMatrice[uiBoucleLignes][uiBoucleColonnes] = MATParam.pptMATMatrice[uiBoucleLignes][uiBoucleColonnes];
	}
		
	
}

template <typename MType> CMatrice<typename MType>::~CMatrice()
{
}
