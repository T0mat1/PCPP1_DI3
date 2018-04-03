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
	*** Constructeur par d�faut                 ***
	***********************************************
	*** E : n�ant                               ***
	*** n�cessite : n�ant                       ***
	*** S : n�ant                               ***
	*** entraine : Matrice 1x1 initialis�e � 1  ***
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

