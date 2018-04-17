#ifndef CMATRICE_H
#define CMATRICE_H 1

#include <iostream>

#define MAT_SIZE_EXCEPTION 20001

template <typename MType> class CMatrice
{
private:
	MType ** pptMATMatrice;
	unsigned int uiMATNombreLignes;
	unsigned int uiMATNombreColonnes;

public:
	// ----------------------------------------------- Constructeurs et destructeur ----------------------------------------------- 

	CMatrice();
	/*************************************************************************************************
	*** Constructeur par d�faut																	   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : n�ant																				   ***
	*** entraine : Matrice 0x0 non initialis�e 													   ***
	*************************************************************************************************/

	CMatrice(CMatrice & MATParam);
	/*************************************************************************************************
	*** Constructeur de recopie																	   ***
	**************************************************************************************************
	*** E : MATParam ; la matrice � recopier													   ***
	*** n�cessite : n�ant																		   ***
	*** S : n�ant																				   ***
	*** entraine : Matrice initialis�e par recopie de MATParam									   ***
	*************************************************************************************************/
	
	CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes);
	/************************************************************************************************
	*** Constructeur par d�faut																	  ***
	*************************************************************************************************
	*** E : uiNombreLignes, uiNombreColonnes ; les dimensions de la matrice						  ***
	*** n�cessite : n�ant																		  ***
	*** S : n�ant																				  ***
	*** entraine : Matrice uiNombreLignes x uiNombreColonnes non initialis�e					  ***
	************************************************************************************************/

	CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes, MType tParam);
	/************************************************************************************************
	*** Constructeur par d�faut																	  ***
	*************************************************************************************************
	*** E : uiNombreLignes, uiNombreColonnes ; les dimensions de la matrice						  ***
	***     tParam ; la valeur initiale															  ***
	*** n�cessite : n�ant																		  ***
	*** S : n�ant																				  ***
	*** entraine : Matrice uiNombreLignes x uiNombreColonnes initialis�e � tParam				  ***
	************************************************************************************************/

	~CMatrice();
	/************************************************************************************************
	*** Destructeur         																	  ***
	*************************************************************************************************
	*** E : n�ant																				  ***
	*** n�cessite : n�ant																		  ***
	*** S : n�ant																				  ***
	*** entraine : Destruction de l'objet CMatrice												  ***
	************************************************************************************************/


	//----------------------------------------------- Accesseurs ----------------------------------------------- 

	unsigned int MATLireNombreLignes()
	{
		return uiMATNombreLignes;
	}
	/*************************************************************************************************
	*** Accesseur en lecture   																	   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreLignes) ; entier naturel			   ***
	*** entraine : retour de la valeur de uiNombreLignes										   ***
	*************************************************************************************************/

	unsigned int MATLireNombreColonnes()
	{
		return uiMATNombreColonnes;
	}
	/*************************************************************************************************
	*** Accesseur en lecture   																	   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreColonnes) ; entier naturel			   ***
	*** entraine : retour de la valeur de uiNombreColonnes    									   ***
	*************************************************************************************************/

	void MATModifierComposante(MType tParam, unsigned int uiLigne, unsigned int uiColonne)
	{
		pptMATMatrice[uiLigne][uiColonne] = tParam;
	}
	/*************************************************************************************************
	*** Accesseur en �criture 																	   ***
	**************************************************************************************************
	*** E : - tParam un param�tre de type MType qui contient la nouvelle valeur de la composante   ***
	***		- uiLigne la coordonn�e de la ligne de la composante � modifier ; entier naturel	   ***
	***		- uiColonne la coordonn�e de la colonne de la composante � modifier ; entier naturel   ***
	*** n�cessite : n�ant																		   ***
	*** S : n�ant																				   ***
	*** entraine : modification d'une composante de la matrice aux coordonn�es (uiColonne,uiLigne) ***
	*************************************************************************************************/

	MType MATLireComposante(unsigned int uiLigne, unsigned int uiColonne)
	{
		return pptMATMatrice[uiLigne][uiColonne];
	}
	/*************************************************************************************************
	*** Accesseur en lecture 																	   ***
	**************************************************************************************************
	*** E : - uiLigne la coordonn�e de la ligne de la composante � modifier ; entier naturel	   ***
	***		- uiColonne la coordonn�e de la colonne de la composante � modifier ; entier naturel   ***
	*** n�cessite : n�ant																		   ***
	*** S : MType valeur de la composante														   ***
	*** entraine : n�ant                                                                           ***
	*************************************************************************************************/

	//----------------------------------------------- Surcharges d'operateurs ----------------------------------------------- 

	CMatrice operator*(int iParam);
	/*************************************************************************************************
	*** Surcharge de l'op�rateur * (multiplication avec un entier)								   ***
	**************************************************************************************************
	*** E : iParam : un entier																	   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice, produit d'un CMatrice et d'un entier								   ***
	*** entraine : n�ant																		   ***
	*************************************************************************************************/
	
	CMatrice operator*(CMatrice & MATParam);
	/*************************************************************************************************
	*** Surcharge de l'op�rateur * (multiplication avec une matrice)							   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice, produit matriciel de deux objets CMatrice						   ***
	*** entraine : n�ant																		   ***
	*************************************************************************************************/

	CMatrice operator+(CMatrice & MATParam);
	/*************************************************************************************************
	*** Surcharge de l'op�rateur + (addition avec une matrice)									   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice, somme de deux objets CMatrice									   ***
	*** entraine : n�ant																		   ***
	*************************************************************************************************/

	CMatrice operator-(CMatrice & MATParam);
	/*************************************************************************************************
	*** Surcharge de l'op�rateur - (soustraction par une matrice)								   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice, diff�rence entre la matrice courante et MATParam					   ***
	*** entraine : n�ant																		   ***
	*************************************************************************************************/
	
	CMatrice operator/(int iParam);
	/*************************************************************************************************
	*** Surcharge de l'op�rateur / (division par un entier)										   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice, o� chaque composante vaut										   ***
	***		celle de la matrice courante divis�e par iParam								           ***
	*** entraine : n�ant																		   ***
	*************************************************************************************************/

	//----------------------------------------------- Methodes ----------------------------------------------- 
	
	void MATAfficherMatrice();
	/*************************************************************************************************
	*** M�thode d'affichage d'une matrice dans la console										   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : n�ant																				   ***
	*** entraine : Affichage de la matrice dans la console										   ***
	*************************************************************************************************/
	
	CMatrice & MATCalculerTransposee();
	/*************************************************************************************************
	*** M�thode de calcul de la transpos�e d'une matrice										   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice �gal � la transpos�e de la matrice								   ***
	*** entraine :																				   ***
	*************************************************************************************************/
};

template <typename MType> CMatrice<MType>::CMatrice()
{
	uiMATNombreLignes = 0;
	uiMATNombreColonnes = 0;
	pptMATMatrice = nullptr;
}

template <typename MType> CMatrice<MType>::CMatrice(CMatrice & MATParam)
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

template <typename MType> CMatrice<MType>::CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes)
{
	unsigned int uiBoucleLignes;
	uiMATNombreLignes = uiNombreLignes;
	uiMATNombreColonnes = uiNombreColonnes;
	pptMATMatrice = new MType*[uiMATNombreLignes];

	for (uiBoucleLignes = 0; uiBoucleLignes < uiMATNombreLignes; uiBoucleLignes++)
		pptMATMatrice[uiBoucleLignes] = new MType[uiMATNombreColonnes];
}

template <typename MType> CMatrice<MType>::CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes, MType tParam)
{
	unsigned int uiBoucleLignes;
	uiMATNombreLignes = uiNombreLignes;
	uiMATNombreColonnes = uiNombreColonnes;
	pptMATMatrice = new MType*[uiMATNombreLignes];

	for (uiBoucleLignes = 0; uiBoucleLignes < uiMATNombreLignes; uiBoucleLignes++)
		pptMATMatrice[uiBoucleLignes] = new MType[uiMATNombreColonnes];

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < MATLireNombreLignes(); uiBoucleLignes++)
	{
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < MATLireNombreColonnes(); uiBoucleColonnes++)
		{
			MATModifierComposante(tParam, uiBoucleLignes, uiBoucleColonnes);
		}
	}
}

template <typename MType> CMatrice<MType>::~CMatrice()
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNombreLignes; uiBoucle++)
		delete pptMATMatrice[uiBoucle];
	delete pptMATMatrice;
}

template <typename MType> CMatrice<MType> CMatrice<MType>::operator*(int iParam)
{
	CMatrice<MType> * pmatMatriceTemp = new CMatrice<MType>(*this);

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < pmatMatriceTemp->MATLireNombreLignes(); uiBoucleLignes++)
	{	
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < pmatMatriceTemp->MATLireNombreColonnes(); uiBoucleColonnes++)
		{
			pmatMatriceTemp->MATModifierComposante(iParam * MATLireComposante(uiBoucleLignes, uiBoucleColonnes), uiBoucleLignes, uiBoucleColonnes);
		}
	}
	return *pmatMatriceTemp;
}

template <typename MType> CMatrice<MType> CMatrice<MType>::operator*(CMatrice & MATParam)
{
	if (MATLireNombreLignes() != MATParam->MATLireNombreColonnes()) {
		throw new CExceptions(MAT_SIZE_EXCEPTION);
	} else {
		CMatrice<MType> * pmatMatriceTemp = new CMatrice<MType>(MATLireNombreLignes(), MATParam->MATLireNombreColonnes());
		MType tTmp;
	
		for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < pmatMatriceTemp->MATLireNombreLignes(); uiBoucleLignes++)
		{	
			for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < pmatMatriceTemp->MATLireNombreColonnes(); uiBoucleColonnes++)
			{
				tTmp = MATLireComposante(uiBoucleLignes, uiBoucleColonnes) * MATParam->MATLireComposante(uiBoucleLignes, uiBoucleColonnes);
				for (unsigned int uiBoucle = 1; uiBoucle < MATLireNombreColonnes(); uiBoucle++)
				{	
					tTmp = tTmp + MATLireComposante(uiBoucleLignes, uiBoucleColonnes+uiBoucle) * MATParam->MATLireComposante(uiBoucleLignes+uiBoucle, uiBoucleColonnes);
				}
				pmatMatriceTemp->MATModifierComposante(tTmp, uiBoucleLignes, uiBoucleColonnes);
			}
		}
		return *pmatMatriceTemp;
	}
}

template <typename MType> CMatrice<MType> CMatrice<MType>::operator+(CMatrice & MATParam)
{
	if (MATLireNombreColonnes() != MATParam->MATLireNombreColonnes() || MATLireNombreLignes() != MATParam->MATLireNombreLignes()) {
		throw new CExceptions(MAT_SIZE_EXCEPTION);
	} else {
		CMatrice<MType> * pmatMatriceTemp = new CMatrice<MType>(MATLireNombreLignes(), MATLireNombreColonnes());
	
		for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < pmatMatriceTemp->MATLireNombreLignes(); uiBoucleLignes++)
		{	
			for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < pmatMatriceTemp->MATLireNombreColonnes(); uiBoucleColonnes++)
			{
				pmatMatriceTemp->MATModifierComposante(MATLireComposante(uiBoucleLignes, uiBoucleColonnes) + MATParam->MATLireComposante(uiBoucleLignes, uiBoucleColonnes), uiBoucleLignes, uiBoucleColonnes);
			}
		}
		return *pmatMatriceTemp;
	}
}

template <typename MType> CMatrice<MType> CMatrice<MType>::operator-(CMatrice & MATParam)
{
	if (MATLireNombreColonnes() != MATParam->MATLireNombreColonnes() || MATLireNombreLignes() != MATParam->MATLireNombreLignes()) {
		throw new CExceptions(MAT_SIZE_EXCEPTION);
	} else {
		CMatrice<MType> * pmatMatriceTemp = new CMatrice<MType>(MATLireNombreLignes(), MATLireNombreColonnes());
	
		for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < pmatMatriceTemp->MATLireNombreLignes(); uiBoucleLignes++)
		{	
			for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < pmatMatriceTemp->MATLireNombreColonnes(); uiBoucleColonnes++)
			{
				pmatMatriceTemp->MATModifierComposante(MATLireComposante(uiBoucleLignes, uiBoucleColonnes) - MATParam->MATLireComposante(uiBoucleLignes, uiBoucleColonnes), uiBoucleLignes, uiBoucleColonnes);
			}
		}
		return *pmatMatriceTemp;
	}
}

template <typename MType> CMatrice<MType> CMatrice<MType>::operator/(int iParam)
{
	CMatrice<MType> * pmatMatriceTemp = new CMatrice<MType>(*this);

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < pmatMatriceTemp->MATLireNombreLignes(); uiBoucleLignes++)
	{	
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < pmatMatriceTemp->MATLireNombreColonnes(); uiBoucleColonnes++)
		{
			pmatMatriceTemp->MATModifierComposante(iParam / MATLireComposante(uiBoucleLignes, uiBoucleColonnes), uiBoucleLignes, uiBoucleColonnes);
		}
	}
	return *pmatMatriceTemp;
}

template <typename MType> void CMatrice<MType>::MATAfficherMatrice()
{
	std::cout << "Affichage de la matrice de taille ( " << MATLireNombreLignes() << " x " << MATLireNombreColonnes() << " )" << std::endl;
	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < MATLireNombreLignes(); uiBoucleLignes++)
	{	
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < MATLireNombreColonnes(); uiBoucleColonnes++)
		{
			std::cout << MATLireComposante(uiBoucleLignes, uiBoucleColonnes) << "\t";
		}
		std::cout << std::endl;
	}
}

template <typename MType> CMatrice<MType> & CMatrice<MType>::MATCalculerTransposee()
{
	CMatrice<MType> * pmatMatriceTemp = new CMatrice<MType>(MATLireNombreColonnes(), MATLireNombreLignes());

	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < MATLireNombreLignes(); uiBoucleLignes++)
	{	
		for (unsigned int uiBoucleColonnes = 0; uiBoucleColonnes < MATLireNombreColonnes(); uiBoucleColonnes++)
		{
			pmatMatriceTemp->MATModifierComposante(MATLireComposante(uiBoucleLignes, uiBoucleColonnes), uiBoucleColonnes, uiBoucleLignes); 
		}
	}
	return *pmatMatriceTemp;
}

#endif