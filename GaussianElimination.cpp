// k = number of bits
// k - (return value) = number of independent xor values 
ll gaussElimination(vector<ll>v, ll k)
{
    ll i = 0;
    for (ll j = 0; j < k; j++) {
        ll l;
        for (l = i; l < v.size() && ((v[l]>>j)&1)==0; l++);
        if (l==v.size()) continue;
        if (l > i) swap(v[i], v[l]);
        for (l = i+1; l < v.size(); l++) if (v[l]&(1<<j)) v[l] ^= v[i];
        i++;
    }
    return i;
}

//-----------------------------#########------------------------------------------

const ll N = 3;

void swap_row(ll matrix[N][N+1], ll i, ll j)
{
    for(ll k = 0;k<=N;k++)
    {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}

ll forwardElim(double matrix[N][N+1])
{
    for(ll k=0;k<N;k++)
    {
        ll i_max = k;
        ll v_max = matrix[i_max][k];

        for(ll i = k+1;i<N;i++)
            if(abs(matrix[i][k]) > v_max)
                v_max = matrix[i][k], i _max = i;

        if(!matrix[k][i_max])
            return k;

        if(i_max != k)
            swap_row(matrix, k, i_max);

        for(ll i=k+1;i<N;i++)
        {
            double f = matrix[i][k]/mat[k][k];

            for(ll j=k+1;j<=N;j++)
                matrix[i][j] = matrix[i][j] - matrix[k][j]*f;

            matrix[i][k] = 0;
        }
    }
    return -1;
}

void backSubstitution(double matrix[N][N+1])
{
    double x[N];

    for(ll i=N-1;i>=0;i--)
    {
        x[i] = matrix[i][N];
        for(ll j=i+1;j<N;j++)
            x[i] =x[i] - matrix[i][j]*a[j];

        x[i] = x[i]/matrix[i][i];
    }

    for(ll i=0;i<N;i++)
        cout<<x[i]<<endl;
}

void gaussianElimination(double matrix[N][N+1])
{
    ll singular_flag = forwardElim(matrix);

    if (singular_flag != -1)
    {
        printf("Singular Matrix.\n");
        if(matrix[singular_flag][N])
            printf("Inconsistent System."); 
        else
            printf("May have infinitely many solutions.");
        return; 
    }

    backSubstitution(matrix);
}
