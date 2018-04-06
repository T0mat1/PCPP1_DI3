#include "stdafx.h"
#include "CMatrice.h"


template <class MType> CMatrice<class MType>::CMatrice()
{
	uiMATNombreLignes = 1;
	uiMATNombreColonnes = 1;
	pptMATMatrice = new MType*[uiMATNombreLignes];
	pptMATMatrice[0] = new MType[uiMATNombreColonnes];
}


CMatrice<class MType>::~CMatrice()
{
}
