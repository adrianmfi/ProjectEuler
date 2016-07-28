ranks = '23456789TJQKA'
suits = 'HCSD'

def getCardsFromFile(filename):
    file = open(filename)
    hands = file.read().split()
    return hands

def isFlush(hand_suits):
    return (max(hand_suits) == 4)

def isStraight(hand_ranks):
    straight = True    
    if max(hand_ranks) == 1:
        for i in hand_ranks[hand_ranks.index(1):hand_ranks.index(1)+5]:
            if i == 0:
                straight = False
                break
    else:
        straight = False
    return straight

def getScoreHand(hand):
    hand_ranks = [0 for i in range(len(ranks))]
    hand_suits = [0 for i in range(len(suits))]
        
    for card in hand:
        hand_ranks[ranks.find(card[0])] += 1
        hand_suits[suits.find(card[1])] += 1
        
    flush = isFlush(hand_suits)
    straight = isStraight(hand_ranks)
    
    maxRanks = max(hand_ranks)
    minRanks = min(hand_ranks)

    if flush and straight:
        if hand_ranks[-1] == 1:
            return 10
        else:
            return 9
    if maxRanks == 4:
        return 8
    if maxRanks == 3 and minRanks == 2:
        return 7
    if flush:
        return 6
    if straight:
        return 5
    if maxRanks == 3:
        return 4
    if maxRanks == 2 and hand_ranks.index(2) != (len(hand_ranks)-1):
        if max(hand_ranks[hand_ranks.index(2)+1:]) == 2:
            return 3
    if maxRanks == 2:
        return 2
    return 1
        

if __name__ == "__main__":
    hands = getCardsFromFile('p054_poker.txt')
    p1_wins = 0
    
    hands_player_1 = []
    hands_player_2 = []
    
    for i in range(0,len(hands),10):
        hands_player_1 += [hands[i:i+5]]
        hands_player_2 += [hands[i+5:i+10]]

    for hand1,hand2 in zip(hands_player_1,hands_player_2):

        p1_score = getScoreHand(hand1)
        p2_score = getScoreHand(hand2)
        if p1_score > p2_score:
            p1_wins +=1
        elif p1_score == p2_score:
            hand_ranks1 = [0 for i in range(len(ranks))]
            hand_ranks2 = [0 for i in range(len(ranks))]
	            
            for card1,card2 in zip(hand1,hand2):
                hand_ranks1[ranks.find(card1[0])] += 1
                hand_ranks2[ranks.find(card2[0])] += 1
            
            if p1_score == 9 or p1_score == 5:
                if hand_ranks1.index(1) > hand_ranks2.index(1):
                   p1_wins+=1
            elif p1_score == 8:
               if hand_ranks1.index(4) > hand_ranks2.index(4):
                   p1_wins +=1
               elif hand_ranks1.index(4) == hand_ranks2.index(4):
                   if hand_ranks1.index(1) > hand_ranks2.index(1):
                       p1_wins +=1
            elif p1_score == 7:
               if hand_ranks1.index(3) > hand_ranks2.index(3):
                   p1_wins +=1
               elif hand_ranks1.index(3) == hand_ranks2.index(3):
                   if hand_ranks1.index(2) > hand_ranks2.index(2):
                       p1_wins +=1
            elif p1_score == 6:
               for rank1,rank2 in zip(hand_ranks1[::-1],hand_ranks2[::-1]):
                   if (rank1 > rank2):
                       p1_wins +=1
                       break
            elif p1_score == 4:
               if hand_ranks1.index(3) > hand_ranks2.index(3):
                   p1_wins +=1
               elif hand_ranks1.index(3) == hand_ranks2.index(3):
                   if hand_ranks1.index(1) > hand_ranks2.index(1):
                       p1_wins +=1
            elif p1_score == 3 or p1_score == 2:
                p1won = False
                for rank1,rank2 in zip(hand_ranks1[::-1],hand_ranks2[::-1]):
                    if rank1 ==2 and rank2 < 2:
                        p1_wins += 1
                        p1won = True
                        break
                if not p1won:
                    for rank1,rank2 in zip(hand_ranks1[::-1],hand_ranks2[::-1]):
                        if rank1 == 1 and rank2 == 0:
                            p1_wins +=1
                            break
            elif p1_score == 1:
                for rank1,rank2 in zip(hand_ranks1[::-1],hand_ranks2[::-1]):
                    if rank1 > rank2:
                        p1_wins +=1
                        break


    print(p1_wins)
