#include "DNA.h"
#include "Sequence.h"
#include <iostream>
using namespace std;

DNA::DNA()
{
    type=promoter;
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

void DNA ::  BuildComplementaryStrand()
{
    startIndex=0;
    endIndex=strlen(seq);
    complementary_strand->seq = new char[strlen(seq)+1];
    for(int i=endIndex-1;i>=0;--i){
        complementary_strand->seq[i]=seq[i];
        if(seq[i]=='A') complementary_strand->seq[i]='T';
        else if(seq[i]=='T') complementary_strand->seq[i]='A';
        else if(seq[i]=='C') complementary_strand->seq[i]='G';
        else if(seq[i]=='G') complementary_strand->seq[i]='C';
    }
    complementary_strand->type=type;
}
char* DNA::getComplementalStrand(){
    return complementary_strand->seq;
}
RNA DNA :: ConvertToRNA(){
    BuildComplementaryStrand();
    RNA tmp;
    tmp.setSeq(complementary_strand->seq);
    for(int i=0;i<strlen(complementary_strand->seq);++i){
        if(tmp.getElement(i)=='T') tmp.setElement('U',i);
    }
    return  tmp;
}

DNA::~DNA()
{
}
