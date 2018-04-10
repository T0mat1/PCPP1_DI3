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

template <typename MType> CMatrice<typename MType>::CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes)
{
	unsigned int uiBoucleLignes, uiBoucleColonnes;
	uiMATNombreLignes = uiNombreLignes;
	uiMATNombreColonnes = uiNombreColonnes;
	pptMATMatrice = new MType*[uiMATNombreLignes];

	for (uiBoucleLignes = 0; uiBoucleLignes < uiMATNombreLignes; uiBoucleLignes++)
		pptMATMatrice[uiBoucleLignes] = new MType[uiMATNombreColonnes];
}

template <typename MType> CMatrice<typename MType>::~CMatrice()
{
	for (unsigned int uiBoucle; uiBoucle < uiMATNombreLignes; uiBoucle++)
		delete pptMATMatrice[uiBoucle];
	delete pptMATMatrice;
}

template <typename MType> inline unsigned int CMatrice<typename MType>::MATLireNombreLignes()
{
	return uiMATNombreLignes;
}

template <typename MType> inline unsigned int CMatrice<typename MType>::MATLireNombreColonnes()
{
	return uiMATNombreColonnes;
}

/*
inline void MATModifierComposante(MType tParam, unsigned int uiLigne, unsigned int uiColonne);
CMatrice operator*(int iParam);
CMatrice operator*(CMatrice MATParam);
CMatrice operator-(CMatrice MATParam);
CMatrice operator/(int iParam);
void MATAfficherMatrice();
CMatrice MATCalculerTransposee();
*/