#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 

                                             //fonctions suplimentaires 
//---------------------------------------
void swapInt (int *a,int *b){
int tmp =*a;
*a=*b;
*b=tmp;
}
//------------------------------------
void swapChar(char *a,char*b){
char tmp =*a;
    *a=*b;
    *b=tmp;
}

//-----------------------------------------
int CompString(char S1[],char S2[]){
int max=MAXIMUM(strlen(S1),strlen(S2));
for (int i=0;i<max;i++){
if (S1[i]>S2[i]) return 1;
}
return 0;
}

//-----------------------------------
int MAXIMUM(int a,int b){
    if (a>b) return a;
    else return b;
}
//-----------------------------------------
void swapString(char *a[],char *b[]){
char tmp[MAXiMUM(strlen(a),strlen(b))];
strcpy(tmp,*a);
strcpy(*a,*b);
strcpy(*b,tmp);
}
//------------------------------------------------
void afficherNbrPermEtComp(int *C,int *P){
    
    printf("Nombre de permutations est: %d\n",&P);
    printf("nombre de comparaisons est: %d\n",&C);
    }

//------------------------------------------------
void afficherVect(int V[],int size){
    int i;
    for(i=0;i<size;i++) printf("%d ",&V[i]);
    printf("\n");
}
 
//-----------------------------------------------
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

//---------------------------------
char** creeMatrice(int *lignes, int *colones) {
    // Demander les dimensions de la matrice
    printf("Entrez le nombre de lignes : ");
    scanf("%d", lignes);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", colones);

    // Allocation dynamique de la matrice
    char** matrix = (char**)malloc(*lignes * sizeof(char*));

    
    printf("Entrez les caracteres pour remplir la matrice :\n");
    for (int i = 0; i < *lignes; i++) {
        printf("Ligne %d : ", i + 1);
        scanf("%s", matrix[i]); // Lit une ligne de caractères
    }

    return matrix;
}
//---------------------------------
 typedef struct liste {
 char word[30];
 struct liste *next;
 }list;
 //-------------------------------
 list* createNode(const char *word) {
    list *newNode = (list *)malloc(sizeof(list));
    printf("entrer un mot \n");
    scanf("%s", word);
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}
//---------------------------------
void append(list **head, const char *word) {
    list *newNode = createNode(word);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    list *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
//--------------------------------------------
char* MatriceToVector(char  matrice [][], int lignes,int colones,char V[lignes*colones]){
//char V[lignes*colones];
int k=0;
char*p=matrice;
for(int i = 0; i <lignes; i++){
    for(int j = 0; j < colones; j++){
       
        V[k] =*(p+(i*lignes+j));
        k=k++;
    }
    printf("\n");
}
return V;
}
//--------------------------------------------
 void VectorToMatrice(char V[],int lignes,int colones,char matrice[][]){
 int S=lignes*colones;
 char*p=matrice;
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
//-------------------------------------------
void TriParSelection(int V[],int size){
    int i,j,iMin,nbrComp=0,nbrPerm=0;
    for(i=0;i<size-1;i++){
        iMin=i;
        for(j=i+1;j<size;j++){
            nbrComp++;
            if(V[j]<V[iMin]){
                iMin=j;
            }
        }
        swapInt(&V[i],&V[iMin]);
         nbrPerm++;
         afficherVect(V,size);
    }
    afficherNbrPermEtComp(&nbrComp,&nbrPerm);
    
}
//----------------------------------------------
void TriParBulle (int V[],int size){
    int i,j,nbrComp=0,nbrPerm=0;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            nbrComp++;
            if(V[j]>V[j+1]){
                swapInt(&V[j],&V[j+1]);
                 nbrPerm++;
                 afficherVect(V,size);
            }
        }
    }
    afficherNbrPermEtComp(&nbrComp,&nbrPerm);

}
//-------------------------------------------
void TriParBulleMatrice(char matrice[][],int lignes,int colones){
int S =lignes*colones;
char * vect =MatriceToVector(matrice,lignes,colones,vect);
int i,j,nbrComp=0,nbrPerm=0;
    for(i=0;i<S-1;i++){
        for(j=0;j<S-i-1;j++){
            nbrComp++;
            if(vect[j]>vect[j+1]){
                swapInt(&vect[j],&vect[j+1]);
                 nbrPerm++;
                 afficherVect(vect,S);
            }
        }
    }
afficherNbrPermEtComp(&nbrComp,&nbrPerm);
VectorToMatrice(vect,lignes,colones,matrice);
}
// ptr=ptr->next;
//--------------------------------
void TriParBulleListe(list *head){
list *ptr=head;
list *p=head;
 int nbrComp=0,nbrPerm=0;
 while(ptr!=NULL){
    p=head;
    while (p!=NULL){   
  
     if(CompString(p->word,p->next->word)!=0){
             nbrComp++;
            swapString(&p->word,&ptr->word);
             nbrPerm++;
             afficherList(head);
        }
    p=p->next;
     }
     ptr=ptr->next;

 }
 afficherNbrPermEtComp(&nbrComp,&nbrPerm);

}
//----------------------------------
typedef struct ELE{
int index;
int nbrPerm;
int nbrComp;
}NI;
//------------------------------
void TriRapide (int V[],int bas , int haut){
if (bas<haut ){
   NI pi =partition (V,bas,haut) ;
   TriRapide(V, bas, pi.index-1) ;
   TriRapide(V, pi.index+1, haut) ;
    afficherNbrPermEtComp(&pi.nbrComp,&pi.nbrPerm);
}
}
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
             afficherVect(V,haut+1);
         }
     }
     swapInt(&V[i+1], &V[haut]);
     NI.nbrPerm++;
     afficherVect(V,haut+1);
     NI.index=i+1;
     return (NI) ;
}

int main (){
// dans la creation de la listes il y a une condition d'arete  boucle while 
 //---------------------------------------- CALLS -----------------------------------------------------


    return 0;
}