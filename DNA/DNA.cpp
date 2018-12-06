#include "DNA.h"
#include "Sequence.h"
#include <iostream>
using namespace std;

DNA::DNA()
{
    type=promoter;
}

DNA::DNA(DNA* rhs){
    seq=rhs->seq;
    type=rhs->type;
}

DNA :: DNA(char * s, DNA_Type atype)
{
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
    type = atype;
}

DNA :: DNA(DNA& rhs):Sequence(rhs)
{
    type=rhs.type;

}

char* DNA :: getDNA()
{
    return seq;
}
void DNA::Print(){
    cout<<seq<<endl;
}

void DNA ::  BuildComplementaryStrand()
{
    startIndex=0;
    endIndex=strlen(seq);
    complementary_strand= new char[strlen(seq)+1];
    for(int i=endIndex-1,j=0;i>=0;--i,j++){
        complementary_strand[j]=seq[i];
        if(seq[i]=='A') complementary_strand[j]='T';
        else if(seq[i]=='T') complementary_strand[j]='A';
        else if(seq[i]=='C') complementary_strand[j]='G';
        else if(seq[i]=='G') complementary_strand[j]='C';
    }
    complementary_strand;
}

char* DNA::getComplementalStrand(){
    return complementary_strand;
}
void DNA::operator=(DNA rhs){
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}
RNA DNA :: ConvertToRNA(){
    BuildComplementaryStrand();
    RNA tmp;
    tmp.setSeq(complementary_strand);
    for(int i=0;i<strlen(complementary_strand);++i){
        if(tmp.getElement(i)=='T') tmp.setElement('U',i);
    }
    return  tmp;
}

DNA::~DNA()
{
}
