#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const float SIZE = 51.0;

//FUNCTION PROTOTYPES
int random_num();//generate random number
void integer_display_51(vector<int> random);//display 51 random integers
int findMode(vector<int> random); //find mode

int main() {
    srand(time(NULL)); // random seed
    int display;//variable to hold display 51 integers
    int mode; // variable to hold most frequent number in set
    float average; //variable for average of the integers
    vector<int> random_51;//vector for 51 random integers
    cout << "Here are " << SIZE << " random integers:" << endl;
    for (int x = 1; x <= SIZE; x++) {//generate 51 integers
        random_51.push_back(random_num());
    }
    integer_display_51(random_51);//display 51 integers
    cout << "Here are " << SIZE << " random integers in numerical order:" << endl;
    sort(random_51.begin(), random_51.end());//sorting inside the vector
    integer_display_51(random_51);//display 51 integers,sorted

    cout << "The median is: " << random_51[26] << endl;

//   mode = findMode(vector<int> random); //call mode function

    int sum = 0;
    for (int x = 0; x < SIZE; x++) {
        sum += random_51[x];
        //divide sum by size outside loop
    }
    average = sum / SIZE;
    cout << fixed << setprecision(2) << "The average is: " << average << endl;

/* to find mode, loop through random 51, how many times have we seen each number, which one is the most, how many times have we seen that number
 * cout current most frequent:
 * how many times we've seen the most frequent
 * variables - last seens number, most seen, last count - # times we've seen last number, most seen
    return 0;
*/

}

int random_num() {
    int rand_num;
    rand_num = rand() % 20 + 1;
    return rand_num;
}

void integer_display_51(vector<int> random) {
    for (int x = 0; x < random.size(); x++) {
        cout << random[x] << " ";

    }
    cout << endl;
}

//find mode
int findMode(vector<int> random) //pass in vector's integers
{
    int frequent_num = random[0]; //mode is in random set
    int mode = frequent_num; //mode will be the most frequent number
    int count = 1; //set count to  1
    int find_mode = 1; //set first number to 1

    for (int x = 0; x < SIZE; x++) //start with index 0, go up to size of vector, increment
    {
        if (random[x] == frequent_num) { // last integer's # occurrences
            ++count;//increment count
        } else { // if new number is most frequent
            if (count > find_mode) {
                find_mode = count; // most frequent
                mode = frequent_num;
            }
            count = 1; // reset count
            frequent_num = random[x];
        }
        return frequent_num;
    }
}

