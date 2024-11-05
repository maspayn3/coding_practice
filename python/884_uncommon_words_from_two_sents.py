# Really looking for the symmetric difference of the two sets 
# If A and B are sets we need all the elemnts except the intersection


def uncommonFromSentences(s1: str, s2: str):
    sentence_1 = s1.split()
    sentence_2 = s2.split()

    word_dict = {}
    uncommon_words = []


    for word in sentence_1:

        if word in word_dict:
            word_dict[word] += 1
        else:
            word_dict[word] = 0

    for word in sentence_2:
        if word in word_dict:
            word_dict[word] += 1
        else:
            word_dict[word] = 0

    for key in word_dict.keys(): 
        if word_dict[key] == 0:
            uncommon_words.append(key)

    return uncommon_words



def main():
    result = uncommonFromSentences("apple apple", "banana")
    print(result)
    


if __name__ == '__main__':
    main()