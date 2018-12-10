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
DNA Protein::GetDNAStrandsEncodingMe(DNA & bigDNA){
    DNA tmp;
    RNA trans(bigDNA.ConvertToRNA());
    bool b=0;
    char codon[4];
    tmp.setSeqSize(strlen(this->seq)*3+1);
    for(int i=0;i<trans.getSeqSiz()-strlen(seq)*3-1;++i){
            b=1;
        for(int j=i,k=0;j<i+strlen(seq)*3;j+=3,k++){
            codon[0]=trans.getElement(j);
            codon[1]=trans.getElement(j+1);
            codon[2]=trans.getElement(j+2);
            if(aminoAcid[codon]!=seq[k]){
                b=0;
                break;
            }
            tmp.setElement(codon[0],j-i);
            tmp.setElement(codon[1],j+1-i);
            tmp.setElement(codon[2],j+2-i);
        }
        if(b) break;
    }
    if(!b) cout<<"can't make this protein from this DNA ";
    else {
        for(int i=0;i<tmp.getSeqSiz();++i){
            if(tmp.getElement(i)=='U') tmp.setElement('T',i);
        }
    }
    tmp.BuildComplementaryStrand();
    tmp.setSeq(tmp.getComplementalStrand());
    return tmp;


}
ostream& operator<<(ostream& out, Protein &s)
{
    out << "The Protein Sequence: ";
    for(int i=0 ; i<strlen(s.seq) ;i++)
    {
        out<<s.seq[i];
    }
    out << endl;
    //out << "The Sequence Type = ";
    //out << endl;
    //out << s(DNA)->type << endl;
    return out;
}

istream& operator>>(istream& in, Protein &s)
{

    in >> s.seq;

    return in;
}

Protein Protein:: operator+(Protein& d2)
{
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

bool Protein ::  operator!= (Protein& d)
{
    if (strcmp(seq,d.seq))
        return true;
    else
        return false;
}
Protein::~Protein()
{
    //dtor
}
