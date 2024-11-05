
#include <iostream>
#include <string>
using namespace std;

// Recursive function to generate permutations of the input string
int returnPermutations(string input, string output[]) {
    // Base case: when input length is 1, store the permutation directly
    if (input.length() == 1) {
        output[0] = input;
        return 1;
    }

    int count = 0; // Total number of permutations generated

    // Iterate over each character in the input string
    for (int i = 0; i < input.length(); i++) {
        // Character to be excluded from the current permutation
        char currentChar = input[i];

        // Form the remaining string by excluding the current character
        string remaining = input.substr(0, i) + input.substr(i + 1);

        // Recursive call to generate permutations of the remaining string
        string temp[1000]; // Temporary array to store permutations of the remaining string
        int tempCount = returnPermutations(remaining, temp);

        // Prepend the current character to each of the generated permutations
        for (int j = 0; j < tempCount; j++) {
            output[count++] = currentChar + temp[j];
        }
    }

    // Return the total number of permutations generated
    return count;
}

int main() {
    string input = "abc";
    string output[1000]; // Array to store the generated permutations

    // Generate all permutations and get the count
    int count = returnPermutations(input, output);

    // Print all generated permutations
    cout << "Permutations of the string \"" << input << "\":" << endl;
    for (int i = 0; i < count; i++) {
        cout << output[i] << endl;
    }

    return 0;
}



/** 
#include <iostream>
#include <vector>
using namespace std;

int returnPermutations(string input, string output[]){
    int count = 0;
    string created;
    for(int i=0;input[i]!='\0' && input.length()>1;i++){
        char ch = input[i];
        int start = count;
        created = input.substr(0,i) + input.substr(i+1);
        count = count + returnPermutations(created,output+count);
        for(int k=start;k<count;k++){
            output[k] = ch + output[k];
        }
    }
    if(input.length()==1){
        for(int k=0;input[k]!='\0';k++){
            output[count] = output[count] + input[k];
            count++;
        }
    }
    
    return count;
}

int main(int argc, char const *argv[])
{
    string st = "shivam";
    string *stOut;
    int ans =  returnPermutations(st, stOut);
    cout << ans;
    for (int i = 0; i <5; i++) {
    cout << stOut[i]<<endl;
    }
    return 0;
}
*/