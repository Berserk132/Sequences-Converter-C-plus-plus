#include "Protein.h"

Protein::Protein()
{
    //ctor
}
Protein ::Protein(char * p){
    seq=new char [strlen(p)+1];
    strcpy(seq,p);
}
Protein ::Protein(Protein * p){
    seq=new char [strlen(p->seq)+1];
    strcpy(seq,p->seq);
    type=p->type;
}

Protein ::Protein(const Protein& p){
    seq=new char [strlen(p.seq)+1];
    strcpy(seq,p.seq);
    type=p.type;
}

void Protein::Print(){
     for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}

void Protein::operator=(Protein rhs){
    seq=rhs.seq;
    type=rhs.type;
}
//DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA){



Protein::~Protein()
{
    //dtor
}
