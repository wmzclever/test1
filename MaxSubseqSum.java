import java.util.ArrayList;
import java.util.Scanner;

public class MaxSubseqSum {
	private int sum=0;
	private int ThisSum=0;
	private int MaxSum=0;
	private ArrayList<Integer> sub=new ArrayList<Integer>();
	public MaxSubseqSum(int sum)
	{
		this.sum=sum;
	}
	public void add(int num)
	{
		sub.add(num);
	}
	public void clear()
	{
		sub.clear();
	}
	public void set(int sum)
	{
		this.sum=sum;
	}
	public int Calculate()	//the core code//calculating online 
	{
		for(int i=0;i<sum;i++)
		{
			ThisSum+=sub.get(i);
			if(ThisSum>MaxSum)
			{
				MaxSum=ThisSum;
			}
			else if(ThisSum<0)
			{
				ThisSum=0;
			}
		}
		return MaxSum;
	}
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int num=0;
		
		System.out.print("Please input the sum of the subsequence:");
		MaxSubseqSum k=new MaxSubseqSum(in.nextInt());
		
		System.out.print("Please input the number:");
		for(int i=0;i<k.sum;i++)
		{
			num=in.nextInt();
			k.add(num);
		}
		System.out.print("the MaxSubseqSum is:"+k.Calculate());
	}
}
