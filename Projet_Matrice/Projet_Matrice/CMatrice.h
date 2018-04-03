#pragma once
template <class MType> class CMatrice
{
private:
	MType ** pptMatrice;
	unsigned int uiNombreLignes;
	unsigned int uiNombreColonnes;

public:
	//Constructeurs et destructeur

	CMatrice();
	/**********************************************
	*** Constructeur par défaut                 ***
	***********************************************
	*** E : néant                               ***
	*** nécessite : néant                       ***
	*** S : néant                               ***
	*** entraine : Matrice 1x1 initialisée à 1  ***
	**********************************************/

	CMatrice(CMatrice & MATParam);
	
	CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes);
	~CMatrice();

	//Accesseurs
	unsigned int MATLireNombreLignes();
	unsigned int MATLireNombreColonnes();

	void MATModifierComposante(MType tParam, unsigned int uiLigne, unsigned int uiColonne);

	//Surcharges d'operateurs
	CMatrice operator*(int iParam);
	CMatrice operator*(CMatrice MATParam);
	CMatrice operator+(CMatrice MATParam);
	CMatrice operator-(CMatrice MATParam);
	CMatrice operator/(CMatrice MATParam);

	//Methodes
	void MATAfficherMatrice();
	CMatrice MATCalculerTransposee();
};

