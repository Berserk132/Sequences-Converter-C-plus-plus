#include "Sequence.h"

Sequence::Sequence()
{
}

Sequence :: Sequence(int length)
{
    cout<<"enter the sequence :";
    seq=new char[strlen(length)+1];
    for(int i=0;i<length;++i){
        cin>>seq[i];
    }
}
Sequence :: Sequence(Sequence& rhs)
{
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}

Sequence::~Sequence()
{
    //dtor
}
