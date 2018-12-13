#include "Sequence.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"

#ifndef RNA_H
#define RNA_H
class DNA;
class RNA;

enum RNA_Type { mRNA, pre_mRNA, mRNA_exon, mRNA_intron };


class RNA : public Sequence
{
private:
	RNA_Type type;
public:
	// constructors and destructor
	RNA();
	RNA(char * seq, RNA_Type atype);
	RNA(const RNA& p);
	~RNA();
	// function to be overridden to print all the RNA information
	void Print();
	// function to convert the RNA sequence into protein sequence
	// using the codonsTable object
	Protein* ConvertToProtein(CodonsTable & table);
	// function to convert the RNA sequence back to DNA
    bool operator== (const RNA& R1) ;
    bool operator!= (const RNA& R1) ;
	RNA operator+ (const RNA&);
	friend istream& operator>> (istream & out, RNA enter);
	DNA* ConvertToDNA();
	RNA_Type get_type();
};


#endif // RNA_H
