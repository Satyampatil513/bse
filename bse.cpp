///CODE FOR TRADER


#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int buyer; 
    int seller;
    int No_of_stocks;
    int trading_price;
    int cmp = 500;                    //*****************************************
    int total_stocks = 100;                //*****************************************
    int number_of_teams = 2;                     //*****************************************
    vector<int> fund(number_of_teams,10000);          //*****************************************
    vector<int> stocks(number_of_teams,total_stocks/number_of_teams);             //*****************************************

    while (true)
    {
    cout<<"Trading price :" ;
    cin>>trading_price;
    cout<<"Enter buying Team No. : " ; 
    cin>>buyer;
    cout<<"Enter Selling Team No. : " ;
    cin>>seller;
    cout<<"No. of stocks to be traded :" ;
    cin>>No_of_stocks;

    if(fund[buyer-1] >=  No_of_stocks * trading_price )   //buyer - 1 as 0 based indexing he vector me...
    {
        string key;
        cout<<endl<<"Settle Fund & stocks(y/n)";
        cin>>key;
    if(key == "y" or key== "Y" ){

         //Enter trade details to csv
        ofstream my_file;
        my_file.open("details.csv", std::ios::out | std::ios::app);
        my_file << buyer << ", "
             << seller << ", "
             << trading_price << ", "
             << No_of_stocks << ", "
             << cmp << " , "
             << "\n";

         //enter funds detail...
        fund[buyer-1] = fund[buyer-1] - No_of_stocks * trading_price ;
        fund[seller-1] = fund[seller-1] + No_of_stocks * trading_price ;
        ofstream my_file1;
        my_file1.open("funds.csv", std::ios::out | std::ios::app);
        for(int i = 0; i< number_of_teams ;i ++){
            my_file1 << fund[i] << ",";  
        };
         my_file1 << endl;

        //enter stocks detail... 
        stocks[buyer-1] = stocks[buyer-1] + No_of_stocks;
        stocks[seller-1] = stocks[seller-1] - No_of_stocks;
        ofstream my_file2;
        my_file2.open("stocks.csv", std::ios::out | std::ios::app);
        for(int i = 0; i< number_of_teams ;i ++){
           my_file2 << stocks[i] << ","; 
        };
        my_file2 << endl ;
                  
        int change = (No_of_stocks*trading_price)-(No_of_stocks*cmp);   
        int new_price = cmp + (change*5)/total_stocks;
        cout<<endl<<"New price : "<< new_price ;
        cmp = new_price;
        cout<<endl;

        }
        else{
            continue;
        }
    }
    else{
        cout<< "Bhai paise nahi he tere pass.";
        cout<<endl;
    }
    }    
    return 0;
}
