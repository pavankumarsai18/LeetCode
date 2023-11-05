use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen = HashMap::new();

        for (index, num) in nums.iter().enumerate() {
            let other = target - num;

            if seen.contains_key(&other) {
                return vec![seen[&other], index as i32];
            }

            seen.insert(num, index as i32);
        }

        return Vec::new();
    }
}
