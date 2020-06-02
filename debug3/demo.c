int fib(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
int main()
{
	int times, result;
	times = read();
	int i;
	for(i=1;i<=times;i++)
	{
		int a;
		a = read();
		if(a >= 1)
		{
			result = fib(a);
		}
		else
		{
			break;
		}
		print(result);
		
	}
	
}