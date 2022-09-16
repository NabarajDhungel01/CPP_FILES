#include <iostream>
using namespace std;
string add_two_strings_as_int(string a, string b);

int main()
{

    string csv_balance = "10", transfer_amount = "5", csv_total;
    // int temp_int_csv_balance,temp_int_transfer_amount,temp_int_total_blc;
    // temp_int_csv_balance = stoi(csv_balance);
    // temp_int_transfer_amount = stoi(transfer_amount);

    // temp_int_total_blc = temp_int_csv_balance - temp_int_transfer_amount;

    // cout << "\n temp_int_total_blc : "<< temp_int_total_blc;

    // csv_balance= to_string(temp_int_total_blc);

    // cout << "\n csv_balance: "<< csv_balance;

    csv_total = add_two_strings_as_int(csv_balance, transfer_amount);

    cout << csv_total;

    return 0;
}

string add_two_strings_as_int(string a, string b)
{
    string result;
    // Initialize a variable
    int num1 = 0;
    int n1 = a.length();

    // Iterate till length of the string
    for (int i = 0; i < n1; i++)
        num1 = num1 * 10 + (int(a[i]) - 48);

    int num2 = 0;
    int n2 = b.length();

    // Iterate till length of the string
    for (int i = 0; i < n2; i++)
        num2 = num2 * 10 + (int(a[i]) - 48);

    int num3 = num1 + num2;

    cout << endl
         << endl
         << num3;

    result = to_string(num3);
    return result;
}