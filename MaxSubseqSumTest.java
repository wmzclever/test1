import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class MaxSubseqSumTest {

	private MaxSubseqSum test=new MaxSubseqSum(8);
	public void InitSub(int n,int[] a)
	{
		test.set(n);
		test.clear();
		for(int k:a)
		{
			test.add(k);
		}
	}
	
	@Test
	void testCalculate_1() {
		int[]a= {1,2,-4,6,-2,-10,5};
		InitSub(6, a);
		assertEquals(6,test.Calculate());
	}
	
	@Test
	void testCalculate_2()
	{
		int[]a= {-1,-2,-3,-5};
		InitSub(4, a);
		assertEquals(0,test.Calculate());
	}
	
	@Test
	void testCalculate_3()
	{
		int[]a= {2,-1,-1};
		InitSub(3, a);
		assertEquals(2,test.Calculate());
	}
}
