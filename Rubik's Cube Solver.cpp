#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<windows.h>
#include<time.h>

using namespace std;

class Cube{
      
      private:
      	
             vector<char>S; 
             vector<char>T; 
             vector<char>R;
			 vector<char>L;
			 vector<char>B;
			 vector<char>F; 
             vector<char>temp;
             friend ostream& operator<<(ostream& out,const Cube& c);
             friend istream& operator>>(istream& is, Cube& d);
             
      public:
      		
      		 void Init(){
      		 	
      		 	F.clear();
      		 	R.clear();
      		 	B.clear();
      		 	L.clear();
      		 	T.clear();
      		 	S.clear();
      		 	
      		 	for(int i=0;i<9;i++){
               		F.push_back('G');
               		R.push_back('O');
               		B.push_back('B');
               		L.push_back('R');
               		T.push_back('Y');
               		S.push_back('W');
               		temp.push_back('X');
               	 }
               	 
			   }
			   
      		 Cube(){
      		 	
               	Init();
               	
             }
             
             Cube(const Cube &c){
             	
             	Init();
               	 
             	for(int i=0;i<9;i++){
               		F[i]=c.F[i];
               		R[i]=c.R[i];
               		B[i]=c.B[i];
               		L[i]=c.L[i];
               		T[i]=c.T[i];
               		S[i]=c.S[i];
               	 }
			 }
             
             inline char Getcol(const char c, const int i)const{
			 		
			 		switch(c){
			 			
			 			case'F':
			 				return F[i];
			 				break;
			 			case'R':
			 				return R[i];
			 				break;
			 			case'B':
			 				return B[i];
			 				break;
			 			case'L':
			 				return L[i];
			 				break;
			 			case'T':
			 				return T[i];
			 				break;
			 			case'S':
			 				return S[i];
			 				break;
			 				
					 }
			 }
             void Setcol(const char &c,const int &a, const char &d){
             	
             	switch(c){
			 			
			 			case'F':
			 				F[a]=d;
			 				break;
			 			case'R':
			 				R[a]=d;
			 				break;
			 			case'B':
			 				B[a]=d;
			 				break;
			 			case'L':
			 				L[a]=d;
			 				break;
			 			case'T':
			 				T[a]=d;
			 				break;
			 			case'S':
			 				S[a]=d;
			 				break;
			 				
					 }
			 }
			 
			 void Move(const string &s){
			 	
			 	
			 	if(s=="RCW"){
	               /*This function moves the Right face of the cube clockwise*/
		           	temp[0]=F[8];temp[1]=F[5];temp[2]=F[2];
					temp[3]=T[8];temp[4]=T[5];temp[5]=T[2];
					temp[6]=B[0];temp[7]=B[3];temp[8]=B[6];
					temp[9]=S[8];temp[10]=S[5];temp[11]=S[2];
		            temp[12]=R[0];temp[13]=R[1];temp[14]=R[2];temp[15]=R[5];
					temp[16]=R[8];temp[17]=R[7];temp[18]=R[6];temp[19]=R[3];
					
					T[8]=temp[0];T[5]=temp[1];T[2]=temp[2];
					B[0]=temp[3];B[3]=temp[4];B[6]=temp[5];
					S[8]=temp[6];S[5]=temp[7];S[2]=temp[8];
					F[8]=temp[9];F[5]=temp[10];F[2]=temp[11];
					R[2]=temp[12];R[5]=temp[13];R[8]=temp[14];R[7]=temp[15];
					R[6]=temp[16];R[3]=temp[17];R[0]=temp[18];R[1]=temp[19];
	            
	            }
		 		else if(s=="RCCW"){
	             	/*This function moves the Right face of the cube counter-clockwise*/
	             	temp[0]=F[8];temp[1]=F[5];temp[2]=F[2];
					temp[3]=T[8];temp[4]=T[5];temp[5]=T[2];
					temp[6]=B[0];temp[7]=B[3];temp[8]=B[6];
					temp[9]=S[8];temp[10]=S[5];temp[11]=S[2];
		            temp[12]=R[0];temp[13]=R[1];temp[14]=R[2];temp[15]=R[5];
					temp[16]=R[8];temp[17]=R[7];temp[18]=R[6];temp[19]=R[3];
					
					S[8]=temp[0];S[5]=temp[1];S[2]=temp[2];
					F[8]=temp[3];F[5]=temp[4];F[2]=temp[5];
					T[8]=temp[6];T[5]=temp[7];T[2]=temp[8];
					B[0]=temp[9];B[3]=temp[10];B[6]=temp[11];
					R[6]=temp[12];R[3]=temp[13];R[0]=temp[14];R[1]=temp[15];
					R[2]=temp[16];R[5]=temp[17];R[8]=temp[18];R[7]=temp[19];
					
				 }
		 		else if(s=="CCW"){
				    /*This function moves the Center of the cube clockwise*/
		            temp[0]=F[7];temp[1]=F[4];temp[2]=F[1];
					temp[3]=T[7];temp[4]=T[4];temp[5]=T[1];
					temp[6]=B[1];temp[7]=B[4];temp[8]=B[7];
					temp[9]=S[7];temp[10]=S[4];temp[11]=S[1];
					
					T[7]=temp[0];T[4]=temp[1];T[1]=temp[2];
					B[1]=temp[3];B[4]=temp[4];B[7]=temp[5];
					S[7]=temp[6];S[4]=temp[7];S[1]=temp[8];
					F[7]=temp[9];F[4]=temp[10];F[1]=temp[11];
					
				}
		 		else if(s=="CCCW"){
	         	 	/*This function moves the Center of the cube counter-clockwise*/
				 	temp[0]=F[7];temp[1]=F[4];temp[2]=F[1];
					temp[3]=T[7];temp[4]=T[4];temp[5]=T[1];
					temp[6]=B[1];temp[7]=B[4];temp[8]=B[7];
					temp[9]=S[7];temp[10]=S[4];temp[11]=S[1];
					
					S[7]=temp[0];S[4]=temp[1];S[1]=temp[2];
					F[7]=temp[3];F[4]=temp[4];F[1]=temp[5];
					T[7]=temp[6];T[4]=temp[7];T[1]=temp[8];
					B[1]=temp[9];B[4]=temp[10];B[7]=temp[11];
					
				 }
		 		else if(s=="LCW"){
	             	 /*This function moves the Left face of the cube clockwise*/
		           	temp[0]=F[6];temp[1]=F[3];temp[2]=F[0];
					temp[3]=T[6];temp[4]=T[3];temp[5]=T[0];
					temp[6]=B[2];temp[7]=B[5];temp[8]=B[8];
					temp[9]=S[6];temp[10]=S[3];temp[11]=S[0];
		            temp[12]=L[0];temp[13]=L[1];temp[14]=L[2];temp[15]=L[5];
					temp[16]=L[8];temp[17]=L[7];temp[18]=L[6];temp[19]=L[3];
					
					S[6]=temp[0];S[3]=temp[1];S[0]=temp[2];
					F[6]=temp[3];F[3]=temp[4];F[0]=temp[5];
					T[6]=temp[6];T[3]=temp[7];T[0]=temp[8];
					B[2]=temp[9];B[5]=temp[10];B[8]=temp[11];
					L[2]=temp[12];L[5]=temp[13];L[8]=temp[14];L[7]=temp[15];
					L[6]=temp[16];L[3]=temp[17];L[0]=temp[18];L[1]=temp[19];
					
				}
		 		else if(s=="LCCW"){
				 	/*This function moves the Left face of the cube counter-clockwise*/
				 	temp[0]=F[6];temp[1]=F[3];temp[2]=F[0];
					temp[3]=T[6];temp[4]=T[3];temp[5]=T[0];
					temp[6]=B[2];temp[7]=B[5];temp[8]=B[8];
					temp[9]=S[6];temp[10]=S[3];temp[11]=S[0];
		            temp[12]=L[0];temp[13]=L[1];temp[14]=L[2];temp[15]=L[5];
					temp[16]=L[8];temp[17]=L[7];temp[18]=L[6];temp[19]=L[3];
					
					T[6]=temp[0];T[3]=temp[1];T[0]=temp[2];
					B[2]=temp[3];B[5]=temp[4];B[8]=temp[5];
					S[6]=temp[6];S[3]=temp[7];S[0]=temp[8];
					F[6]=temp[9];F[3]=temp[10];F[0]=temp[11];
					L[6]=temp[12];L[3]=temp[13];L[0]=temp[14];L[1]=temp[15];
					L[2]=temp[16];L[5]=temp[17];L[8]=temp[18];L[7]=temp[19];	
					
				 }
		 		else if(s=="BCW"){
				 	 /*This function moves the Bottom of the cube horizzontally and clockwise*/
				 	temp[0]=F[6];temp[1]=F[7];temp[2]=F[8];
					temp[3]=R[6];temp[4]=R[7];temp[5]=R[8];
					temp[6]=B[6];temp[7]=B[7];temp[8]=B[8];
					temp[9]=L[6];temp[10]=L[7];temp[11]=L[8];
		            temp[12]=S[0];temp[13]=S[1];temp[14]=S[2];temp[15]=S[5];
					temp[16]=S[8];temp[17]=S[7];temp[18]=S[6];temp[19]=S[3];
					
					L[6]=temp[0];L[7]=temp[1];L[8]=temp[2];
					F[6]=temp[3];F[7]=temp[4];F[8]=temp[5];
					R[6]=temp[6];R[7]=temp[7];R[8]=temp[8];
					B[6]=temp[9];B[7]=temp[10];B[8]=temp[11];
					S[6]=temp[12];S[3]=temp[13];S[0]=temp[14];S[1]=temp[15];
					S[2]=temp[16];S[5]=temp[17];S[8]=temp[18];S[7]=temp[19];
					
	            }
		 		else if(s=="BCCW"){
	             	/*This function moves the Bottom of the cube horizzontally and counter-clockwise*/
				 	temp[0]=F[6];temp[1]=F[7];temp[2]=F[8];
					temp[3]=R[6];temp[4]=R[7];temp[5]=R[8];
					temp[6]=B[6];temp[7]=B[7];temp[8]=B[8];
					temp[9]=L[6];temp[10]=L[7];temp[11]=L[8];
		            temp[12]=S[0];temp[13]=S[1];temp[14]=S[2];temp[15]=S[5];
					temp[16]=S[8];temp[17]=S[7];temp[18]=S[6];temp[19]=S[3];
					
					R[6]=temp[0];R[7]=temp[1];R[8]=temp[2];
					B[6]=temp[3];B[7]=temp[4];B[8]=temp[5];
					L[6]=temp[6];L[7]=temp[7];L[8]=temp[8];
					F[6]=temp[9];F[7]=temp[10];F[8]=temp[11];
					S[2]=temp[12];S[5]=temp[13];S[8]=temp[14];S[7]=temp[15];
					S[6]=temp[16];S[3]=temp[17];S[0]=temp[18];S[1]=temp[19];
					
				 }
		 		else if(s=="MCW"){
				 	/*This function moves the mid of the cube horizzontally and clockwise*/
				 	temp[0]=F[3];temp[1]=F[4];temp[2]=F[5];
					temp[3]=R[3];temp[4]=R[4];temp[5]=R[5];
					temp[6]=B[3];temp[7]=B[4];temp[8]=B[5];
					temp[9]=L[3];temp[10]=L[4];temp[11]=L[5];
					
					L[3]=temp[0];L[4]=temp[1];L[5]=temp[2];
					F[3]=temp[3];F[4]=temp[4];F[5]=temp[5];
					R[3]=temp[6];R[4]=temp[7];R[5]=temp[8];
					B[3]=temp[9];B[4]=temp[10];B[5]=temp[11];
				 	
				 }
		 		else if(s=="MCCW"){
				 	/*This function moves the Center of the cube horizzontally and counter-clockwise*/
				 	temp[0]=F[3];temp[1]=F[4];temp[2]=F[5];
					temp[3]=R[3];temp[4]=R[4];temp[5]=R[5];
					temp[6]=B[3];temp[7]=B[4];temp[8]=B[5];
					temp[9]=L[3];temp[10]=L[4];temp[11]=L[5];
					
					R[3]=temp[0];R[4]=temp[1];R[5]=temp[2];
					B[3]=temp[3];B[4]=temp[4];B[5]=temp[5];
					L[3]=temp[6];L[4]=temp[7];L[5]=temp[8];
					F[3]=temp[9];F[4]=temp[10];F[5]=temp[11];
					
				 }
		 		else if(s=="TCW"){
				 	/*This function moves the Top of the cube horizzontally and clockwise*/
				 	temp[0]=F[0];temp[1]=F[1];temp[2]=F[2];
					temp[3]=R[0];temp[4]=R[1];temp[5]=R[2];
					temp[6]=B[0];temp[7]=B[1];temp[8]=B[2];
					temp[9]=L[0];temp[10]=L[1];temp[11]=L[2];
		            temp[12]=T[0];temp[13]=T[1];temp[14]=T[2];temp[15]=T[5];
					temp[16]=T[8];temp[17]=T[7];temp[18]=T[6];temp[19]=T[3];
					
					L[0]=temp[0];L[1]=temp[1];L[2]=temp[2];
					F[0]=temp[3];F[1]=temp[4];F[2]=temp[5];
					R[0]=temp[6];R[1]=temp[7];R[2]=temp[8];
					B[0]=temp[9];B[1]=temp[10];B[2]=temp[11];
					T[2]=temp[12];T[5]=temp[13];T[8]=temp[14];T[7]=temp[15];
					T[6]=temp[16];T[3]=temp[17];T[0]=temp[18];T[1]=temp[19];
					
				 }
		 		else if(s=="TCCW"){
				 	/*This function moves the Top of the cube horizzontally and counter-clockwise*/
	         		temp[0]=F[0];temp[1]=F[1];temp[2]=F[2];
					temp[3]=R[0];temp[4]=R[1];temp[5]=R[2];
					temp[6]=B[0];temp[7]=B[1];temp[8]=B[2];
					temp[9]=L[0];temp[10]=L[1];temp[11]=L[2];
		            temp[12]=T[0];temp[13]=T[1];temp[14]=T[2];temp[15]=T[5];
					temp[16]=T[8];temp[17]=T[7];temp[18]=T[6];temp[19]=T[3];
					
					R[0]=temp[0];R[1]=temp[1];R[2]=temp[2];
					B[0]=temp[3];B[1]=temp[4];B[2]=temp[5];
					L[0]=temp[6];L[1]=temp[7];L[2]=temp[8];
					F[0]=temp[9];F[1]=temp[10];F[2]=temp[11];
					T[6]=temp[12];T[3]=temp[13];T[0]=temp[14];T[1]=temp[15];
					T[2]=temp[16];T[5]=temp[17];T[8]=temp[18];T[7]=temp[19];
					
				 }
				else if(s=="MLCW"){
					/*This funtion moves the mid layer clockwise*/
				 	temp[0]=T[3];temp[1]=T[4];temp[2]=T[5];
					temp[3]=R[1];temp[4]=R[4];temp[5]=R[7];
					temp[6]=S[5];temp[7]=S[4];temp[8]=S[3];
					temp[9]=L[7];temp[10]=L[4];temp[11]=L[1];
					
					R[1]=temp[0];R[4]=temp[1];R[7]=temp[2];
					S[5]=temp[3];S[4]=temp[4];S[3]=temp[5];
					L[7]=temp[6];L[4]=temp[7];L[1]=temp[8];
					T[3]=temp[9];T[4]=temp[10];T[5]=temp[11];
				 }
				else if(s=="MLCCW"){
					/*This funtion moves the mid layer counter-clockwise*/
				 	temp[0]=T[3];temp[1]=T[4];temp[2]=T[5];
					temp[3]=R[1];temp[4]=R[4];temp[5]=R[7];
					temp[6]=S[5];temp[7]=S[4];temp[8]=S[3];
					temp[9]=L[7];temp[10]=L[4];temp[11]=L[1];
					
					L[7]=temp[0];L[4]=temp[1];L[1]=temp[2];
					T[3]=temp[3];T[4]=temp[4];T[5]=temp[5];
					R[1]=temp[6];R[4]=temp[7];R[7]=temp[8];
					S[5]=temp[9];S[4]=temp[10];S[3]=temp[11];
				}
		 		else if(s=="BLCW"){
		 			/*This funtion moves the back layer clockwise*/
				 	temp[0]=T[0];temp[1]=T[1];temp[2]=T[2];
					temp[3]=R[2];temp[4]=R[5];temp[5]=R[8];
					temp[6]=S[8];temp[7]=S[7];temp[8]=S[6];
					temp[9]=L[6];temp[10]=L[3];temp[11]=L[0];
		            temp[12]=B[0];temp[13]=B[1];temp[14]=B[2];temp[15]=B[5];
					temp[16]=B[8];temp[17]=B[7];temp[18]=B[6];temp[19]=B[3];
					
					R[2]=temp[0];R[5]=temp[1];R[8]=temp[2];
					S[8]=temp[3];S[7]=temp[4];S[6]=temp[5];
					L[6]=temp[6];L[3]=temp[7];L[0]=temp[8];
					T[0]=temp[9];T[1]=temp[10];T[2]=temp[11];
					B[6]=temp[12];B[3]=temp[13];B[0]=temp[14];B[1]=temp[15];
					B[2]=temp[16];B[5]=temp[17];B[8]=temp[18];B[7]=temp[19];
				 }
		 		else if(s=="BLCCW"){
		 			/*This funtion moves the back layer counter-clockwise*/
				 	temp[0]=T[0];temp[1]=T[1];temp[2]=T[2];
					temp[3]=R[2];temp[4]=R[5];temp[5]=R[8];
					temp[6]=S[8];temp[7]=S[7];temp[8]=S[6];
					temp[9]=L[6];temp[10]=L[3];temp[11]=L[0];
		            temp[12]=B[0];temp[13]=B[1];temp[14]=B[2];temp[15]=B[5];
					temp[16]=B[8];temp[17]=B[7];temp[18]=B[6];temp[19]=B[3];
					
					L[6]=temp[0];L[3]=temp[1];L[0]=temp[2];
					T[0]=temp[3];T[1]=temp[4];T[2]=temp[5];
					R[2]=temp[6];R[5]=temp[7];R[8]=temp[8];
					S[8]=temp[9];S[7]=temp[10];S[6]=temp[11];
					B[2]=temp[12];B[5]=temp[13];B[8]=temp[14];B[7]=temp[15];
					B[6]=temp[16];B[3]=temp[17];B[0]=temp[18];B[1]=temp[19];
				}
		 		else if(s=="FLCW"){
		 			/*This funtion moves the front layer clockwise*/
				 	temp[0]=T[6];temp[1]=T[7];temp[2]=T[8];
					temp[3]=R[0];temp[4]=R[3];temp[5]=R[6];
					temp[6]=S[2];temp[7]=S[1];temp[8]=S[0];
					temp[9]=L[8];temp[10]=L[5];temp[11]=L[2];
		            temp[12]=F[0];temp[13]=F[1];temp[14]=F[2];temp[15]=F[5];
					temp[16]=F[8];temp[17]=F[7];temp[18]=F[6];temp[19]=F[3];
					
					R[0]=temp[0];R[3]=temp[1];R[6]=temp[2];
					S[2]=temp[3];S[1]=temp[4];S[0]=temp[5];
					L[8]=temp[6];L[5]=temp[7];L[2]=temp[8];
					T[6]=temp[9];T[7]=temp[10];T[8]=temp[11];
					F[2]=temp[12];F[5]=temp[13];F[8]=temp[14];F[7]=temp[15];
					F[6]=temp[16];F[3]=temp[17];F[0]=temp[18];F[1]=temp[19];
				 }
		 		else if(s=="FLCCW"){
				 	/*This funtion moves the front layer counter-clockwise*/
				 	temp[0]=T[6];temp[1]=T[7];temp[2]=T[8];
					temp[3]=R[0];temp[4]=R[3];temp[5]=R[6];
					temp[6]=S[2];temp[7]=S[1];temp[8]=S[0];
					temp[9]=L[8];temp[10]=L[5];temp[11]=L[2];
		            temp[12]=F[0];temp[13]=F[1];temp[14]=F[2];temp[15]=F[5];
					temp[16]=F[8];temp[17]=F[7];temp[18]=F[6];temp[19]=F[3];
					
					L[8]=temp[0];L[5]=temp[1];L[2]=temp[2];
					T[6]=temp[3];T[7]=temp[4];T[8]=temp[5];
					R[0]=temp[6];R[3]=temp[7];R[6]=temp[8];
					S[2]=temp[9];S[1]=temp[10];S[0]=temp[11];
					F[6]=temp[12];F[3]=temp[13];F[0]=temp[14];F[1]=temp[15];
					F[2]=temp[16];F[5]=temp[17];F[8]=temp[18];F[7]=temp[19];
					
				}
		 		else if(s=="FlipU"){
		 			/*This function moves flips the cube of 90° from bottom to top*/
		 			temp[0]=F[6];temp[1]=F[3];temp[2]=F[0];
					temp[3]=T[6];temp[4]=T[3];temp[5]=T[0];
					temp[6]=B[2];temp[7]=B[5];temp[8]=B[8];
					temp[9]=S[6];temp[10]=S[3];temp[11]=S[0];
		            temp[12]=L[0];temp[13]=L[1];temp[14]=L[2];temp[15]=L[5];
					temp[16]=L[8];temp[17]=L[7];temp[18]=L[6];temp[19]=L[3];
					
					T[6]=temp[0];T[3]=temp[1];T[0]=temp[2];
					B[2]=temp[3];B[5]=temp[4];B[8]=temp[5];
					S[6]=temp[6];S[3]=temp[7];S[0]=temp[8];
					F[6]=temp[9];F[3]=temp[10];F[0]=temp[11];
					L[6]=temp[12];L[3]=temp[13];L[0]=temp[14];L[1]=temp[15];
					L[2]=temp[16];L[5]=temp[17];L[8]=temp[18];L[7]=temp[19];
					
					temp[0]=F[7];temp[1]=F[4];temp[2]=F[1];
					temp[3]=T[7];temp[4]=T[4];temp[5]=T[1];
					temp[6]=B[1];temp[7]=B[4];temp[8]=B[7];
					temp[9]=S[7];temp[10]=S[4];temp[11]=S[1];
					
					T[7]=temp[0];T[4]=temp[1];T[1]=temp[2];
					B[1]=temp[3];B[4]=temp[4];B[7]=temp[5];
					S[7]=temp[6];S[4]=temp[7];S[1]=temp[8];
					F[7]=temp[9];F[4]=temp[10];F[1]=temp[11];
					
					temp[0]=F[8];temp[1]=F[5];temp[2]=F[2];
					temp[3]=T[8];temp[4]=T[5];temp[5]=T[2];
					temp[6]=B[0];temp[7]=B[3];temp[8]=B[6];
					temp[9]=S[8];temp[10]=S[5];temp[11]=S[2];
		            temp[12]=R[0];temp[13]=R[1];temp[14]=R[2];temp[15]=R[5];
					temp[16]=R[8];temp[17]=R[7];temp[18]=R[6];temp[19]=R[3];
					
					T[8]=temp[0];T[5]=temp[1];T[2]=temp[2];
					B[0]=temp[3];B[3]=temp[4];B[6]=temp[5];
					S[8]=temp[6];S[5]=temp[7];S[2]=temp[8];
					F[8]=temp[9];F[5]=temp[10];F[2]=temp[11];
					R[2]=temp[12];R[5]=temp[13];R[8]=temp[14];R[7]=temp[15];
					R[6]=temp[16];R[3]=temp[17];R[0]=temp[18];R[1]=temp[19];	
					
		 		}
		 		
		 		else if(s=="FlipD"){
		 			/*This function moves the Right face of the cube counter-clockwise*/
		 			temp[0]=F[6];temp[1]=F[3];temp[2]=F[0];
					temp[3]=T[6];temp[4]=T[3];temp[5]=T[0];
					temp[6]=B[2];temp[7]=B[5];temp[8]=B[8];
					temp[9]=S[6];temp[10]=S[3];temp[11]=S[0];
		            temp[12]=L[0];temp[13]=L[1];temp[14]=L[2];temp[15]=L[5];
					temp[16]=L[8];temp[17]=L[7];temp[18]=L[6];temp[19]=L[3];
					
					S[6]=temp[0];S[3]=temp[1];S[0]=temp[2];
					F[6]=temp[3];F[3]=temp[4];F[0]=temp[5];
					T[6]=temp[6];T[3]=temp[7];T[0]=temp[8];
					B[2]=temp[9];B[5]=temp[10];B[8]=temp[11];
					L[2]=temp[12];L[5]=temp[13];L[8]=temp[14];L[7]=temp[15];
					L[6]=temp[16];L[3]=temp[17];L[0]=temp[18];L[1]=temp[19];
					
					temp[0]=F[7];temp[1]=F[4];temp[2]=F[1];
					temp[3]=T[7];temp[4]=T[4];temp[5]=T[1];
					temp[6]=B[1];temp[7]=B[4];temp[8]=B[7];
					temp[9]=S[7];temp[10]=S[4];temp[11]=S[1];
					
					S[7]=temp[0];S[4]=temp[1];S[1]=temp[2];
					F[7]=temp[3];F[4]=temp[4];F[1]=temp[5];
					T[7]=temp[6];T[4]=temp[7];T[1]=temp[8];
					B[1]=temp[9];B[4]=temp[10];B[7]=temp[11];
					
					temp[0]=F[8];temp[1]=F[5];temp[2]=F[2];
					temp[3]=T[8];temp[4]=T[5];temp[5]=T[2];
					temp[6]=B[0];temp[7]=B[3];temp[8]=B[6];
					temp[9]=S[8];temp[10]=S[5];temp[11]=S[2];
		            temp[12]=R[0];temp[13]=R[1];temp[14]=R[2];temp[15]=R[5];
					temp[16]=R[8];temp[17]=R[7];temp[18]=R[6];temp[19]=R[3];
					
					S[8]=temp[0];S[5]=temp[1];S[2]=temp[2];
					F[8]=temp[3];F[5]=temp[4];F[2]=temp[5];
					T[8]=temp[6];T[5]=temp[7];T[2]=temp[8];
					B[0]=temp[9];B[3]=temp[10];B[6]=temp[11];
					R[6]=temp[12];R[3]=temp[13];R[0]=temp[14];R[1]=temp[15];
					R[2]=temp[16];R[5]=temp[17];R[8]=temp[18];R[7]=temp[19];
					
		 		}
		 		else if(s=="FlipR"){
		 			/*This function moves rotates the cube of 90° from left to right*/
		 			temp[0]=F[0];temp[1]=F[1];temp[2]=F[2];
					temp[3]=R[0];temp[4]=R[1];temp[5]=R[2];
					temp[6]=B[0];temp[7]=B[1];temp[8]=B[2];
					temp[9]=L[0];temp[10]=L[1];temp[11]=L[2];
		            temp[12]=T[0];temp[13]=T[1];temp[14]=T[2];temp[15]=T[5];
					temp[16]=T[8];temp[17]=T[7];temp[18]=T[6];temp[19]=T[3];
					
					L[0]=temp[0];L[1]=temp[1];L[2]=temp[2];
					F[0]=temp[3];F[1]=temp[4];F[2]=temp[5];
					R[0]=temp[6];R[1]=temp[7];R[2]=temp[8];
					B[0]=temp[9];B[1]=temp[10];B[2]=temp[11];
					T[2]=temp[12];T[5]=temp[13];T[8]=temp[14];T[7]=temp[15];
					T[6]=temp[16];T[3]=temp[17];T[0]=temp[18];T[1]=temp[19];
					
					temp[0]=F[3];temp[1]=F[4];temp[2]=F[5];
					temp[3]=R[3];temp[4]=R[4];temp[5]=R[5];
					temp[6]=B[3];temp[7]=B[4];temp[8]=B[5];
					temp[9]=L[3];temp[10]=L[4];temp[11]=L[5];
					
					L[3]=temp[0];L[4]=temp[1];L[5]=temp[2];
					F[3]=temp[3];F[4]=temp[4];F[5]=temp[5];
					R[3]=temp[6];R[4]=temp[7];R[5]=temp[8];
					B[3]=temp[9];B[4]=temp[10];B[5]=temp[11];
					
					temp[0]=F[6];temp[1]=F[7];temp[2]=F[8];
					temp[3]=R[6];temp[4]=R[7];temp[5]=R[8];
					temp[6]=B[6];temp[7]=B[7];temp[8]=B[8];
					temp[9]=L[6];temp[10]=L[7];temp[11]=L[8];
		            temp[12]=S[0];temp[13]=S[1];temp[14]=S[2];temp[15]=S[5];
					temp[16]=S[8];temp[17]=S[7];temp[18]=S[6];temp[19]=S[3];
					
					L[6]=temp[0];L[7]=temp[1];L[8]=temp[2];
					F[6]=temp[3];F[7]=temp[4];F[8]=temp[5];
					R[6]=temp[6];R[7]=temp[7];R[8]=temp[8];
					B[6]=temp[9];B[7]=temp[10];B[8]=temp[11];
					S[6]=temp[12];S[3]=temp[13];S[0]=temp[14];S[1]=temp[15];
					S[2]=temp[16];S[5]=temp[17];S[8]=temp[18];S[7]=temp[19];
				}
		 	    else if (s=="FlipL"){
		 	    	/*This function moves rotates the cube of 90° from right to left*/
		 	    	temp[0]=F[0];temp[1]=F[1];temp[2]=F[2];
					temp[3]=R[0];temp[4]=R[1];temp[5]=R[2];
					temp[6]=B[0];temp[7]=B[1];temp[8]=B[2];
					temp[9]=L[0];temp[10]=L[1];temp[11]=L[2];
		            temp[12]=T[0];temp[13]=T[1];temp[14]=T[2];temp[15]=T[5];
					temp[16]=T[8];temp[17]=T[7];temp[18]=T[6];temp[19]=T[3];
					
					R[0]=temp[0];R[1]=temp[1];R[2]=temp[2];
					B[0]=temp[3];B[1]=temp[4];B[2]=temp[5];
					L[0]=temp[6];L[1]=temp[7];L[2]=temp[8];
					F[0]=temp[9];F[1]=temp[10];F[2]=temp[11];
					T[6]=temp[12];T[3]=temp[13];T[0]=temp[14];T[1]=temp[15];
					T[2]=temp[16];T[5]=temp[17];T[8]=temp[18];T[7]=temp[19];
					
					temp[0]=F[3];temp[1]=F[4];temp[2]=F[5];
					temp[3]=R[3];temp[4]=R[4];temp[5]=R[5];
					temp[6]=B[3];temp[7]=B[4];temp[8]=B[5];
					temp[9]=L[3];temp[10]=L[4];temp[11]=L[5];
					
					R[3]=temp[0];R[4]=temp[1];R[5]=temp[2];
					B[3]=temp[3];B[4]=temp[4];B[5]=temp[5];
					L[3]=temp[6];L[4]=temp[7];L[5]=temp[8];
					F[3]=temp[9];F[4]=temp[10];F[5]=temp[11];
					
					temp[0]=F[6];temp[1]=F[7];temp[2]=F[8];
					temp[3]=R[6];temp[4]=R[7];temp[5]=R[8];
					temp[6]=B[6];temp[7]=B[7];temp[8]=B[8];
					temp[9]=L[6];temp[10]=L[7];temp[11]=L[8];
		            temp[12]=S[0];temp[13]=S[1];temp[14]=S[2];temp[15]=S[5];
					temp[16]=S[8];temp[17]=S[7];temp[18]=S[6];temp[19]=S[3];
					
					R[6]=temp[0];R[7]=temp[1];R[8]=temp[2];
					B[6]=temp[3];B[7]=temp[4];B[8]=temp[5];
					L[6]=temp[6];L[7]=temp[7];L[8]=temp[8];
					F[6]=temp[9];F[7]=temp[10];F[8]=temp[11];
					S[2]=temp[12];S[5]=temp[13];S[8]=temp[14];S[7]=temp[15];
					S[6]=temp[16];S[3]=temp[17];S[0]=temp[18];S[1]=temp[19];
		 	    }
		 	    else if(s=="Rotate"){
		 	    	/*This funciotn moves the cube 90° north to east*/
		 	    	temp[0]=T[6];temp[1]=T[7];temp[2]=T[8];
					temp[3]=R[0];temp[4]=R[3];temp[5]=R[6];
					temp[6]=S[2];temp[7]=S[1];temp[8]=S[0];
					temp[9]=L[8];temp[10]=L[5];temp[11]=L[2];
		            temp[12]=F[0];temp[13]=F[1];temp[14]=F[2];temp[15]=F[5];
					temp[16]=F[8];temp[17]=F[7];temp[18]=F[6];temp[19]=F[3];
					
					R[0]=temp[0];R[3]=temp[1];R[6]=temp[2];
					S[2]=temp[3];S[1]=temp[4];S[0]=temp[5];
					L[8]=temp[6];L[5]=temp[7];L[2]=temp[8];
					T[6]=temp[9];T[7]=temp[10];T[8]=temp[11];
					F[2]=temp[12];F[5]=temp[13];F[8]=temp[14];F[7]=temp[15];
					F[6]=temp[16];F[3]=temp[17];F[0]=temp[18];F[1]=temp[19];
					
					temp[0]=T[3];temp[1]=T[4];temp[2]=T[5];
					temp[3]=R[1];temp[4]=R[4];temp[5]=R[7];
					temp[6]=S[5];temp[7]=S[4];temp[8]=S[3];
					temp[9]=L[7];temp[10]=L[4];temp[11]=L[1];
					
					R[1]=temp[0];R[4]=temp[1];R[7]=temp[2];
					S[5]=temp[3];S[4]=temp[4];S[3]=temp[5];
					L[7]=temp[6];L[4]=temp[7];L[1]=temp[8];
					T[3]=temp[9];T[4]=temp[10];T[5]=temp[11];
					
					temp[0]=T[0];temp[1]=T[1];temp[2]=T[2];
					temp[3]=R[2];temp[4]=R[5];temp[5]=R[8];
					temp[6]=S[8];temp[7]=S[7];temp[8]=S[6];
					temp[9]=L[6];temp[10]=L[3];temp[11]=L[0];
		            temp[12]=B[0];temp[13]=B[1];temp[14]=B[2];temp[15]=B[5];
					temp[16]=B[8];temp[17]=B[7];temp[18]=B[6];temp[19]=B[3];
					
					L[6]=temp[0];L[3]=temp[1];L[0]=temp[2];
					T[0]=temp[3];T[1]=temp[4];T[2]=temp[5];
					R[2]=temp[6];R[5]=temp[7];R[8]=temp[8];
					S[8]=temp[9];S[7]=temp[10];S[6]=temp[11];
					B[2]=temp[12];B[5]=temp[13];B[8]=temp[14];B[7]=temp[15];
					B[6]=temp[16];B[3]=temp[17];B[0]=temp[18];B[1]=temp[19];	
		 	    }
		 	    else if (s=="RALG"){
		 	    	 /*This function performs righty alg*/
		 	    	temp[0]=F[8];temp[1]=F[5];temp[2]=F[2];
					temp[3]=T[8];temp[4]=T[5];temp[5]=T[2];
					temp[6]=B[0];temp[7]=B[3];temp[8]=B[6];
					temp[9]=S[8];temp[10]=S[5];temp[11]=S[2];
		            temp[12]=R[0];temp[13]=R[1];temp[14]=R[2];temp[15]=R[5];
					temp[16]=R[8];temp[17]=R[7];temp[18]=R[6];temp[19]=R[3];
					
					T[8]=temp[0];T[5]=temp[1];T[2]=temp[2];
					B[0]=temp[3];B[3]=temp[4];B[6]=temp[5];
					S[8]=temp[6];S[5]=temp[7];S[2]=temp[8];
					F[8]=temp[9];F[5]=temp[10];F[2]=temp[11];
					R[2]=temp[12];R[5]=temp[13];R[8]=temp[14];R[7]=temp[15];
					R[6]=temp[16];R[3]=temp[17];R[0]=temp[18];R[1]=temp[19];
					
					temp[0]=F[0];temp[1]=F[1];temp[2]=F[2];
					temp[3]=R[0];temp[4]=R[1];temp[5]=R[2];
					temp[6]=B[0];temp[7]=B[1];temp[8]=B[2];
					temp[9]=L[0];temp[10]=L[1];temp[11]=L[2];
		            temp[12]=T[0];temp[13]=T[1];temp[14]=T[2];temp[15]=T[5];
					temp[16]=T[8];temp[17]=T[7];temp[18]=T[6];temp[19]=T[3];
					
					L[0]=temp[0];L[1]=temp[1];L[2]=temp[2];
					F[0]=temp[3];F[1]=temp[4];F[2]=temp[5];
					R[0]=temp[6];R[1]=temp[7];R[2]=temp[8];
					B[0]=temp[9];B[1]=temp[10];B[2]=temp[11];
					T[2]=temp[12];T[5]=temp[13];T[8]=temp[14];T[7]=temp[15];
					T[6]=temp[16];T[3]=temp[17];T[0]=temp[18];T[1]=temp[19];
					
					temp[0]=F[8];temp[1]=F[5];temp[2]=F[2];
					temp[3]=T[8];temp[4]=T[5];temp[5]=T[2];
					temp[6]=B[0];temp[7]=B[3];temp[8]=B[6];
					temp[9]=S[8];temp[10]=S[5];temp[11]=S[2];
		            temp[12]=R[0];temp[13]=R[1];temp[14]=R[2];temp[15]=R[5];
					temp[16]=R[8];temp[17]=R[7];temp[18]=R[6];temp[19]=R[3];
					
					S[8]=temp[0];S[5]=temp[1];S[2]=temp[2];
					F[8]=temp[3];F[5]=temp[4];F[2]=temp[5];
					T[8]=temp[6];T[5]=temp[7];T[2]=temp[8];
					B[0]=temp[9];B[3]=temp[10];B[6]=temp[11];
					R[6]=temp[12];R[3]=temp[13];R[0]=temp[14];R[1]=temp[15];
					R[2]=temp[16];R[5]=temp[17];R[8]=temp[18];R[7]=temp[19];
					
					temp[0]=F[0];temp[1]=F[1];temp[2]=F[2];
					temp[3]=R[0];temp[4]=R[1];temp[5]=R[2];
					temp[6]=B[0];temp[7]=B[1];temp[8]=B[2];
					temp[9]=L[0];temp[10]=L[1];temp[11]=L[2];
		            temp[12]=T[0];temp[13]=T[1];temp[14]=T[2];temp[15]=T[5];
					temp[16]=T[8];temp[17]=T[7];temp[18]=T[6];temp[19]=T[3];
					
					R[0]=temp[0];R[1]=temp[1];R[2]=temp[2];
					B[0]=temp[3];B[1]=temp[4];B[2]=temp[5];
					L[0]=temp[6];L[1]=temp[7];L[2]=temp[8];
					F[0]=temp[9];F[1]=temp[10];F[2]=temp[11];
					T[6]=temp[12];T[3]=temp[13];T[0]=temp[14];T[1]=temp[15];
					T[2]=temp[16];T[5]=temp[17];T[8]=temp[18];T[7]=temp[19];
				}
		 	    else if (s=="LALG"){
		 	    	/*This function performs lefty alg*/
		 	    	temp[0]=F[6];temp[1]=F[3];temp[2]=F[0];
					temp[3]=T[6];temp[4]=T[3];temp[5]=T[0];
					temp[6]=B[2];temp[7]=B[5];temp[8]=B[8];
					temp[9]=S[6];temp[10]=S[3];temp[11]=S[0];
		            temp[12]=L[0];temp[13]=L[1];temp[14]=L[2];temp[15]=L[5];
					temp[16]=L[8];temp[17]=L[7];temp[18]=L[6];temp[19]=L[3];
					
					T[6]=temp[0];T[3]=temp[1];T[0]=temp[2];
					B[2]=temp[3];B[5]=temp[4];B[8]=temp[5];
					S[6]=temp[6];S[3]=temp[7];S[0]=temp[8];
					F[6]=temp[9];F[3]=temp[10];F[0]=temp[11];
					L[6]=temp[12];L[3]=temp[13];L[0]=temp[14];L[1]=temp[15];
					L[2]=temp[16];L[5]=temp[17];L[8]=temp[18];L[7]=temp[19];
					
					temp[0]=F[0];temp[1]=F[1];temp[2]=F[2];
					temp[3]=R[0];temp[4]=R[1];temp[5]=R[2];
					temp[6]=B[0];temp[7]=B[1];temp[8]=B[2];
					temp[9]=L[0];temp[10]=L[1];temp[11]=L[2];
		            temp[12]=T[0];temp[13]=T[1];temp[14]=T[2];temp[15]=T[5];
					temp[16]=T[8];temp[17]=T[7];temp[18]=T[6];temp[19]=T[3];
					
					R[0]=temp[0];R[1]=temp[1];R[2]=temp[2];
					B[0]=temp[3];B[1]=temp[4];B[2]=temp[5];
					L[0]=temp[6];L[1]=temp[7];L[2]=temp[8];
					F[0]=temp[9];F[1]=temp[10];F[2]=temp[11];
					T[6]=temp[12];T[3]=temp[13];T[0]=temp[14];T[1]=temp[15];
					T[2]=temp[16];T[5]=temp[17];T[8]=temp[18];T[7]=temp[19];
					
					temp[0]=F[6];temp[1]=F[3];temp[2]=F[0];
					temp[3]=T[6];temp[4]=T[3];temp[5]=T[0];
					temp[6]=B[2];temp[7]=B[5];temp[8]=B[8];
					temp[9]=S[6];temp[10]=S[3];temp[11]=S[0];
		            temp[12]=L[0];temp[13]=L[1];temp[14]=L[2];temp[15]=L[5];
					temp[16]=L[8];temp[17]=L[7];temp[18]=L[6];temp[19]=L[3];
					
					S[6]=temp[0];S[3]=temp[1];S[0]=temp[2];
					F[6]=temp[3];F[3]=temp[4];F[0]=temp[5];
					T[6]=temp[6];T[3]=temp[7];T[0]=temp[8];
					B[2]=temp[9];B[5]=temp[10];B[8]=temp[11];
					L[2]=temp[12];L[5]=temp[13];L[8]=temp[14];L[7]=temp[15];
					L[6]=temp[16];L[3]=temp[17];L[0]=temp[18];L[1]=temp[19];
					
					temp[0]=F[0];temp[1]=F[1];temp[2]=F[2];
					temp[3]=R[0];temp[4]=R[1];temp[5]=R[2];
					temp[6]=B[0];temp[7]=B[1];temp[8]=B[2];
					temp[9]=L[0];temp[10]=L[1];temp[11]=L[2];
		            temp[12]=T[0];temp[13]=T[1];temp[14]=T[2];temp[15]=T[5];
					temp[16]=T[8];temp[17]=T[7];temp[18]=T[6];temp[19]=T[3];
					
					L[0]=temp[0];L[1]=temp[1];L[2]=temp[2];
					F[0]=temp[3];F[1]=temp[4];F[2]=temp[5];
					R[0]=temp[6];R[1]=temp[7];R[2]=temp[8];
					B[0]=temp[9];B[1]=temp[10];B[2]=temp[11];
					T[2]=temp[12];T[5]=temp[13];T[8]=temp[14];T[7]=temp[15];
					T[6]=temp[16];T[3]=temp[17];T[0]=temp[18];T[1]=temp[19];
		 	    }
		 	    
		 	    
		 	}
			 		 	
		 	 void color(const char c)const{
		 		
		 		switch(c) {				    
					case 'W':
				    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				    	break;
				    
				    case 'G':
				    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				    	break;
				    
				    case 'O':
				    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				    	break;
				    	          		
           			case 'B':
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
						break;
				    	
				    case 'R':
				    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				    	break;
				    	
				    case 'Y':
				    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				    	break;    
        		}
			 }
			 			 
			  /*This function shuffles the cube randomly*/
			 void Shuffle(){
			 	int count=0;
			 	do{
			 		int i;
			 		i=rand()%16+1;
			 		switch(i){			 			
			 			case 1:
			 				Move("RCW");
			 				count++;
			 				break;
			 			case 2:
			 				Move("RCCW");
			 				count++;
			 				break;
			 			case 3:
			 				Move("CCW");
			 				count++;
			 				break;
			 			case 4:
			 				Move("CCCW");
			 				count++;
			 				break;
			 			case 5:
			 				Move("LCW");
			 				count++;
			 				break;
			 			case 6:
			 				Move("LCCW");
			 				count++;
			 				break;
			 			case 7:
			 				Move("BCW");
			 				count++;
			 				break;
			 			case 8:
			 				Move("BCCW");
			 				count++;
			 				break;
			 			case 9:
			 				Move("MCW");
			 				count++;
			 				break;
			 			case 10:
			 				Move("MCCW");
			 				count++;
			 				break;
			 			case 11:
			 				Move("TCW");
			 				count++;
			 				break;
			 			case 12:
			 				Move("TCCW");
			 				count++;
			 				break;
			 			case 13:
			 				Move("FlipU");
			 				count++;
			 				break;
			 			case 14:
			 				Move("FlipD");
			 				count++;
			 				break;
			 			case 15:
			 				Move("FlipR");
			 				count++;
			 				break;
			 			case 16:
			 				Move("FlipL");
			 				count++;
			 				break;			 			
					 }
				 }while(count<30);
			}
			
			istream& operator=(const Cube& c){
				for(int i=0;i<9;i++){
					this->Setcol('F',i, c.Getcol('F',i));
					this->Setcol('B',i, c.Getcol('B',i));
					this->Setcol('L',i, c.Getcol('L',i));
					this->Setcol('T',i, c.Getcol('T',i));
					this->Setcol('S',i, c.Getcol('S',i));
					this->Setcol('R',i, c.Getcol('R',i));
				}
			}
};

ostream& operator<<(ostream& out, const Cube& c){
	
	char x;
	const char y=254;
	
	cout<<"\nFRONT   RIGHT   BACK    LEFT    TOP    BOT\n";
    c.color(c.Getcol('F',0));
    out<<y<<" ";
	c.color(c.Getcol('F',1));
    out<<y<<" ";	
	c.color(c.Getcol('F',2));
    out<<y<<"   ";	
	c.color(c.Getcol('R',0));
    out<<y<<" ";
	c.color(c.Getcol('R',1));
    out<<y<<" ";	
	c.color(c.Getcol('R',2));
    out<<y<<"   ";
    c.color(c.Getcol('B',0));
    out<<y<<" ";
	c.color(c.Getcol('B',1));
    out<<y<<" ";	
	c.color(c.Getcol('B',2));
    out<<y<<"   ";
    c.color(c.Getcol('L',0));
    out<<y<<" ";
    c.color(c.Getcol('L',1));
    out<<y<<" ";
    c.color(c.Getcol('L',2));
    out<<y<<"   ";
	c.color(c.Getcol('T',0));
    out<<y<<" ";
	c.color(c.Getcol('T',1));
    out<<y<<" ";	
	c.color(c.Getcol('T',2));
    out<<y<<"  ";	
	c.color(c.Getcol('S',0));
    out<<y<<" ";
	c.color(c.Getcol('S',1));
    out<<y<<" ";	
	c.color(c.Getcol('S',2));
    out<<y<<" ";
    
	out<<"\n";
	
	c.color(c.Getcol('F',3));
    out<<y<<" ";
	c.color(c.Getcol('F',4));
    out<<y<<" ";	
	c.color(c.Getcol('F',5));
    out<<y<<"   ";	
	c.color(c.Getcol('R',3));
    out<<y<<" ";
	c.color(c.Getcol('R',4));
    out<<y<<" ";	
	c.color(c.Getcol('R',5));
    out<<y<<"   ";
    c.color(c.Getcol('B',3));
    out<<y<<" ";
	c.color(c.Getcol('B',4));
    out<<y<<" ";	
	c.color(c.Getcol('B',5));
    out<<y<<"   ";
    c.color(c.Getcol('L',3));
    out<<y<<" ";
    c.color(c.Getcol('L',4));
    out<<y<<" ";
    c.color(c.Getcol('L',5));
    out<<y<<"   ";
	c.color(c.Getcol('T',3));
    out<<y<<" ";
	c.color(c.Getcol('T',4));
    out<<y<<" ";	
	c.color(c.Getcol('T',5));
    out<<y<<"  ";	
	c.color(c.Getcol('S',3));
    out<<y<<" ";
	c.color(c.Getcol('S',4));
    out<<y<<" ";	
	c.color(c.Getcol('S',5));
    out<<y<<" ";
   	
	out<<"\n";
	
	c.color(c.Getcol('F',6));
    out<<y<<" ";
	c.color(c.Getcol('F',7));
    out<<y<<" ";	
	c.color(c.Getcol('F',8));
    out<<y<<"   ";	
	c.color(c.Getcol('R',6));
    out<<y<<" ";
	c.color(c.Getcol('R',7));
    out<<y<<" ";	
	c.color(c.Getcol('R',8));
    out<<y<<"   ";
    c.color(c.Getcol('B',6));
    out<<y<<" ";
	c.color(c.Getcol('B',7));
    out<<y<<" ";	
	c.color(c.Getcol('B',8));
    out<<y<<"   ";
    c.color(c.Getcol('L',6));
    out<<y<<" ";
    c.color(c.Getcol('L',7));
    out<<y<<" ";
    c.color(c.Getcol('L',8));
    out<<y<<"   ";
	c.color(c.Getcol('T',6));
    out<<y<<" ";
	c.color(c.Getcol('T',7));
    out<<y<<" ";	
	c.color(c.Getcol('T',8));
    out<<y<<"  ";	
	c.color(c.Getcol('S',6));
    out<<y<<" ";
	c.color(c.Getcol('S',7));
    out<<y<<" ";	
	c.color(c.Getcol('S',8));
    out<<y<<" ";
    out<<"\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
istream& operator>>(istream& is, Cube& d){
	
	int count=0;
	char a;
	
	do{
		cin>>a;
		while(a!='W'&& a!='Y'&& a!='R'&& a!='B'&& a!='G'&& a!='O'){	
			cout<<"Please, type a valid letter!\nOrange: O, Green: G, White: W, Red: R, Blue: B,Yellow: Y"<<endl;
			cin >> a;
		}
		d.Setcol('F',count,a);
		count++;
	}while(count<9);
	count=0;
	cout<<"Turn the cube right and insert colors:"<<endl;
	do{
		cin>>a;
		while(a!='W'&& a!='Y'&& a!='R'&& a!='B'&& a!='G'&& a!='O'){	
			cout<<"Please, type a valid letter!\nOrange: O, Green: G, White: W, Red: R, Blue: B,Yellow: Y"<<endl;
			cin >> a;
		}
		d.Setcol('R',count,a);
		count++;
	}while(count<9);
	count=0;
	cout<<"Turn the cube right and insert colors:"<<endl;
	do{
		cin>>a;
		while(a!='W'&& a!='Y'&& a!='R'&& a!='B'&& a!='G'&& a!='O'){	
			cout<<"Please, type a valid letter!\nOrange: O, Green: G, White: W, Red: R, Blue: B,Yellow: Y"<<endl;
			cin >> a;
		}
		d.Setcol('B',count,a);
		count++;
	}while(count<9);
	count=0;
	cout<<"Turn the cube right and insert colors:"<<endl;
	do{
		cin>>a;
	while(a!='W'&& a!='Y'&& a!='R'&& a!='B'&& a!='G'&& a!='O'){	
			cout<<"Please, type a valid letter!\nOrange: O, Green: G, White: W, Red: R, Blue: B,Yellow: Y"<<endl;
			cin >> a;
		}
		d.Setcol('L',count,a);
		count++;
	}while(count<9);
	count=0;
	cout<<"Turn the cube right and then up and insert colors:"<<endl;
	do{
		cin>>a;
		while(a!='W'&& a!='Y'&& a!='R'&& a!='B'&& a!='G'&& a!='O'){	
			cout<<"Please, type a valid letter!\nOrange: O, Green: G, White: W, Red: R, Blue: B,Yellow: Y"<<endl;
			cin >> a;
		}
		d.Setcol('T',count,a);
		count++;
	}while(count<9);
	count=0;
	cout<<"Turn the cube down twice and insert colors:"<<endl;
	do{
		cin>>a;
		while(a!='W'&& a!='Y'&& a!='R'&& a!='B'&& a!='G'&& a!='O'){	
			cout<<"Please, type a valid letter!\nOrange: O, Green: G, White: W, Red: R, Blue: B,Yellow: Y"<<endl;
			cin >> a;
		}
		d.Setcol('S',count,a);
		count++;
	}while(count<9);
}

	
class Solver{
 	
	private:
		
		vector<string>moves;
		vector<Cube>phases;
		vector<int>np;
		
		
	public:
		
	Solver(){}
	
	const Cube Getphase(const int a){return phases[a];}
	const int Getnp(const int a){return np[a];}
	
	inline const int Getmovesn()const{return moves.size();}
	
	inline const string Getmove(const int a)const{return moves[a];}
	
	void ClearMoves(){moves.clear();}
	
	const bool Solve(Cube &c1){
		
		np.clear();
		phases.clear();
		
		{
		char x;	
		int count=0;
		moves.clear();
		
		/*Rotates faces till it finds the one with yellow center*/
		bool ok=false;
		bool ok2=false;
		bool ok3=false;
		bool ok4=false;
		
		do{
				if(count>20)return false;
				x=c1.Getcol('F',4);
				if(x!='Y'){
					c1.Move("FlipR");
					moves.push_back("FlipR");
					x=c1.Getcol('F',4);
					if(x!='Y'){
						c1.Move("FlipU");
						moves.push_back("FlipU");
						x=c1.Getcol('F',4);
					}
				}
				count++;
		}while(x!='Y');
		
		count=0;
		do{
			
			if(ok3==true){
				if(c1.Getcol('R',5)=='W'){
					c1.Move("RCW");
					moves.push_back("RCW");
					c1.Move("BCW");
					moves.push_back("BCW");
					c1.Move("RCCW");
					moves.push_back("RCCW");
					ok4=true;
				}
				else if(c1.Getcol('L',3)=='W'){
					c1.Move("LCCW");
					moves.push_back("LCCW");
					c1.Move("BCCW");
					moves.push_back("BCCW");
					c1.Move("LCW");
					moves.push_back("LCW");
					ok4=true;
				}
				else if(c1.Getcol('S',7)=='W'){
					c1.Move("BLCCW");
					moves.push_back("BLCCW");
					c1.Move("RCW");
					moves.push_back("RCW");
					c1.Move("BCW");
					moves.push_back("BCW");
					c1.Move("RCCW");
					moves.push_back("RCCW");
					ok4=true;
				}
				else if(c1.Getcol('T',1)=='W'){
					c1.Move("BLCW");
					moves.push_back("BLCW");
					c1.Move("RCW");
					moves.push_back("RCW");
					c1.Move("BCW");
					moves.push_back("BCW");
					c1.Move("RCCW");
					moves.push_back("RCCW");
					ok4=true;
				}
				else if(c1.Getcol('L',1)=='W'){
					c1.Move("LCCW");
					moves.push_back("LCCW");
					c1.Move("LCCW");
					moves.push_back("LCCW");
					c1.Move("BCCW");
					moves.push_back("BCCW");
					c1.Move("LCCW");
					moves.push_back("LCCW");
					c1.Move("LCCW");
					moves.push_back("LCCW");
					ok4=true;
				}	
				else if(c1.Getcol('R',1)=='W'){
					c1.Move("RCCW");
					moves.push_back("RCCW");
					c1.Move("RCCW");
					moves.push_back("RCCW");
					c1.Move("BCW");
					moves.push_back("BCW");
					c1.Move("RCCW");
					moves.push_back("RCCW");
					c1.Move("RCCW");
					moves.push_back("RCCW");
					ok4=true;
				}
			}
			
			if(ok4!=true){
				
				if(c1.Getcol('F',7)=='W'){}
				else if(c1.Getcol('R',7)=='W'){
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('L',7)=='W'){
					c1.Move("BCCW");
					moves.push_back("BCCW");
				}
				else if(c1.Getcol('B',7)=='W'){
					c1.Move("BCW");
					moves.push_back("BCW");
					c1.Move("BCW");
					moves.push_back("BCW");					
				}
				else if(c1.Getcol('R',3)=='W'){
					c1.Move("RCCW");
					moves.push_back("RCCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('R',5)=='W'){
					c1.Move("RCW");
					moves.push_back("RCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('T',5)=='W'){
					c1.Move("MLCW");
					moves.push_back("MLCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('T',3)=='W'){
					c1.Move("MLCCW");
					moves.push_back("MLCCW");
					c1.Move("BCCW");
					moves.push_back("BCCW");
				}
				else if(c1.Getcol('S',5)=='W'){
					c1.Move("MLCW");
					moves.push_back("MLCW");
					c1.Move("BCCW");
					moves.push_back("BCCW");
				}
				else if(c1.Getcol('S',3)=='W'){
					c1.Move("MLCCW");
					moves.push_back("MLCCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('R',1)=='W'){
					c1.Move("RCCW");
					moves.push_back("RCCW");
					c1.Move("RCCW");
					moves.push_back("RCCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('S',1)=='W'){
					c1.Move("BCCW");
					moves.push_back("BCCW");
					c1.Move("MLCW");
					moves.push_back("MLCW");
					c1.Move("BCCW");
					moves.push_back("BCCW");
				}
				else if(c1.Getcol('T',1)=='W'){
					c1.Move("BLCW");
					moves.push_back("BLCW");
					c1.Move("RCW");
					moves.push_back("RCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('L',1)=='W'){
					c1.Move("MLCW");
					moves.push_back("MLCW");
					c1.Move("MLCW");
					moves.push_back("MLCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('B',3)=='W'){
					c1.Move("BLCW");
					moves.push_back("BLCW");
					c1.Move("BCW");
					moves.push_back("BCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('B',5)=='W'){
					c1.Move("BLCCW");
					moves.push_back("BLCCW");
					c1.Move("BCW");
					moves.push_back("BCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('S',7)=='W'){
					c1.Move("BLCCW");
					moves.push_back("BLCCW");
					c1.Move("RCW");
					moves.push_back("RCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('L',3)=='W'){
					c1.Move("BLCW");
					moves.push_back("BLCW");
					c1.Move("BLCW");
					moves.push_back("BLCW");
					c1.Move("RCW");
					moves.push_back("RCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
				else if(c1.Getcol('B',1)=='W'){
					c1.Move("BLCW");
					moves.push_back("BLCW");
					c1.Move("BLCW");
					moves.push_back("BLCW");
					c1.Move("BCW");
					moves.push_back("BCW");
					c1.Move("BCW");
					moves.push_back("BCW");
				}
			}
			
			if(ok3==true)ok4=true;
			if(ok2==true)ok3=true;
			if(ok==true)ok2=true;
			ok=true;
			
			if(ok4!=true){
				c1.Move("Rotate");
				moves.push_back("Rotate");
			}
			
			count++;
			
		}while(ok4!=true);
		
		if(c1.Getcol('F',1)!='W' || c1.Getcol('F',3)!='W' || c1.Getcol('F',5)!='W' || c1.Getcol('F',7)!='W'){
			cout<<c1;
			return false;
		}
		/*Daisy phase completed*/
		c1.Move("FlipU");
		moves.push_back("FlipU");
		
		{
			
		char y;
		int count=0;
		int count2=0;
		
		/*This is the transition from  completing "Daisy" phase to solving the "white cross", that will be positioned in the bottom face*/
		do{		
			do{	
				if(count2>100)return false;					
				x=c1.Getcol('F',1);
				y=c1.Getcol('F',4);				
				if(x!=y){
					c1.Move("BCW");
					c1.Move("MCW");
					moves.push_back("BCW");
					moves.push_back("MCW");
					count2++;
				}
			}while(x!=y);			
			c1.Move("FLCW");
			c1.Move("FLCW");
			c1.Move("TCW");
			moves.push_back("FLCW");
			moves.push_back("FLCW");
			moves.push_back("TCW");
			count++;
		}while(count<4);
		
		}/*Destroys x*/
		}/*Destroys y, count and count2*/
		
		np.push_back(moves.size());
		phases.push_back(c1);
		
   		/*Here starts the second face where bottom layer corner are positioned.*/
		{
		/*loop spy variable*/	
		int count=0;
		/*this bool represent a correct cuby positioning*/
		bool ok=false;
		bool ok2=false;
		bool ok3=false;
		bool ok4=false;
		
		do{	
			if(count>50){return false;}
			/*Checks if bottom right cuby is already positioned*/
			if(c1.Getcol('F',8)==c1.Getcol('F',4) || c1.Getcol('R',6)==c1.Getcol('F',4) || c1.Getcol('S',2)==c1.Getcol('F',4)){
				if(c1.Getcol('F',8)==c1.Getcol('R',4) || c1.Getcol('R',6)==c1.Getcol('R',4) || c1.Getcol('S',2)==c1.Getcol('R',4)){						
				    if(c1.Getcol('F',8)=='W' || c1.Getcol('R',6)=='W' || c1.Getcol('S',2)=='W' ){
				    	if(c1.Getcol('F',8)==c1.Getcol('F',4) && c1.Getcol('R',6)==c1.Getcol('R',4) && c1.Getcol('S',2)=='W'){
				    		if(ok3==true)ok4=true;
				    		if(ok2==true)ok3=true;
							if(ok==true)ok2=true;
							ok=true;
							count=0;
			    			if(ok4!=true){
								c1.Move("FlipL");
					    		moves.push_back("FlipL");
					    	}
						}
						else{ /*if it is in wright position but twisted*/
							do{
					    		c1.Move("RALG");
							    moves.push_back("RALG");
							}while(c1.Getcol('F',8)!=c1.Getcol('F',4) || c1.Getcol('R',6)!=c1.Getcol('R',4) || c1.Getcol('S',2)!='W');
							if(ok3==true)ok4=true;
				    		if(ok2==true)ok3=true;
							if(ok==true)ok2=true;
							ok=true;
							count=0;
							if(ok4!=true){
								c1.Move("FlipL");
					    		moves.push_back("FlipL");
					    	}	
						}
					}
				}
			}
			/*checks if top cuby is the wright one*/
			if(c1.Getcol('F',2)==c1.Getcol('F',4) || c1.Getcol('T',8)==c1.Getcol('F',4) || c1.Getcol('R',0)==c1.Getcol('F',4) ){
				if(c1.Getcol('F',2)==c1.Getcol('R',4) || c1.Getcol('T',8)==c1.Getcol('R',4) || c1.Getcol('R',0)==c1.Getcol('R',4)){						
				   if(c1.Getcol('F',2)=='W' || c1.Getcol('T',8)=='W' || c1.Getcol('R',0)=='W' ){
				    	
							do{
					    		c1.Move("RALG");
							    moves.push_back("RALG");
							}while(c1.Getcol('F',8)!=c1.Getcol('F',4) || c1.Getcol('R',6)!=c1.Getcol('R',4) || c1.Getcol('S',2)!='W');
							if(ok3==true)ok4=true;
				    		if(ok2==true)ok3=true;
							if(ok==true)ok2=true;
							ok=true;
							count=0;
							if(ok4!=true){ /*when a cuby is positioned, except when all are ok, turns the cube left*/
								c1.Move("FlipL");
					    		moves.push_back("FlipL");
					    	}
					    
						}	
					}
			}
			
			/* this is needed to take all bottom corners on top to check them all*/
			if(count==4 && ok!=true){
				
	   				c1.Move("FlipL");
			   		moves.push_back("FlipL");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					count++;
			}
			
			if(count==4 && ok2!=true){
					
	   				c1.Move("FlipL");
			   		moves.push_back("FlipL");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					count++;
			}
			
			if(count==4 && ok3!=true){
				
	   				c1.Move("FlipL");
			   		moves.push_back("FlipL");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipR");
					moves.push_back("FlipR");
					count++;
			}
			
			if(ok4!=true){
				c1.Move("TCCW");
				moves.push_back("TCCW");
				count++;
			}
			
			
	}while(ok4!=true);
		
		}/*destroys ok,2,3,4 and count*/
		
		np.push_back(moves.size()-np[0]);
		phases.push_back(c1);
		
		/*Here starts phase 3 where middle layer edges are positioned*/
		
		{
			
		int count=0;
		bool ok=false;
		bool ok2=false;
		bool ok3=false;
		bool ok4=false;
		
		do{	
			if(count>100)return false;
	    	if(c1.Getcol('F',5)==c1.Getcol('F',4) || c1.Getcol('R',3)==c1.Getcol('F',4)){
				if(c1.Getcol('F',5)==c1.Getcol('R',4) || c1.Getcol('R',3)==c1.Getcol('R',4)){						
				    if(c1.Getcol('F',5)==c1.Getcol('F',4) && c1.Getcol('R',3)==c1.Getcol('R',4)){
				    	if(ok3==true)ok4=true;
			    		if(ok2==true)ok3=true;
						if(ok==true)ok2=true;
						ok=true;
						count=0;
						if(ok4!=true){
							c1.Move("FlipL");
				    		moves.push_back("FlipL");
				    	}
					}
					else{
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FlipR");
						moves.push_back("FlipR");
						c1.Move("LALG");
						moves.push_back("LALG");
						c1.Move("FlipL");
						moves.push_back("FlipL");
						c1.Move("TCW");
						moves.push_back("TCW");
						c1.Move("TCW");
						moves.push_back("TCW");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FlipR");
						moves.push_back("FlipR");
						c1.Move("LALG");
						moves.push_back("LALG");
						c1.Move("FlipL");
						moves.push_back("FlipL");
						if(ok3==true)ok4=true;
			    		if(ok2==true)ok3=true;
						if(ok==true)ok2=true;
						ok=true;
						count=0;
						if(ok4!=true){
							c1.Move("FlipL");
				    		moves.push_back("FlipL");
				    	}	
					}
				}
			}
			
			if(c1.Getcol('F',1)==c1.Getcol('F',4) || c1.Getcol('T',7)==c1.Getcol('F',4)){
				if(c1.Getcol('F',1)==c1.Getcol('R',4) || c1.Getcol('T',7)==c1.Getcol('R',4)){						
				   	c1.Move("TCW");
					moves.push_back("TCW");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipR");
					moves.push_back("FlipR");
					c1.Move("LALG");
					moves.push_back("LALG");
					c1.Move("FlipL");
					moves.push_back("FlipL");
						
				}
			}
				
			 			
			if(count==3 && ok!=true){
				c1.Move("FlipL");
				moves.push_back("FlipL");
				for(int i=0;i<3;i++){
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FlipR");
						moves.push_back("FlipR");
						c1.Move("LALG");
						moves.push_back("LALG");
						c1.Move("FlipL");
						moves.push_back("FlipL");
						c1.Move("FlipL");
						moves.push_back("FlipL");
					}
					count++;
			}
			
			if(count==3 && ok2!=true){
				c1.Move("FlipL");
				moves.push_back("FlipL");
				c1.Move("RALG");
				moves.push_back("RALG");
				c1.Move("FlipR");
				moves.push_back("FlipR");
				c1.Move("LALG");
				moves.push_back("LALG");
				c1.Move("FlipL");
				moves.push_back("FlipL");
				c1.Move("FlipL");
				moves.push_back("FlipL");
				c1.Move("RALG");
				moves.push_back("RALG");
				c1.Move("FlipR");
				moves.push_back("FlipR");
				c1.Move("LALG");
				moves.push_back("LALG");
				c1.Move("FlipL");
				moves.push_back("FlipL");
				c1.Move("FlipL");
				moves.push_back("FlipL");
				c1.Move("FlipL");
				moves.push_back("FlipL");
				count++;
			}
			
			if(count==3 && ok3!=true){
				c1.Move("FlipL");
				moves.push_back("FlipL");
				c1.Move("RALG");
				moves.push_back("RALG");
				c1.Move("FlipR");
				moves.push_back("FlipR");
				c1.Move("LALG");
				moves.push_back("LALG");
				count++;
			}
			
			if(ok4!=true){
				c1.Move("TCCW");
				moves.push_back("TCCW");
	   			count++;
	   		}	
			  					
		}while(ok4!=true);
				
	    }/*destroys ok1,2,3,4*/
	
		np.push_back(moves.size()-np[0]-np[1]);
		phases.push_back(c1);
		
		/*Checks if top yellow cross is already done*/
		if(c1.Getcol('T',1)=='Y' && c1.Getcol('T',3)=='Y' && c1.Getcol('T',4)=='Y' && c1.Getcol('T',5)=='Y' && c1.Getcol('T',7)=='Y'){}
		else{
			
			if((c1.Getcol('T',3)=='Y' && c1.Getcol('T',4)=='Y' && c1.Getcol('T',5)=='Y')){
				c1.Move("FLCW");
				moves.push_back("FLCW");
				c1.Move("RALG");
				moves.push_back("RALG");
				c1.Move("FLCCW");
				moves.push_back("FLCCW");
			}
			
			else{
				
				c1.Move("FlipR");
				moves.push_back("FlipR");
				
				if(c1.Getcol('T',3)=='Y' && c1.Getcol('T',4)=='Y' && c1.Getcol('T',5)=='Y'){
					c1.Move("FLCW");
					moves.push_back("FLCW");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FLCCW");
					moves.push_back("FLCCW");
				}
				else{
					
					if(c1.Getcol('T',4)=='Y' && c1.Getcol('T',5)=='Y' && c1.Getcol('T',7)=='Y'){
						
						c1.Move("FLCW");
						moves.push_back("FLCW");
						c1.Move("MLCW");
						moves.push_back("MLCW");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FLCCW");
						moves.push_back("FLCCW");
						c1.Move("MLCCW");
						moves.push_back("MLCCW");
							
					}
					
					else if(c1.Getcol('T',3)=='Y' && c1.Getcol('T',4)=='Y' && c1.Getcol('T',7)=='Y'){
						c1.Move("FlipL");
						moves.push_back("FlipL");
						c1.Move("FLCW");
						moves.push_back("FLCW");
						c1.Move("MLCW");
						moves.push_back("MLCW");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FLCCW");
						moves.push_back("FLCCW");
						c1.Move("MLCCW");
						moves.push_back("MLCCW");
						
					}
					
					else if(c1.Getcol('T',1)=='Y' && c1.Getcol('T',3)=='Y' && c1.Getcol('T',4)=='Y'){
						c1.Move("FlipL");
						moves.push_back("FlipL");
						c1.Move("FlipL");
						moves.push_back("FlipL");
						c1.Move("FLCW");
						moves.push_back("FLCW");
						c1.Move("MLCW");
						moves.push_back("MLCW");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FLCCW");
						moves.push_back("FLCCW");
						c1.Move("MLCCW");
						moves.push_back("MLCCW");
						
					}
					
					else if(c1.Getcol('T',1)=='Y' && c1.Getcol('T',4)=='Y' && c1.Getcol('T',5)=='Y'){
						
						c1.Move("FlipR");
						moves.push_back("FlipR");
						c1.Move("FLCW");
						moves.push_back("FLCW");
						c1.Move("MLCW");
						moves.push_back("MLCW");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FLCCW");
						moves.push_back("FLCCW");
						c1.Move("MLCCW");
						moves.push_back("MLCCW");
						
					}
					
					else{
						c1.Move("FLCW");
						moves.push_back("FLCW");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FLCCW");
						moves.push_back("FLCCW");
						c1.Move("FLCW");
						moves.push_back("FLCW");
						c1.Move("MLCW");
						moves.push_back("MLCW");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FLCCW");
						moves.push_back("FLCCW");
						c1.Move("MLCCW");
						moves.push_back("MLCCW");
					}
				}
				
			}
		}
		
		/*Here starts the fourth phase where top layer corner are postioned*/
		
		while((c1.Getcol('F',2)!=c1.Getcol('F',4) && c1.Getcol('R',0)!=c1.Getcol('F',4) && c1.Getcol('T',8)!=c1.Getcol('F',4))
		    || (c1.Getcol('F',2)!=c1.Getcol('R',4) && c1.Getcol('R',0)!=c1.Getcol('R',4) && c1.Getcol('T',8)!=c1.Getcol('R',4))){
				c1.Move("TCW");
				moves.push_back("TCW");
		}
		
		c1.Move("FlipL");
		moves.push_back("FlipL");
		
		if((c1.Getcol('F',2)==c1.Getcol('F',4) || c1.Getcol('R',0)==c1.Getcol('F',4) || c1.Getcol('T',8)==c1.Getcol('F',4))
		    && (c1.Getcol('F',2)==c1.Getcol('R',4) ||c1.Getcol('R',0)==c1.Getcol('R',4) || c1.Getcol('T',8)==c1.Getcol('R',4))){
		    	
		    		c1.Move("FlipL");
					moves.push_back("FlipL");
					
					if((c1.Getcol('F',2)==c1.Getcol('F',4) || c1.Getcol('R',0)==c1.Getcol('F',4) || c1.Getcol('T',8)==c1.Getcol('F',4))
		   				 && (c1.Getcol('F',2)==c1.Getcol('R',4) || c1.Getcol('R',0)==c1.Getcol('R',4) || c1.Getcol('T',8)==c1.Getcol('R',4))){}
		   			else{
		   					c1.Move("FlipL");
							moves.push_back("FlipL");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("FlipR");
							moves.push_back("FlipR");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("TCCW");
							moves.push_back("TCCW");
					   }
			}
		else{
			
				c1.Move("TCCW");
				moves.push_back("TCCW");
				
				if((c1.Getcol('F',2)==c1.Getcol('F',4) || c1.Getcol('R',0)==c1.Getcol('F',4) || c1.Getcol('T',8)==c1.Getcol('F',4))
		    		&& (c1.Getcol('F',2)==c1.Getcol('R',4) || c1.Getcol('R',0)==c1.Getcol('R',4) || c1.Getcol('T',8)==c1.Getcol('R',4))){
		   			 	
		   			 		c1.Move("TCW");
							moves.push_back("TCW");
							c1.Move("FlipL");
							moves.push_back("FlipL");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("FlipR");
							moves.push_back("FlipR");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("TCCW");
							moves.push_back("TCCW");
							c1.Move("FlipL");
							moves.push_back("FlipL");
						
						if((c1.Getcol('F',2)==c1.Getcol('F',4) || c1.Getcol('R',0)==c1.Getcol('F',4) || c1.Getcol('T',8)==c1.Getcol('F',4))
		   				 && (c1.Getcol('F',2)==c1.Getcol('R',4) || c1.Getcol('R',0)==c1.Getcol('R',4) || c1.Getcol('T',8)==c1.Getcol('R',4))){}
						else{
							
							c1.Move("FlipL");
							moves.push_back("FlipL");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("RALG");
							moves.push_back("RALG");
							c1.Move("FlipR");
							moves.push_back("FlipR");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("LALG");
							moves.push_back("LALG");
							c1.Move("TCCW");
							moves.push_back("TCCW");
						}
				}	
				else{
					
					c1.Move("FlipL");
					moves.push_back("FlipL");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					c1.Move("TCW");
					moves.push_back("TCW");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipR");
					moves.push_back("FlipR");
					c1.Move("LALG");
					moves.push_back("LALG");
					c1.Move("LALG");
					moves.push_back("LALG");
					c1.Move("LALG");
					moves.push_back("LALG");
					c1.Move("TCCW");
					moves.push_back("TCCW");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("RALG");
					moves.push_back("RALG");
					c1.Move("FlipR");
					moves.push_back("FlipR");
					c1.Move("LALG");
					moves.push_back("LALG");
					c1.Move("LALG");
					moves.push_back("LALG");
					c1.Move("LALG");
					moves.push_back("LALG");
					c1.Move("TCCW");
					moves.push_back("TCCW");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					c1.Move("FlipL");
					moves.push_back("FlipL");
					
					if((c1.Getcol('F',2)==c1.Getcol('F',4) || c1.Getcol('R',0)==c1.Getcol('F',4) || c1.Getcol('T',8)==c1.Getcol('F',4))
		    		 && (c1.Getcol('F',2)==c1.Getcol('R',4) || c1.Getcol('R',0)==c1.Getcol('R',4) || c1.Getcol('T',8)==c1.Getcol('R',4))){}
					else{
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("FlipR");
						moves.push_back("FlipL");
						c1.Move("LALG");
						moves.push_back("LALG");
						c1.Move("LALG");
						moves.push_back("LALG");
						c1.Move("LALG");
						moves.push_back("LALG");
						c1.Move("TCCW");
						moves.push_back("TCCW");
					}
					
				}
			
		}  
		
		np.push_back(moves.size()-np[0]-np[1]-np[2]);
		phases.push_back(c1);
		
		/*Here starts phase 5 where last layer is completed*/
		
		c1.Move("FlipD");
		moves.push_back("FlipD");
		c1.Move("FlipD");
		moves.push_back("FlipD");
		
		int count=0;
		int count2;
		bool ok=false;
		
		do{
			count2=0;
			
			while((c1.Getcol('R',6)!='Y' && (c1.Getcol('F',8)!='Y')) && (count2<4)){
				c1.Move("BCW");
				moves.push_back("BCW");
				count2++;
				if(count2>4) ok=true;
			}
			
			count2=0;	
			
			if(ok!=true){
				c1.Move("RALG");
				moves.push_back("RALG");
				c1.Move("RALG");
				moves.push_back("RALG");
				c1.Move("BCW");
				moves.push_back("BCW");
					
				while((c1.Getcol('R',6)!='Y' && (c1.Getcol('F',8)!='Y')) && (count2<4)){
					c1.Move("BCW");
					moves.push_back("BCW");
					count2++;
				}
				
				if(count2<4){
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("BCW");
						moves.push_back("BCW");	
					}
				
				else{
						c1.Move("BCW");
						moves.push_back("BCW");	
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("RALG");
						moves.push_back("RALG");
						c1.Move("RALG");
						moves.push_back("RALG");
					}
				}
				
			if(c1.Getcol('F',6)!='Y' && c1.Getcol('F',7)!='Y' && c1.Getcol('F',8)!='Y'&& c1.Getcol('R',6)!='Y'&& c1.Getcol('R',7)!='Y'&& c1.Getcol('R',8)!='Y'&&
				c1.Getcol('B',6)!='Y'&& c1.Getcol('B',7)!='Y' && c1.Getcol('B',8)!='Y'&& c1.Getcol('L',6)!='Y'&& c1.Getcol('L',7)!='Y'&& c1.Getcol('L',9)!='Y') ok=true;
		}while(ok!=true);
	
		c1.Move("FlipU");
		moves.push_back("FlipU");
		c1.Move("FlipU");
		moves.push_back("FlipU");
		
		
			
		while((c1.Getcol('F',0)!=c1.Getcol('F',4) && c1.Getcol('F',2)!=c1.Getcol('F',4))){
			c1.Move("TCW");
			moves.push_back("TCW");
		}
		/*Controls if the cube is already solved*/
		while(c1.Getcol('F',1)!=c1.Getcol('F',4) || c1.Getcol('R',1)!=c1.Getcol('R',4) || c1.Getcol('B',1)!=c1.Getcol('B',4) || c1.Getcol('L',1)!=c1.Getcol('L',4)){
				
				count=0;
				
				while(((c1.Getcol('F',0)!=c1.Getcol('F',4) || c1.Getcol('F',1)!=c1.Getcol('F',4) || c1.Getcol('F',2)!=c1.Getcol('F',4)) && count<3)){
					c1.Move("FlipR");
					moves.push_back("FlipR");
					count++;
				}
				
				c1.Move("RALG");
				moves.push_back("RALG");
				c1.Move("LALG");
				moves.push_back("LALG");
				for(int i=0;i<5;i++){
					c1.Move("RALG");
					moves.push_back("RALG");
				}
				for(int i=0;i<5;i++){
					c1.Move("LALG");
					moves.push_back("LALG");
				}
				
		}		
		np.push_back(moves.size()-np[0]-np[1]-np[2]-np[3]);
		phases.push_back(c1);
		return true;
	}
};

int main(){
	
		int go=false;
		bool ok=false;
		bool ok2=false;
		
        ofstream of;
		Cube c1;
		Solver s;
		Solver s2;
		Cube c2;
		
		do{
			int a;
		    int count;
			count =0;
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout<<"\n\nR";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout<<"U";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout<<"B";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout<<"I";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"K";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout<<"'S";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout<<" C";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout<<"U";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout<<"B";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout<<"E ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"S";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout<<"O";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout<<"L";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout<<"V";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout<<"E";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout<<"R\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			
			do{
				cout<<"Press 1 to generate a cube, 2 to load a cube manually, 3 to simulate some cubes resolutions."<<endl;
				cin >> a;
				
				while(cin.fail()){
				    cout << "Please, type a number from the list!"<<endl;
				    cin.clear();
				    cin.ignore(256,'\n');
				    cin >> a;
				}
			}while(a!=1 && a!=2 && a!=3);
			
			switch(a){
			
				case 1:
					
					srand(time(NULL));
					c1.Shuffle();
					cout<<c1;
					ok=false;
					break;
				
				case 2:
					bool ok2;
					
					do{
						cout<<"Insert first face colors following this order:\n\n1 2 3\n4 5 6\n7 8 9\n\nOrange: O, Green: G, White: W, Red: R, Blue: B,Yellow: Y"<<endl;
						cin>>c1;
						c2=c1;
						ok2=s.Solve(c2);
						if(ok2!=true){
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							cout<<"\nCube was not loaded properly! Please restart."<<endl;
						}
					}while(ok2!=true);
					
					cout<<c1;
					ok=false;
					break;
				
				case 3:
					
					int avg1;
		            int avg2;
		            int avg3;
		            int avg4;
		            int avg5;
		            
                    int min;
	            	int max;
	            	int timea;
	            	float timeb;
	            	float cubes;
	            	int fail=0;
	            	
	            	avg1=0;
	            	avg2=0;
	            	avg3=0;
	            	avg4=0;
	            	avg5=0;
	            	
	            	min=20000;
	            	max=0;
	            	
					cout<<"\nHow many cubes would you like to simulate?"<<endl;
					cin >> a;
					while(cin.fail()){
					    cout << "Please, type a number!"<<endl;
					    cin.clear();
					    cin.ignore(256,'\n');
					    cin >> a;
					}
					
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					cout<<"\nSimulating cubes, please wait."<<endl;
					timea=time(NULL);
					do{
                        srand(time(NULL)^2+count);
                        c1.Shuffle();
						if(s.Solve(c1)!=true){
							fail++;
						}
						
						avg1=avg1+s.Getnp(0);
						avg2=avg2+s.Getnp(1);
						avg3=avg3+s.Getnp(2);
						avg4=avg4+s.Getnp(3);
						avg5=avg5+s.Getnp(4);
						
						if(count==a/10){
							cout<<"10% completed!"<<endl;
						}
						if(count==a/5){
							cout<<"20% completed!"<<endl;
						}
						if(count==(a/10)*3){
							cout<<"30% completed!"<<endl;
						}
						if(count==(a/10)*4){
							cout<<"40% completed!"<<endl;
						}
						if(count==(a/2)){
							cout<<"50% completed!"<<endl;
						}
						if(count==(a/10)*6){
							cout<<"60% completed!"<<endl;
						}
						if(count==(a/10)*7){
							cout<<"70% completed!"<<endl;
						}
						if(count==(a/10)*8){
							cout<<"80% completed!"<<endl;
						}
						if(count==(a/10)*9){
							cout<<"90% completed!"<<endl;
						}
						if(s.Getnp(0)+s.Getnp(1)+s.Getnp(2)+s.Getnp(3)+s.Getnp(4)<min){
                           min=s.Getnp(0)+s.Getnp(1)+s.Getnp(2)+s.Getnp(3)+s.Getnp(4);
                        }
                        if(s.Getnp(0)+s.Getnp(1)+s.Getnp(2)+s.Getnp(3)+s.Getnp(4)>max){
                           max=s.Getnp(0)+s.Getnp(1)+s.Getnp(2)+s.Getnp(3)+s.Getnp(4);
                        }
                         s.ClearMoves();
						 count++;
					}while(count<a);
					
					timeb=time(NULL)-timea;
					cubes=count/timeb;
					
					avg1=avg1/a;
					avg2=avg2/a;
					avg3=avg3/a;
					avg4=avg4/a;
					avg5=avg5/a;
					
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				    cout<<"\n\n\nSTATISTICS                                                STATISTICS (on over 100 milion simulation)"<<endl;
				    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout<<"\nPhase one completed in "<<avg1<<" moves on average.               Phase one completed in 40 moves on average.\n"<<endl;
					cout<<"Phase two completed in "<<avg2<<" moves on average.               Phase two completed in 30 moves on average.\n"<<endl;
					cout<<"Phase three completed in "<<avg3<<" moves on average.             Phase three completed in 66 moves on average.\n"<<endl;
					cout<<"Phase four completed in "<<avg4<<" moves on average.              Phase four completed in 23 moves on average.\n"<<endl;
					cout<<"Last phase solved in "<<avg5<<" moves on average.                 Last phase solved in 46 moves on average.\n"<<endl;
					cout<<"Average total moves: "<<avg1+avg2+avg3+avg4+avg5<<"                                  Average total moves: 205\n"<<endl;
					cout<<"Min moves to solve the cube: "<<min<<"                          Min moves to solve the cube: 62\n"<<endl;
					cout<<"Max moves to solve the cube: "<<max<<"                          Max moves to solve the cube: 307\n"<<endl;
					if(timeb<60)cout<<"Simulation time: "<<timeb<<"seconds.\n"<<endl;
					else if(timeb>300 && timeb<3600)cout<<"Simulation time: "<<timeb/60<<"minutes.\n"<<endl;
					else if(timeb>3600)cout<<"Simulation time:"<<timeb/3600<<"hours.\n"<<endl;
					cout<<"Cubes solved per second: "<<cubes<<endl;
					cout<<"\nFailed solving: "<<fail<<endl;
					ok=true;
					break;  
			}
			
			if(ok!=true){
                    do{
                    	
        			cout<<"\nPress 1 to solve the cube manually, 2 to solve the cube automatically, 3 to go back to Main Menu."<<endl;
        			cin >> a;
        			
					while(cin.fail()){
					    cout << "Please, type a number from the list!" <<endl;
					    cin.clear();
					    cin.ignore(256,'\n');
					    cin >> a;
					}
					
        			switch(a){
        			
        				case 1:
                             
        					cout<<"\n\n\nManual cube solver\n"<<endl;
        					cout<<c1;
        					
        					do{
        						
        						cout<<"\nList of movements\n1)Right face clockwise  8)Right face counter clockwise   15)Front Layer clockwise\n2)Center face clockwise 9)Center face counter clockwise  16)Back layer clockwise\n3)Left face clockwise  10)Left face counter clockwise    17)Shuffle the cube\n4)Top layer clockwise"
                                "  11)Top layer counter clockwise    18)Reset the cube\n5)Mid layer clockwise  12)Mid layer counter clockwise    19)Go back to main menu\n6)Bot layer clockwise  13)Bot layer counter clockwise\n7)Flip the cube right  14)Flip the cube up\n"<<endl;
                                
                                cin >> a;
        						while(cin.fail()){
								    cout << "Please, type a number from the list!"<<endl;
								    cin.clear();
								    cin.ignore(256,'\n');
								    cin >> a;
								}
        						
        						switch(a){
        							
        							case 1:
        								c1.Move("RCW");
        								cout<<c1;
        								break;
        							case 2:
        								c1.Move("CCW");
        								cout<<c1;
        								break;
        							case 3:
        								c1.Move("LCW");
        								cout<<c1;
        								break;
        							case 4:
        								c1.Move("TCW");
        								cout<<c1;
        								break;
        							case 5:
        								c1.Move("MCW");
        								cout<<c1;
        								break;
        							case 6:
        								c1.Move("FlipL");
        								cout<<c1;
        								break;
        							case 7:
        								c1.Move("FlipR");
        								cout<<c1;
        								break;
        							case 8:
        								c1.Move("RCCW");
        								cout<<c1;
        								break;
        							case 9:
        								c1.Move("CCCW");
        								cout<<c1;
        								break;
        							case 10:
        								c1.Move("LCCW");
        								cout<<c1;
        								break;
        							case 11:
        								c1.Move("TCCW");
        								cout<<c1;
        								break;
        							case 12:
        								c1.Move("MCCW");
        								cout<<c1;
        								break;
        							case 13:
        								c1.Move("BCCW");
        								cout<<c1;
        								break;
        							case 14:
        								c1.Move("FlipU");
        								cout<<c1;
        								break;
        							case 15:
        								c1.Move("FLCW");
        								cout<<c1;
        								break;
        							case 16:
        								c1.Move("BLCW");
										cout<<c1;
        								break;
        							case 17:
        								c1.Shuffle();
        								cout<<c1;
        								break;
        							case 18:
        								c1.Init();
        								cout<<c1;
        								break;
        							case 19:
        								ok2=true;
        								ok=true;
        								break;
        								
        							default:
        								cout<<"\n\nNot a valid number!"<<endl;
        								cout<<c1;
        						}
        								
        					}while(ok2!=true);
        					break;
        				
        			case 2:	
        				
        				c2=c1;
        				s.Solve(c1);
        				cout<<"\nPhase one, 'The white cross' completed in "<<s.Getnp(0)<<" moves:"<<endl;
        				cout<<s.Getphase(0);
        				cout<<"\nPhase two, 'Positioning bottom layer corners'completed in "<<s.Getnp(1)<<" moves:"<<endl;
        				cout<<s.Getphase(1);
        				cout<<"\nPhase three, 'Positioning mid layer edges'completed in "<<s.Getnp(2)<<" moves:"<<endl;
        				cout<<s.Getphase(2);
        				cout<<"\nPhase four, 'Positioning top layer corners'completed in "<<s.Getnp(3)<<" moves:"<<endl;
        				cout<<s.Getphase(3);
        				cout<<"\nLast phase completed in "<<s.Getnp(4)<<" moves, Cube solved in: "<<s.Getnp(0)+s.Getnp(1)+s.Getnp(2)+s.Getnp(3)+s.Getnp(4)<<" moves."<<endl;
        				cout<<s.Getphase(4);
        				cout<<"\nSaving a file Moves.txt in current folder...\n"<<endl;
        				
        				of.open ("Moves.txt");
        				
        				for(int i=0;i<s.Getmovesn();i++){
        					of<<i+1<<" "<<s.Getmove(i)<<";\n";
        				 }
        				of.close();
        				
        				cout<<"Press 1 for a step by step solution, 2 to go back to main menu"<<endl;
        				cin >> a;
						while(cin.fail()){
						    cout << "Please, type a number from the list!"<<endl;
						    cin.clear();
						    cin.ignore(256,'\n');
						    cin >> a;
						}
					
						
						
											
						switch(a){
							
							ok=false;
							count=0;
							
							case 1:
								
								cout<<"\nStep by step solver:\n"<<endl;
								cout<<c2;
								
								do{
									cout<<"\nPress 1 for next step, 2 to go back to main menu"<<endl;
									cin >> a;
									while(cin.fail()){
									    cout << "Please, type a number from the list!"<<endl;
									    cin.clear();
									    cin.ignore(256,'\n');
									    cin >> a;
									}
									switch(a){
										
										case 1:
											
											if(count==s.Getmovesn()){
												cout<<"\nCube completed!"<<endl;
												cout<<c2;
												s.ClearMoves();
						    					ok=true;
						    					break;
											}
											cout<<"\nStep "<<count+1<<" of "<<s.Getmovesn()<<" :"<<s.Getmove(count)<<endl;
											c2.Move(s.Getmove(count));
											if(ok!=true)cout<<c2;
											count++;
											break;
											
										case 2:
											
											s.ClearMoves();
						    				ok=true;
						    				break;	
						    			
						    			default:
						    				
						    				cout<<"Not a valid number!\n"<<endl;
									}		
								}while(ok!=true);
								break;
								
        					case 2:
        						
        						s.ClearMoves();
			    				ok=true;
			    				break;
			    			
			    			default:
			    				
			    				cout<<"Not a valid number!\n"<<endl;
			    		}
        			
        			case 3:
        				ok=true;
        				break;
        				
        			default:
        				
        				cout<<"Not a valid number!\n"<<endl;
        		 }
        		 
			}while(ok!=true);
          }
		}while(go!=true);   
}

