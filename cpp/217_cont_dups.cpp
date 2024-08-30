#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> dups;
        ios::sync_with_stdio(false);
        switch (nums.size()) {
            case 0: return false;
            case 1: return false;
            case 2: return nums.front() == nums.back();
        }

        for (int i = 0; i < nums.size(); i++) {
            
            if (dups.find(nums[i]) == dups.end()) {
                dups.insert({nums[i], true});
            }
            else {
                return true;
            }
        }
        return false;
    }
};


int main() {
    return 0;
}


//////////////////// <----This line is 80 long exactly----> ////////////////////



////////////////////////////////////////////////////////////////////////////////
    // THIS hot garbage speeds up the code because they use iostream or similar
    // to output their test results and if you want to compete for the top spot
    // you need to do this (or similar) to speed up the part of the problem that
    // lies outside your function. Yes I hate it. I wonder if it might be an
    // option to do it in the constructor of the Solution class? Or possibly,
    // do something with the "new" operator on `Solution` to return nullptr or
    // some stack-allocated value just to take out 1 allocation and make it even
    // faster (assuming they call "new" on Solution - they very well might given
    // the other mistakes they have with their underlying framework.)
////////////////////////////////////////////////////////////////////////////////
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();


class Solution
{
public:
    bool containsDuplicate(vector<int>& nums) // I'd add "const" here if I could
    {                                          // but that's not the interface
        switch(nums.size())
        {
            case 0: return false; //or we could do fallthrough but ¯\_(ツ)_/¯
            case 1: return false;
            case 2: return nums.front()==nums.back();
        }

        auto const begin = nums.begin();
        auto const end = nums.end();

        for(auto cursor = begin+1;cursor != end; cursor+=1)
        {
            if (SortCursor(begin,cursor)) return true;
        }
        return false;
    }

private:
    // preconditions:
    // - range [begin,cursor) is sorted
    // - begin < cursor && cursor < end
    // returns:
    // - true if value of *cursor is in sorted range [begin,cursor)
    // - else false
    bool SortCursor(auto begin, auto cursor) const
    {
        auto sortedEnd = cursor-1;

        if (*sortedEnd == *cursor) return true;

        // worst case for lower_bound occurs when the object is inside/outside
        // the range (that is, the range is sorted or reverse-sorted) so we check
        // for that first.

        //range [begin,cursor] is already sorted and cursor is not a duplicate
        if (*sortedEnd < *cursor) return false;

        auto insertionPoint = (*begin > *cursor)
            ? begin
            : std::lower_bound(begin,cursor,*cursor);

        if(*insertionPoint == *cursor)
            return true;
        
        std::rotate(insertionPoint,cursor,cursor+1);
        return false;
    }
};