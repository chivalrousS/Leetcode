package leetcode;

import java.util.HashMap;
import java.util.Map;

public class majority {
	public static int majorityElement(int[] num)
	{
		int len = num.length;
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int i=0;i<len;++i)
		{
			if(!map.containsKey(num[i]))
			{
				map.put(num[i], 1);
				if(len == 1)
					return num[i];
			}
			else 
			{
				map.put(num[i], map.get(num[i])+1);
				if(map.get(num[i]) > len/2)
					return num[i];
			}
		}
		for(Map.Entry<Integer, Integer> entry:map.entrySet())
		{
			int key = entry.getKey();
			int count = entry.getValue();
			if(count >=len/2)
				return key;
		}
		return -1;
	}
	
	public static void main(String[] args)
	{
		int[] num1 = {8,8,7,7,7};
		int[] num2 = {3,1,3,2,3,4,6};
		int result1 = majorityElement(num1);
		int result2 = majorityElement(num2);
		System.out.println("num1 is "+result1+",num2 is "+result2);
	}

}
