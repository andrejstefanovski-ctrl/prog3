#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> const &A) 
{
  for (int i : A) {
    cout << i << " ";
  }
  cout << endl;
}

void printArray(int * A, int n) 
{
    for (int i=0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int maximizeExpression(vector<int> const &A) {
  int n = A.size();

  if (n < 4) {
    exit(-1);
  }

  int first[n + 1], second[n], third[n - 1], fourth[n - 2];

  for (int i = 0; i <= n - 3; i++) {
    first[i] = second[i] = third[i] = fourth[i] = INT_MIN;
  }

  first[n - 2] = second[n - 2] = third[n - 2] = INT_MIN;
  first[n - 1] = second[n - 1] = first[n] = INT_MIN;

  for (int i = n - 1; i >= 0; i--) {
    first[i] = max(first[i + 1], A[i]); //max vrednost od nizata, vo slucajov iniijalno ke e first = [40, 40, 40, 40, 40, 40, -INF]
  }

    printArray(first, n+1);

  for (int i = n - 2; i >= 0; i--) {
    second[i] = max(second[i + 1], first[i + 1] - A[i]); //max vrednost na A[s]-A[r], kade s>r. ili kako first[i+1]-A[i], ili najdobrata vrednost od second do sega
  }

    printArray(second, n);

  for (int i = n - 3; i >= 0; i--) {
    third[i] = max(third[i + 1], second[i + 1] + A[i]); //slicna logika kako second, samo sega na A[s]-A[r]+A[q], kade sto vo second ni e najdobra vrednost na A[s]-A[r]
  }

    printArray(third, n-1);

    for (int i = n - 4; i >= 0; i--) {
    fourth[i] = max(fourth[i + 1], third[i + 1] - A[i]); //slicno kako prethodnite
  }

  return fourth[0];
}

int main() {
  vector<int> A = {3, 9, 10, 1, 30, 40};

  cout << maximizeExpression(A);

  return 0;
}