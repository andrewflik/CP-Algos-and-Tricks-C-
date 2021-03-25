#include<bits/stdc++.h>


// #include <boost/multiprecision/cpp_int.hpp> 
// using namespace boost::multiprecision; 

#define int long long
#define endl "\n"
using namespace std;
int solve(int op, int e, int h, int n, int a, int b, int c){
    int cakes = 0, oml = 0, shake = 0;
    if(op == 1){
        // COS
        cakes += min(e, h); 
        e -= cakes, h -= cakes;
        if(cakes >= n) return n * c;   // all n get cakes
        oml += e/2;
        e -= oml * 2;
        if(cakes + oml >= n) return cakes * c + (n-cakes) * a; // cake dominant then remaining get oml
        shake += h/3;
        h -= shake * 3;

        if(cakes + oml + shake >= n) return cakes * c + oml * a + (n-(cakes+oml)) * b;
    }else if(op == 2){
        // CSO
        cakes += min(e, h);  
        e -= cakes, h -= cakes;
        if(cakes >= n) return n * c;   // all n get cakes
        shake += h/3;
        h -= shake * 3;
        if(cakes + shake >= n)
            return cakes * c + (n-cakes) * b;
        oml += e/2;
        e -= oml * 2;
        if(cakes + shake + oml >= n)
            return cakes * c + shake * b + (n - (cakes + shake)) * a;
    }else if(op == 3){
        // SOC
        shake += h/3;
        h -= shake * 3;
        if(shake >= n) return n * b;    // all b get shakes
        oml += e/2;
        e -= oml * 2;
        if(shake + oml >= n) return shake * b + (n-shake) * a;    // 
        cakes += min(e, h); 
        e -= cakes, h -= cakes;
        if(shake + oml + cakes >= n) return shake * b + oml * a + (n- (shake + oml)) * c;
    }else if(op == 4){
        // SCO
        shake += h/3;
        h -= shake * 3;
        if(shake >= n) return n * b;
        cakes += min(e, h); 
        e -= cakes, h -= cakes;
        if(cakes + shake >= n) return shake * b + (n-shake) * c;
        oml += e/2;
        e -= oml * 2;
        if(cakes + shake + oml >= n) return shake * b + cakes * c + (n-(shake + cakes)) * a;
    }else if(op == 5){
        // OSC
        oml += e/2;
        e -= oml * 2;
        if(oml >= n) return n * a;
        shake += h/3;
        h -= shake * 3;
        if(shake + oml >= n) return oml * a + (n-oml) * b;
        cakes += min(e, h);
        e -= cakes, h -= cakes;
        if(shake + oml + cakes >= n) return oml * a + shake * b + (n-(oml + shake)) * c;
    }else{
        // OCS
        oml += e/2;
        e -= oml * 2;
        if(oml >= n) return n * a;
        cakes += min(e, h); 
        e -= cakes, h -= cakes;
        if(oml + cakes >= n) return oml * a + (n-oml) * c;
        shake += h/3;
        h -= shake * 3;
        if(oml + cakes + shake >= n) return oml * a + cakes * c + (n-(oml + cakes)) * b;
    }
    //if(cakes + oml + shake < n)
    return INT_MAX;
}
int solve2(int e, int h, int n, int a, int b, int c){
    int n1, n2, n3, ans = INT_MAX;
    n1 = e/2; // Oml
    n2 = h/3; // shake
    n3 = min(e, min(h, n)); // cake
    for(int i=0; i<=n/2; i++){
        for(int j=0, k=n-i; k>=0; k--, j++){
            if(n1 >= i and n2 >= j and n3 >= k){
                int currE = 0, currH = 0;
                currE = i*2 + k;
                currH = j*3 + k;
                if(currE <= e and currH <= h)    
                    ans = min(ans, a*i + b*j + c*k), cout << i << " + " << j << " + " << k << " = " << i + j + k  << " - " << a*i + b*j + c*k << endl;
            }
        }
    }
    return ans;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, e, h, a, b, c;
        cin >> n >> e >> h; // Total People/ Total Eggs / Total Choclates
        cin >> a >> b >> c; // costs - Omellete/Shake/Cake
            int a1 = solve(1, e, h, n, a, b, c);
            int a2 = solve(2, e, h, n, a, b, c);
            int a3 = solve(3, e, h, n, a, b, c);
            int a4 = solve(4, e, h, n, a, b, c);
            int a5 = solve(5, e, h, n, a, b, c);
            int a6 = solve(6, e, h, n, a, b, c);
            int ans = min(a1, min(a2, min(a3, min(a4, min(a5, a6)))));
            // if(n >= 1e5 and ans != INT_MAX){
            //     cout << ans << endl;
            //     continue;
            // }
            int ans1 = solve2(e, h, n, a, b, c);
            int answer = min(ans, ans1);
            if(ans == INT_MAX)
                cout << -1 << endl;
            else
                cout << answer << endl;
    }
}