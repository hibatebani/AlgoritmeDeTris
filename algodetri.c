#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 

                                             //fonctions suplimentaires 
//---------------------------------------swap integers 
void swapInt (int *a,int *b){ 
int tmp =*a;
*a=*b;
*b=tmp;
}
//------------------------------------swap characters 
void swapChar(char *a,char*b){
char tmp =*a;
    *a=*b;
    *b=tmp;
}
//----------------------------------- le maximum entre 2 nombres 
int MAXIMUM(int a,int b){
    if (a>b) return a;
    else return b;
}
//----------------------------------------- comparer entre 2 strings 
int CompString(char S1[],char S2[]){
int max=MAXIMUM(strlen(S1),strlen(S2));
for (int i=0;i<max;i++){
if (S1[i]>S2[i]) return 1;
}
return 0;
}

//----------------------------------------- swap strings 
void swapString(char a[],char b[]){
char tmp[MAXIMUM(strlen(a),strlen(b))];
strcpy(tmp,a);
strcpy(a,b);
strcpy(b,tmp);
}
//------------------------------------------------ affichage de nombre de permutation et nombre de comparaison 
void afficherNbrPermEtComp(int *C,int *P){
    
    printf("Nombre de permutations est: %d\n",&P);
    printf("nombre de comparaisons est: %d\n",&C);
    }

//------------------------------------------------affichage de vecteur d'entiers
void afficherVectInt(int V[],int size){
    int i;
    for(i=0;i<size;i++) printf("%d ",&V[i]);
    printf("\n");
}
//------------------------------------------------affichage de vecteur de caracteres
void afficherVectChar(char V[],int size){
    int i;
    for(i=0;i<size;i++) printf("%d ",&V[i]);
    printf("\n");
}
 //--------------------------------------------structure de la liste 
 typedef struct liste {
 char word[30];
 struct liste *next;
 }list;
//-----------------------------------------------affichage d'une list 
 void afficherList(list *head) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    list *ptr = head;
    
    while (ptr != NULL) {
        printf("%s -> ", &ptr->word);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

//--------------------------------------- creation d'une matrice dynamiquement 
char** creeMatrice(int lignes, int colones) {
    // Demander les dimensions de la matrice
    printf("Entrez le nombre de lignes : ");
    scanf("%d", lignes);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", colones);

    // Allocation dynamique de la matrice
    char** matrix = (char**)malloc(lignes * sizeof(char*));

    
    printf("Entrez les caracteres pour remplir la matrice :\n");
    for (int i = 0; i < lignes; i++) {
        printf("Ligne %d : ", i + 1);
        scanf("%s", matrix[i]); // Lit une ligne de caractères
    }

    return matrix;
}

 //--------------------------------------creation d'un nouveau node 
 list* createNode(const char *word) {
    list *newNode = (list *)malloc(sizeof(list));
    printf("entrer un mot \n");
    scanf("%s", word);
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}
//-------------------------------------creation de la list
void append(list *head, const char *word) {
    list *newNode = createNode(word);
    if (head == NULL) {
        *head = *newNode;
        return;
    }
    list *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
//--------------------------------------------transferer une matrice a un vecteur 
char* MatriceToVector(int lignes,int colones,char matrice [lignes][colones],char V[lignes*colones]){

int k=0;
char* p=* matrice;
for(int i = 0; i <lignes; i++){
    for(int j = 0; j < colones; j++){
       
        V[k] =*(p+(i*lignes+j));
        k=k++;
    }
    printf("\n");
}
return V;
}
//-----------------------------------------------transferer un vecteur a une matrice 
 void VectorToMatrice(char V[],int lignes,int colones,char matrice[lignes][colones]){
 int S=lignes*colones;
 char*p=*matrice;
 int k=0;
 int i=0;
 while (lignes!=S){

    for (int j = k; j < colones; j++){
*(p+(i*lignes+j))=V[i];
 }
 k=k+colones;
 i=i++;
 lignes=lignes*i;
 }
 }
                                                  //fonction principale
//---------------------------------------------TRI PAR SELECTION -VECTEUR-
void TriParSelection(int V[],int size){
    int i,j,iMin,nbrComp=0,nbrPerm=0;
    for(i=0;i<size-1;i++){
        iMin=i; 
        for(j=i+1;j<size;j++){
            nbrComp++;
            if(V[j]<V[iMin]){  //recuperer le plus petit element du vecteur dans chaque iteration 
                iMin=j;
            }
        }
        swapInt(&V[i],&V[iMin]); // tries les plus petits elements au debut de tableau  ---ordre de tri croissant ---
         nbrPerm++;
         afficherVectInt(V,size); 
    }
    afficherNbrPermEtComp(&nbrComp,&nbrPerm);
    
}
//---------------------------------------------- TRI PAR BULLE -VECTEUR-
void TriParBulle (int V[],int size){
    int i,j,nbrComp=0,nbrPerm=0;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){// a chaque fois on compare entre les elements adjacents 
            nbrComp++;
            if(V[j]>V[j+1]){     //en met les valeur petites au debut 
                swapInt(&V[j],&V[j+1]);
                 nbrPerm++;
                 afficherVectInt(V,size);
            }
        }
    }
    afficherNbrPermEtComp(&nbrComp,&nbrPerm);

}
//-------------------------------------------TRI PAR BULLE -MATRICE-
void TriParBulleMatrice(int lignes,int colones, char matrice[lignes][colones]){
int S =lignes*colones;
char * vect =MatriceToVector(lignes,colones, matrice,vect);
int i,j,nbrComp=0,nbrPerm=0;
    for(i=0;i<S-1;i++){
        for(j=0;j<S-i-1;j++){
            nbrComp++;
            if(vect[j]>vect[j+1]){
                swapChar(&vect[j],&vect[j+1]);
                 nbrPerm++;
                 afficherVectChar(vect,S);
            }
        }
    }
afficherNbrPermEtComp(&nbrComp,&nbrPerm);
VectorToMatrice(vect,lignes,colones,matrice);
}

//------------------------------------------TRI PAR BULLE --LISTE-- 
void TriParBulleListe(list *head){
list *ptr=head;
list *p=head;
 int nbrComp=0,nbrPerm=0;
 while(ptr!=NULL){
    p=head;
    while (p!=NULL){   
  
     if(CompString(p->word,p->next->word)!=0){
             nbrComp++;
            swapString(p->word,ptr->word);
             nbrPerm++;
             afficherList(head);
        }
    p=p->next;
     }
     ptr=ptr->next;

 }
 afficherNbrPermEtComp(&nbrComp,&nbrPerm);

}
//----------------------------------structure de l'element de la fonction partition
typedef struct ELE{
int index;
int nbrPerm;
int nbrComp;
}NI;
//-----------------------------------------------TRI RAPIDE -VECTEUR-
NI partition (int V [],int bas,int haut){
NI NI;
     int pivot = V[haut] ;
     int i = (bas-1) ;
     int j;
     for (j=bas; j<=haut; j++){
         NI.nbrComp++;
         if (V[j] <= pivot){
             i++;
             swapInt(&V[i], &V[j]);
             NI.nbrPerm++;
             afficherVectInt(V,haut+1);
         }
     }// obtenir les element qui sont inferieure aux pivot aux debut de tableau 
     swapInt(&V[i+1], &V[haut]);// le pivot soit entre 2 sous tableau le premier est inferieur a lui
     // et le deuxieme a les element grands a lui 
     NI.nbrPerm++;
     afficherVectInt(V,haut+1);
     NI.index=i+1;
     return (NI) ;
}
void TriRapide (int V[],int bas , int haut){
if (bas<haut ){
   NI pi =partition (V,bas,haut) ;
   TriRapide(V, bas, pi.index-1) ;
   TriRapide(V, pi.index+1, haut) ;
   // on divise les autres sous tableaus en comparant avec le nouveau pivot 
    afficherNbrPermEtComp(&pi.nbrComp,&pi.nbrPerm);
}
}


int main (){
// dans la creation de la listes il y a une condition d'arete  boucle while 
 //---------------------------------------- CALLS -----------------------------------------------------
int i;
 list *head = NULL;
 char word[30];
int colones,lignes;
 char matrice[lignes][colones];
int v [10]={3,6,78,23,11,94,6,71,3};
printf("--------------------------entrer votre choix ----------------------- ");
printf("trier un vecteur \n tri rapide entrer 0 \n  tri par selection entrer 1 \n tri par bulle entrer 2  \n ");
printf("trier une liste \n  tri par bulle entrer 3\n tri par insertion entrer 4 \n ");
printf("trier une matrice \n  tri par bulle entrer 5 \n tri par fusion entrer 6 \n ");
scanf("%d",&i);
switch (i)
{
 case 0:
    TriRapide(v,0,9);
    break;

case 1:
    TriParSelection(v,10);
    break;
case 2:
    TriParBulle(v,10);
    break;
 case 3:
    printf("vous voulliez dabort cree votre liste  \n SI VOUS TAPPEZ -1 LA CREATION DOIT S'ARETER \n");
    while (strcmp(word,"-1")!=0){
        append(head, word);
        scanf("%s", word);
    }
    TriParBulleListe(head);
    
     break;
case 4:
    
    break;
 case 5:
    printf("vous voulliez dabort cree votre matrice \n ");
    printf("entrer le nombre de colonnes et de lignes de votre matrice \n");
    scanf("%d %d",&lignes,&colones);
    creeMatrice(lignes, colones);
    TriParBulleMatrice(lignes,colones,matrice);
    break;
case 6:
    
    break;
default:printf("votre choix est un valide , vous vouliez ressayer  ");
    break;
}

    return 0;
}