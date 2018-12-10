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
    DNA d10("TTACGCCAT",tail);
    DNA d4("TACCGTTACGCCATCATT",tail);
    DNA d2;
    //d2 = d1+ d4;
    cout << (d1!=d10);
    cout << endl;
    //cout << d2;
    //cin >> d1;
    d1.BuildComplementaryStrand();
    RNA r1;
    cout << d1;
    r1=d1.ConvertToRNA();
    cout << r1;
    d2=(r1.ConvertToDNA());
    cout << d2;
    Protein p1;
    p1=(r1.ConvertToProtein());
    cout << p1;
    DNA d3;
    d3=p1.GetDNAStrandsEncodingMe(d4);
    cout<<endl;
    cout<<"D3 = ; ";
    d3.Print();

    return 0;
}
