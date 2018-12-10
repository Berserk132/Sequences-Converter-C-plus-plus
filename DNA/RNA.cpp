#include "RNA.h"

RNA::RNA()
{
    //ctor
}
RNA::RNA(char * seq, RNA_Type atype)
{
    this->seq=new char[strlen(seq)+1];
    strcpy(this->seq,seq);
    type=atype;
}
RNA::RNA(const RNA& rhs){
    seq=new char[strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
    type=rhs.type;
}
void RNA::Print(){
    for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}

Protein RNA::ConvertToProtein(){
    Protein tmp;
    char* tmpChar = new char [strlen(seq)+1];
    char codon[4];
    for(int i=0,j=0;i<strlen(seq);i+=3,j++){
        codon[0]=seq[i],codon[1]=seq[i+1],codon[2]=seq[i+2];
        tmpChar[j]=aminoAcid[codon];
        if(tmpChar[j]==' ') break;
    }
    tmp.setSeq(tmpChar);
    return tmp;
}

ostream& operator<<(ostream& out, RNA &s)
{
    out << "The RNA Sequence: ";
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

istream& operator>>(istream& in, RNA &s)
{

    in >> s.seq;

    return in;
}

RNA RNA:: operator+(RNA& d2)
{
    RNA tmp;
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

bool RNA ::  operator!= (RNA& d)
{
    if (strcmp(seq,d.seq))
        return true;
    else
        return false;
}

DNA RNA::ConvertToDNA()const{
    RNA temp;
    DNA tmp;
    temp.seq=new char[strlen(seq)+1];
    strcpy(temp.seq,seq);
    for(int i=0;i<strlen(seq);++i){
        if(temp.seq[i]=='U') temp.seq[i]='T';
    }
    tmp.setSeq(temp.seq);
    tmp.BuildComplementaryStrand();
    tmp.setSeq(tmp.getComplementalStrand());
    return tmp;

}
RNA::~RNA(){
    //dtor
}
