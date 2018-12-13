#ifndef DNA_H
#define DNA_H
#include"RNA.h"
#include <bits/stdc++.h>

class RNA;
enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
  	private:
        DNA_Type type;
        char* complementary_strand;
        int startIndex;
        int endIndex;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(char * seq, DNA_Type atype);
        DNA(char * seq);
        DNA(DNA* rhs);
        DNA(const DNA& rhs);
        DNA(int length);

        char* getDNA();

        void operator=(DNA rhs);
 	 	// function printing DNA sequence information to user
        void Print();
        bool valid(char* chr);
        //void printDNA();
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA(int startIndex=0,int endIndex=0);
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();
        char* getComplementalStrand();

        ~DNA();
  };

#endif // DNA_H
