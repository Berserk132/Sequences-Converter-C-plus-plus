#include "RNA.h"
// Default Constructor
RNA::RNA()
{
    //ctor
}

bool RNA::valid(char* ch){
    for(int i=0;i<strlen(ch);++i)
        if((char)ch[i]=='A'||(char)ch[i]=='U'||(char)ch[i]=='C'||(char)ch[i]=='G')
                continue;
        else{
            string x="invalid input for RNA ";
            throw x;
        }
    return 1;
}

// Constructor to Create a RNA Sequence
RNA::RNA(char * seq, RNA_Type atype)
{
    valid(seq);
    this->seq=new char[strlen(seq)+1];
    strcpy(this->seq,seq);
    type=atype;
}
// copy constructor to create a RNA sequence equal to another one
RNA::RNA(const RNA& rhs){
    valid(rhs.seq);
    seq=new char[strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
    type=rhs.type;
}
void RNA::Print(){
    for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}
// function to convert a RNA Sequence to Protein Sequence
Protein RNA::ConvertToProtein(){
    Protein tmp;
    char* tmpChar = new char [(strlen(seq)/3)+1];
    char codon[4];
    for(int i=0,j=0;i<strlen(seq);i+=3,j++){
        codon[0]=seq[i],codon[1]=seq[i+1],codon[2]=seq[i+2];
        tmpChar[j]=aminoAcid[codon];
        if(tmpChar[j]==' ') break;
    }
    tmp.setSeq(tmpChar);
    return tmp;
}
// function to convert a RNA Sequence to DNA Sequence
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

// cout Operator to print the content of RNA Object
ostream& operator<<(ostream& out, RNA &s)
{
    out << "The RNA Sequence: ";
    for(int i=0 ; i<strlen(s.seq) ;i++)
    {
        out<<s.seq[i];
    }
    out << endl;
    out << "The RNA Type = ";
    if (s.type == 0)
    {
        out << "mRNA";
    }
    else if (s.type == 1)
    {
        out << "pre_mRNA";
    }
    else if (s.type == 2)
    {
        out << "mRNA_exon";
    }
    else if (s.type == 3)
    {
        out << "mRNA_intron";
    }
    out << endl;
    return out;
}
// cin Operator to take from user the content of RNA Object
istream& operator>>(istream& in, RNA &s)
{

    in >> s.seq;

    return in;
}
// plus operator to add a RNA sequence to another RNA sequence
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
// not equal operator to check if two RNA sequences not equal to each other
bool RNA ::  operator!= (RNA& d)
{
    if (strcmp(seq,d.seq))
        return true;
    else
        return false;
}
// Default Destructor
RNA::~RNA(){
    //dtor
}
