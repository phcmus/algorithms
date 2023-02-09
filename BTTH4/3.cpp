#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string filename = "input_3.txt";
int n, k = 0;
vector<float> a;

bool isReadFile(string filename) {
    ifstream inputfile(filename);
    bool res = false;

    if (inputfile.is_open()) {
        inputfile >> n;

        for (float i = 0; i < n; i++) {
            float temp;
            inputfile >> temp;
            a.push_back(temp);
        }

        inputfile >> k;

        res = true;
    } else {
        cout << "Cannot open file!" << endl;
    }

    inputfile.close();
    return res;
}

void printVector(vector<float> arr) {
    for (float i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

int Partition(vector<float> &arr, int lower, int upper, int &pos) {
    float pivot = arr[pos];
    cout << "Partition: " << lower << " " << upper << " " << pos << endl;
    printVector(arr);
    swap(arr[lower], arr[pos]);
    printVector(arr);
    pos = lower;
    for (int i = lower + 1; i <= upper; i++) {
        cout << "pos" << pos << endl;
        if (pivot > arr[i]) {
            pos++;
            swap(arr[i], arr[pos]);
        }
    }
    swap(arr[lower], arr[pos]);
    return pos;
}

float Selection(vector<float> &arr, int lower, int upper, int k) {
    int h = rand() % (upper - lower) + lower;
    cout << "h = " << h << endl;
    int pos = Partition(arr, lower, upper, h);
    if (pos == k) {
        return arr[pos];
    }
    if (pos > k) {
        Selection(arr, lower, pos - 1, k);
    }
    if (pos < k) {
        Selection(arr, pos + 1, upper, k);
    }
}

int main() {
    bool read = isReadFile(filename);
    if (!read) {
        return 1;
    }

    printVector(a);

    float result = Selection(a, 0, a.size() - 1, 4);
    cout << "result = " << result << endl;

    return 0;
}
