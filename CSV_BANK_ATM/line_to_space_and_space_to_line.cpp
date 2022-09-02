#include <iostream>
using namespace std;
string convert_space_to_line(string input_string);
string convert_line_to_space(string input_string);


int main()
{
    string Full_Name;
    string Full_Name_with_line;
    string Full_Name_with_space;

    cout << " Enter Name with Spaces : ";
    getline(cin,Full_Name);


    cout <<"\n\n FULL NAME is : "<<Full_Name;

    cout << "\n\n NAME converted spaces to _ is : "<< convert_space_to_line(Full_Name);

    Full_Name_with_line = convert_space_to_line(Full_Name);

    cout << "\n\n Name converted spaces to _ stored in Full_Name_with_line variable is "<< Full_Name_with_line;

    Full_Name_with_space = convert_line_to_space(Full_Name_with_line);

    cout<<"\n\n Name converted line to spaces stored in Full_Name _with_space is : "<< Full_Name_with_space;

return 0;
}

string convert_space_to_line(string input_string)
{
    string output_string = "\0";
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == ' ')
        {
            output_string += "_";
        }
        else
        {
            output_string += input_string[i];
        }
        
    }
    return output_string;
    
}

string convert_line_to_space(string input_string)
{   
    string output_string = "\0";
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == '_')
        {
            output_string += " ";
        }
        else
        {
            output_string += input_string[i];
        }
        
    }
    return output_string;

}