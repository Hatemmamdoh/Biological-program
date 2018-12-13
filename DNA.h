#include <bits/stdc++.h>
#include "Sequence.h"
#ifndef DNA_H
#define DNA_H

using namespace std;
class RNA;

enum DNA_Type { promoter, motif, tail, noncoding };

class DNA : public Sequence
{
private:
	DNA_Type type;
	DNA * complementary_strand = nullptr;
	int startIndex;
	int endIndex;
public:
	// constructors and destructor
	DNA();
	DNA(char * seq, DNA_Type atype);
	DNA(DNA& rhs);
	// function printing DNA sequence information to user
	void Print();
	//void PrintC();
	// function to convert the DNA sequence to RNA sequence
	// It starts by building the complementary_strand of the current
	// DNA sequence (starting from the startIndex to the endIndex), then,
	// it builds the RNA corresponding to that complementary_strand.
	RNA* ConvertToRNA();
	// function to build the second strand/pair of DNA sequence
	// To build a complementary_strand (starting from the startIndex to
	// the endIndex), convert each A to T, each T to A, each C to G, and
	// each G to C. Then reverse the resulting sequence.
	void BuildComplementaryStrand();
	void set_type(DNA_Type T);
	DNA_Type get_type() const;
	DNA& operator+(const DNA& add);
	bool operator==(const DNA& add);
	bool operator!=(const DNA& add);
	friend istream& operator>> (istream & in, DNA enter);
	//friend DNA& operator+(DNA left, const DNA& add);
};

#endif // DNA_H
