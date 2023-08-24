

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void selectionSort(vector<int>& arr)
{
    int arSize = arr.size();
    for (int i = 0; i < arSize; i++)
    {
        int posOfMinElement = i;
        for (int j = i + 1; j < arSize; j++)
        {
            if (arr[j] < arr[posOfMinElement])
            {
                posOfMinElement = j;
            }
        }
        if(posOfMinElement!=i)
            swap(arr[i], arr[posOfMinElement]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> socks(n);

    int s;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        socks[i] = s;
    }


    int socksCounter= 1;

    selectionSort(socks);

    for (int i = n-1; i > 0; i--)
    {
        if(socks[i] == socks[i - 1])
            socksCounter++;
    }



    cout << socksCounter / 2<<"\n";




}

