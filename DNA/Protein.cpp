#include "Protein.h"

Protein::Protein()
{
    //ctor
}

Protein ::Protein(char * p){
    seq=new char [strlen(p)+1];
    strcpy(seq,p);
}
//DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA){



Protein::~Protein()
{
    //dtor
}
