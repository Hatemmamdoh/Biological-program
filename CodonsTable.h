#ifndef CODONSTABLE_H
#define CODONSTABLE_H

#include<fstream>

#include<cstring>


using namespace std;

struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
  	private:

   	public:
   	    Codon codons[64];
 	 	// constructors and destructor
        CodonsTable(string codonsFileName);
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(string codonsFileName);
        Codon getAminoAcid(char * value);
        void setCodon(char * value, char AminoAcid, int index);
};

#endif // CODONSTABLE_H
