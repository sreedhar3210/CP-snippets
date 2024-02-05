class factorial_ops{
    public:
        //inv_fact[i] = 1 / fact[i]
        vector<ll> fact(N + 1, 0), inv_fact(N + 1, 0);

        void factorials() {
            fact[0] = 1;

            for(ll i = 1;i <= N;i++)
                fact[i] = (fact[i - 1] * i) % MOD;

            inv_fact[N] = fast_pow(fact[N], MOD - 2);

            for(ll i = N - 1;i >= 0;i--)
                inv_fact[i] =  (inv_fact[i + 1] * (i + 1)) % MOD;
        }

        ll ncr(int n, int k) {
            return (fact[n] * ((inv_fact[k] * inv_fact[n - k]) % MOD)) % MOD;
        }

        ll npr(int n,int k)
        {
            return ((fact[n]*inv_fact[n-k])%MOD);
        }
};
