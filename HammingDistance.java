package Leetcode;

import java.lang.*;

/**
 * Created by junbao on 2017/6/3.
 */
public class HammingDistance {
    public int hammingDistance(int x, int y) {
        //汉明距离即x与y异或后得到的值z,获取z的二进制数中的1的个数
        int diff = x ^ y;
        int res = testBinary(diff);
        return res;
    }
    public static int testBinary(int x){
        int count = 0;
        int bit = 0;
        while(x > 0){
            bit = x % 2;
            if(1 == bit)
                ++count;
            x /= 2;
        }
        return count;
    }

    //public static void main(String[] args)
    public static void main(String[] args){
        HammingDistance hd = new HammingDistance();
        int x = 1,y = 4;
        System.out.println(hd.hammingDistance(x,y));
    }

}
