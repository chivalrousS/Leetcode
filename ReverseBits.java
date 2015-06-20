package leetcode;
/*
 * Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
 */
public class ReverseBits {
	// you need treat n as an unsigned value
    public static int reverseBits(int n) {
        //
        int INT_SIZE = Integer.SIZE;
        
        for(int i = 0;i < INT_SIZE/2; ++i)
        {
            int j = INT_SIZE - 1 - i;
            
            int low = (n >>i ) & 1;
            int high = (n >> j) & 1;
            
            int m = 1 << i;
            int p = 1 << j;
            
            if((low ^ high) == 1)
                n = n^(m | p);
        }
        return n;
    }
    public static void main(String[] args)
    {
    	int n = 43261596;
    	int m = reverseBits(n);
    	System.out.printf("%s\t%s",n,m);
    }

}
