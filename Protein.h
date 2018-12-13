#ifndef PROTEIN_H
#define PROTEIN_H
#include "Sequence.h"
#include "DNA.h"
//#include "RNA.h"
#include <string>

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
    private:
        Protein_Type type;
    public:
        // constructors and destructor
        Protein();
        Protein(char * p,Protein_Type atype);
        Protein(const Protein&);
        virtual ~Protein();
        // return an array of DNA sequences that can possibly
        // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
        void Print();
        Protein_Type get_type ();
        Protein operator+ (const Protein&);
        bool operator== (const Protein&);
        bool operator!= (const Protein&);
		friend istream& operator>> (istream & out, Protein enter);


};


#endif // PROTEIN_H
