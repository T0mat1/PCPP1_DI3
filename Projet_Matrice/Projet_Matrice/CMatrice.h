#ifndef CMATRICE_H
#define CMATRICE_H 1

template <class MType> class CMatrice
{
private:
	MType ** pptMATMatrice;
	unsigned int uiMATNombreLignes;
	unsigned int uiMATNombreColonnes;

public:
	// ----------------------------------------------- Constructeurs et destructeur ----------------------------------------------- 

	CMatrice();
	/*************************************************************************************************
	*** Constructeur par défaut																	   ***
	**************************************************************************************************
	*** E : néant																				   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : Matrice 1x1 initialisée à 1													   ***
	*************************************************************************************************/

	CMatrice(CMatrice & MATParam);
	/*************************************************************************************************
	*** Constructeur de recopie																	   ***
	**************************************************************************************************
	*** E : MATParam ; la matrice à recopier													   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : Matrice initialisée par recopie de MATParam									   ***
	*************************************************************************************************/
	
	CMatrice(unsigned int uiNombreLignes, unsigned int uiNombreColonnes);
	/************************************************************************************************
	*** Constructeur par défaut																	  ***
	*************************************************************************************************
	*** E : uiNombreLignes, uiNombreColonnes ; les dimensions de la matrice						  ***
	*** nécessite : néant																		  ***
	*** S : néant																				  ***
	*** entraine : Matrice 1x1 initialisée à 1													  ***
	************************************************************************************************/

	~CMatrice();
	/************************************************************************************************
	*** Destructeur         																	  ***
	*************************************************************************************************
	*** E : néant																				  ***
	*** nécessite : néant																		  ***
	*** S : néant																				  ***
	*** entraine : Destruction de l'objet CMatrice												  ***
	************************************************************************************************/


	//----------------------------------------------- Accesseurs ----------------------------------------------- 

	inline unsigned int MATLireNombreLignes();
	/*************************************************************************************************
	*** Accesseur en lecture   																	   ***
	**************************************************************************************************
	*** E : néant																				   ***
	*** nécessite : néant																		   ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreLignes) ; entier naturel			   ***
	*** entraine : retour de la valeur de uiNombreLignes										   ***
	*************************************************************************************************/

	inline unsigned int MATLireNombreColonnes();
	/*************************************************************************************************
	*** Accesseur en lecture   																	   ***
	**************************************************************************************************
	*** E : néant																				   ***
	*** nécessite : néant																		   ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreColonnes) ; entier naturel			   ***
	*** entraine : retour de la valeur de uiNombreColonnes    									   ***
	*************************************************************************************************/

	inline void MATModifierComposante(MType tParam, unsigned int uiLigne, unsigned int uiColonne);
	/*************************************************************************************************
	*** Accesseur en écriture 																	   ***
	**************************************************************************************************
	*** E : - tParam un paramètre de type MType qui contient la nouvelle valeur de la composante   ***
	***		- uiLigne la coordonnée de la ligne de la composante à modifier ; entier naturel	   ***
	***		- uiColonne la coordonnée de la colonne de la composante à modifier ; entier naturel   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : modification d'une composante de la matrice aux coordonnées (uiColonne,uiLigne) ***
	*************************************************************************************************/


	//----------------------------------------------- Surcharges d'operateurs ----------------------------------------------- 

	CMatrice operator*(int iParam);
	/*************************************************************************************************
	*** Surcharge de l'opérateur * (multiplication avec un entier)								   ***
	**************************************************************************************************
	*** E : iParam : un entier																	   ***
	*** nécessite : néant																		   ***
	*** S : Un objet CMatrice, produit d'un CMatrice et d'un entier								   ***
	*** entraine : néant																		   ***
	*************************************************************************************************/
	
	CMatrice operator*(CMatrice MATParam);
	/*************************************************************************************************
	*** Surcharge de l'opérateur * (multiplication avec une matrice)							   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** nécessite : néant																		   ***
	*** S : Un objet CMatrice, produit matriciel de deux objets CMatrice						   ***
	*** entraine : néant																		   ***
	*************************************************************************************************/

	CMatrice operator+(CMatrice MATParam);
	/*************************************************************************************************
	*** Surcharge de l'opérateur + (addition avec une matrice)									   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** nécessite : néant																		   ***
	*** S : Un objet CMatrice, somme de deux objets CMatrice									   ***
	*** entraine : néant																		   ***
	*************************************************************************************************/

	CMatrice operator-(CMatrice MATParam);
	/*************************************************************************************************
	*** Surcharge de l'opérateur - (soustraction par une matrice)								   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** nécessite : néant																		   ***
	*** S : Un objet CMatrice, différence entre la matrice courante et MATParam					   ***
	*** entraine : néant																		   ***
	*************************************************************************************************/
	
	CMatrice operator/(int iParam);
	/*************************************************************************************************
	*** Surcharge de l'opérateur / (division par un entier)										   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** nécessite : néant																		   ***
	*** S : Un objet CMatrice, où chaque composante vaut										   ***
	***		celle de la matrice courante divisée par iParam								           ***
	*** entraine : néant																		   ***
	*************************************************************************************************/

	//----------------------------------------------- Methodes ----------------------------------------------- 
	
	void MATAfficherMatrice();
	/*************************************************************************************************
	*** Méthode d'affichage d'une matrice dans la console										   ***
	**************************************************************************************************
	*** E : néant																				   ***
	*** nécessite : néant																		   ***
	*** S : néant																				   ***
	*** entraine : Affichage de la matrice dans la console										   ***
	*************************************************************************************************/
	
	CMatrice MATCalculerTransposee();
	/*************************************************************************************************
	*** Méthode de calcul de la transposée d'une matrice										   ***
	**************************************************************************************************
	*** E : néant																				   ***
	*** nécessite : néant																		   ***
	*** S : Un objet CMatrice égal à la transposée de la matrice								   ***
	*** entraine :																				   ***
	*************************************************************************************************/
};

#endif