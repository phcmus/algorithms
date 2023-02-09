#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;

vector<int> result;
int cost = 99999;

int readedFile(string filename, vector<vector<int>> &road) // return number of cities
{
    ifstream inputfile(filename);
    int cities_count = 0;

    if (inputfile.is_open())
    {
        inputfile >> cities_count;
        road = vector<vector<int>>(cities_count, vector<int>(cities_count, 0));

        while (!inputfile.eof())
        {
            int src = 0, des = 0;
            inputfile >> src;
            if (src != -1)
            {
                inputfile >> des >> road[src - 1][des - 1];
                road[des - 1][src - 1] = road[src - 1][des - 1];
            }
        }
    }
    else
    {
        cout << "Mo file khong thanh cong! File khong ton tai!" << endl;
    }
    inputfile.close();
    return cities_count;
}

bool validateData(int cities_count, vector<vector<int>> road)
{
    if (cities_count == 0)
    {
        cout << "Khong ton tai thanh pho! Kiem tra lai!" << endl;
        return false;
    }
    if (road.size() != cities_count)
    {
        cout << "Khong doc duoc du lieu! Kiem tra lai!" << endl;
        return false;
    }
    for (int i = 0; i < road.size(); i++)
    {
        if (road[i].size() != cities_count)
        {
            cout << "Du lieu khong chinh xac! Kiem tra lai!" << endl;
            return false;
        }
    }

    return true;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool isHamilton(vector<int> cities, const vector<vector<int>> road, int& ccost)
{
    int n = cities.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (road[cities[i]][cities[i + 1]] <= 0)
        {
            return false;
        }
        ccost += road[cities[i]][cities[i + 1]];
    }

    if (road[cities[n - 1]][cities[0]] <= 0)
    {
        return false;
    }
    ccost += road[cities[n - 1]][cities[0]];
    return true;
}

void findPath(vector<int> cities, int pivot, const vector<vector<int>> road)
{
    if (pivot == cities.size() - 1)
    {
        int ccost = 0;
        if (isHamilton(cities, road, ccost))
        {
            if (ccost < cost)
            {
                result = vector<int>(cities);
                result.push_back(cities[0]);
                cost = ccost;
            }
        }
    }
    else
    {
        int n = cities.size();
        for (int i = pivot; i < n; i++)
        {
            swap(cities[pivot], cities[i]);
            findPath(cities, pivot + 1, road);
            swap(cities[pivot], cities[i]);
        }
    }
}

int main()
{
    string filename = "input_5.txt";
    vector<vector<int>> road;
    int cities_count = readedFile(filename, road);

    if (validateData(cities_count, road))
    {
        vector<int> cities(cities_count);
        iota(cities.begin(), cities.end(), 0);
        findPath(cities, 0, road);

        if (result.size() == cities_count + 1)
        {
            for (int i = 0; i < result.size(); i++)
            {
                cout << result[i] + 1 << " ";
            }
            cout << endl << cost << endl;            
        }
        
    }

    return 0;
}
