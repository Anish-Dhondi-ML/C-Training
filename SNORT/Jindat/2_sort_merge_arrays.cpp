// Session 2
// 16-02-2023
// Write program to sort two arrays and merge them into a third array. 



#include <iostream>


int merge_arrays(int arrone[], int arrtwo[], int arrthree[], int m, int n)
{

    int i,j;
    for(i = 0; i < m; i++)
    {
        arrthree[i] = arrone[i];
    }

    for(i = m, j = 0 ; i < m + n; i++, j++)
    {
        arrthree[i] = arrtwo[j];
    }
}

int main()
{
    int n,m;
    std::cout << "Enter the size of Array one : " << std::endl;
    std::cin >> m;
    
    std::cout << "Input the Array 1 elements : " << std::endl;
    for(i = 0; i<m;i++)
    {
        std::cin >> arr1[i];
    }

    std::cout << "Enter the size of Array two : " << std::endl;
    std::cin >> n;

    int arr1[m],arr2[n];
    int arr3[m+n];
    int i;

    std::cout << "Input the elements of Array one : " << std::endl;
    for(i = 0; i<m;i++)
    {
        std::cin >> arr1[i];
    }

    std::cout << "Input the elements of Array two : ";
    for(i = 0;i<n;i++)
    {
        std::cin >> arr2[i];
    }

    merge_arrays(arr1,arr2,arr3,m,n);
    std::cout << "The Merged Sorted Array : " << std::endl;
    
    std::sort(arr3, arr3 +(m+n));
    for(i = 0; i < n + m; i++)
    {
        std::cout << arr3[i] << " " << std::endl;;
    }


}
