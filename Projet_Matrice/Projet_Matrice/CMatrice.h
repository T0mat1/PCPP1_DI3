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
	*** Constructeur par d�faut																	   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : n�ant																				   ***
	*** entraine : Matrice 1x1 initialis�e � 1													   ***
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
	*** entraine : Matrice 1x1 initialis�e � 1													  ***
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

	inline unsigned int MATLireNombreLignes();
	/*************************************************************************************************
	*** Accesseur en lecture   																	   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreLignes) ; entier naturel			   ***
	*** entraine : retour de la valeur de uiNombreLignes										   ***
	*************************************************************************************************/

	inline unsigned int MATLireNombreColonnes();
	/*************************************************************************************************
	*** Accesseur en lecture   																	   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : Nombre de lignes de la matrice (attribut uiNombreColonnes) ; entier naturel			   ***
	*** entraine : retour de la valeur de uiNombreColonnes    									   ***
	*************************************************************************************************/

	inline void MATModifierComposante(MType tParam, unsigned int uiLigne, unsigned int uiColonne);
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
	
	CMatrice operator*(CMatrice MATParam);
	/*************************************************************************************************
	*** Surcharge de l'op�rateur * (multiplication avec une matrice)							   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice, produit matriciel de deux objets CMatrice						   ***
	*** entraine : n�ant																		   ***
	*************************************************************************************************/

	CMatrice operator+(CMatrice MATParam);
	/*************************************************************************************************
	*** Surcharge de l'op�rateur + (addition avec une matrice)									   ***
	**************************************************************************************************
	*** E : MATParam : un objet CMatrice														   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice, somme de deux objets CMatrice									   ***
	*** entraine : n�ant																		   ***
	*************************************************************************************************/

	CMatrice operator-(CMatrice MATParam);
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
	
	CMatrice MATCalculerTransposee();
	/*************************************************************************************************
	*** M�thode de calcul de la transpos�e d'une matrice										   ***
	**************************************************************************************************
	*** E : n�ant																				   ***
	*** n�cessite : n�ant																		   ***
	*** S : Un objet CMatrice �gal � la transpos�e de la matrice								   ***
	*** entraine :																				   ***
	*************************************************************************************************/
};

#endif