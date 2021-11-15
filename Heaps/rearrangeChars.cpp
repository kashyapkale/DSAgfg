//https://practice.geeksforgeeks.org/problems/rearrange-characters5322/0
string rearrangeString(string str){
    unordered_map<char, int> umap;

    for (auto i:str)
        umap[i]++;

    priority_queue<pair<int, int> > maxHeap;

    for (auto it:umap)
        maxHeap.push(make_pair(it.second, it.first));

    string ans = "";

    while (!maxHeap.empty()) {
        if (maxHeap.size() == 1) {
            if (maxHeap.top().first > 1)
                break;
            else{
                ans += maxHeap.top().second;
                maxHeap.pop();
                continue;
            }
        }


        pair<int, int> s1 = maxHeap.top();
        maxHeap.pop();
        pair<int, int> s2 = maxHeap.top();
        maxHeap.pop();

        ans += s1.second;
        ans += s2.second;

        s1.first--;
        s2.first--;

        if (s1.first > 0)
            maxHeap.push(s1);
        if (s2.first > 0)
            maxHeap.push(s2);
    }
    //cout<<ans<<endl;
    return (maxHeap.empty())?ans:"-1";
}
