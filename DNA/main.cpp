#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
using namespace std;

void loadCodon(){
    string sequenc;
    char equivlent;
    freopen("Codons.txt","r",stdin);
    for(int i=0;i<64;++i){
        cin>>sequenc;
        cin.get();
        cin.get(equivlent);
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
    loadCodon();
    DNA d1("TTACGCCAT",tail);
    DNA d4("TACCGTTACGCCATCATT",tail);
    DNA d2;
    d1.BuildComplementaryStrand();
    RNA r1;
    cout<<"D1 = : ";
    d1.Print();
    cout<<"R1 = : ";
    r1=d1.ConvertToRNA();
    r1.Print();
    cout<<"D2 = : ";
    d2=(r1.ConvertToDNA());
    d2.Print();
    Protein p1;
    cout<<"P1 = ; ";
    p1=(r1.ConvertToProtein());
    p1.Print();
    DNA d3;
    d3=p1.GetDNAStrandsEncodingMe(d4);
    cout<<endl<<endl;
    d3.Print();

    return 0;
}
