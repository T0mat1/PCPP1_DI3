#pragma once
template <class MType> class CMatrice
{
private:
	MType ** pptMatrice;
	unsigned int uiNombreLignes;
	unsigned int uiNombreColonnes;

public:
	CMatrice()

	~CMatrice();
};

