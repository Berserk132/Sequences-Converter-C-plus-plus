#ifndef RNA_H
#define RNA_H
#include "Sequence.h"
#include "Protein.h"
#include <bits/stdc++.h>

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
class Protein;
class DNA;


class RNA : public Sequence
{
    private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * seq, RNA_Type atype);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        //void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codons Table object
        Protein ConvertToProtein();
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
};

#endif // RNA_H
