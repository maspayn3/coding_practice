import heapq

def minTimeToVisitAllPoints(points):
    total_time = 0

    # vertical, horizontal, and diagonal movment are all 1 second
    # we can basically try to simulate a greedy walking path
    # IDEA: always try to walk diagonally, it gives the most distance
    #   What makes a diagonal possible? 
    #           - Able to move horizontally and verticall
        #           - if diff_x < 0 || diff_x > 0 && diff_y > 0 || diff_y < 0  
    for i, point in enumerate(points):

        if i + 1 == len(points):
            break

        curr_point = point
        next_point = points[i + 1]

        diff_x = next_point[0] - curr_point[0]
        diff_y = next_point[1] - curr_point[1]

        # until this is not true we can move diagonally
        while (diff_x != 0) and (diff_y != 0):
            total_time += 1

            if diff_x < 0:
                diff_x += 1
            else:
                diff_x -= 1

            if diff_y < 0:
                diff_y += 1
            else:
                diff_y -= 1

        # now check for horizontal and vertical leftover movement
        if diff_y != 0:
            total_time += abs(diff_y)
        if diff_x != 0:
            total_time += abs(diff_x)

    return total_time


def main():
    minTimeToVisitAllPoints([[1,1],[3,4],[-1,0]])

if __name__ == '__main__':
    main()