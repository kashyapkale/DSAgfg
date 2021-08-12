//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
static bool meetingComparator(pair<int, pair<int, int> > A, pair<int, pair<int, int> > B){
    if (A.second.second != B.second.second)
        return A.second.second < B.second.second;

               return A.first < B.first;
}

int maxMeetings(int start[], int end[], int n){
    vector<pair<int, pair<int, int> > > meetings;

    for (int i = 0; i < n; i++)
        meetings.push_back(make_pair(i, make_pair(start[i], end[i])));

    sort(meetings.begin(), meetings.end(), meetingComparator);
    int end_time = INT_MIN, start_time = INT_MIN;
    int ans = 0;

    for (auto it:meetings) {
        if (it.second.second > end_time && it.second.first > end_time) {
            ans++;
            end_time = it.second.second;
            start_time = it.second.first;
        }
    }

    return ans;
}
