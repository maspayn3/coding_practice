import heapq

def min_add_to_make_valid(s: str):
        # idea is to just keep a running count of the 
        # number based on what we see "(": 1 or ")": -1 

        result = 0
        open_tracker = 0
        for paren in s:
            if paren == "(":
                open_tracker += 1

            elif paren == ")":
                if open_tracker == 0:
                    result += 1
                else:
                    open_tracker -= 1


        result += open_tracker
        return result
                
def main():
    s = "()))(("
    print(min_add_to_make_valid(s))
    

if __name__ == '__main__':
    main()