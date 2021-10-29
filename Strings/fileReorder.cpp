//https://practice.geeksforgeeks.org/problems/rotate-by-90-degree3034/1

bool comp(pair<string, pair<string, string> > &a, pair<string, pair<string, string> > &b) {
    // if the string after the identifier is same, in that case we will check the identifier
    if (a.second.second == b.second.second) return a.second.first < b.second.first;
// otherwise compare the string after the identifier
    return a.second.second < b.second.second;
}
vector<string> fileReorder(vector<string>& files) {
    vector<string> answer;
    vector<pair<string, pair<string, string> > > p;
    vector<string> let, dig;

    for (auto x:files) {
        string s = x;
        size_t pos = s.find(' ');
        // head stores the first identifier, body stores the rest of the string
        string head = s.substr(0, pos);
        string body = s.substr(pos + 1);
        //if digit file, then add it in dig vector
        if (isdigit(body[0])) {
            dig.push_back(s);
        }
        else {
            // else add the string with the identifier and the rest of the string in p vector
            p.push_back({ s, { head, body } });
        }
    }
    sort(p.begin(), p.end(), comp);
    for (auto x:p) {
        answer.push_back(x.first);
    }
    // After pushing letter file strings, add digit file strings
    for (auto x:dig) {
        answer.push_back(x);
    }
    return answer;
}
