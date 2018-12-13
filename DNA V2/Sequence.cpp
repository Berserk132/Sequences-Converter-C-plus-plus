#include "Sequence.h"
map<string,char>aminoAcid;

Sequence::Sequence()
{

}
// Parameterized Constructor to set the length of Sequence

Sequence :: Sequence(int length)
{
    seq=new char[length+1];
}
// Function to Get The sequence

char* Sequence::getSeq()const{
    return seq;
}
// Function to Get The sequence Size

int Sequence::getSeqSiz() const{
    return strlen(seq);
}
//copy constructor
Sequence :: Sequence(Sequence& rhs)
{
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}
// Setter to set a new sequence

void Sequence ::setSeq(char* seq2){
    this->seq=new char [ strlen(seq2)+1];
    strcpy(seq,seq2);
}
// Function to set element in a sequence

void Sequence::setElement(char element,int idx){
    seq[idx]=(char)element;
}

// setter to set the size of a sequence

void Sequence ::setSeqSize(int siz){
    this->seq=new char [ siz+1];
}
// Function to get an element of a sequence

char Sequence::getElement(int idx)const{
    return seq[idx];
}
// operator to compare two sequence and return 1 if the two sequences are equal

bool Sequence ::  operator== (Sequence* d)
{
    if (!strcmp(seq,d->seq))
        return true;
    else
        return false;
}
// operator to compare two sequence and return 1 if the two sequences are not equal

bool Sequence ::  operator!= (Sequence* d)
{
    if (!strcmp(seq,d->seq))
        return false;
    else
        return true;
}
Sequence::~Sequence()
{
    //dtor
}
