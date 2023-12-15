class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        balanceMap = defaultdict(int)

        for from_, to_, amount in transactions:
            balanceMap[from_] -= amount
            balanceMap[to_] += amount

        positives = [val for val in balanceMap.values() if val > 0]
        negatives = [val for val in balanceMap.values() if val < 0]


        def backtrack(positives, negatives):

            if len(positives) + len(negatives) == 0: return 0

            negative = negatives[0]
            min_transactions = float('inf')

            for positive in positives:

                new_positives = positives.copy()
                new_negatives = negatives.copy()

                new_positives.remove(positive)
                new_negatives.remove(negative)

                amount_owed = positive + negative

                if amount_owed > 0:
                    new_positives.append(amount_owed)
                elif amount_owed < 0:
                    new_negatives.append(amount_owed)

                
                min_transactions = min(min_transactions, backtrack(new_positives, new_negatives))
            
            return min_transactions + 1
        
        return backtrack(positives, negatives)

                
