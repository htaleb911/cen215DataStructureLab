#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

// name =>                                                                                                  OĞUZ TAHA SANCAKTAR
// schoolId =>                                                                                                   2017555051

//                                                                                                             Include Algorithms   {START}
//                                                                                                             Include Algorithms   {START}
//                                                                                                             Include Algorithms   {START}
//                                                                                                             Include Algorithms   {START}

//insertion Sort

void insertionSort(int array[], int number)
{
    int i, key, j;
    for (i = 1; i < number; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Char array insertion sort

void insertionSortChar(char array[], int n)
{
    int i, j;
    char key;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Selection
void selectionSort(int array[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min])
                min = j;
        swap(&array[min], &array[i]);
    }
}

void selectionSortChar(char array[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min])
                min = j;
        swapChar(&array[min], &array[i]);
    }
}
// Bubble Sort
void bubbleSort(int array[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}

void bubbleSortChar(char array[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swapChar(&array[j], &array[j + 1]);
}
// Merge sort
void merge(int array[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

void mergeChar(char array[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortChar(char array[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortChar(array, l, m);
        mergeSortChar(array, m + 1, r);

        mergeChar(array, l, m, r);
    }
}

//quick sort
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int part = partition(array, low, high);

        quickSort(array, low, part - 1);
        quickSort(array, part + 1, high);
    }
}

char partitionChar(char array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swapChar(&array[i], &array[j]);
        }
    }
    swapChar(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSortChar(char array[], int low, int high)
{
    if (low < high)
    {
        int part = partitionChar(array, low, high);

        quickSortChar(array, low, part - 1);
        quickSortChar(array, part + 1, high);
    }
}

//heap sort

void heapify(int array[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && array[l] > array[largest])
        largest = l;

    if (r < n && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n)
{
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (j = n - 1; j > 0; j--)
    {
        swap(&array[0], &array[j]);
        heapify(array, j, 0);
    }
}

void heapifyChar(char array[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && array[l] > array[largest])
        largest = l;

    if (r < n && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        swapChar(&array[i], &array[largest]);
        heapifyChar(array, n, largest);
    }
}

void heapSortChar(char array[], int n)
{
    int i, j;
    for (i = n / 2 - 1; i >= 0; i--)
        heapifyChar(array, n, i);

    for (j = n - 1; j > 0; j--)
    {
        swapChar(&array[0], &array[j]);
        heapifyChar(array, j, 0);
    }
}

void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

//                                                                                                             Include Algorithms   {END}
//                                                                                                             Include Algorithms   {END}
//                                                                                                             Include Algorithms   {END}
//                                                                                                             Include Algorithms   {END}

//                                                                                                                  Main Function

int main()
{


    clock_t t;

    // School IDD 
    int schoolId[] = {2, 0, 1, 7, 5, 5, 5, 0, 5, 1};
    // Name Surname    
    char nameSurname[] = "oguz taha sancaktar";
    int n = sizeof(schoolId) / sizeof(schoolId[0]);
    int charSize = strlen(nameSurname);

    t = clock();
    insertionSort(schoolId, n);
    t = clock() - t;
    printArray(schoolId, n);
    printf("Insertion Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    insertionSortChar(nameSurname, charSize);

    t = clock() - t;
    printf("%s\n", nameSurname);

    printf("Insertion Char Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);




    //Selection Sort

    int schoolId1[] = {2, 0, 1, 7, 5, 5, 5, 0, 5, 1};

    char nameSurname1[] = "oguz taha sancaktar";
    int n1 = sizeof(schoolId1) / sizeof(schoolId1[0]);
    int charSize1 = strlen(nameSurname1);
    selectionSort(schoolId1, n1);
    t = clock() - t;
    printArray(schoolId1, n1);
    printf("Selection Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    selectionSortChar(nameSurname1, charSize1);
    t = clock() - t;
    printf("%s\n", nameSurname1);
    printf("Selection Char Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    //Bubble Sort

    int schoolId2[] = {2, 0, 1, 7, 5, 5, 5, 0, 5, 1};

    char nameSurname2[] = "oguz taha sancaktar";
    int n2 = sizeof(schoolId2) / sizeof(schoolId2[0]);
    int charSize2 = strlen(nameSurname2);

    bubbleSort(schoolId2, n2);
    t = clock() - t;
    printArray(schoolId2, n2);
    printf("Bubble Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    bubbleSortChar(nameSurname2, charSize2);
    t = clock() - t;
    printf("%s\n", nameSurname2);
    printf("Bubble Char Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    //Merge Sort

    int schoolId3[] = {2, 0, 1, 7, 5, 5, 5, 0, 5, 1};

    char nameSurname3[] = "oguz taha sancaktar";
    int n3 = sizeof(schoolId3) / sizeof(schoolId3[0]);
    int charSize3 = strlen(nameSurname3);

    mergeSort(schoolId3, 0, n3 - 1);
    t = clock() - t;
    printArray(schoolId3, n3);
    printf("Merge Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    mergeSortChar(nameSurname3, 0, charSize3 - 1);
    t = clock() - t;
    printf("%s\n", nameSurname3);
    printf("Merge Char Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    //Quick Sort

    int schoolId4[] = {2, 0, 1, 7, 5, 5, 5, 0, 5, 1};

    char nameSurname4[] = "oguz taha sancaktar";
    int n4 = sizeof(schoolId4) / sizeof(schoolId4[0]);
    int charSize4 = strlen(nameSurname4);

    quickSort(schoolId4, 0, n4 - 1);
    t = clock() - t;
    printArray(schoolId4, n4);
    printf("Quick Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    quickSortChar(nameSurname4, 0, charSize4 - 1);
    t = clock() - t;
    printf("%s\n", nameSurname4);
    printf("Quick Char Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    //Heap Sort

    int schoolId5[] = {2, 0, 1, 7, 5, 5, 5, 0, 5, 1};

    char nameSurname5[] = "oguz taha sancaktar";
    int n5 = sizeof(schoolId5) / sizeof(schoolId5[0]);
    int charSize5 = strlen(nameSurname5);

    heapSort(schoolId5, n5);
    t = clock() - t;
    printArray(schoolId5, n5);
    printf("Heap Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);
    heapSortChar(nameSurname5, charSize5);
    t = clock() - t;
    printf("%s\n", nameSurname5);
    printf("Heap Char Sort Time: %f\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
}