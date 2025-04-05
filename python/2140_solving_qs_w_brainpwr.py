from typing import List

# Very incorrect solution. Does not consider all paths
def most_points(questions: List[List[int]]) -> int: 
    num_qs = len(questions)
    max_points = 0

    for i in range(num_qs):
        score = questions[i][0]
        cost = questions[i][1] + 1
        next_i = i + cost

        while next_i < num_qs:
            score += questions[next_i][0]
            cost = questions[next_i][1] + 1
            next_i += cost
            
        max_points = max(max_points, score)
    return max_points

def most_points_correct(questions) -> int:
    
    dp = {}

    # returns maximum score from starting exam at i
    def dfs(i):
        if i >= len(questions):
            return 0
        
        if i in dp: 
            return dp[i]

        dp[i] = max(
            dfs(i + 1), # skip question
            questions[i][0] + dfs(i + 1 + questions[i][1])
            )
        return dp[i]
    return dfs(0)

def main():
    sol = most_points_correct([[3,2],[4,3],[4,4],[2,5]])
    print(sol)

if __name__ == '__main__':
    main()