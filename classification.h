#include<iostream>
#include<vector>

using namespace std;
class classification
{
	vector<vector<double> > ClassData;
	unsigned int k;
	public:
	void ClassificationRead(string fname1,string fname2,string fname3,string fname4);
	void PrintFiles();
	void checkvalidations();	
	int classificationAlgo(int k);
};
