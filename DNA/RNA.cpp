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
RNA::RNA(RNA& rhs):Sequence(rhs){
    type=rhs.type;
}
Protein RNA::ConvertToProtein(){
    Protein tmp;
    char* tmpChar = new char [(strlen(seq)/3)+1];
    char codon[4];
    for(int i=0,j=0;i<strlen(seq);i+=3,j++){
        codon[1]=seq[i],codon[1]=seq[i+1],codon[1]=seq[i+2];
        tmpChar[j]=aminoAcid[codon];
        if(tmpChar[j]==' ') break;
    }
    tmp.setSeq(tmpChar);
    return tmp;
}
DNA RNA::ConvertToDNA(){
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
