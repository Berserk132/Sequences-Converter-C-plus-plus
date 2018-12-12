#include "Sequence.h"
map<string,char>aminoAcid;
map<char,string>reversedAcid;

Sequence::Sequence()
{
}

Sequence :: Sequence(int length)
{
    seq=new char[length+1];
    //if(n<1) throw "you cant make a zero sequence";
}
char* Sequence::getSeq()const{
    return seq;
}
int Sequence::getSeqSiz() const{
    return strlen(seq);
}

Sequence :: Sequence(Sequence& rhs)
{
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}
void Sequence ::setSeq(char* seq2){
    this->seq=new char [ strlen(seq2)+1];
    for(int i=0;i<strlen(seq2);++i)
        seq[i]=(char)seq2[i];
}
void Sequence::setElement(char element,int idx){
    seq[idx]=(char)element;
}

void Sequence ::setSeqSize(int siz){
    this->seq=new char [ siz+1];
}
char Sequence::getElement(int idx)const{
    return seq[idx];
}
bool Sequence ::  operator== (Sequence* d)
{
    if (strcmp(seq,d->seq))
        return false;
    else
        return true;
}
bool Sequence ::  operator!= (Sequence* d)
{
    if (strcmp(seq,d->seq))
        return true;
    else
        return false;
}
Sequence::~Sequence()
{
    //dtor
}
