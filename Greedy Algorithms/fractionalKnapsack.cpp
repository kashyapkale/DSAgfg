//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
//Please Note : I have used extra space here , can easily be done in O(1) space.
static bool knapsackComparator(pair<Item, double> Item1, pair<Item, double> Item2){
    if(Item1.second != Item2.second)    
        return Item1.second > Item2.second;
    
    return Item1.first.weight<Item2.first.weight;
}

double fractionalKnapsack(int W, Item arr[], int n){
    vector<pair<Item, double> > bag;

    for (int i = 0; i < n; i++)
        bag.push_back(make_pair(arr[i], ((double)arr[i].value / (double)arr[i].weight)));
    sort(bag.begin(), bag.end(), knapsackComparator);

    double ans = 0;

    for (int i = 0; i < n; i++) {
    
        if (bag[i].first.weight <= W) {
            ans += bag[i].first.value;
            W = W - bag[i].first.weight;
            continue;
        }

        ans += (bag[i].second * W);
        W = 0;
        break;
    }

    return ans;
}
