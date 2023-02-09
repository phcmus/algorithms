#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string filename = "input_4.txt";
int n, t;
vector<int> numbers;

bool isReadFile(string filename) {
    ifstream inputfile(filename);
    bool res = false;

    if (inputfile.is_open()) {
        inputfile >> n;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            inputfile >> temp;
            numbers.push_back(temp);
        }
        inputfile >> t;

        res = true;
    } else {
        cout << "Cannot open file!" << endl;
    }

    inputfile.close();
    return res;
}

void print(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
        // if (arr[i]) {
        //   cout << numbers[i] << ' ';
        // }
    }
    cout << endl;
}

void SoS(vector<int> s, int size, int sum, int start) {
    if (sum == t)
        print(s, size);
    else
        for (int i = start; i < n; i++) {
            s[size] = numbers[i];
            SoS(s, size + 1, sum + numbers[i], i + 1);
        }
}

int sum(vector<int> arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        res += arr[i];
    }
    return res;
}

int main() {
    bool read = isReadFile(filename);
    if (!read) {
        return 1;
    }

    // cout << "Read n = " << n << endl;
    // printVector(numbers);
    // cout << t << endl;

    vector<int> s = vector<int>(n, 0);
    int total = sum(numbers);
    // sort(numbers);
    if (numbers[0] <= t <= total)
        SoS(s, 0, 0, 0);
}
