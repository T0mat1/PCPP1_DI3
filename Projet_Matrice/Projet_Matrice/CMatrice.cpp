#include "stdafx.h"
#include "CMatrice.h"


template <typename MType> CMatrice<typename MType>::CMatrice()
{
	uiMATNombreLignes = 1;
	uiMATNombreColonnes = 1;
	pptMATMatrice = new MType*[uiMATNombreLignes];
	pptMATMatrice[0] = new MType[uiMATNombreColonnes];
}


template <typename MType> CMatrice<typename MType>::~CMatrice()
{
}
