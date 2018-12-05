#include "DNA.h"
#include "Sequence.h"
#include <iostream>
using namespace std;

DNA::DNA()
{
    //ctor

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
RNA DNA :: ConvertToRNA(){
    BuildComplementaryStrand();
    RNA tmp;
    tmp.seq=new char [strlen(complementary_strand->seq)+1];
    strcpy(tmp.seq,complementary_strand->seq);
    tmp.type=1;
    for(int i=0;i<strlen(tmp.seq);++i){
        if(tmp.seq[i]=='T') tmp.seq[i]=='U';
    }
    return  tmp;
}

DNA::~DNA()
{
    //dtor
    delete [] seq;
    delete [] complementary_strand;
}
