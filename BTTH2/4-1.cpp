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

void printVector(vector<bool> arr) {
    for (int i = 0; i < arr.size(); i++) {
        // cout << arr[i] << ' ';
        if (arr[i]) {
            cout << numbers[i] << ' ';
        }
    }
    cout << endl;
}

void SoS(int k, int sum, int total, vector<int> w, vector<bool> s) {
    if (sum == t)
        printVector(s);
    else if ((sum + total >= t) && (sum + w[k] <= t)) {
        s[k] = true;
        SoS(k + 1, sum + w[k], total - w[k], w, s);
        s[k] = false;
        SoS(k + 1, sum, total - w[k], w, s);
    }
}

int sum(vector<int> arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        res += arr[i];
    }
    return res;
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main() {
    bool read = isReadFile(filename);
    if (!read) {
        return 1;
    }
    // cout << "Read n = " << n << endl;
    // printVector(numbers);
    // cout << t << endl;

    vector<bool> s = vector<bool>(n, false);
    int total = sum(numbers);
    sort(numbers);
    if (numbers[0] <= t <= total)
        SoS(0, 0, total, numbers, s);
}
