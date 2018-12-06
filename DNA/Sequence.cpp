#include "Sequence.h"
 map<string,char>aminoAcid;           //extern to tell the compiler that aminoAcid exist somewhere else
 map<char,string>reversedAcid;
Sequence::Sequence()
{
}

Sequence :: Sequence(int length)
{
    cout<<"enter the sequence :";
    seq=new char[length+1];
    for(int i=0;i<length;++i){
        cin>>seq[i];
    }
}

Sequence :: Sequence(Sequence& rhs)
{
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}
void Sequence ::setSeq(char seq2[]){
    this->seq=new char [ strlen(seq2)+1];
    strcpy(this->seq,seq2);
}
char Sequence::getElement(int idx){
    return seq[idx];
}
void Sequence::setElement(char element,int idx){
    seq[idx]=element;
}

Sequence::~Sequence()
{
    //dtor
}
