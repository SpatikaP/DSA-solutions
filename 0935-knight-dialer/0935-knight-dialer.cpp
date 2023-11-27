class Solution {
    static const int MOD = 1000000007;
public:
    int knightDialer( int N ){
        vector<long> cur( 10, 1 ), next( cur );
        for( int i{ 2 };  i <= N;  ++i ){
            next[ 0 ] = (  cur[ 4 ] + cur[ 6 ]  ) % MOD;
            next[ 1 ] = (  cur[ 6 ] + cur[ 8 ]  ) % MOD;
            next[ 2 ] = (  cur[ 7 ] + cur[ 9 ]  ) % MOD;
            next[ 3 ] = (  cur[ 4 ] + cur[ 8 ]  ) % MOD;
            next[ 4 ] = (  cur[ 0 ] + cur[ 3 ] + cur[ 9 ]  ) % MOD;
            next[ 5 ] = (  0  );
            next[ 6 ] = (  cur[ 0 ] + cur[ 1 ] + cur[ 7 ]  ) % MOD;
            next[ 7 ] = (  cur[ 2 ] + cur[ 6 ]  ) % MOD;
            next[ 8 ] = (  cur[ 1 ] + cur[ 3 ]  ) % MOD;
            next[ 9 ] = (  cur[ 2 ] + cur[ 4 ]  ) % MOD;
            cur.swap( next );
        }
        return accumulate( cur.begin(), cur.end(), 0L ) % MOD;
    }
};