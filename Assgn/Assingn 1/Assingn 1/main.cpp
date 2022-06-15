//
//  main.cpp
//  Assingn 1
//
//  Created by Aim Kim on 2022-06-13.
//

#include <iostream>

using namespace std;

// takes 12 digits and return the check digit
int compute_check_digit(int arr[], int size){
    int check_digit;
    // to be implemented
    // Step 1: add together all alternate numbers starting from the right
    // 5 0 1 2 3 4 5 7 6 4 2 1
    // 0 + 2 + 4 + 7 + 4 + 1 = 18
    int sum = 0;
    for (int i = size - 1; i >= 0 ; i = i - 2 ){
        sum += arr[i];
    }
    // cout << sum;
    // cout << endl;
    

    // Step 2: multiply the answer by 3
    // 18 x 3 = 54
    sum *= 3;

    

    // Step 3: now add together the remaining numbers
    // 5 0 1 2 3 4 5 7 6 4 2 1
    // 5 + 1 + 3 + 5 + 6 + 2 = 22
    int sum2 = 0;
    for (int i = size - 2; i >= 0 ; i = i - 2 ){
        sum2 += arr[i];
    }
    ;
    

    // Step 4: add step 2 and 3 together
    int sum3 = sum + sum2;
    // 54 + 22 = 76

    

    // Step 5: the difference between step 4 and the next 10th number:
    // 76 + 4 = 80
    check_digit = 10 - (sum3 % 10);
    // sum3 = 75 -> expected output 5
    // sum3 = 70 -> expected output 0 - special case
    // sum3 = 79 -> expected output 1
    if(sum3 % 10 == 0) // or check_digiti == 10
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
        cout << " 4.EAN-14\n";
        cout << " 5.SSCC\n";
        cout << "____________________\n";
    cout << " Choose your product code type: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Please enter the first 7 digit numbers\n";
        number_size = 7;
    }
    
   else if ( choice == 2)
   {
        cout << "Please enter the first 12 digit numbers\n";
        number_size = 10;
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
        number_size = 16;
   }
   else
   {
       cout << "wrong";
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
    //UPC-A
    //EAN-13
    //EAN-14
    //SSCC
           
//    cout << "Not a Valid Choice. \n"
//    << "Choose again.\n";
           
    }

    while (choice <=5);
    
    
    
    
     // 4


    return 0;
}

