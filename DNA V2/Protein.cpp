#include "Protein.h"

Protein::Protein()
{
    //ctor

}
//K N T S I M Q H P R L E D A G V Y C W F
//validation function for input
bool Protein::valid(char* ch){
    for(int i=0;i<strlen(ch);++i)
        if((char)ch[i]=='K'||(char)ch[i]=='N'||(char)ch[i]=='T'||(char)ch[i]=='S'||(char)ch[i]=='I'||(char)ch[i]=='M'||(char)ch[i]=='Q'||
           (char)ch[i]=='H'||(char)ch[i]=='P'||(char)ch[i]=='R'||(char)ch[i]=='L'||(char)ch[i]=='E'||(char)ch[i]=='D'||(char)ch[i]=='A'||
           (char)ch[i]=='G'||(char)ch[i]=='V'||(char)ch[i]=='Y'||(char)ch[i]=='C'||(char)ch[i]=='W'||(char)ch[i]=='F'){

            continue;
            }
        else{
            string x="invalid input for Protein ";
            throw x;
        }
    return 1;
}
// Constructor to create a new Protein

Protein ::Protein(char * p)
{
    valid(p);
    seq=new char [strlen(p)+1];
    strcpy(seq,p);
}
Protein ::Protein(Protein * p){
    valid(p->seq);
    seq=new char [strlen(p->seq)+1];
    strcpy(seq,p->seq);
    type=p->type;
}
// copy constructor to create a protein sequence equal to another one

Protein ::Protein(const Protein& p){
    valid(p.seq);
    seq=new char [strlen(p.seq)+1];
    strcpy(seq,p.seq);
    type=p.type;
}


void Protein::Print(){
     for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}
// equal operator to make protein object equals another protein object

void Protein::operator=(Protein rhs){
    seq=rhs.seq;
    type=rhs.type;
}
// Function that Return a DNA after makes sure that we can convert that DNA to Protein

DNA Protein::GetDNAStrandsEncodingMe(DNA & bigDNA){
    DNA tmp(strlen(this->seq)*3+1);
    RNA trans(bigDNA.ConvertToRNA(-1,-1));//make RNA to access the amino acid table
    bool b=0;
    char codon[4];
    for(int i=0;i<trans.getSeqSiz()-strlen(seq)*3-1;++i){
            b=1;
            int j=i;
        for(int k=0;j<i+strlen(seq)*3;j+=3,k++){
            codon[0]=trans.getElement(j);
            codon[1]=trans.getElement(j+1);
            codon[2]=trans.getElement(j+2);
            if(aminoAcid[codon]!=seq[k]){  //search for the Codon of key
                b=0;
                break;
            }
            tmp.setElement(codon[0],j-i);
            tmp.setElement(codon[1],j+1-i);
            tmp.setElement(codon[2],j+2-i);
        }
        if(b){
            break;
        }
    }
    tmp.setElement('\0',strlen(this->seq)*3);//end of character array
    if(!b) cout<<"can't make this protein from this DNA ";
    else {
        for(int i=0;i<tmp.getSeqSiz();++i){
            if(tmp.getElement(i)=='U') tmp.setElement('T',i);
        }
    }
    return tmp;


}
// plus operator to add a protein sequence to another protein sequence

Protein Protein:: operator+(Protein& d2)
{
    valid(d2.seq);
    Protein tmp;
    int length2 = strlen(d2.seq);
    int length1 = strlen(seq);
    tmp.seq = new char [length1+length2+2];
    for (int i=0; i<length1; i++)
    {
        tmp.seq[i] = seq[i];
    }
    for (int i=length1; i<length1+length2; i++)
    {
        tmp.seq[i] = d2.seq[i-length1];
    }
    return tmp;
}

Protein::~Protein()
{
    //dtor
}
