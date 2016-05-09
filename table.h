#include<iostream>
#include<vector>
using namespace std;
class table{
	vector<vector<double> > data;
	public :
		
	  void CSVreadData(string fname); 					// Reading file for Table Class. (Data File)
	  double CSVavg(int colno);							//getting the average of column
	  double CSVstd_dev(int colno);						//getting the corrected simple standard deviation
	  int CSVNoRows();									//getting number of rows
	  int CSVNoCols();									//getting number of column
	  double CSVcell(int rowno,int colno);				//getting value of particular cell
	  double CSVcellval(int rowno,int colno,double val);//change the value of particular cell
	  void CSVdata_std();								//for data standardization
	  int CSVremove_row(int rowno);						//for remove the row
	  int CSVremove_col(int colno);						//for remove the column
	  void CSVadd_row(vector<double> val);				//for add the row
	  void CSVadd_col(vector<double> val);				//for add the column
	  friend ostream &operator<<(ostream &stream, table &obj);//overloading the operator
	 
};
