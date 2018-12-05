#include <iostream>
#include "Sequence.h"
#include "DNA.h"
using namespace std;
void loadCodon(){
    string sequenc;
    char equivlent;
    freopen("Codons.txt","r",stdin);
    for(int i=0;i<64;++i){
        cin>>sequenc>>equivlent;
        reversedAcid[equivlent]=sequenc;
        aminoAcid[sequenc]=equivlent;
    }
}
char* Align(Sequence * s1, Sequence * s2){
    char *lcs=new char[strlen(s1->seq)+1];
    char *lcs2=new char[strlen(s2->seq)+1];
    for(int i=0,j=0,k=0;i<strlen(s1->seq),j<strlen(s2->seq);++i,++j){
        if(s1->seq[i]==s2->seq[j]) lcs[k]=s1->seq[i],k++;
    }
    for(int i=0,j=0,k=0;i<strlen(s2->seq),j<strlen(s1->seq);++i,++j){
        if(s2->seq[i]==s1->seq[j]) lcs2[k]=s2->seq[i],k++;
    }
    return (strlen(lcs)>=strlen(lcs2))?lcs:lcs2;
}

int main()
{
    DNA f1("ATGCTGCA", motif);


    return 0;
}
