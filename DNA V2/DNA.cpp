#include "DNA.h"
#include "Sequence.h"
#include <iostream>
using namespace std;

DNA::DNA()
{
    type=promoter;
}

bool DNA::valid(char* ch){
    for(int i=0;i<strlen(ch);++i)
        if((char)ch[i]=='A'||(char)ch[i]=='T'||(char)ch[i]=='C'||(char)ch[i]=='G'){
            continue;
        }
        else{
            string x="invalid input for DNA ";
            throw x;
        }
    return 1;
}

DNA::DNA(DNA* rhs){
    (valid(rhs->seq));
    seq=new char[strlen(rhs->seq)+1];
    seq=rhs->seq;
    type=rhs->type;
}
DNA ::DNA(int length):Sequence(length){}
DNA :: DNA(char * s, DNA_Type atype)
{
    valid(s);
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
    type = atype;
}

DNA :: DNA(const DNA& rhs)
{
    valid(rhs.seq);
    seq=new char[strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
    type=rhs.type;

}

char* DNA :: getDNA()
{
    return seq;
}

void DNA::Print(){
    for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}

void DNA ::  BuildComplementaryStrand()
{
    startIndex=0;
    endIndex=strlen(seq);
    complementary_strand= new char[strlen(seq)+1];
    //cout<<complementary_strand<<" btngan"<<strlen(seq)+1<<endl;
    for(int j=0,i=endIndex-1;i>=0;--i,++j){
        complementary_strand[j]=seq[i];
        if(seq[i]=='A') complementary_strand[j]='T';
        else if(seq[i]=='T') complementary_strand[j]='A';
        else if(seq[i]=='C') complementary_strand[j]='G';
        else if(seq[i]=='G') complementary_strand[j]='C';
    }
    //cout<<complementary_strand<<" btngan2"<<endl;
    //complementary_strand;
}

char* DNA::getComplementalStrand(){
    return complementary_strand;
}
void DNA::operator=(DNA rhs){
    valid(rhs.seq);
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}
RNA DNA :: ConvertToRNA(){
    BuildComplementaryStrand();
    RNA tmp ;
    tmp.setSeq(complementary_strand);
    for(int i=0;i<strlen(complementary_strand);++i){
        if(tmp.getElement(i)=='T') tmp.setElement('U',i);
    }
    return  tmp;
}

DNA::~DNA()
{
}
