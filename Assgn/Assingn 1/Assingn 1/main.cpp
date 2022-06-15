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
    int arr_EAN_8[12];
    int arr_UPC_A[12];
    int arr[12];
    int arr_EAN_14[12];
    int arr_SSCC[12];
    
    do
    {
   

        cout << endl;
        cout << " 1.EAN-8\n";
        cout << " 2.UPC-A\n";
        cout << " 3.EAN-13\n";
        cout << " 4.EAN-14\n";
        cout << " 5.SSCC\n";
    cout << " Choose your product code type: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    //EAN-8
            cout << "Please enter the first 12 digit numbers\n";
            for (i = 0; i < 12; i++ )
            {
                cin >> arr_EAN_8[i];
            }
            cout << "Last sigit:\n";
            cout << compute_check_digit(arr_EAN_8, 12);
            break;
    case 2:
    //UPC-A
            cout << "Please enter the first 12 digit numbers\n";
            for (i = 0; i < 12; i++ )
            {
                cin >> arr_UPC_A[i];
            }
            cout << "Last sigit:\n";
            cout << compute_check_digit(arr_UPC_A, 12);
            break;
    case 3:
    //EAN-13
            cout << "Please enter the first 12 digit numbers\n";
            for (i = 0; i < 12; i++ )
            {
                cin >> arr[i];
            }
            cout << "Last sigit:\n";
            cout << compute_check_digit(arr, 12);
            break;
    case 4:
    //EAN-14
            cout << "Please enter the first 12 digit numbers\n";
            for (i = 0; i < 12; i++ )
            {
                cin >> arr_EAN_14[i];
            }
            cout << "Last sigit:\n";
            cout << compute_check_digit(arr_EAN_14, 12);
            break;
    case 5:
    //SSCC
            cout << "Please enter the first 12 digit numbers\n";
            for (i = 0; i < 12; i++ )
            {
                cin >> arr_SSCC[i];
            }
            cout << "Last sigit:\n";
            cout << compute_check_digit(arr_SSCC, 12);
            break;
    default:
            cout << "test";
//    cout << "Not a Valid Choice. \n"
//    << "Choose again.\n";
            
    break;
           
    }

    }while (choice <=5);
    
    
    
    
     // 4


    return 0;
}

