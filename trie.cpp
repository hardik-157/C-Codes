struct node{
    vector<pair<ll,ll>> a;
    node *arr[3];
};

node *newNode() 
{ 
    node *temp = new node;  
    temp->arr[0] = temp->arr[1] = temp->arr[2] = NULL; 
    return temp; 
}

void insert(node *root, ll tmp[], ll x, ll y) 
{ 
    node *temp = root;
    for (ll i=0; i<100; i++) 
    {
        ll val = tmp[i];
        if (temp->arr[val] == NULL) 
            temp->arr[val] = newNode(); 

        temp = temp->arr[val]; 
    }
    temp->a.push_back(make_pair(x,y)); //your value; 
}

void traverse(node *root)
{
    //cout<<"hii"<<endl;
    node *temp = root;
    for(ll j=0;j<3;j++)
    {
        if(temp->arr[j] != NULL)
        {
            cout<<" J "<<j<<endl;
            traverse(temp->arr[j]);
        }
    }
    if(temp->a.size()>0)
    {
        for(ll i=0;i<temp->a.size();i++)
        {
            cout<<temp->a[i].first<< " " << temp->a[i].second <<endl;
        }
        cout<<" Ends Here "<<endl;
    }
}