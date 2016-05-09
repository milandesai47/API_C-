#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<exception>
#include "table.h"
using namespace std;
table tbl; 							//===== object for Table Class

//================Reading The Data File===================
 void table::CSVreadData(string fname)
{
			ifstream inf(fname.c_str());
			if (!inf) {
		        cerr << "File not avilable" << endl;
		        exit(0);
		    }
		    int row = 0;
		    string csvLine, val;
		    double dval;
		    while (inf) {
		        getline(inf, csvLine);
		        istringstream  stream(csvLine);
		        tbl.data.resize(row+1);
		     	while(getline(stream, val, ',')) { 
					dval = atof(val.c_str());
					tbl.data[row].push_back(dval); 
		    	}
		        row++;		       
		    }
		    if(tbl.data[tbl.data.size()-1].size() == 0) {
				tbl.data.resize(tbl.data.size()-1);
			}		   
}
//============= Fuction for getting Average of Perticular Colomn==========//
double table::CSVavg(int colno)
{	
	if(colno<=tbl.data[0].size()){
	double sum=0;
	colno=colno-1;
	int i=0;
		for(i=0;i<tbl.data.size();i++)
			{
				sum = sum + (tbl.data[i][colno]);
			}
       return sum/tbl.data.size();
	}
	else
	{
		throw string("No colomns Available");
	}
	
}

//============= Fuction for getting Corrected STD_ DEV of Perticular Colomn==========//
double table::CSVstd_dev(int colno)
{
	if(colno<=tbl.data[0].size()){
		double sum=0,avg=0,e;
		colno=colno-1;
	     for(int i=0;i<tbl.data.size();i++)
				{sum = sum+ (tbl.data[i][colno]);}
	   			 avg=sum/tbl.data.size();
	    double inverse = 1.0 / (tbl.data.size()-1);
	   for(int i=0;i<tbl.data.size();i++)
	    {
	        e += pow((tbl.data[i][colno])-avg, 2);
	    }
	    return sqrt(inverse * e);	
	}
	else
	{
		throw string("No colomns Available");
	}
}

//============= Fuction for getting Number Of Rows In Table==========//
int table::CSVNoRows()
{
	return tbl.data.size();
}

//============= Fuction for getting Number Of Colomns In Table==========//
int table::CSVNoCols()
{
	return tbl.data[0].size() ;
}

//============= Fuction for getting value Of perticular cell In Table==========//
double table::CSVcell(int rowno,int colno)
{
	if(colno<=tbl.data[0].size() && rowno<=tbl.data.size()){
		rowno=rowno-1;
		colno=colno-1;
				return tbl.data[rowno][colno];
	}
	else
	{
		throw string("Invalid Cell");
	}
}
//============= Fuction for changing value Of perticular cell In Table==========//
double table::CSVcellval(int rowno,int colno,double val)
{
	if(colno<=tbl.data[0].size() && rowno<=tbl.data.size()){
	rowno=rowno-1;
	colno=colno-1;
	tbl.data[rowno][colno]=val;
	return val;
	}
	else
	{
		throw string("Invalid Cell");
	}
}
//============= Fuction for Standerdizae Data in table==========//
void table::CSVdata_std()
{
	double avg;
	vector<vector<double> > temp;
	double val;
	temp.resize(tbl.data.size());
	for(int row=0;row<=tbl.data.size();row++)
	{
		for(int col=0;col<tbl.data[row].size();col++)
		{
			double avg = tbl.CSVavg(col+1);
			double std_dev = tbl.CSVstd_dev(col+1);
			val = (tbl.data[row][col]-avg) / std_dev;
			temp[row].push_back(val);			
		}
	}
	tbl.data = temp;
	cout<<"========Data Standardization Succsessfully Completed======="<<endl;
	cout<<"========Call Overloading Method For Output the Data ======="<<endl;
	

}


//============= Fuction for Remove the Row in Table============//
int table::CSVremove_row(int rowno)
{
	if(rowno<=tbl.data.size()){
	rowno=rowno-1;
	tbl.data.erase(tbl.data.begin()+rowno);
	return tbl.data[rowno][1];
	}
	else
	{
		throw string("No Row Avaliable");
	}

}

//============= Fuction for Remove the Colomn in Table============//
int table::CSVremove_col(int colno)
{
	if(colno<=tbl.data[0].size())
	{
		colno=colno-1;
	 	for(int i=0;i<tbl.data.size();i++)
		{tbl.data[i].erase(tbl.data[i].begin() + colno);}
		return colno;
	}
	else
	{
		throw string("No Colomn Available");
	}
	
}

//============= Fuction for Add the Row in Table============//
void table::CSVadd_row(vector<double> val)
{	
			tbl.data.resize(tbl.data.size() + 1);
			for(int row=0;row<val.size();row++)
			{
				tbl.data[tbl.data.size() - 1].push_back(val[row]);
			}
}

//============= Fuction for Add the Colomn in Table============//
void table::CSVadd_col(vector<double> val)
{	
cout<<val.size();
		for(int col=0;col<val.size();col++)
		{
			
		tbl.data[col].push_back(val[col]);
		}

}

//============= Fuction for overload the intertion(<<)operator in table============//
ostream &operator<<(ostream &stream, table &obj)
{
	stream<<"\t\t\t========================File Data========================"<<endl<<endl;	
	for( int row=0; row<tbl.data.size(); row++) {
				if(row<9)
				{cout<<"Row::"<<row+1<<"  ";}
				else
				{cout<<"Row::"<<row+1<<" ";}
				for(int col=0; col<tbl.data[row].size(); col++) {
			
				if(tbl.data[row][col]<0)
					stream<<"|"<<setiosflags(ios::fixed)<<setprecision(4)<<tbl.data[row][col];
				else
					stream<<"| "<<setiosflags(ios::fixed)<<setprecision(4)<<tbl.data[row][col];
				}
			stream<<endl;
			}	
 	return stream;	
}

