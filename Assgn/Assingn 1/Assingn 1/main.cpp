//
//  main.cpp
//  Assingn 1
//
//  Created by Aim Kim on 2022-06-13.
//

#include <iostream>

using namespace std;

int compute_check_digit(int arr[], int size){
    int check_digit;
    int sum = 0;
    for (int i = size - 1; i >= 0 ; i = i - 2 ){
        sum += arr[i];
    }
   
    

    
    sum *= 3;
    

 
    int sum2 = 0;
    for (int i = size - 2; i >= 0 ; i = i - 2 ){
        sum2 += arr[i];
    }
    ;
    

    int sum3 = sum + sum2;

    

  
    check_digit = 10 - (sum3 % 10);
   
    if(sum3 % 10 == 0)
        check_digit = 0;
    return check_digit;
}

int main()
{
    int choice;
    int i;
    int number_size = 0;
    int arr[17];
    
    do
    {
        cout << endl;
        cout << "Check Digit Calculator\n";
        cout << "____________________\n";
        cout << " 1.EAN-8\n";
        cout << " 2.UPC-A\n";
        cout << " 3.EAN-13\n";
        cout << " 4.ITF-14\n";
        cout << " 5.SSCC\n";
        cout << "____________________\n";
    cout << "Choose your product code type: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Please enter the first 7 digit numbers\n";
        number_size = 7;
    }
    
   else if ( choice == 2)
   {
        cout << "Please enter the first 12 digit numbers\n";
        number_size = 11;
   }
        
   else if ( choice == 3)
   {
        cout << "Please enter the first 12 digit numbers\n";
        number_size = 12;
   }
   else if ( choice == 4)
   {
        cout << "Please enter the first 13 digit numbers\n";
        number_size = 13;
   }
   else if ( choice == 5)
   {
        cout << "Please enter the first 17 digit numbers\n";
        number_size = 17;
   }
   else if ( choice > 5)
   {
       cout << "Error: " << choice << " is an invalid choice\n";
       break;
   }
        for (i = 0; i < number_size; i++ )
        {
            cin >> arr[i];
        }
        cout << "____________________\n";
        cout << "The check digit is ";
        cout << compute_check_digit(arr, number_size) << endl ;
        cout << "The product code is " ;
        for (i = 0; i < number_size; i++ )
        {
            cout << arr[i];
        }
        cout << compute_check_digit(arr, number_size) << endl ;
 
           
    }

    while (choice <=5);
    
    



    return 0;
}

