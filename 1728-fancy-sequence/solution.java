class Fancy {
    
    ArrayList<Long> nums;
    
    long add, mult;
    long mod = 1000000007;
    long inverseMod = 1;
    public Fancy() 
    {
        nums = new ArrayList<Long>();
        add = 0;
        mult = 1;
    }
    
    private long inverse(long p) 
    {
        long inv = 1, y = mod-2;
        for (; y > 0; y /= 2) {
            if (y % 2 != 0)
                inv = (inv * p) % mod;
            p = (p * p) % mod;
        }
        return inv;
    }
    
    public void append(int val) 
    {
        nums.add((mod + val - add)%mod * inverse(mult)%mod);
       
    }
    
   
    public void addAll(int inc) 
    {
        add += inc;
        
    }
    
    public void multAll(int m) 
    {
        add = (add * m) % mod;
        mult = (mult *m)%mod;

    }
    
    public int getIndex(int idx) 
    {
        if(idx >= nums.size())
            return -1;
        return (int)(((nums.get(idx)*mult)%mod + add)%mod);
        
    }
}

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy obj = new Fancy();
 * obj.append(val);
 * obj.addAll(inc);
 * obj.multAll(m);
 * int param_4 = obj.getIndex(idx);
 */
