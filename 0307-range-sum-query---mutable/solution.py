class SegmentTree:
    def __init__(self, nums):
        n = len(nums)
        self.n = n
        self.tree = [0] * (4 * n)  # segment tree array
        self.build(nums, 0, 0, n - 1)

    def build(self, nums, node, start, end):
        if start == end:
            # Leaf node will have a single element
            self.tree[node] = nums[start]
        else:
            mid = (start + end) // 2
            left_child = 2 * node + 1
            right_child = 2 * node + 2
            self.build(nums, left_child, start, mid)
            self.build(nums, right_child, mid + 1, end)
            # Internal node will have the sum of both of its children
            self.tree[node] = self.tree[left_child] + self.tree[right_child]

    def update(self, idx, val, node, start, end):
        if start == end:
            # Leaf node, update the value
            self.tree[node] = val
        else:
            mid = (start + end) // 2
            left_child = 2 * node + 1
            right_child = 2 * node + 2
            if start <= idx <= mid:
                self.update(idx, val, left_child, start, mid)
            else:
                self.update(idx, val, right_child, mid + 1, end)
            # After update, recalculate the sum of the current node
            self.tree[node] = self.tree[left_child] + self.tree[right_child]

    def query(self, L, R, node, start, end):
        if R < start or end < L:
            # No overlap
            return 0
        if L <= start and end <= R:
            # Total overlap
            return self.tree[node]
        # Partial overlap
        mid = (start + end) // 2
        left_child = 2 * node + 1
        right_child = 2 * node + 2
        left_sum = self.query(L, R, left_child, start, mid)
        right_sum = self.query(L, R, right_child, mid + 1, end)
        return left_sum + right_sum


class NumArray:

    def __init__(self, nums):
        # Initialize the Segment Tree with the nums array
        self.segment_tree = SegmentTree(nums)

    def update(self, index, val):
        # Update the value at the index in the original array
        self.segment_tree.update(index, val, 0, 0, self.segment_tree.n - 1)

    def sumRange(self, left, right):
        # Get the sum in the range [left, right]
        return self.segment_tree.query(left, right, 0, 0, self.segment_tree.n - 1)

