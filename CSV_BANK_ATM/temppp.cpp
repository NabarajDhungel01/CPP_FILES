// C++ program for the above approach
#include <iostream>
#include <sstream> // for using stringstream
using namespace std;

string  Add_two_Strings(string a, string b);
string Subtract_two_Strings(string a, string b);

// Driver Code
int main()
{
    // // Given string of number
    // string s = "10"; // blc
    // string t = "5";  // amt

    // string result_sum = "\0";
    // string result_sub = "\0"; // subtract
    // // Function Call
    // result_sum = Add_two_Strings(s, t);
    // result_sub = Subtract_two_Strings(s,t);

    // cout << "Result Sum is " << result_sum;
    // cout << "Result Sub is " << result_sub;

    string csv_amount = "100";
    string transfer_amount = "20";

    cout  << "Before Function Call "<< csv_amount<< endl << endl;

    csv_amount = Subtract_two_Strings(csv_amount, transfer_amount);
    cout << "\nsubtracted csv_amount is "<< csv_amount << endl;
    csv_amount = "100";
    csv_amount = Add_two_Strings(csv_amount, transfer_amount); // the amount will  be updated of the receiver id

    cout << endl << "After Function Call "<< csv_amount<< endl << endl;

}

string Add_two_Strings(string a, string b) // for receivers id 
{
    cout << a << "  " << b;


    stringstream ss;
    stringstream geek(a);
    int x = 0;
    geek >> x;
    cout << "Value of x : " << x;


    //

    stringstream geek2(b);
    int x2 = 0;
    geek2 >> x2;
    cout << "Value of x2 : " << x2;

    int total_plus;
    // int total_minus;
    total_plus = x+x2;

    cout
        << " TOtal Plus : " << total_plus;
    // cout << " TOtal minus : " << total_minus ;
    // _2_int_to_string(x ,XX);
    return to_string(total_plus);
}
string Subtract_two_Strings(string a, string b) // for sender
{
    cout << a << "  " << b;

    stringstream ss;
    stringstream geek(a);
    int x = 0;
    geek >> x;
    cout << "Value of x : " << x;


    //

    stringstream geek2(b);
    int x2 = 0;
    geek2 >> x2;
    cout << "Value of x2 : " << x2;

    // int total_plus;
    int total_minus;
    // total_plus = x2 + x;

    // FOR EXTRA SECURITY AND ERROR HANDLING
    // FOR EXTRA SECURITY AND ERROR HANDLING
    // FOR EXTRA SECURITY AND ERROR HANDLING

    if (x2 > x ) // this means if the transfer amount is greater than the balance 
    {
        cout << " \n\n Insufficient Balance \n\n  ";
        total_minus = x; // if there is insufficient blc the original value will be returned as it is 
    }
    else
    {total_minus = x - x2 ;}
    // total_minus =  x - x2;

    cout
        << " TOtal Minus: " << total_minus;
    // cout << " TOtal minus : " << total_minus ;
    // _2_int_to_string(x ,XX);
    return to_string(total_minus);
}
