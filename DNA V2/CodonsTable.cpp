#include "CodonsTable.h"

CodonsTable::CodonsTable()
{
    //ctor
}
void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
    ifstream get;
    get.open(codonsFileName,ios::in);
    for(int i=0;i<64;++i){
        get>>codons[i].value;
        get.get();
        get.get(codons[i].AminoAcid);
    }
    get.close();

}
Codon CodonsTable::getAminoAcid(char * value)
{
    for(int i=0;i<64;++i){
        if(!strcmp(codons[i].value,value))
            return codons[i];
    }

}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    strcpy(codons[index].value,value);
    codons[index].AminoAcid=AminoAcid;
}

CodonsTable::~CodonsTable()
{
    //dtor
}
