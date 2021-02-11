//Inversion count using PBDS

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,greater<int>,rb_tree_tag,
		tree_order_statistics_node_update>
		pbds;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
        pbds st;
		for(int i=0;i<n;i++){
			cin>>a[i];

		}

		int inv_count=0;

		for(int i=0;i<n;i++){
			inv_count += st.order_of_key(a[i]);
            st.insert(a[i]);
		}

		cout<<inv_count;
	}

}