#include <iostream>
#include <vector>

#define ll long long
#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while( t-- ){
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for ( int i = 0; i < n; i++ ){
            cin >> arr[i];
        }
        
        vector<int> pf(n+1, 1);
        
        int s = 0;
        int e = 1;
        int sum = arr[s] + arr[e];
        int start = -1;
        
        while ( s != e && e != n ){
            if ( sum > n ){
                sum = sum - arr[s];
                s++;
                
                if ( (s == e) && (s != n-1 ) ){
                    e++;
                    sum = sum + arr[e];
                } else {
                    pf[sum]++;
                    e++;
                    if ( e < n )
                        sum = sum + arr[e];
                }
            } else {
                pf[sum]++;
                
                if ( start != s ){
                    start = s;
                    int temp = start;
                    while ( temp != (e-1) ){
                        sum = sum - arr[temp];
                        pf[sum]++;
                        temp++;
                    }
                }
                e++;
                sum = sum + arr[e];
            }
        }
        
        for ( int i = 1; i <= n; i++ ){
            cout << pf[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
