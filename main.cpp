#include <iostream>
#include <vector>

using namespace std;
int random_num();
void display(vector<int> random);

int main() {
    srand(time(NULL)); // random seed

    vector<int> random_51;

    for (int x = 1; x <= 51; x++) {
    random_51.push_back(random_num());
    }


    return 0;

}
int random_num(){
    int rand_num;
    rand_num = rand() % 20 + 1;
    return rand_num;
}

void display(vector<int> random){
    for (int x = 0; x<random.size(); x++){
        cout<<random[x]<<" ";
    }

}