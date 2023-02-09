#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;

int k;

bool validateData(vector<int> nums, int k)
{
    if (nums.size() == 0)
    {
        cout << "Mang so nguyen rong! Kiem tra lai!" << endl;
        return false;
    }
    if (k < 0)
    {
        cout << "k am! Kiem tra lai!" << endl;
        return false;
    }

    return true;
}

int readedFile(string filename, vector<int> &number) // return k
{
    ifstream inputfile(filename);
    int count = 0;

    if (inputfile.is_open())
    {
        inputfile >> count;
        number = vector<int>(count, 0);

        for (int i = 0; i < count; i++)
        {
            inputfile >> number[i];
        }
    }
    else
    {
        cout << "Mo file khong thanh cong! File khong ton tai!" << endl;
    }

    int k;
    inputfile >> k;
    inputfile.close();
    return k;
}

void SoS(vector<int> selector, int size, int sum, int start, const vector<int> nums)
{
    if (sum == k)
    {
        for (int i = 0; i < selector.size(); i++)
        {
            if (selector[i] != 0)
                cout << selector[i] << " ";
        }
        cout << endl;
    }
    else
        for (int i = start; i < nums.size(); i++)
        {
            selector[size] = nums[i];
            SoS(selector, size + 1, sum + nums[i], i + 1, nums);
        }
}
int main()
{
    string filename = "input_6.txt";
    vector<int> nums;
    k = readedFile(filename, nums);    

    if (validateData(nums, k))
    {
        vector<int> selector(nums.size(), 0);
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (nums[0] <= k <= total)
        {
            SoS(selector, 0, 0, 0, nums);
        }
    }

    return 0;
}
