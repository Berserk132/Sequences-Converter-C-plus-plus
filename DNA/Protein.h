#ifndef PROTEIN_H
#define PROTEIN_H
#include "Sequence.h"
#include "DNA.h"
#include <bits/stdc++.h>
class DNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
    private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p);
 	 	Protein(Protein* p);
 	 	Protein(const Protein& p);
 	 	~Protein();
 	 	void Print();
 	 	void operator=(Protein rhs);
 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
        DNA GetDNAStrandsEncodingMe(DNA & bigDNA);
        friend ostream& operator<<(ostream& out, Protein &s);
        friend istream& operator>>(istream& in, Protein &s);
        Protein operator+(Protein& d);
        bool operator!= (Protein& d);
};

#endif // PROTEIN_H
