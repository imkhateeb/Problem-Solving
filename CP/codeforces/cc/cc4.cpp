#include <bits/stdc++.h>
#include <deque>
#define ll long long
#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while( t-- ){
        
        // My code
        
        int n, k;
        cin >> n >> k;
        
        vector<int> v;
        
        
        int odd = 1;
        int even = 2;
        int last = 1;
        
        while ( k != 0 ){
            
            if ( k == 1 ){
                if ( last%2 == 0 ){
                    while ( even <= n ){
                        v.push_back(even);
                        even = even + 2;
                    }
                    while ( odd <= n ){
                        v.push_back(odd);
                        odd = odd + 2;
                    }
                    
                } else {
                    
                    while ( odd <= n ){
                        v.push_back(odd);
                        odd = odd + 2;
                    }

                    while ( even <= n ){
                        v.push_back(even);
                        even = even + 2;
                    }
                }
            } else {
                if ( last%2 != 0 ){
                    v.push_back(odd);
                    last = even;
                    odd = odd + 2;
                } else {
                    v.push_back(even);
                    last = odd;
                    even = even + 2;
                }
            }
            
            k--;
            
        }
        
        for(int i = 0; i < n; i++ ){
            cout << v[i] << " ";
        }cout << endl;
    }
    
    
    return 0;
}