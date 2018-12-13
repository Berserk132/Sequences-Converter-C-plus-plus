#include "DNA.h"
#include "Sequence.h"
#include <iostream>
using namespace std;
// Default Constructor

DNA::DNA()
{

}
//valid function for input
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
// copy constructor to create a DNA sequence equal to another one

DNA::DNA(DNA* rhs)
{
    (valid(rhs->seq));
    seq=new char[strlen(rhs->seq)+1];
    seq=rhs->seq;
    type=rhs->type;
}
// Constructor to create a new DNA Sequence

DNA ::DNA(int length):Sequence(length)
{

}
// copy constructor to create a DNA sequence equal to another one

DNA :: DNA(char * s, DNA_Type atype)
{
    valid(s);
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
    type = atype;
}
// copy constructor to create a DNA sequence equal to another one

DNA :: DNA(char * s)
{
    valid(s);
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
}


DNA :: DNA(const DNA& rhs)
{
    valid(rhs.seq);
    seq=new char[strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
    type=rhs.type;

}
// getter to get a DNA Sequence

char* DNA :: getDNA()
{
    return seq;
}

void DNA::Print(){
    for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}

// Function to invert the DNA Sequence to get it's Complement

void DNA ::  BuildComplementaryStrand()
{
    startIndex=0;
    endIndex=strlen(seq);
    complementary_strand= new char[strlen(seq)+1];
    for(int j=0,i=endIndex-1;i>=0;--i,++j){
        complementary_strand[j]=seq[i];
        if(seq[i]=='A') complementary_strand[j]='T';
        else if(seq[i]=='T') complementary_strand[j]='A';
        else if(seq[i]=='C') complementary_strand[j]='G';
        else if(seq[i]=='G') complementary_strand[j]='C';
    }
}
// getter to return the complementary strand

char* DNA::getComplementalStrand(){
    return complementary_strand;
}
// operator equal to create a DNA sequence equal to another one

void DNA::operator=(DNA rhs){
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}
// Function to Convert the DNA Sequence to RNA Sequence

RNA DNA :: ConvertToRNA(int startIndex,int endIndex){
    RNA tmp ;
    if(!startIndex && ! endIndex){  //if both of them =0
        cout<<"enter the start and end index -1,-1 for all the DNA : ";
        cin>>startIndex>>endIndex;

        if(startIndex==-1 &&endIndex==-1){
            I:
            tmp.setSeq(this->seq);
            for(int i=0;i<strlen(seq);++i)
                if(tmp.getElement(i)=='T') tmp.setElement('U',i);
        }
        else if(startIndex>=endIndex || endIndex>strlen(seq)){
            string x="invalid boundary";
            throw x;
        }
        else {
            tmp.setSeqSize((endIndex-startIndex)+1);
            for(int i=startIndex,k=0;i<endIndex;++i,++k){
                tmp.setElement(seq[i],k);
                if(tmp.getElement(k)=='T') tmp.setElement('U',k);\
            }
            cout<<tmp.getSeq()<<endl;
        }
    }
    else goto I;        //only called from protein function
    return  tmp;
}

DNA::~DNA()
{
}
